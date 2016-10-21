#ifndef QRNAVIGATIONTABVIEW_H
#define QRNAVIGATIONTABVIEW_H

#include <QtWidgets/qtreeview.h>

#include "qrchaosbase_global.h"
#include "qrglobal.h"

NS_CHAOS_BASE_BEGIN

class QrNavigationTabViewPrivate;

class CHAOSBASE_SHAREDEXPORT QrNavigationTabView : public QTreeView
{
    QR_DECLARE_PRIVATE(QrNavigationTabView)
public:
    QrNavigationTabView(QWidget *parent = 0);
};

NS_CHAOS_BASE_END

#endif // QRNAVIGATIONTABVIEW_H
