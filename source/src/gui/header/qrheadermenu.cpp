#include "gui/header/qrheadermenu.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qtoolbar.h>


NS_CHAOS_BASE_BEGIN

class QrHeaderMenuPrivate {
    QR_DECLARE_PUBLIC(QrHeaderMenu)
public:
    QrHeaderMenuPrivate(QrHeaderMenu *q) : q_ptr(q) {}
    void initUI();

public:
    QToolBar *collection = nullptr;
};

void QrHeaderMenuPrivate::initUI()
{
    Q_Q(QrHeaderMenu);
    QHBoxLayout *hBox = new QHBoxLayout();
    hBox->setAlignment(Qt::AlignRight);
    hBox->setContentsMargins(0, 0, 0, 0);
    hBox->setSpacing(0);

    collection = new QToolBar(q);
    collection->setOrientation(Qt::Horizontal);
    collection->setFloatable(false);
    collection->setMovable(false);
    collection->setToolTipDuration(0);
    hBox->addWidget(collection);

    q->setLayout(hBox);
}


NS_CHAOS_BASE_END


USING_NS_CHAOS_BASE;

QrHeaderMenu::QrHeaderMenu(QWidget* parent)
    : QWidget(parent), d_ptr(new QrHeaderMenuPrivate(this))
{
    d_ptr->initUI();
}
