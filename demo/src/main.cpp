#include <QApplication>
#include <QtCore/qdebug.h>

#include "db/qrframedb.h"
#include "entity/qrsqldatabase.h"
#include "qrrunguard.h"

#include "qrchaosframer.h"
#include "gui/qrchaosmainwindow.h"
#include "qrchaosapplication.h"

USING_NS_CHAOS_BASE;

int main(int argc, char *argv[])
{
    Qters::QrCommon::QrRunGuard guard("qters.farme.chaos.v1");
    if ( !guard.tryToRun() ) {
        qDebug() << "framer start fail, progress is about to quit.";
        return 0;
    }

    QCoreApplication::setOrganizationName("Qters");
    QCoreApplication::setApplicationName("chaos");

    Qters::QrOrm::QrSqlDatabaseParams dbParam;
    dbParam.driverName = "QSQLITE";
    dbParam.folder = "data";
    dbParam.databaseName = "chaos.db";

    Qters::QrFrame::QrFramerConfig frameConfig;
    frameConfig.dbParams = dbParam;
    frameConfig.installLog = false;

    QrChaosApplication app(argc, argv);
    if(! app.init(frameConfig)) {
        return -1;
    }

    return app.exec();
}
