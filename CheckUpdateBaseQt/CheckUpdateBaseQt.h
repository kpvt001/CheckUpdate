#pragma once
//#ifndef CHECKUPDATEBASEQT_H
//#define CHECKUPDATEBASEQT_H

#include "checkupdatebaseqt_global.h"

#include <QString>
#include <QUrl>
#include <QObject>

#include "CheckUpdateBaseQtResult.h"
#include "CheckUpdateBaseQtError.h"


class CheckUpdateBaseQtSink
{
public:
    virtual void OnCheckUpdateFinished(CheckUpdateBaseQtResult *result) = 0;
    virtual void OnCheckUpdateError(CheckUpdateBaseQtError *error) = 0;
};



class SHARED_EXPORT CheckUpdateBaseQt : public QObject
{
    //Q_OBJECT
public:
    void virtual Start() = 0;
    void virtual SetSink(CheckUpdateBaseQtSink *sink) = 0;
    //void virtual SetLocalRootPath(const QString &rootPath);
    void virtual SetRemoteSourceVersionUrl(const QUrl &url) = 0;
    void virtual SetAppId(const QString &appId) = 0;
    void virtual SetGroupId(const QString &groupId) = 0;
    void virtual SetLocalVersion(const int version[]) = 0;
    static CheckUpdateBaseQt* Create();

protected:
    CheckUpdateBaseQt(QObject *parent = nullptr);
};

//#endif // CHECKUPDATEBASEQT_H
