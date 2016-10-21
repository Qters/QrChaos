#include "db/qrtblsystemtray.h"

#include "db/qrframedb.h"
#include "qrsqlhelper.h"
#include "qrdbresultsguard.h"
#include "generator/qrselectsql.h"

USING_NS_QRFRAME;
USING_NS_QRORM;
USING_NS_CHAOS_BASE;

QrTblSystemlTray::QrTblSystemlTray()
{

}

QString QrTblSystemlTray::tableName() const
{
    return "system_tray";
}

int QrTblSystemlTray::getId() const
{
    return id;
}

void QrTblSystemlTray::setId(int value)
{
    id = value;
}

QString QrTblSystemlTray::getIcon() const
{
    return icon;
}

void QrTblSystemlTray::setIcon(const QString &value)
{
    icon = value;
}

QString QrTblSystemlTray::getText() const
{
    return text;
}

void QrTblSystemlTray::setText(const QString &value)
{
    text = value;
}

bool QrTblSystemlTray::getSeparator() const
{
    return separator;
}

void QrTblSystemlTray::setSeparator(bool value)
{
    separator = value;
}

bool QrTblSystemlTray::getVisible() const
{
    return isvisible;
}

void QrTblSystemlTray::setVisible(bool value)
{
    isvisible = value;
}

int QrTblSystemlTray::getSort() const
{
    return sort;
}

void QrTblSystemlTray::setSort(int value)
{
    sort = value;
}

QString QrTblSystemlTray::getKey() const
{
    return key;
}

void QrTblSystemlTray::setKey(const QString &value)
{
    key = value;
}

/////////////////////////////////////////////////////////////////////////
bool QrTbSystemlTrayHelper::getTrayList(QVector<QrSystemlTrayData> *datas)
{
    Q_ASSERT(nullptr != datas);

    QrTblSystemlTray tblSysTray;
    QrSelectSql selectSql;
    auto query = selectSql.setTable(&tblSysTray)
            .columns("separator", "isvisible", "icon", "text", "key")
            .orderAsc("sort").getSqlQuery();

    auto database = QrFrameDb::getInstance()->getDatabase();
    auto error = QrSqlHelper::call_query(query, &database);
    if (error.isValid()) {
        qInfo() << "could't get system tray datas";
        return false;
    }

    QrDbResultsGuard<QrTblSystemlTray> dbObjs;
    Q_FOREACH(auto result, dbObjs.fetchResultsBySqlQuery(query)) {
        datas->push_back(QrSystemlTrayData{
                             result->getSeparator(),    //  separator
                             result->getVisible(),      //  isvisible
                             result->getIcon(),         //  icon
                             result->getText(),         //  text
                             result->getKey(),          //  key
                         });
    }

    return true;
}
