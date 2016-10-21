#ifndef QRNAVIGATIONMODEL_H
#define QRNAVIGATIONMODEL_H

#include <QtCore/qsortfilterproxymodel.h>

#include "qrchaosbase_global.h"

NS_CHAOS_BASE_BEGIN

class CHAOSBASE_SHAREDEXPORT QrNavigationFilterProxyModel : public QSortFilterProxyModel{
public:
    explicit QrNavigationFilterProxyModel(QObject *parent = 0);

    // QSortFilterProxyModel interface
protected:
    virtual bool filterAcceptsRow(int source_row,
                                  const QModelIndex &source_parent) const override;
};

NS_CHAOS_BASE_END

#endif // QRNAVIGATIONMODEL_H
