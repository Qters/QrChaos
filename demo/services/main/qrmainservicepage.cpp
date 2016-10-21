#include "qrmainservicepage.h"
#include "ui_qrmainservicepage.h"

Ui::QrMainServicePage *test = new Ui::QrMainServicePage();

USING_NS_CHAOS_MAIN_SERVICE;

QrMainServicePage::QrMainServicePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QrMainServicePage)
{
    ui->setupUi(this);
}

QrMainServicePage::~QrMainServicePage()
{
    delete ui;
}
