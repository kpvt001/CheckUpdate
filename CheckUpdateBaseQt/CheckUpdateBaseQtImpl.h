#pragma once
//#ifndef CHECKUPDATEBASEQTIMPL_H
//#define CHECKUPDATEBASEQTIMPL_H

#include "CheckUpdateBaseQt.h"

class CheckUpdateBaseQtImpl : public CheckUpdateBaseQt
{
    struct Version
    {
        int v1;
        int v2;
        int v3;
        int v4;
    };

public:
    void virtual SetSink(CheckUpdateBaseQtSink *sink);
    void virtual SetRemoteSourceVersionUrl(const QUrl &url);
    void virtual SetAppId(const QString &appId);
    void virtual SetGroupId(const QString &groupId);
    void virtual SetLocalVersion(const int version[]);

private:
    CheckUpdateBaseQtImpl();

    Version mLocalVersion;
    CheckUpdateBaseQtSink *mSink;
    QUrl mRemoteSourceVersionUrl;
    QString mAppId;
    QString mGroupId;

};

//#endif // CHECKUPDATEBASEQTIMPL_H
