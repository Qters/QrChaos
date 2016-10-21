#ifndef QRMAINSERVICE_H
#define QRMAINSERVICE_H

#include "qrglobal.h"
#include "core/qrifservice.h"
#include "gui/navigation/qrnavigation.h"
#include "qrchaosmainservice_global.h"

NS_CHAOS_MAIN_SERVICE_BEGIN

class QrMainServicePrivate;

class CHAOS_MAINSERVICESHARED_EXPORT QrMainService : public QObject, public Qters::QrFrame::QrIfService
{
    Q_OBJECT
    QR_DECLARE_PRIVATE(QrMainService)
    Q_PLUGIN_METADATA(IID "com.qters.qrframe.normal.service.main" FILE "mainservice.json")
    Q_INTERFACES(Qters::QrFrame::QrIfService)

public:
    QrMainService();

    // QrIfService interface
public:
    virtual bool init() override;

private slots:
    void onAbout();
    void onContact();
    void onNews();
};

NS_CHAOS_MAIN_SERVICE_END

#endif // QRMAINSERVICE_H
