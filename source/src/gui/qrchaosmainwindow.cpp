﻿#include "gui/qrchaosmainwindow.h"

#include <QtCore/qdebug.h>
#include <QtWidgets/qaction.h>
#include <QtWidgets/qdesktopwidget.h>
#include <QtWidgets/qapplication.h>

#include "gui/framewindow/qrframewindow.h"
#include "gui/qrworkspace.h"
#include "gui/qrstatusbar.h"

NS_CHAOS_BASE_BEGIN

class QrChaosMainwindowPrivate {
    QR_DECLARE_PUBLIC(QrChaosMainwindow)

public:
    QrChaosMainwindowPrivate(QrChaosMainwindow* q):q_ptr(q){}

public:
    void loadUIFramework();
    void initShortcuts();
    void initSize();

public:
    QrFrameWindow *frameWindow = nullptr;
};

void QrChaosMainwindowPrivate::loadUIFramework() {
    Q_Q(QrChaosMainwindow);
    frameWindow = new QrFrameWindow(q);
    q->setCentralWidget(frameWindow);
}

void QrChaosMainwindowPrivate::initShortcuts() {
    Q_Q(QrChaosMainwindow);
    auto quickCloseWorkspace = new QAction(q);
    quickCloseWorkspace->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_W));
    q->addAction(quickCloseWorkspace);
    q->connect(quickCloseWorkspace, &QAction::triggered, [this](){
        auto workspace = this->frameWindow->getWorkspace();
        workspace->removeTab(workspace->currentIndex());
    });

    auto quickSwitchWorkspace = new QAction(q);
    quickSwitchWorkspace->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Tab));
    q->addAction(quickSwitchWorkspace);
    q->connect(quickSwitchWorkspace, &QAction::triggered, [this](){
        auto workspace = this->frameWindow->getWorkspace();
        workspace->setCurrentIndex((workspace->currentIndex()+1) % workspace->count());
    });

    //  TODO
    auto switchNormalMode = new QAction(q);
    switchNormalMode->setShortcut(QKeySequence(Qt::ALT + Qt::Key_1));
    q->addAction(switchNormalMode);
    q->connect(switchNormalMode, &QAction::triggered,
                     this->frameWindow->getStatusbar(), &QrStatusBar::onNormalMode);

    auto switchSimpleMode = new QAction(q);
    switchSimpleMode->setShortcut(QKeySequence(Qt::ALT + Qt::Key_2));
    q->addAction(switchSimpleMode);
    q->connect(switchSimpleMode, &QAction::triggered,
                     this->frameWindow->getStatusbar(), &QrStatusBar::onSimpleMode);

    auto switchFullMode = new QAction(q);
    switchFullMode->setShortcut(QKeySequence(Qt::ALT + Qt::Key_3));
    q->addAction(switchFullMode);
    q->connect(switchFullMode, &QAction::triggered,
                     this->frameWindow->getStatusbar(), &QrStatusBar::onFullScreenMode);
}

void QrChaosMainwindowPrivate::initSize() {
    Q_Q(QrChaosMainwindow);
    const QRect& screenRect = QApplication::desktop()->availableGeometry();
    QSize scrSize(screenRect.width()*0.6,screenRect.height()*0.6);
    q->resize(scrSize);
}

NS_CHAOS_BASE_END


USING_NS_CHAOS_BASE;

QrChaosMainwindow::QrChaosMainwindow(QWidget* parent)
    : QrMainWindow(parent), d_ptr(new QrChaosMainwindowPrivate(this))
{
    setWindowFlags(Qt::FramelessWindowHint);
}

QrFrameWindow *QrChaosMainwindow::getFrameWindow()
{
    Q_D(QrChaosMainwindow);
    return d->frameWindow;
}

bool QrChaosMainwindow::init()
{
    Q_D(QrChaosMainwindow);
    d->loadUIFramework();
    d->initShortcuts();
    d->initSize();

    return true;
}

