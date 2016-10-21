#include "qrproductservice.h"

#include <QtCore/qdebug.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qapplication.h>

#include "gui/qrworkspace.h"
#include "gui/qrsystemtray.h"
#include "gui/navigation/qrnavigation.h"

#include "qrproductform.h"

NS_CHAOS_PRODUCT_SERVICE_BEGIN

class QrProductServicePrivate{
public:
    QrProductForm *projectForm;

public:
    void loadUI(){
        projectForm = new QrProductForm();
    }
};

NS_CHAOS_PRODUCT_SERVICE_END

USING_NS_CHAOS_BASE;
USING_NS_CHAOS_PRODUCT_SERVICE;

QrProductService::QrProductService()
    :d_ptr(new QrProductServicePrivate)
{

}

bool QrProductService::init()
{
    QrNavigation::qrconnect("product.qrcommon", this, SLOT(onQrCommon()));
    QrNavigation::qrconnect("product.qrframe", this, SLOT(onQrFrame()));
    QrNavigation::qrconnect("product.qrorm", this, SLOT(onQrOrm()));
    QrNavigation::qrconnect("product.qrtest", this, SLOT(onQrTest()));
    QrNavigation::qrconnect("product.qrlogger", this, SLOT(onQrLogger()));
    QrNavigation::qrconnect("product.qrupdate", this, SLOT(onQrUpdate()));
    QrNavigation::qrconnect("product.qrcache", this, SLOT(onQrCache()));

    Q_D(QrProductService);
    d->loadUI();

    return true;
}

void QrProductService::onQrCommon()
{
    Q_D(QrProductService);
    d->projectForm->setTitle("QrCommon");
    d->projectForm->setPresentation("common functions for Qters");
    QrWorkspace::appendTab(d->projectForm, "QrCommon");
}

void QrProductService::onQrFrame()
{
    Q_D(QrProductService);
    d->projectForm->setTitle("QrFrame");
    d->projectForm->setPresentation("cilent develop frame for Qt-based C++ apps ");
    QrWorkspace::appendTab(d->projectForm, "QrFrame");
}

void QrProductService::onQrOrm()
{
    Q_D(QrProductService);
    d->projectForm->setTitle("QrOrm");
    d->projectForm->setPresentation("orm frame for Qt-based C++ apps");
    QrWorkspace::appendTab(d->projectForm, "QrOrm");
}

void QrProductService::onQrTest()
{
    Q_D(QrProductService);
    d->projectForm->setTitle("QrTest");
    d->projectForm->setPresentation("test frame for Qt-based C++ apps");
    QrWorkspace::appendTab(d->projectForm, "QrTest");
}

void QrProductService::onQrLogger()
{
    Q_D(QrProductService);
    d->projectForm->setTitle("QrLogger");
    d->projectForm->setPresentation("Logger: simple, convinient and thread safe logger for Qt-based C++ apps");
    QrWorkspace::appendTab(d->projectForm, "QrLogger");
}

void QrProductService::onQrUpdate()
{
    Q_D(QrProductService);
    d->projectForm->setTitle("QrUpdate");
    d->projectForm->setPresentation("Update/Remote repository system based on Qt5");
    QrWorkspace::appendTab(d->projectForm, "QrUpdate");
}

void QrProductService::onQrCache()
{
    Q_D(QrProductService);
    d->projectForm->setTitle("QrCache");
    d->projectForm->setPresentation("cache frame for Qt-based C++ apps");
    QrWorkspace::appendTab(d->projectForm, "QrCache");
}
