#ifndef QRWORKSPACE_H
#define QRWORKSPACE_H

#include <QtWidgets/qtabwidget.h>

#include "qrglobal.h"
#include "qrchaosbase_global.h"

QT_BEGIN_NAMESPACE
class QWidget;
QT_END_NAMESPACE


NS_CHAOS_BASE_BEGIN

class QrWorkspaceWidget;
class QrWorkspacePrivate;

class CHAOSBASE_SHAREDEXPORT QrWorkspace : public QTabWidget
{
    Q_OBJECT
    QR_DECLARE_PRIVATE(QrWorkspace)

public:
    explicit QrWorkspace(QWidget *parent = nullptr);

public:
    static int appendTab(QrWorkspaceWidget *widget, QString label, bool autoExpanding = true);
};

NS_CHAOS_BASE_END

#endif // QRWORKSPACE_H
