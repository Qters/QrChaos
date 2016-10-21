#ifndef QRNAVIGATION_H
#define QRNAVIGATION_H

#include <functional>

#include <QtWidgets/qwidget.h>

#include "qrchaosbase_global.h"
#include "qrglobal.h"

NS_CHAOS_BASE_BEGIN

class QrNavigationPrivate;

class CHAOSBASE_SHAREDEXPORT QrNavigation : public QWidget
{
    QR_DECLARE_PRIVATE(QrNavigation)
public:
    explicit QrNavigation(QWidget* parent = nullptr);

public:
    //  signal is void(bool checked = false)
    static bool qrconnect(const QString& path,
                          const QObject *receiver,
                          const char *member);
};

NS_CHAOS_BASE_END

#endif // QRNAVIGATION_H
