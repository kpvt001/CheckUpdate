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
    virtual void OnCheckUpdateFinished(CheckUpdateBaseQtResult *result);
    virtual void OnCheckUpdateError(CheckUpdateBaseQtError *error);
};



class SHARED_EXPORT CheckUpdateBaseQt
{

public:
    static CheckUpdateBaseQt* Create();
    void virtual SetSink(CheckUpdateBaseQtSink *sink);
    //void virtual SetLocalRootPath(const QString &rootPath);
    void virtual SetRemoteSourceVersionUrl(const QUrl &url);
    void virtual SetAppId(const QString &appId);
    void virtual SetGroupId(const QString &groupId);

    // If version[3](build version) is not 0, only check version[3]
    //   , otherwise check version[0-2].
    void virtual SetLocalVersion(const int version[]);

    virtual ~CheckUpdateBaseQt();


private:
    CheckUpdateBaseQt();
};

//#endif // CHECKUPDATEBASEQT_H
