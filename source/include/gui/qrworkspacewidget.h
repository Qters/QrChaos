#ifndef QRWORKSPACEWIDGET_H
#define QRWORKSPACEWIDGET_H

#include <QtWidgets/qwidget.h>

#include "qrchaosbase_global.h"


NS_CHAOS_BASE_BEGIN

class CHAOSBASE_SHAREDEXPORT QrWorkspaceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QrWorkspaceWidget(QWidget* parent = Q_NULLPTR);
    virtual ~QrWorkspaceWidget();

public:
    virtual void switchFrom(int from);
    virtual bool closeRequested();
};

NS_CHAOS_BASE_END

#endif // QRWORKSPACEWIDGET_H
