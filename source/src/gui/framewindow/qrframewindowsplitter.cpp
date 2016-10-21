#include "gui/framewindow/qrframewindowsplitter.h"

#include <QtCore/qdebug.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qstyle.h>


NS_CHAOS_BASE_BEGIN

class QrFrameWindowSplitterPrivate{
    QR_DECLARE_PUBLIC(QrFrameWindowSplitter)

public:
    QrFrameWindowSplitterPrivate(QrFrameWindowSplitter *q);
    void setQssObjectNames();

public:
    QrHandleButton *handleBtn = nullptr;
};

QrFrameWindowSplitterPrivate::QrFrameWindowSplitterPrivate(QrFrameWindowSplitter *q)
    : q_ptr(q) {}

NS_CHAOS_BASE_END


USING_NS_CHAOS_BASE;

QrHandleButton::QrHandleButton(QWidget *parent)
    : QPushButton(parent),
      opened(true)
{
}

void QrHandleButton::switchOpenProperty()
{
    opened = !opened;
    style()->unpolish(this);
    style()->polish(this);
    update();
}

bool QrHandleButton::getOpened() const
{
    return opened;
}

void QrHandleButton::setOpened(bool value)
{
    opened = value;
}

/////////////////////////////////////////////////////////////////
QrFrameWindowSplitter::QrFrameWindowSplitter(QWidget *parent)
    : QSplitter(parent),
      d_ptr(new QrFrameWindowSplitterPrivate(this))
{
    setOrientation(Qt::Horizontal);
}

void QrFrameWindowSplitter::initHandle(int index)
{
    auto handle = this->handle(index);
    Q_ASSERT(nullptr != handle);
    if(nullptr == handle) {
        return;
    }

    Q_D(QrFrameWindowSplitter);
    d->handleBtn = new QrHandleButton(handle);
    d->handleBtn->setObjectName("frameWindowSplitter_handleBtn");
    d->handleBtn->setCursor(Qt::PointingHandCursor);
    connect(d->handleBtn,&QPushButton::clicked, [this, index](){
        Q_D(QrFrameWindowSplitter);
        if(0 == this->sizes().at(0)) {  //  close
            this->setSizes(QList<int>()<<this->widget(index)->width() << this->widget(index)->width());
        } else {    //  open
            this->setSizes(QList<int>()<< 0 << this->widget(index)->width());
        }
        d->handleBtn->switchOpenProperty();
    });

    auto layout = new QVBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    layout->addWidget(d->handleBtn);

    handle->setLayout(layout);
}
