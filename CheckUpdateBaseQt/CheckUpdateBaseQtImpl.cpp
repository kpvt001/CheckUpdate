#include "CheckUpdateBaseQtImpl.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QSsl>

#include "CheckUpdateBaseQtError.h"

CheckUpdateBaseQtImpl::CheckUpdateBaseQtImpl() : CheckUpdateBaseQt()
{

}

CheckUpdateBaseQtImpl::~CheckUpdateBaseQtImpl()
{
}

void CheckUpdateBaseQtImpl::SetSink(CheckUpdateBaseQtSink *sink)
{
    mSink = sink;
}

void CheckUpdateBaseQtImpl::SetRemoteSourceVersionUrl(const QUrl &url)
{
    mRemoteSourceVersionUrl = url;
}

void CheckUpdateBaseQtImpl::SetAppId(const QString &appId)
{
    mAppId = appId;
}

void CheckUpdateBaseQtImpl::SetGroupId(const QString &groupId)
{
    mGroupId = groupId;
}

void CheckUpdateBaseQtImpl::SetLocalVersion(const int version[])
{
    mLocalVersion.v1 = version[0];
    mLocalVersion.v2 = version[1];
    mLocalVersion.v3 = version[2];
    mLocalVersion.v4 = version[3];
}

void CheckUpdateBaseQtImpl::Start()
{
    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
    connect(mgr, SIGNAL(finished(QNetworkReply*)), this, SLOT(onNetReplyFinished(QNetworkReply*)));
    QNetworkRequest request(mRemoteSourceVersionUrl);
    if (mRemoteSourceVersionUrl.toString().toLower().startsWith(QString("https").toLower()))
    {
        QSslConfiguration sslConfig;
        sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
        sslConfig.setProtocol(QSsl::TlsV1SslV3);
        request.setSslConfiguration(sslConfig);
    }
    mgr->get(request);
    qDebug() << mRemoteSourceVersionUrl;
}

void CheckUpdateBaseQtImpl::onNetReplyFinished(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError)
    {
        DisposeNetworkReplyError(reply->error());
    }
    else
    {
        QJsonParseError jParseError;
        QJsonDocument jDoc = QJsonDocument::fromJson(reply->readAll(), &jParseError);
        qDebug() << reply->readAll();
        qDebug() << reply->readAll().size();
        qDebug() << jParseError.errorString();
        if (!jDoc.isObject())
        {
            DisposeError(CheckUpdateBaseQtError::ErrorUnknownError);
        }
        else
        {
            QJsonObject jObject = jDoc.object();
            CheckUpdateBaseQtResult *result = MakeResult(jObject["result"].toObject());
            if (mSink != nullptr)
                mSink->OnCheckUpdateFinished(result);
            if (!result->IsHeld())
                delete result;
        }
    }
    reply->deleteLater();
    this->deleteLater();
}

void CheckUpdateBaseQtImpl::DisposeError(int errorCode)
{
    CheckUpdateBaseQtError *error = CheckUpdateBaseQtError::Create();
    error->SetCode(errorCode);
    if (mSink)
        mSink->OnCheckUpdateError(error);

    if (!error->IsHeld())
        delete error;
}

void CheckUpdateBaseQtImpl::DisposeNetworkReplyError(int errorCode)
{
    Q_UNUSED(errorCode)
    CheckUpdateBaseQtError *error = CheckUpdateBaseQtError::Create();
    error->SetCode(CheckUpdateBaseQtError::ErrorNetworkIuuse);
    if (mSink)
        mSink->OnCheckUpdateError(error);

    if (!error->IsHeld())
        delete error;
}

CheckUpdateBaseQtResult* CheckUpdateBaseQtImpl::MakeResult(const QJsonObject &jObject)
{
    CheckUpdateBaseQtResult *result = CheckUpdateBaseQtResult::Create();

    QJsonArray jVersions = jObject["version"].toArray();
    int v[4];
    for (int i = 0; i < 4; i++)
    {
        QJsonValue jValue = jVersions[i];
        v[i] = jValue.toInt();
    }
    result->SetRemoteSourceVersion(v);
    result->SetRemoteVersionIsNewer(VersionIsNewerThanLocal(v));

    QString summary = jObject["summary"].toString();
    result->SetVersionSummary(summary);

    QString pageUrlString = jObject["latestFileLink"].toString();
    result->SetFileDownloadPageUrlString(pageUrlString);

    return result;
}

bool CheckUpdateBaseQtImpl::VersionIsNewerThanLocal(const int version[]) const
{
    bool ret = version[0] > mLocalVersion.v1
            || version[1] > mLocalVersion.v2
            || version[2] > mLocalVersion.v3
            || version[3] > mLocalVersion.v4;

    return ret;
}
