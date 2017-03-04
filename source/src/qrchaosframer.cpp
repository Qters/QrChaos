#include "qrchaosframer.h"

#include <QtCore/qdebug.h>

#include "qrutf8.h"
#include "qrsplashscreen.h"

#include "gui/qrstyle.h"

USING_NS_CHAOS_BASE;
USING_NS_QRFRAME;

bool QrChaosFramer::start()
{
    QrSplashStep initSkinStep;
    initSkinStep.message = QObject::tr("初始化皮肤");
    initSkinStep.failMsg = "fail to init skin";
    initSkinStep.function = [](){
        return QrStyle::initSkin();
    };

    addSplashStep(initSkinStep);

    if (! QrFramer::start()) {
        qWarning() << "qrfame framer initialize fail.";
        return false;
    }

    return true;
}
