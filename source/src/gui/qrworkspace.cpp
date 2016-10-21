#include "gui/qrworkspace.h"

#include <QtCore/qmap.h>
#include <QtCore/qdebug.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qscrollarea.h>
#include <QtWidgets/qtabbar.h>

NS_CHAOS_BASE_BEGIN

class QrWorkspacePrivate{
    QR_DECLARE_PUBLIC(QrWorkspace)
public:
    QrWorkspacePrivate(QrWorkspace *q);

public:
    static QrWorkspacePrivate* dInstance();

public:
    QMap<QWidget*, QScrollArea*> existedTabWidgets;

public:
    static QrWorkspace* qInstance;
};

QrWorkspace* QrWorkspacePrivate::qInstance = nullptr;

QrWorkspacePrivate::QrWorkspacePrivate(QrWorkspace *q)
    : q_ptr(q) {
    qInstance = q;
}

QrWorkspacePrivate *QrWorkspacePrivate::dInstance(){
    Q_ASSERT(nullptr != QrWorkspacePrivate::qInstance);
    return QrWorkspacePrivate::qInstance->d_func();
}

NS_CHAOS_BASE_END


USING_NS_CHAOS_BASE;

QrWorkspace::QrWorkspace(QWidget *parent)
    :QTabWidget(parent), d_ptr(new QrWorkspacePrivate(this))
{
    tabBar()->setObjectName("workspace_tabbar");
    setTabsClosable(true);

    connect(this, &QrWorkspace::tabCloseRequested, [this](int index){
        this->d_func()->existedTabWidgets.remove(
                    qobject_cast<QScrollArea*>(this->widget(index))->widget());
        this->removeTab(index);
    });
}

int QrWorkspace::appendTab(QWidget *widget, QString label)
{
    if (nullptr == widget) {
        qWarning() << "widget append to tag is null.";
        return -1;
    }

    auto q = QrWorkspacePrivate::qInstance;
    Q_ASSERT(nullptr != q);
    auto d = QrWorkspacePrivate::dInstance();
    if (d->existedTabWidgets.contains(widget)) {
        qInfo() << label << " widget is exist. show previous widget.";
        auto preIndex = q->indexOf(d->existedTabWidgets[widget]);
        q->setTabText(preIndex, label);
        q->setCurrentIndex(preIndex);
        return preIndex;
    }

    auto wrapWidget = new QScrollArea();
    wrapWidget->setWidget (widget);
    wrapWidget->setWidgetResizable (true);
    d->existedTabWidgets[widget] = wrapWidget;

    auto tabIndex = q->addTab(wrapWidget, label);
    q->setCurrentIndex(tabIndex);

    return tabIndex;
}

