#ifndef QRNAVIGATIONHEADER_H
#define QRNAVIGATIONHEADER_H

#include <QtWidgets/qframe.h>

#include "qrchaosbase_global.h"
#include "qrglobal.h"


NS_CHAOS_BASE_BEGIN

class QrNavigationFilterProxyModel;
class QrNavigationHeaderPrivate;

class CHAOSBASE_SHAREDEXPORT QrNavigationHeader : public QFrame
{
    Q_OBJECT
    QR_DECLARE_PRIVATE(QrNavigationHeader)
public:
    QrNavigationHeader(QWidget* parent = 0);

Q_SIGNALS:
    void beginSearch();

public Q_SLOTS:
    void navigationModelProxy(QrNavigationFilterProxyModel *modelProxy);
};

NS_CHAOS_BASE_END

#endif // QRNAVIGATIONHEADER_H
