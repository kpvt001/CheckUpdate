#pragma once
//#ifndef CHECKUPDATEBASEQT_H
//#define CHECKUPDATEBASEQT_H

#include "checkupdatebaseqt_global.h"

#include <QString>
#include <QUrl>

#include "CheckUpdateBaseQtResult.h"
#include "CheckUpdateBaseQtError.h"


class CheckUpdateBaseQtSink
{
public:
    virtual void OnCheckUpdateFinished(CheckUpdateBaseQtResult *result) = 0;
    virtual void OnCheckUpdateError(CheckUpdateBaseQtError *error) = 0;
};



class SHARED_EXPORT CheckUpdateBaseQt
{

public:
    static CheckUpdateBaseQt* Create();
    void virtual SetSink(CheckUpdateBaseQtSink *sink) = 0;
    //void virtual SetLocalRootPath(const QString &rootPath);
    void virtual SetRemoteSourceVersionUrl(const QUrl &url) = 0;
    void virtual SetAppId(const QString &appId) = 0;
    void virtual SetGroupId(const QString &groupId) = 0;

    // If version[3](build version) is not 0, only check version[3]
    //   , otherwise check version[0-2].
    void virtual SetLocalVersion(const int version[]) = 0;

protected:
    CheckUpdateBaseQt();
};

//#endif // CHECKUPDATEBASEQT_H
