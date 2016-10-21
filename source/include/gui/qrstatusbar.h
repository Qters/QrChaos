#ifndef QRSTATUSBAR_H
#define QRSTATUSBAR_H

#include <QtWidgets/qstatusbar.h>

#include "qrglobal.h"
#include "qrchaosbase_global.h"

NS_CHAOS_BASE_BEGIN

class QrStatusBarPrivate;

class CHAOSBASE_SHAREDEXPORT QrStatusBar : public QStatusBar
{
    Q_OBJECT
    QR_DECLARE_PRIVATE(QrStatusBar)

public:
    explicit QrStatusBar(QWidget* parent = nullptr);

public Q_SLOTS:
    void onNormalMode(bool checked = false);
    void onSimpleMode(bool checked = false);
    void onFullScreenMode(bool checked = false);
};

NS_CHAOS_BASE_END

#endif //   QRSTATUSBAR_H
