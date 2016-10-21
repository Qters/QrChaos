#ifndef QRNAVIGATIONTAB_H
#define QRNAVIGATIONTAB_H

#include <QtWidgets/qwidget.h>
#include <QtCore/qmap.h>

#include "qrchaosbase_global.h"
#include "db/qrtblnavigation.h"
#include "qrglobal.h"

BENIGN_RACE_BEGIN
class QPushButton;
BENIGN_RACE_END

NS_CHAOS_BASE_BEGIN

class QrNavigationFilterProxyModel;
class QrNavigationTabPagePrivate;

class CHAOSBASE_SHAREDEXPORT QrNavigationTabPage : public QWidget
{
    Q_OBJECT
    QR_DECLARE_PRIVATE(QrNavigationTabPage)

signals:
    void addButton(QString path, QPushButton* itemButton);
    void removeButton(QString path, QPushButton* itemButton);

public:
    QrNavigationTabPage(QWidget* parent = 0);

public Q_SLOTS:
    void expandAll();

public:
    void initModelByDbData(QrNavigationDbData* dbData);
    QrNavigationFilterProxyModel *modelProxy();
};

NS_CHAOS_BASE_END

#endif  //  QRNAVIGATIONTAB_H
