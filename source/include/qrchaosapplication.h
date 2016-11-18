#ifndef QRCHAOSAPPLICATION_H
#define QRCHAOSAPPLICATION_H

#include <QtCore/qcoreapplication.h>
#include <QtWidgets/qapplication.h>

#include "qrglobal.h"
#include "qrframe_global.h"

#include "qrchaosbase_global.h"

#if defined(QrChaosApp)
#undef QrChaosApp
#endif
#define QrChaosApp (static_cast<QrChaosApplication *>(QCoreApplication::instance()))

NS_QRFRAME_BEGIN
class QrFramerConfig;
NS_QRFRAME_END

NS_CHAOS_BASE_BEGIN

class QrChaosApplicationPrivate;
class CHAOSBASE_SHAREDEXPORT QrChaosApplication : public QApplication
{
    Q_OBJECT

    QR_DECLARE_PRIVATE(QrChaosApplication)

public:
    QrChaosApplication(int &argc, char **argv);
    virtual ~QrChaosApplication();

Q_SIGNALS:
    void sig_workspaceChange();

public:
    virtual bool init(const QrFramerConfig& config);
};

NS_CHAOS_BASE_END

#endif // QRCHAOSAPPLICATION_H