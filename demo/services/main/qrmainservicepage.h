#ifndef QRMAINSERVICEPAGE_H
#define QRMAINSERVICEPAGE_H

#include <QWidget>

#include "qrchaosmainservice_global.h"

namespace Ui {
class QrMainServicePage;
}

NS_CHAOS_MAIN_SERVICE_BEGIN
class QrMainServicePage : public QWidget
{
    Q_OBJECT
public:
    explicit QrMainServicePage(QWidget *parent = 0);
    ~QrMainServicePage();

private:
    Ui::QrMainServicePage *ui;
};

NS_CHAOS_MAIN_SERVICE_END

#endif // QRMAINSERVICEPAGE_H
