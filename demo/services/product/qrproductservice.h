#ifndef QRPRODUCTSERVICE_H
#define QRPRODUCTSERVICE_H

#include "qrglobal.h"
#include "core/qrifservice.h"
#include "qrchaosproductservice_global.h"

NS_CHAOS_PRODUCT_SERVICE_BEGIN

class QrProductServicePrivate;

class CHAOS_PRODUCTSERVICESHARED_EXPORT QrProductService : public QObject, public Qters::QrFrame::QrIfService
{
    Q_OBJECT
    QR_DECLARE_PRIVATE(QrProductService)
    Q_PLUGIN_METADATA(IID "com.qters.qrframe.normal.service.product" FILE "productservice.json")
    Q_INTERFACES(Qters::QrFrame::QrIfService)

public:
    QrProductService();

    // QrIfService interface
public:
    virtual bool init() override;

private slots:
    void onQrCommon();
    void onQrFrame();
    void onQrOrm();
    void onQrTest();
    void onQrLogger();
    void onQrUpdate();
    void onQrCache();
};

NS_CHAOS_PRODUCT_SERVICE_END

#endif // QRPRODUCTSERVICE_H
