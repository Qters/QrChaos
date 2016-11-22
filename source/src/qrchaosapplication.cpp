#include "qrchaosapplication.h"

#include <QtCore/qdebug.h>

#include "core/qrframer.h"
#include "qrchaosframer.h"
#include "gui/qrchaosmainwindow.h"
#include "qrchaosapplication.h"

USING_NS_QRFRAME;
USING_NS_QRCOMMON;

NS_CHAOS_BASE_BEGIN

class QrChaosApplicationPrivate{
    QR_DECLARE_PUBLIC(QrChaosApplication)

public:
    QrChaosMainwindow mwindow;
    QrChaosFramer framer;

public:
    QrChaosApplicationPrivate(QrChaosApplication *q) : q_ptr(q) {}
};

NS_CHAOS_BASE_END

USING_NS_CHAOS_BASE;

QrChaosApplication::QrChaosApplication(int &argc, char **argv)
    : QApplication(argc, argv),
      d_ptr(new QrChaosApplicationPrivate(this))
{
}

QrChaosApplication::~QrChaosApplication()
{

}

QrChaosMainwindow *QrChaosApplication::getMainWindow()
{
    Q_D(QrChaosApplication);
    return &d->mwindow;
}

bool QrChaosApplication::init(const QrFramerConfig& config)
{
    Q_D(QrChaosApplication);
    d->framer.setMainWindow(&d->mwindow);
    d->framer.setConfig(config);

    if(! d->framer.start()) {
        qDebug() << "framer start fail, progress is about to quit.";
        return false;
    }

    return true;
}
