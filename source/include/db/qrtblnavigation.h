#ifndef QRTBLNAVIGATION_H
#define QRTBLNAVIGATION_H

#include <QtCore/qstring.h>
#include <QtCore/qvector.h>

#include "entity/qrsqltable.h"

#include "qrchaosbase_global.h"
#include "qrglobal.h"

NS_CHAOS_BASE_BEGIN

class CHAOSBASE_SHAREDEXPORT QrTblNavigation : public Qters::QrOrm::QrSqlTable
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId)
    Q_PROPERTY(int parentid READ getParentid WRITE setParentid)
    Q_PROPERTY(QString key READ getKey WRITE setKey)
    Q_PROPERTY(QString display READ getDisplay WRITE setDisplay)
    Q_PROPERTY(QString icon READ getIcon WRITE setIcon)

public:
    int getId() const;
    void setId(int value);

    int getParentid() const;
    void setParentid(int value);

    QString getKey() const;
    void setKey(const QString &value);

    QString getDisplay() const;
    void setDisplay(const QString &value);

    QString getIcon() const;
    void setIcon(const QString &value);

    // QrSqlTable interface
public:
    virtual QString tableName() const override;

private:
    int id;
    int parentid;
    QString key;
    QString display;
    QString icon;
};

struct QrNavigationDbData {
    int id;
    int parentid;
    QString key;
    QString display;
    QString icon;
    QVector<QrNavigationDbData*> children;
};

class QrTblNavigationHelperPrivate;

class CHAOSBASE_SHAREDEXPORT QrTblNavigationHelper{
    QR_DECLARE_PRIVATE(QrTblNavigationHelper)
public:
    //
    /*!
     * \brief get navigtaion data from database
     *          all data are create by new, caller is responsible for delete data!!!
     * \return  root data, get all data by iterate root's children
     */
    QrNavigationDbData* getData();
};

NS_CHAOS_BASE_END

#endif // QRTBLNAVIGATION_H
