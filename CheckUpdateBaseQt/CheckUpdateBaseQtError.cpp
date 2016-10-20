#include "CheckUpdateBaseQtError.h"

#include "CheckUpdateBaseQtErrorImpl.h"

CheckUpdateBaseQtError::CheckUpdateBaseQtError()
{

}

CheckUpdateBaseQtError* CheckUpdateBaseQtError::Create()
{
    CheckUpdateBaseQtError *e = new CheckUpdateBaseQtErrorImpl;
    return e;
}
