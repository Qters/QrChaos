#include "gui/navigation/qrnavigation.h"

#include <QtCore/qdebug.h>
#include <QtWidgets/qtabwidget.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qtabbar.h>

#include "gui/navigation/qrnavigationheader.h"
#include "gui/navigation/qrnavigationtabpage.h"
#include "db/qrtblnavigation.h"
#include "db/qrtblframeconfig.h"

NS_CHAOS_BASE_BEGIN

class QrNavigationPrivate {
    QR_DECLARE_PUBLIC(QrNavigation)
public:
    QrNavigationPrivate(QrNavigation *q);

public:
    static QrNavigationPrivate* dInstance();

public:
    void loadUI();
    void addTotalTabPage();
    void addCustomTabPage();
    QPushButton *getButton(const QString &path);

public:
    QrNavigationHeader *header = nullptr;
    QrNavigationTabPage *totalTabPage = nullptr;
    QrNavigationTabPage *customTabPage = nullptr;
    QTabWidget* navigationTab = nullptr;
    QMap<QString, QPushButton*> pathButtonContainer;

public:
    static QrNavigation* qInstance;
};

QrNavigation* QrNavigationPrivate::qInstance = nullptr;

QrNavigationPrivate::QrNavigationPrivate(QrNavigation *q)
    : q_ptr(q) {
    qInstance = q;
}

QrNavigationPrivate *QrNavigationPrivate::dInstance(){
    Q_ASSERT(nullptr != QrNavigationPrivate::qInstance);
    return QrNavigationPrivate::qInstance->d_func();
}

void QrNavigationPrivate::addTotalTabPage(){
    Q_Q(QrNavigation);
    QrTblNavigationHelper tblNavigationHelper;
    totalTabPage = new QrNavigationTabPage(q);
    QObject::connect(totalTabPage, &QrNavigationTabPage::addButton,
                     [this](QString path, QPushButton* itemButton){
        this->pathButtonContainer[path] = itemButton;
    });

    totalTabPage->initModelByDbData(tblNavigationHelper.getData());
    QObject::connect(totalTabPage, &QrNavigationTabPage::removeButton,
                     [this](QString path, QPushButton* itemButton){
        auto findIter = this->pathButtonContainer.find(path);
        Q_ASSERT(findIter.value() == itemButton);
        this->pathButtonContainer.erase(findIter);
        qDebug() << "navigation remove item " << path;
    });
    this->header->navigationModelProxy(totalTabPage->modelProxy()); //  default

    navigationTab->addTab(totalTabPage, "Total");
}

void QrNavigationPrivate::addCustomTabPage(){
    static QString type = "gui";
    static QString key = "custom_nav";

    Q_Q(QrNavigation);
    QString needCusttomNavigation;
    if ( ! Qters::QrFrame::QrTblFrameConfigHelper::getValueBy(type, key, &needCusttomNavigation) ) {
        needCusttomNavigation = "false";
    }
    if ( "true" == needCusttomNavigation ) {
        customTabPage = new QrNavigationTabPage(q);
        navigationTab->addTab(customTabPage, "Custom");
    }
}

void QrNavigationPrivate::loadUI()
{
    Q_Q(QrNavigation);
    header = new QrNavigationHeader(q);

    navigationTab = new QTabWidget(q);
    navigationTab->tabBar()->setObjectName("navigation_bar");

    addTotalTabPage();
    addCustomTabPage();

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
    mainLayout->addWidget(header);
    mainLayout->addWidget(navigationTab);
    q->setLayout(mainLayout);

    QObject::connect(navigationTab, &QTabWidget::currentChanged, [this](int index){
        auto curNavTab = qobject_cast<QrNavigationTabPage*>(this->navigationTab->widget(index));
        this->header->navigationModelProxy(curNavTab->modelProxy());
    });

    QObject::connect(this->header, &QrNavigationHeader::beginSearch, [this](){
        qobject_cast<QrNavigationTabPage*>(navigationTab->currentWidget())->expandAll();
    });
}

QPushButton *QrNavigationPrivate::getButton(const QString &path)
{
    return pathButtonContainer[path];
}

NS_CHAOS_BASE_END


USING_NS_CHAOS_BASE;

QrNavigation::QrNavigation(QWidget* parent)
    : QWidget(parent), d_ptr(new QrNavigationPrivate(this))
{
    setFixedWidth(158);
    d_ptr->loadUI();
}

bool QrNavigation::qrconnect(const QString &path,
                             const QObject *receiver,
                             const char *member)
{
    auto pushButton = QrNavigationPrivate::dInstance()->getButton(path);
    if (nullptr == pushButton) {
        return false;
    }

    QObject::connect (pushButton, SIGNAL(clicked ()), receiver, member);
    return true;
}
