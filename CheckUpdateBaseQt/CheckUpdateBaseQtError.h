#pragma once
//#ifndef CHECKUPDATEBASEQTERROR_H
//#define CHECKUPDATEBASEQTERROR_H

#include "checkupdatebaseqt_global.h"

class SHARED_EXPORT CheckUpdateBaseQtError
{
public:
    CheckUpdateBaseQt();
    virtual ~CheckUpdateBaseQtError();

    virtual int Code() const;
    virtual void SetCode(int code);
    virtual QString What() const;
    virtual void SetWhat(const QString &what);
    virtual void Hold();
    virtual void SetHold(bool hold);
};


//#endif // CHECKUPDATEBASEQTERROR_H
