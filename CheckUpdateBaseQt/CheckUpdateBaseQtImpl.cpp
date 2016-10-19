#include "CheckUpdateBaseQtImpl.h"

CheckUpdateBaseQtImpl::CheckUpdateBaseQtImpl() : CheckUpdateBaseQt()
{

}

void CheckUpdateBaseQtImpl::SetSink(CheckUpdateBaseQtSink *sink)
{
    mSink = sink;
}

void CheckUpdateBaseQtImpl::SetRemoteSourceVersionUrl(const QUrl &url)
{
    mRemoteSourceVersionUrl = rul;
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
