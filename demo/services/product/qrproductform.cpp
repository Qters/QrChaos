#include "qrproductform.h"
#include "ui_qrproductform.h"

QrProductForm::QrProductForm(QWidget *parent) :
    QWidget(parent),
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
