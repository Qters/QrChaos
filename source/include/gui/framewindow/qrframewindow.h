#ifndef QRFRAMEWINDOW_H
#define QRFRAMEWINDOW_H

#include <QtWidgets/qframe.h>

#include "qrchaosbase_global.h"
#include "qrglobal.h"

NS_CHAOS_BASE_BEGIN

class QrHeader;
class QrNavigation;
class QrWorkspace;
class QrStatusBar;
class QrFrameWindowPrivate;

class CHAOSBASE_SHAREDEXPORT QrFrameWindow : public QFrame
{
    QR_DECLARE_PRIVATE(QrFrameWindow)

public:
    explicit QrFrameWindow(QWidget* parent = nullptr);

public:
    QrHeader *getHeader();
    QrNavigation *getNavigation();
    QrWorkspace *getWorkspace();
    QrStatusBar *getStatusbar();
};

NS_CHAOS_BASE_END

#endif // QRFRAMEWINDOW_H
