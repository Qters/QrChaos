#include "qrproductform.h"
#include "ui_qrproductform.h"

USING_NS_CHAOS_BASE;

QrProductForm::QrProductForm(QWidget *parent) :
    QrWorkspaceWidget(parent),
    ui(new Ui::QrProductForm)
{
    ui->setupUi(this);
}

QrProductForm::~QrProductForm()
{
    delete ui;
}

void QrProductForm::setTitle(const QString &value)
{
    ui->project_title->setText(value);
}

void QrProductForm::setPresentation(const QString &value)
{
    ui->presentation->setText(value);
}
