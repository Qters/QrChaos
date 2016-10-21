#ifndef QRFRAMEWINDOWSPLITTER_H
#define QRFRAMEWINDOWSPLITTER_H

#include <QtWidgets/qsplitter.h>
#include <QtWidgets/qpushbutton.h>

#include "qrchaosbase_global.h"
#include "qrglobal.h"

NS_CHAOS_BASE_BEGIN

class QrFrameWindowSplitterPrivate;

class CHAOSBASE_SHAREDEXPORT QrHandleButton : public QPushButton{
    Q_OBJECT
    Q_PROPERTY(bool opened READ getOpened WRITE setOpened)

public:
    explicit QrHandleButton(QWidget *parent=0);

public:
    void switchOpenProperty();

    bool getOpened() const;
    void setOpened(bool value);

private:
    bool opened;
};

class CHAOSBASE_SHAREDEXPORT QrFrameWindowSplitter : public QSplitter
{
    QR_DECLARE_PRIVATE(QrFrameWindowSplitter)

public:
    explicit QrFrameWindowSplitter(QWidget* parent = nullptr);
    void initHandle(int index);
};

NS_CHAOS_BASE_END

#endif // QRFRAMEWINDOWSPLITTER_H
