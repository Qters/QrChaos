#ifndef QRCHAOS_PRODUCT_SERVICE_GLOBAL_H
#define QRCHAOS_PRODUCT_SERVICE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CHAOS_PRODUCTSERVICE_LIBRARY)
#  define CHAOS_PRODUCTSERVICESHARED_EXPORT Q_DECL_EXPORT
#else
#  define CHAOS_PRODUCTSERVICESHARED_EXPORT Q_DECL_IMPORT
#endif

//  qrchaos's service namespace
#define NS_CHAOS_PRODUCT_SERVICE_BEGIN \
    namespace Qters {   \
    namespace QrFrame { \
    namespace QrChaos {   \
    namespace QrProductService {

#define NS_CHAOS_PRODUCT_SERVICE_END \
    } \
    } \
    } \
    }

#define USING_NS_CHAOS_PRODUCT_SERVICE    using namespace Qters::QrFrame::QrChaos::QrProductService

#endif // QRCHAOS_PRODUCT_SERVICE_GLOBAL_H
