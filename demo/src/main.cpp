#include <QApplication>
#include <QtCore/qdebug.h>

#include "db/qrframedb.h"
#include "entity/qrsqldatabase.h"
#include "qrrunguard.h"

#include "qrchaosframer.h"
#include "gui/qrchaosmainwindow.h"

USING_NS_CHAOS_BASE;

int main(int argc, char *argv[])
{
    Qters::QrCommon::QrRunGuard guard("qters.farme.chaos.v1");
    if ( !guard.tryToRun() ) {
        return 0;
    }

    Qters::QrOrm::QrSqlDatabaseParams dbParam;
    dbParam.driverName = "QSQLITE";
    dbParam.folder = "data";
    dbParam.databaseName = "chaos.db";

    Qters::QrFrame::QrFramerConfig frameConfig;
    frameConfig.dbParams = dbParam;
    frameConfig.installLog = false;

    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName("Qters");
    QCoreApplication::setApplicationName("chaos");

    QrChaosMainwindow mwindow;
    QrChaosFramer framer;
    framer.setConfig(frameConfig);
    framer.setMainWindow(&mwindow);
    framer.start();

    return app.exec();
}
