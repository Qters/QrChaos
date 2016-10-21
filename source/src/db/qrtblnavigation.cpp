#include "db/qrtblnavigation.h"

#include "db/qrframedb.h"
#include "generator/qrselectsql.h"
#include "qrsqlhelper.h"
#include "qrdbresultsguard.h"

NS_CHAOS_BASE_BEGIN

class QrTblNavigationHelperPrivate{
public:
    bool findRoot(QList<QrTblNavigation*> *dbData, QrNavigationDbData *root);
    void makeNavigationData(QrNavigationDbData* root,
                            QList<QrTblNavigation*> *dbData,
                            QMap<int, QrNavigationDbData*> dataMap);
    void convert(QrTblNavigation *from, QrNavigationDbData *to);

public:
    static const int root = 0;
};

bool QrTblNavigationHelperPrivate::findRoot(QList<QrTblNavigation*> *dbData, QrNavigationDbData *root)
{
    for(int idx=0; idx<dbData->size(); ++idx) {
        auto data = dbData->at(idx);
        if (QrTblNavigationHelperPrivate::root == data->getParentid()) {    //  root
            convert(data, root);
            dbData->removeAt(idx);
            return true;
        }
    }

    return false;
}

void QrTblNavigationHelperPrivate::makeNavigationData(QrNavigationDbData* root,
                                                      QList<QrTblNavigation*> *dbData,
                                                      QMap<int, QrNavigationDbData*> dataMap)
{
    for (int idx=0; idx<dbData->size(); ++idx) {
        auto data = dbData->at(idx);
        auto navData = new QrNavigationDbData();
        convert(data, navData);

        auto parentIter = dataMap.find(data->getParentid());
        if (parentIter != dataMap.end()) {    //  had parent
            parentIter.value()->children.push_back(navData);
        } else {
            root->children.push_back(navData);
        }
        dataMap[navData->id] = navData;
    }
}

void QrTblNavigationHelperPrivate::convert(QrTblNavigation *from, QrNavigationDbData *to)
{
    to->id = from->getId();
    to->parentid = from->getParentid();
    to->key = from->getKey();
    to->display = from->getDisplay();
    to->icon = from->getIcon();
}

NS_CHAOS_BASE_END


USING_NS_QRFRAME;
USING_NS_CHAOS_BASE;

int QrTblNavigation::getId() const
{
    return id;
}

void QrTblNavigation::setId(int value)
{
    id = value;
}

int QrTblNavigation::getParentid() const
{
    return parentid;
}

void QrTblNavigation::setParentid(int value)
{
    parentid = value;
}

QString QrTblNavigation::getKey() const
{
    return key;
}

void QrTblNavigation::setKey(const QString &value)
{
    key = value;
}

QString QrTblNavigation::getDisplay() const
{
    return display;
}

void QrTblNavigation::setDisplay(const QString &value)
{
    display = value;
}

QString QrTblNavigation::getIcon() const
{
    return icon;
}

void QrTblNavigation::setIcon(const QString &value)
{
    icon = value;
}

QString QrTblNavigation::tableName() const {
    return "navigation";
}

QrNavigationDbData* QrTblNavigationHelper::getData()
{
    auto root = new QrNavigationDbData();

    QrTblNavigation tblNavigation;
    QrSelectSql selectSql;
    auto query = selectSql.setTable(&tblNavigation)
            .columns("*").orderAsc("parentid").getSqlQuery();

    auto database = QrFrameDb::getInstance()->getDatabase();
    auto error = QrSqlHelper::call_query(query, &database);
    if (error.isValid()) {
        qWarning() << "could't get frame's navigation data, " << error.text();
        return root;
    }

    QrDbResultsGuard<QrTblNavigation> dbObjs;
    auto dbData = dbObjs.fetchResultsBySqlQuery(query);

    Q_D(QrTblNavigationHelper);
    if (! d->findRoot(&dbData, root)) {
        return root;
    }

    QMap<int, QrNavigationDbData*> dataMap;
    dataMap[root->id] = root;

    d->makeNavigationData(root, &dbData, dataMap);
    return root;
}
