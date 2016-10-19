#pragma once
//#ifndef CHECKUPDATEBASEQTRESULT_H
//#define CHECKUPDATEBASEQTRESULT_H

#include <QString>

#include "checkupdatebaseqt_global.h"

class SHARED_EXPORT CheckUpdateBaseQtResult
{
public:
    CheckUpdateBaseQtResult();

    virtual bool RemoteHasNewVersion() const = 0;
    virtual void SetRemoteHasNewVersion(bool b) = 0;
    virtual void Hold() = 0;
    virtual void SetHold(bool hold) = 0;
    virtual void GetRemoteSourceVersion(int *version) = 0;
    virtual void SetRemoteSourceVersion(const int version[]) = 0;
    virtual QString VersionSummary() const = 0;
    virtual void SetVersionSummary(const QString &summary) = 0;
    virtual QString FileDownloadPageUrlString() const = 0;
    virtual void SetFileDownloadPageUrlString(const QString &page) = 0;
};

//#endif // CHECKUPDATEBASEQTRESULT_H
