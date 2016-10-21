#ifndef QRSTYLE_H
#define QRSTYLE_H

#include <QtCore/qvector.h>

#include "qrglobal.h"
#include "qrchaosbase_global.h"

NS_CHAOS_BASE_BEGIN

struct QrQssData {
    int skinIndex;
    QString skinName;
    QString skinQssFileName;
};

class QrStylePrivate;
class CHAOSBASE_SHAREDEXPORT QrStyle
{
    QR_DECLARE_PRIVATE(QrStyle)

public:
    QrStyle();

public:
    enum class SkinIndex{
        Default = 0,
        Blue = 1,
    };

public:
    static SkinIndex curSkinIndex();
    static bool initSkin();
    static bool loadSkin(SkinIndex skinIndex);
    static const QVector<QrQssData>& getSkinDataInDB(bool clear = false);

public:
    static QString Key_SkinIndex;
};

NS_CHAOS_BASE_END

#endif // QRSTYLE_H
