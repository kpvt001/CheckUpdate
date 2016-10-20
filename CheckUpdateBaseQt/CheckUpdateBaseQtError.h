#pragma once
//#ifndef CHECKUPDATEBASEQTERROR_H
//#define CHECKUPDATEBASEQTERROR_H

#include <QString>

#include "checkupdatebaseqt_global.h"

class SHARED_EXPORT CheckUpdateBaseQtError
{
public:
    enum Error
    {
        NoError = 0,
        ErrorNetworkIuuse = 10000,
        ErrorUnknownError = 99999,
    };
    virtual int Code() const = 0;
    virtual void SetCode(int code) = 0;
    virtual QString What() const = 0;
    virtual void SetWhat(const QString &what) = 0;
    virtual bool IsHeld() const =0;
    virtual void Hold() = 0;
    virtual void SetHold(bool hold) = 0;
    static CheckUpdateBaseQtError* Create();

protected:
    CheckUpdateBaseQtError();
};


//#endif // CHECKUPDATEBASEQTERROR_H
