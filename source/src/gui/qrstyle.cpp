#include "gui/qrstyle.h"

#include <QtCore/qdebug.h>
#include <QtCore/qfile.h>
#include <QtCore/qtextstream.h>
#include <QtWidgets/qapplication.h>
#include <QtCore/qsettings.h>

#include "db/qrtblframeconfig.h"

NS_CHAOS_BASE_BEGIN

class QrStylePrivate{
public:
    static QVector<QrQssData> qssDbData;

public:
    static bool loadQss(const QString& qssFileName);
};

QVector<QrQssData> QrStylePrivate::qssDbData;

bool QrStylePrivate::loadQss(const QString &qssFileName){
    QFile qssFile(qssFileName);
    if (!qssFile.exists()) {
        qDebug() << "Unable to set stylesheet, file not found"
                 << qssFileName;

        return false;
    }

    qssFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream ts(&qssFile);
    qApp->setStyleSheet(ts.readAll());

    return true;
}

NS_CHAOS_BASE_END


USING_NS_CHAOS_BASE;

QString QrStyle::Key_SkinIndex = "skin_index";

QrStyle::QrStyle()
    : d_ptr(new QrStylePrivate)
{

}

QrStyle::SkinIndex QrStyle::curSkinIndex()
{
    QSettings settings;
    return static_cast<SkinIndex>(
                settings.value(
                    QrStyle::Key_SkinIndex,
                    static_cast<int>(SkinIndex::Default)).toInt());
}

bool QrStyle::initSkin()
{
    return QrStyle::loadSkin(QrStyle::curSkinIndex());
}

const QVector<QrQssData>& QrStyle::getSkinDataInDB(bool clear /*= false*/)
{
    if (! clear && ! QrStylePrivate::qssDbData.isEmpty()) {
        return QrStylePrivate::qssDbData;
    }

    QrStylePrivate::qssDbData.clear();

    static const QString dbSkinType = "skin";
    static const QString dbKey = "qsses";
    QString qsses;
    if (! Qters::QrFrame::QrTblFrameConfigHelper::getValueBy(dbSkinType, dbKey, &qsses)) {
        return QrStylePrivate::qssDbData;
    }

    Q_FOREACH(auto qss, qsses.split(';')) {
        auto qssProps = qss.split(',');
        if (3 != qssProps.size()) {
            qWarning() << "qss property in database in unrecognized." << qssProps;
            continue;
        }

        QrQssData qdddata;
        qdddata.skinIndex = qssProps.at(0).toInt();
        qdddata.skinName = qssProps.at(1);
        qdddata.skinQssFileName = qssProps.at(2);

        QrStylePrivate::qssDbData.push_back(qdddata);
    }

    return QrStylePrivate::qssDbData;
}

bool QrStyle::loadSkin(SkinIndex skinIndex) {
    auto qssDatas = QrStyle::getSkinDataInDB();

    Q_FOREACH(auto qssData, qssDatas) {
        if (skinIndex != static_cast<SkinIndex>(qssData.skinIndex)){
            continue;
        }

        QSettings settings;
        settings.setValue(QrStyle::Key_SkinIndex,
                          static_cast<int>(skinIndex));


        return QrStylePrivate::loadQss(qssData.skinQssFileName);
    }

    return false;
}

