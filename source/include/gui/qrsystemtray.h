#ifndef QRSYSTEMTRAY_H
#define QRSYSTEMTRAY_H

#include "qrglobal.h"
#include "qrchaosbase_global.h"

//NS_CHAOS_BASE_BEGIN

NS_CHAOS_BASE_BEGIN

class QrSystemTrayPrivate;
class CHAOSBASE_SHAREDEXPORT QrSystemTray
{
    QR_DECLARE_PRIVATE(QrSystemTray)
public:
    QrSystemTray(QWidget* parent);

public:
    static bool qrconnect(const QString &key,
                          const QObject *receiver,
                          const char *member);
};

NS_CHAOS_BASE_END

#endif // QRSYSTEMTRAY_H
