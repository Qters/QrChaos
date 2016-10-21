#ifndef QRCHAOS_MAIN_SERVICE_GLOBAL_H
#define QRCHAOS_MAIN_SERVICE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CHAOS_MAINSERVICE_LIBRARY)
#  define CHAOS_MAINSERVICESHARED_EXPORT Q_DECL_EXPORT
#else
#  define CHAOS_MAINSERVICESHARED_EXPORT Q_DECL_IMPORT
#endif

//  qrchaos's main service namespace
#define NS_CHAOS_MAIN_SERVICE_BEGIN \
    namespace Qters {   \
    namespace QrFrame { \
    namespace QrChaos {   \
    namespace QrMainService {

#define NS_CHAOS_MAIN_SERVICE_END \
    } \
    } \
    } \
    }

#define USING_NS_CHAOS_MAIN_SERVICE    using namespace Qters::QrFrame::QrChaos::QrMainService

#endif // QRCHAOS_MAIN_SERVICE_GLOBAL_H
