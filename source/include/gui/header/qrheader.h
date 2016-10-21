#ifndef QRHEADER_H
#define QRHEADER_H

#include <QtWidgets/qframe.h>

#include "qrchaosbase_global.h"
#include "qrglobal.h"

QT_BEGIN_NAMESPACE
class QMouseEvent;
class QAbstractButton;
QT_END_NAMESPACE


NS_CHAOS_BASE_BEGIN

class QrHeaderPrivate;

class CHAOSBASE_SHAREDEXPORT QrHeader : public QFrame
{
    Q_OBJECT
    QR_DECLARE_PRIVATE(QrHeader)
public:
    explicit QrHeader(QWidget *parent = nullptr);

    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *) override;
    virtual void mouseReleaseEvent(QMouseEvent *) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *) override;
    virtual void mouseMoveEvent(QMouseEvent *) override;
};

NS_CHAOS_BASE_END

#endif  //  QRHEADER_H
