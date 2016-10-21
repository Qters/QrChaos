#include "qrchaosframer.h"

#include <QtCore/qdebug.h>

#include "gui/qrstyle.h"

USING_NS_CHAOS_BASE;
USING_NS_QRFRAME;

bool QrChaosFramer::start()
{
    if (! QrFramer::start()) {
        qWarning() << "qrfame framer initialize fail.";
        return false;
    }

    QrStyle::initSkin();

    return true;
}
