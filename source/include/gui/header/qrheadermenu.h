#ifndef QRHEADERMENU_H
#define QRHEADERMENU_H

#include <QtWidgets/qwidget.h>

#include "qrglobal.h"
#include "qrchaosbase_global.h"

NS_CHAOS_BASE_BEGIN


class QrHeaderMenuPrivate;

class QrHeaderMenu : public QWidget
{
    QR_DECLARE_PRIVATE(QrHeaderMenu)
public:
    QrHeaderMenu(QWidget* parent = 0);
};


NS_CHAOS_BASE_END

#endif // QRHEADERMENU_H
