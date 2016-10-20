#include "CheckUpdateBaseQtResult.h"

#include "CheckUpdateBaseQtResultImpl.h"

CheckUpdateBaseQtResult::CheckUpdateBaseQtResult()
{

}

CheckUpdateBaseQtResult* CheckUpdateBaseQtResult::Create()
{
    CheckUpdateBaseQtResult * r = new CheckUpdateBaseQtResultImpl;
    return r;
}
