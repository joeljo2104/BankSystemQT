#-------------------------------------------------
#
# Project created by QtCreator 2019-03-09T16:14:06
#
#-------------------------------------------------

QT       += core gui \
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AJBank
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += sql \
          c++11


SOURCES += \
        main.cpp \
        welcomewindow.cpp \
    airticket1.cpp \
    airticket2.cpp \
    bankservices.cpp \
    billpayment1.cpp \
    carloan1.cpp \
    carloan2.cpp \
    currencyconvertor.cpp \
    educationloan1.cpp \
    educationloan2.cpp \
    fundstransfer1.cpp \
    fundstransfer2.cpp \
    goldloan1.cpp \
    goldloan2.cpp \
    homeloan1.cpp \
    homeloan2.cpp \
    loans.cpp \
    mainmenu.cpp \
    mobilebill1.cpp \
    mobilebill2.cpp \
    movieticket1.cpp \
    movieticket2.cpp \
    tickets.cpp \
    transactionlist.cpp \
    utilitybill1.cpp \
    utilitybill2.cpp \
    withdrawal1.cpp \
    withdrawal2.cpp \
    deposit1.cpp \
    deposit2.cpp \
    admin.cpp \
    login.cpp \
    newcustomer.cpp \
    usernamepassword.cpp \
    viewdetails.cpp \
    menublank.cpp \
    suggestion.cpp \
    updatedetails.cpp \
    adminpage.cpp

HEADERS += \
        welcomewindow.h \
    airticket1.h \
    airticket2.h \
    bankservices.h \
    billpayment1.h \
    carloan1.h \
    carloan2.h \
    currencyconvertor.h \
    educationloan1.h \
    educationloan2.h \
    fundstransfer1.h \
    fundstransfer2.h \
    goldloan1.h \
    goldloan2.h \
    homeloan1.h \
    homeloan2.h \
    loans.h \
    mainmenu.h \
    mobilebill1.h \
    mobilebill2.h \
    movieticket1.h \
    movieticket2.h \
    tickets.h \
    transactionlist.h \
    utilitybill1.h \
    utilitybill2.h \
    withdrawal1.h \
    withdrawal2.h \
    deposit1.h \
    deposit2.h \
    admin.h \
    login.h \
    newcustomer.h \
    usernamepassword.h \
    viewdetails.h \
    menublank.h \
    suggestion.h \
    updatedetails.h \
    adminpage.h

FORMS += \
        welcomewindow.ui \
    airticket1.ui \
    airticket2.ui \
    bankservices.ui \
    billpayment1.ui \
    carloan1.ui \
    carloan2.ui \
    currencyconvertor.ui \
    educationloan1.ui \
    educationloan2.ui \
    fundstransfer1.ui \
    fundstransfer2.ui \
    goldloan1.ui \
    goldloan2.ui \
    homeloan1.ui \
    homeloan2.ui \
    loans.ui \
    mainmenu.ui \
    mobilebill1.ui \
    mobilebill2.ui \
    movieticket1.ui \
    movieticket2.ui \
    tickets.ui \
    transactionlist.ui \
    utilitybill1.ui \
    utilitybill2.ui \
    withdrawal1.ui \
    withdrawal2.ui \
    deposit1.ui \
    deposit2.ui \
    admin.ui \
    login.ui \
    newcustomer.ui \
    usernamepassword.ui \
    viewdetails.ui \
    menublank.ui \
    suggestion.ui \
    updatedetails.ui \
    adminpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
