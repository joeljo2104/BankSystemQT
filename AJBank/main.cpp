#include "welcomewindow.h"
#include <QApplication>
#include<QSplashScreen>
#include<QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    QPixmap Pic = QPixmap(":/background/Logo.png");
    Pic = Pic.scaled(743,450,Qt::KeepAspectRatio, Qt::SmoothTransformation);
    splash->setPixmap(Pic);
    splash->show();

    WelcomeWindow w;
    QTimer::singleShot(3000,splash,SLOT(close()));

    w.showMaximized();
    return a.exec();
}
