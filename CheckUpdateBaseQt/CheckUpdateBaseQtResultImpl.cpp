#include "CheckUpdateBaseQtResultImpl.h"

CheckUpdateBaseQtResultImpl::CheckUpdateBaseQtResultImpl()
    : mIsHeld(false)
    , CheckUpdateBaseQtResult()
{

}

bool CheckUpdateBaseQtResultImpl::RemoteHasNewVersion() const
{
    return mRemoteHasNewVersion;
}

void CheckUpdateBaseQtResultImpl::SetRemoteHasNewVersion(bool b)
{
    mRemoteHasNewVersion = b;
}

void CheckUpdateBaseQtResultImpl::Hold()
{
    SetHold(true);
}

void CheckUpdateBaseQtResultImpl::SetHold(bool hold)
{
    mIsHeld = hold;
}

void CheckUpdateBaseQtResultImpl::GetRemoteSourceVersion(int *version)
{
    for (int i = 0; i < 4; i++)
        version[i] = mRemoteVersion[i];
}

void CheckUpdateBaseQtResultImpl::SetRemoteSourceVersion(const int version[])
{
    for (int i = 0; i < 4; i++)
        mRemoteVersion[i] = version[i];
}

QString CheckUpdateBaseQtResultImpl::VersionSummary() const
{
    return mVersionSummary;
}

void CheckUpdateBaseQtResultImpl::SetVersionSummary(const QString &summary)
{
    mVersionSummary = summary;
}

QString CheckUpdateBaseQtResultImpl::FileDownloadPageUrlString() const
{
    return mFileDownloadPageUrlString;
}

void CheckUpdateBaseQtResultImpl::SetFileDownloadPageUrlString(const QString &page)
{
    mFileDownloadPageUrlString = page;
}
