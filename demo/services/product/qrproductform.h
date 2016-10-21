#ifndef QRCOMMONFORM_H
#define QRCOMMONFORM_H

#include <QWidget>

namespace Ui {
class QrProductForm;
}

class QrProductForm : public QWidget
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
