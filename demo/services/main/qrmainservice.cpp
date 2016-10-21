#include "qrmainservice.h"

#include <QtCore/qdebug.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qapplication.h>

#include "gui/qrworkspace.h"
#include "gui/qrsystemtray.h"
#include "gui/navigation/qrnavigation.h"

#include "qrmainservicepage.h"

NS_CHAOS_MAIN_SERVICE_BEGIN

class QrMainServicePrivate{
public:
    QrMainServicePage *welcomePage;

public:
    void loadUI();
};

void QrMainServicePrivate::loadUI()
{
    welcomePage = new QrMainServicePage();
}

NS_CHAOS_MAIN_SERVICE_END


USING_NS_CHAOS_BASE;
USING_NS_CHAOS_MAIN_SERVICE;

QrMainService::QrMainService()
    :d_ptr(new QrMainServicePrivate)
{

}

bool QrMainService::init()
{
    bool success = true;

    Q_D(QrMainService);
    d->loadUI();

    //  connect navigation
    QrNavigation::qrconnect("home.about", this, SLOT(onAbout()));
    QrNavigation::qrconnect("home.contact", this, SLOT(onContact()));
    QrNavigation::qrconnect("home.news", this, SLOT(onNews()));

    //  connect system tray
    success &= QrSystemTray::qrconnect("exit", qApp, SLOT(quit()));

    //  pop welcome page in workspace
    success &= QrWorkspace::appendTab(d->welcomePage, "Qters") >= 0;

    return success;
}

void QrMainService::onAbout()
{

}

void QrMainService::onContact()
{

}

void QrMainService::onNews()
{

}
