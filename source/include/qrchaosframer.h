#ifndef QRCHAOSFRAMER_H
#define QRCHAOSFRAMER_H

#include "core/qrframer.h"

#include "qrchaosbase_global.h"

NS_CHAOS_BASE_BEGIN

class CHAOSBASE_SHAREDEXPORT QrChaosFramer
        : public Qters::QrFrame::QrFramer
{
    // QrFramer interface
public:
    virtual bool start() override;
};

NS_CHAOS_BASE_END

#endif // QRCHAOSFRAMER_H
