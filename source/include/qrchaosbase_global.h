#ifndef QRCHAOS_BASE_GLOBAL_H
#define QRCHAOS_BASE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CHAOS_BASE_LIBRARY)
#  define CHAOSBASE_SHAREDEXPORT Q_DECL_EXPORT
#else
#  define CHAOSBASE_SHAREDEXPORT Q_DECL_IMPORT
#endif

//  qrchaos's namespace
#define NS_CHAOS_BASE_BEGIN \
    namespace Qters { \
    namespace QrFrame { \
    namespace QrChaos { \
    namespace QrBase {

#define NS_CHAOS_BASE_END \
    } \
    } \
    } \
    }

#define USING_NS_CHAOS_BASE    using namespace Qters::QrFrame::QrChaos::QrBase

#endif // QRCHAOS_BASE_GLOBAL_H
