#include "CheckUpdateBaseQtErrorImpl.h"

CheckUpdateBaseQtErrorImpl::CheckUpdateBaseQtErrorImpl()
    : mCode(0)
    , CheckUpdateBaseQtErrork()
{

}

int CheckUpdateBaseQtErrorImpl::Code() const
{
    return mCode;
}

void CheckUpdateBaseQtErrorImpl::SetCode(int code)
{
    mCode = code;
}

QString CheckUpdateBaseQtErrorImpl::What() const
{
    return mWhat;
}

void CheckUpdateBaseQtErrorImpl::SetWhat(const QString &what)
{
    mWhat = what;
}

void CheckUpdateBaseQtErrorImpl::Hold()
{
    SetHold(true);
}

void CheckUpdateBaseQtErrorImpl::SetHold(bool hold)
{
    mIsHeld = hold;
}
