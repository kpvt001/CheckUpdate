#include "CheckUpdateBaseQt.h"

#include "CheckUpdateBaseQtImpl.h"

CheckUpdateBaseQt::CheckUpdateBaseQt(QObject *parent)
    : QObject(parent)
{
}

CheckUpdateBaseQt* CheckUpdateBaseQt::Create()
{
    CheckUpdateBaseQt *instance = new CheckUpdateBaseQtImpl;
    return instance;
}
