#ifndef QRCOMMONFORM_H
#define QRCOMMONFORM_H

#include <QWidget>

#include "gui/qrworkspacewidget.h"

namespace Ui {
class QrProductForm;
}

class QrProductForm : public Qters::QrFrame::QrChaos::QrBase::QrWorkspaceWidget
{
    Q_OBJECT

public:
    explicit QrProductForm(QWidget *parent = 0);
    ~QrProductForm();

public:
    void setTitle(const QString& value);
    void setPresentation(const QString& value);

private:
    Ui::QrProductForm *ui;
};

#endif // QRCOMMONFORM_H
