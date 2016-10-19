#include "CheckUpdateBaseQt.h"

#include "CheckUpdateBaseQtImpl.h"

CheckUpdateBaseQt::CheckUpdateBaseQt()
{
}

CheckUpdateBaseQt* CheckUpdateBaseQt::Create()
{
    CheckUpdateBaseQt *instance = new CheckUpdateBaseQtImpl;
    return instance;
}
