#pragma once
//#ifndef CHECKUPDATEBASEQTRESULT_H
//#define CHECKUPDATEBASEQTRESULT_H

#include <QString>

#include "checkupdatebaseqt_global.h"

class SHARED_EXPORT CheckUpdateBaseQtResult
{
public:
    virtual bool RemoteVersionIsNewer() const = 0;
    virtual void SetRemoteVersionIsNewer(bool b) = 0;
    virtual void Hold() = 0;
    virtual bool IsHeld() const = 0;
    virtual void SetHold(bool hold) = 0;
    virtual void GetRemoteSourceVersion(int *version) = 0;
    virtual void SetRemoteSourceVersion(const int version[]) = 0;
    virtual QString VersionSummary() const = 0;
    virtual void SetVersionSummary(const QString &summary) = 0;
    virtual QString FileDownloadPageUrlString() const = 0;
    virtual void SetFileDownloadPageUrlString(const QString &page) = 0;
    static CheckUpdateBaseQtResult* Create();

protected:
    CheckUpdateBaseQtResult();

};

//#endif // CHECKUPDATEBASEQTRESULT_H
