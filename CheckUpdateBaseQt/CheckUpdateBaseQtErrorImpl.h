#pragma once
//#ifndef CHECKUPDATEBASEQTERRORIMPL_H
//#define CHECKUPDATEBASEQTERRORIMPL_H

#include "CheckUpdateBaseQtError.h"

class CheckUpdateBaseQtErrorImpl :public CheckUpdateBaseQtError
{
public:
    CheckUpdateBaseQtErrorImpl();

    virtual int Code() const;
    virtual void SetCode(int code);
    virtual QString What() const;
    virtual void SetWhat(const QString &what);
    virtual void Hold();
    virtual void SetHold(bool hold);

private:
    int mCode;
    QString mWhat;
    bool mIsHeld;
};

//#endif // CHECKUPDATEBASEQTERRORIMPL_H
