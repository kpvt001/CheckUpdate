#pragma once
//#ifndef CHECKUPDATEBASEQTRESULTIMPL_H
//#define CHECKUPDATEBASEQTRESULTIMPL_H

#include <QJsonObject>

#include "CheckUpdateBaseQtResult.h"

class CheckUpdateBaseQtResultImpl : public CheckUpdateBaseQtResult
{
public:
    CheckUpdateBaseQtResultImpl();

    virtual bool RemoteVersionIsNewer() const;
    virtual void SetRemoteVersionIsNewer(bool b);
    virtual void Hold();
    virtual bool IsHeld() const;
    virtual void SetHold(bool hold);
    virtual void GetRemoteSourceVersion(int *version);
    virtual void SetRemoteSourceVersion(const int version[]);
    virtual QString VersionSummary() const;
    virtual void SetVersionSummary(const QString &summary);
    virtual QString FileDownloadPageUrlString() const;
    virtual void SetFileDownloadPageUrlString(const QString &page);

private:
    bool mRemoteHasNewVersion;
    bool mIsHeld;
    int mRemoteVersion[4];
    QString mVersionSummary;
    QString mFileDownloadPageUrlString;
};

//#endif // CHECKUPDATEBASEQTRESULTIMPL_H
