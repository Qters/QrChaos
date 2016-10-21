![User Interface](http://img.hoop8.com/1608A/fJSJLbn2.png)

# database table DRIVE user interface

## navigation

id	|	parentid	|	key			  |	display		  |	icon	                                                          |	tag
----|-----------|-----------|-------------|-----------------------------------------------------------------|---------
1	  |	0			    |	root		  |	root		    |			                                                            |	system
2	  |	1			    |	home		  |	home		    |	:/main_service/images/blue/main_service/main0.png		            |	main
3	  |	2			    |	about		  |	about us	  |	:/main_service/images/blue/main_service/main1.png		            |	main
4	  |	2			    |	contact	  |	contact us	|	:/main_service/images/blue/main_service/main2.png		            |	main
5	  |	2			    |	news		  |	what's new	|	:/main_service/images/blue/main_service/main3.png		            |	main
9	  |	1			    |	product		|	product		  |	:/product_service/images/blue/product_service/product0.png		  |	main
10	|	9			    |	qrcommon	|	qrcommon	  |	:/product_service/images/blue/product_service/product1.png		  |	first
11	|	9			    |	qrframe		|	qrframe		  |	:/product_service/images/blue/product_service/product2.png		  |	first
12	|	9			    |	qrorm		  |	qrorm		    |	:/product_service/images/blue/product_service/product3.png		  |	first
13	|	9			    |	qrtest		|	qrtest		  |	:/product_service/images/blue/product_service/product4.png		  |	first
14	|	9			    |	qrlogger	|	qrlogger	  |	:/product_service/images/blue/product_service/product5.png		  |	first
15	|	9			    |	qrupdate	|	qrupdate	  |	:/product_service/images/blue/product_service/product6.png		  |	first
17	|	9			    |	qrcache		|	qrcache		  |	:/product_service/images/blue/product_service/product7.png		  |	first

![navigation ui](http://img.hoop8.com/1608A/TiBC4cSe.png)

```cpp
...
class QrNavigation {
...
static bool qrconnect(const QString& path,
                          const QObject *receiver,
                          const char *member);
...
};

//  connect signal and slot by navigaiton path(like java package path)
class SomeService{
public:
  void init() {
    QrNavigation::qrconnect("home.product.qrframe", this, SLOT(onQrFrame()));
  }
private slots:
    void onQrFrame() {}
}
```
[demo : connect signal and slot of navigaiton](https://github.com/Qters/QrFrame/blob/master/chaos/services/product/qrproductservice.cpp#L38)

## system tray

id	| separator	| isvisible	| text	      | icon	                                                  | sort	| key
----|-----------|-----------|-------------|---------------------------------------------------------|-------|-----
1	  | True	    | True	    | setting		  | :/system_tray/images/blue/system_tray/setting.png       | 1	    | setting
2	  | False	    | True	    | about		    | :/system_tray/images/blue/system_tray/about.png         | 3	    | about
3	  | False	    | True	    | help		    | :/system_tray/images/blue/system_tray/help.png          | 2	    | help
4	  | True	    | True	    | check update|	:/system_tray/images/blue/system_tray/check_update.png  | 4	    | check.update
5	  | False	    | True	    | exit		    | :/system_tray/images/blue/system_tray/exit.png          | 5	    | exit

![sytem tray ui](http://img.hoop8.com/1608A/cuVXeOH2.png)
```cpp
...
class QrSystemTray {
...
static bool qrconnect(const QString& path,
                          const QObject *receiver,
                          const char *member);
...
};

//  connect signal and slot by system tray path(like java package path)
class SomeService{
public:
  void init() {
    QrSystemTray::qrconnect("exit", qApp, SLOT(quit()));
  }
}
```
[demo : connect signal and slot of system tray](https://github.com/Qters/QrFrame/blob/master/chaos/services/main/qrmainservice.cpp#L53)

# workspace 

```cpp
...
class QrWorkspace {
...
static int appendTab(QWidget *widget, QString label);
...
};


QrWorkspace::appendTab(new QPushButton(), "Tab Title");

```
[demo : append tab page to workspace](https://github.com/Qters/QrFrame/blob/master/chaos/services/product/qrproductservice.cpp#L57)
