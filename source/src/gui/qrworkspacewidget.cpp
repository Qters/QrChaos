#include "gui/qrworkspacewidget.h"

USING_NS_CHAOS_BASE;

QrWorkspaceWidget::QrWorkspaceWidget(QWidget *parent)
    : QWidget(parent)
{

}

QrWorkspaceWidget::~QrWorkspaceWidget()
{

}

void QrWorkspaceWidget::switchFrom(int from)
{
    Q_UNUSED(from);
}

bool QrWorkspaceWidget::closeRequested()
{
    return true;
}
