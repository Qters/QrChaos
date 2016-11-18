#include "gui/qrworkspace.h"

#include <QtCore/qmap.h>
#include <QtCore/qdebug.h>
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qscrollarea.h>
#include <QtWidgets/qtabbar.h>

#include "gui/qrworkspacewidget.h"

NS_CHAOS_BASE_BEGIN

class QrWorkspacePrivate{
    QR_DECLARE_PUBLIC(QrWorkspace)

public:
    static QrWorkspace* qInstance;

    int lastIndex = -1;
    QMap<QrWorkspaceWidget*, QScrollArea*> existedTabWidgets;

public:
    QrWorkspacePrivate(QrWorkspace *q);

public:
    static QrWorkspacePrivate* dInstance();
    QrWorkspaceWidget* getWorkspaceWidget(int index);
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

QrWorkspaceWidget *QrWorkspacePrivate::getWorkspaceWidget(int index)
{
    Q_Q(QrWorkspace);
    return qobject_cast<QrWorkspaceWidget*>(
                qobject_cast<QScrollArea*>(q->widget(index))->widget());
}

NS_CHAOS_BASE_END


USING_NS_CHAOS_BASE;

QrWorkspace::QrWorkspace(QWidget *parent)
    :QTabWidget(parent), d_ptr(new QrWorkspacePrivate(this))
{
    tabBar()->setObjectName("workspace_tabbar");
    setTabsClosable(true);

    connect(this, &QrWorkspace::tabCloseRequested, [this](int index){
        Q_D(QrWorkspace);
        QrWorkspaceWidget *workspaceWidget = d->getWorkspaceWidget(index);
        if(! workspaceWidget->closeRequested()) {
            qDebug() << "workspace widget reject to close.";
            return;
        }
        d->existedTabWidgets.remove(workspaceWidget);
        removeTab(index);
    });
    connect(this, &QrWorkspace::currentChanged, [this](int index){
        Q_D(QrWorkspace);
        QrWorkspaceWidget *workspaceWidget = d->getWorkspaceWidget(index);
        workspaceWidget->switchFrom(d->lastIndex);
        d->lastIndex = index;
    });
}

int QrWorkspace::appendTab(QrWorkspaceWidget *widget, QString label, bool autoExpanding /*= true*/)
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

        d->lastIndex = preIndex;

        return preIndex;
    }

    if(autoExpanding) {
        widget->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
    }

    auto wrapWidget = new QScrollArea();
    wrapWidget->setWidget (widget);
    wrapWidget->setWidgetResizable(true);
    d->existedTabWidgets[widget] = wrapWidget;

    auto tabIndex = q->addTab(wrapWidget, label);
    q->setCurrentIndex(tabIndex);

    d->lastIndex = tabIndex;

    return tabIndex;
}

