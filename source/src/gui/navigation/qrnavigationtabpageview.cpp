#include "gui/navigation/qrnavigationtabpageview.h"

NS_CHAOS_BASE_BEGIN

class QrNavigationTabViewPrivate{
    QR_DECLARE_PUBLIC(QrNavigationTabView)
public:
    QrNavigationTabViewPrivate(QrNavigationTabView* q);
public:

public:

};

QrNavigationTabViewPrivate::QrNavigationTabViewPrivate(QrNavigationTabView *q)
    : q_ptr(q) {}

NS_CHAOS_BASE_END


USING_NS_CHAOS_BASE;

QrNavigationTabView::QrNavigationTabView(QWidget *parent)
    :QTreeView(parent), d_ptr(new QrNavigationTabViewPrivate(this))
{
    setHeaderHidden(true);
    setRootIsDecorated(false);
    connect(this, &QrNavigationTabView::clicked, [this](const QModelIndex &index){
        this->isExpanded(index)? this->collapse(index) : this->expand(index);
    });
}

