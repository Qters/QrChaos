#include "gui/navigation/qrnavigationheader.h"

#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtGui/qstandarditemmodel.h>
#include <QtCore/qsortfilterproxymodel.h>

#include "gui/navigation/qrnavigationmodel.h"

NS_CHAOS_BASE_BEGIN

class QrNavigationHeaderPrivate{
    QR_DECLARE_PUBLIC(QrNavigationHeader)
public:
    QrNavigationHeaderPrivate(QrNavigationHeader *q) : q_ptr(q) {}

public:
    void loadUI();

public:
//    QPushButton* autoHide = nullptr;
    QLineEdit* search = nullptr;
    QrNavigationFilterProxyModel *filterProxy;
};

void QrNavigationHeaderPrivate::loadUI()
{
    Q_Q(QrNavigationHeader);
//    autoHide = new QPushButton(q);
//    autoHide->setObjectName("navigationHeader_autohide");
//    autoHide->setCursor(Qt::PointingHandCursor);
//    autoHide->setToolTip("auto hide");

    search = new QLineEdit(q);
    search->setObjectName("navigationHeader_search");
    search->setPlaceholderText("Search Navigation");

    QObject::connect(search, &QLineEdit::textChanged, [this](const QString &value){
        if (nullptr == this->filterProxy
                ||  nullptr == this->filterProxy->sourceModel()) {
            return;
        }
        emit this->q_func()->beginSearch();
        this->filterProxy->setFilterRegExp(value);
    });

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(search);//, 0, Qt::AlignLeft);
//    mainLayout->addWidget(autoHide, 0, Qt::AlignRight);
    q->setLayout(mainLayout);
}

NS_CHAOS_BASE_END


USING_NS_CHAOS_BASE;

QrNavigationHeader::QrNavigationHeader(QWidget* parent)
    : QFrame(parent), d_ptr(new QrNavigationHeaderPrivate(this))
{
    d_ptr->loadUI();
}

void QrNavigationHeader::navigationModelProxy(QrNavigationFilterProxyModel *modelProxy)
{
    Q_D(QrNavigationHeader);
    d->filterProxy = modelProxy;
}

