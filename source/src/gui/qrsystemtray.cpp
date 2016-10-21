#include "gui/qrsystemtray.h"

#include <QtCore/qdebug.h>
#include <QtCore/qmap.h>
#include <QtWidgets/qsystemtrayicon.h>
#include <QtWidgets/qaction.h>
#include <QtWidgets/qmenu.h>

#include "db/qrtblsystemtray.h"
#include "db/qrtblframeconfig.h"

NS_CHAOS_BASE_BEGIN

class QrSystemTrayPrivate{
    QR_DECLARE_PUBLIC(QrSystemTray)
public:
    static QrSystemTrayPrivate *dInstance();

public:
    QrSystemTrayPrivate(QWidget* parent) : parent(parent) {}
    bool initTray();
    QAction *getAction(const QString& key);

public:
    QWidget* parent;
    QMenu trayMenu;
    QSystemTrayIcon systemTray;
    QMap<QString, QAction*> actions;

public:
    static QrSystemTray* qInstance;
};

QrSystemTray* QrSystemTrayPrivate::qInstance = nullptr;

QrSystemTrayPrivate *QrSystemTrayPrivate::dInstance(){
    Q_ASSERT(nullptr != QrSystemTrayPrivate::qInstance);
    return QrSystemTrayPrivate::qInstance->d_func();
}

QAction *QrSystemTrayPrivate::getAction(const QString &key) {
    Q_ASSERT(actions.contains(key));
    return actions[key];
}

bool QrSystemTrayPrivate::initTray() {
    QVector<QrSystemlTrayData> trayDatas;
    if (! QrTbSystemlTrayHelper::getTrayList(&trayDatas)) {
        return false;
    }

    QMap<QString, QString> systemtrayValues;
    if (! Qters::QrFrame::QrTblFrameConfigHelper::getKeyValuesByType("systemtray", &systemtrayValues)) {
        return false;
    }

    if ("false" == systemtrayValues["use"]) {
        qDebug() << "database config deside not use system tray";
        return false;
    }

    systemTray.setIcon(QIcon(systemtrayValues["icon"]));
    systemTray.setToolTip(systemtrayValues["tooltip"]);

    trayMenu.clear();
    Q_FOREACH(QrSystemlTrayData data, trayDatas) {
        auto action = new QAction(data.text, parent);
        action->setIcon(QIcon(data.icon));
        if (! data.visible) {
            action->setVisible(false);
        }

        trayMenu.addAction(action);
        actions[data.key] = action;
        if (data.separator) {
            trayMenu.addSeparator();
        }
    }
    systemTray.setContextMenu(&trayMenu);

    systemTray.show();
    return true;
}

NS_CHAOS_BASE_END


USING_NS_CHAOS_BASE;

QrSystemTray::QrSystemTray(QWidget* parent)
    :d_ptr(new QrSystemTrayPrivate(parent))
{
    QrSystemTrayPrivate::qInstance = this;
    d_ptr->initTray();
}

bool QrSystemTray::qrconnect(const QString &key,
                             const QObject *receiver,
                             const char *member)
{
    auto action = QrSystemTrayPrivate::dInstance()->getAction(key);
    if (nullptr == action) {
        return false;
    }

    QObject::connect (action, SIGNAL(triggered(bool)), receiver, member);
    return true;
}
