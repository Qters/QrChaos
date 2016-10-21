#include "gui/navigation/qrnavigationmodel.h"

USING_NS_CHAOS_BASE;

QrNavigationFilterProxyModel::QrNavigationFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel (parent) {}

bool QrNavigationFilterProxyModel::filterAcceptsRow(
        int source_row,
        const QModelIndex &source_parent) const
{
    if (filterRegExp().isEmpty()) {
        return true;
    }

    auto index = sourceModel()->index(source_row, 0, source_parent);
    if (sourceModel()->rowCount(index) > 0
            && sourceModel()->columnCount(index) > 0) {
        return true;    //  not a leaf node
    }

    return sourceModel()->data(index).toString().contains(filterRegExp());
}
