#ifndef QRCHAOSMAINWINDOW_H
#define QRCHAOSMAINWINDOW_H

#include "qrmainwindow.h"
#include "qrglobal.h"

#include "qrchaosbase_global.h"

QT_BEGIN_NAMESPACE
class QSplitter;
QT_END_NAMESPACE

NS_CHAOS_BASE_BEGIN

class QrChaosMainwindowPrivate;

class CHAOSBASE_SHAREDEXPORT QrChaosMainwindow : public Qters::QrFrame::QrMainWindow
{
    Q_OBJECT
    QR_DECLARE_PRIVATE(QrChaosMainwindow)
public:
    explicit QrChaosMainwindow(QWidget *parent = nullptr);

    // QrMainWindow interface
public:
    virtual bool init() override;
};

NS_CHAOS_BASE_END

#endif QRCHAOSMAINWINDOW_H
