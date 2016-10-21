#include "gui/qrstatusbar.h"

#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qboxlayout.h>

#include "gui/framewindow/qrframewindow.h"
#include "gui/header/qrheader.h"
#include "gui/navigation/qrnavigation.h"


NS_CHAOS_BASE_BEGIN

class QrStatusBarPrivate{
    QR_DECLARE_PUBLIC(QrStatusBar)
public:
    QrStatusBarPrivate(QrStatusBar *q);

public:
    void loadUI();
    void connectDisplayMode();
    QrFrameWindow *getFrameWindow();

public:
    QPushButton* normalMode = nullptr;
    QPushButton* simpleMode = nullptr;
    QPushButton* fullScreenMode = nullptr;
};

QrStatusBarPrivate::QrStatusBarPrivate(QrStatusBar *q)
    :q_ptr(q) {
}

QrFrameWindow* QrStatusBarPrivate::getFrameWindow() {
    Q_Q(QrStatusBar);
    QrFrameWindow* framewindow = dynamic_cast<QrFrameWindow*>(q->parent());
    Q_ASSERT(framewindow);
    return framewindow;
}

void QrStatusBarPrivate::loadUI()
{
    Q_Q(QrStatusBar);
    normalMode = new QPushButton(q);
    normalMode->setObjectName("statusbar_normalmode");
    simpleMode = new QPushButton(q);
    simpleMode->setObjectName("statusbar_simplemode");
    fullScreenMode = new QPushButton(q);
    fullScreenMode->setObjectName("statusbar_fullmode");

    auto displayModeLayout = new QHBoxLayout();
    displayModeLayout->setContentsMargins(0,0,0,0);
    displayModeLayout->setSpacing(0);
    displayModeLayout->addWidget(normalMode);
    displayModeLayout->addWidget(simpleMode);
    displayModeLayout->addWidget(fullScreenMode);
    QWidget* displayMode = new QWidget(q);
    displayMode->setLayout(displayModeLayout);

    q->addPermanentWidget(displayMode);
}

void QrStatusBarPrivate::connectDisplayMode()
{
    Q_Q(QrStatusBar);
    QObject::connect(normalMode, &QPushButton::clicked, q, &QrStatusBar::onNormalMode);
    QObject::connect(simpleMode, &QPushButton::clicked, q, &QrStatusBar::onSimpleMode);
    QObject::connect(fullScreenMode, &QPushButton::clicked, q, &QrStatusBar::onFullScreenMode);
}

NS_CHAOS_BASE_END

USING_NS_CHAOS_BASE;

QrStatusBar::QrStatusBar(QWidget* parent)
    : QStatusBar(parent), d_ptr(new QrStatusBarPrivate(this))
{
    setFixedHeight(26);
    d_ptr->loadUI();
    d_ptr->connectDisplayMode();
}

void QrStatusBar::onNormalMode(bool checked /*= false*/)
{
    Q_UNUSED(checked);
    Q_D(QrStatusBar);
    d->getFrameWindow()->getNavigation()->show();
    d->getFrameWindow()->getHeader()->show();
}

void QrStatusBar::onSimpleMode(bool checked /*= false*/)
{
    Q_UNUSED(checked);
    Q_D(QrStatusBar);
    d->getFrameWindow()->getNavigation()->hide();
    d->getFrameWindow()->getHeader()->show();
}

void QrStatusBar::onFullScreenMode(bool checked /*= false*/)
{
    Q_UNUSED(checked);
    Q_D(QrStatusBar);
    d->getFrameWindow()->getNavigation()->hide();
    d->getFrameWindow()->getHeader()->hide();
}

