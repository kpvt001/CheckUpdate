#pragma once
//#ifndef CHECKUPDATEBASEQTIMPL_H
//#define CHECKUPDATEBASEQTIMPL_H
#include <QtNetwork/QNetworkReply>
#include <QJsonObject>

#include "CheckUpdateBaseQt.h"
#include "CheckUpdateBaseQtResult.h"

class CheckUpdateBaseQtImpl : public CheckUpdateBaseQt
{
    Q_OBJECT

    friend class CheckUpdateBaseQt;

    struct Version
    {
        int v1;
        int v2;
        int v3;
        int v4;
    };

public:
    virtual ~CheckUpdateBaseQtImpl();
    virtual void Start();
    void virtual SetSink(CheckUpdateBaseQtSink *sink);
    void virtual SetRemoteSourceVersionUrl(const QUrl &url);
    void virtual SetAppId(const QString &appId);
    void virtual SetGroupId(const QString &groupId);
    void virtual SetLocalVersion(const int version[]);

public slots:
    void onNetReplyFinished(QNetworkReply *reply);

private:
    CheckUpdateBaseQtImpl();
    void DisposeNetworkReplyError(int errorCode);
    void DisposeError(int errorCode);
    CheckUpdateBaseQtResult* MakeResult(const QJsonObject &jObject);
    bool VersionIsNewerThanLocal(const int version[]) const;

    Version mLocalVersion;
    CheckUpdateBaseQtSink *mSink;
    QUrl mRemoteSourceVersionUrl;
    QString mAppId;
    QString mGroupId;

};

//#endif // CHECKUPDATEBASEQTIMPL_H
