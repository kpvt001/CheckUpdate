#pragma once
//#ifndef CHECKUPDATEBASEQTRESULT_H
//#define CHECKUPDATEBASEQTRESULT_H

#include "checkupdatebaseqt_global.h"

class SHARED_EXPORT CheckUpdateBaseQtResult
{
public:
    CheckUpdateBaseQtResult();
    virtual ~CheckUpdateBaseQtResult();

    virtual bool RemoteHasNewVersion() const;
    virtual void SetRemoteHasNewVersion(bool b);
    virtual void Hold();
    virtual void SetHold(bool hold);
    virtual void GetRemoteSourceVersion(int *version);
    virtual void SetRemoteSourceVersion(const int version[]);
    virtual QString VersionSummary() const;
    virtual void SetVersionSummary(const QString &summary);
    virtual QString FileDownloadPageUrlString() const;
    virtual void SetFileDownloadPageUrlString(const QString &page);
};

//#endif // CHECKUPDATEBASEQTRESULT_H
