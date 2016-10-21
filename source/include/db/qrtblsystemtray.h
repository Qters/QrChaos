#ifndef QRTBLTRAY_H
#define QRTBLTRAY_H


#include "entity/qrsqltable.h"

#include "qrchaosbase_global.h"
#include "qrglobal.h"

NS_CHAOS_BASE_BEGIN

class CHAOSBASE_SHAREDEXPORT QrTblSystemlTray : public Qters::QrOrm::QrSqlTable
{
    Q_OBJECT
    Q_PROPERTY(int id READ getId WRITE setId)
    Q_PROPERTY(bool separator READ getSeparator WRITE setSeparator)
    Q_PROPERTY(bool isvisible READ getVisible WRITE setVisible)
    Q_PROPERTY(int sort READ getSort WRITE setSort)
    Q_PROPERTY(QString icon READ getIcon WRITE setIcon)
    Q_PROPERTY(QString text READ getText WRITE setText)
    Q_PROPERTY(QString key READ getKey WRITE setKey)
public:
    QrTblSystemlTray();

    // QrSqlTable interface
public:
    virtual QString tableName() const override;

    int getId() const;
    void setId(int value);

    QString getIcon() const;
    void setIcon(const QString &value);

    QString getText() const;
    void setText(const QString &value);

    bool getSeparator() const;
    void setSeparator(bool value);

    bool getVisible() const;
    void setVisible(bool value);

    int getSort() const;
    void setSort(int value);

    QString getKey() const;
    void setKey(const QString &value);

private:
    int id;
    bool separator;
    bool isvisible;
    int sort;
    QString icon;
    QString text;
    QString key;
};

struct QrSystemlTrayData{
    bool separator;
    bool visible;
    QString icon;
    QString text;
    QString key;
};

class CHAOSBASE_SHAREDEXPORT QrTbSystemlTrayHelper{
public:
    static bool getTrayList(QVector<QrSystemlTrayData> *datas);
};

NS_CHAOS_BASE_END

#endif // QRTBLTRAY_H
