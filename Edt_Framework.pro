QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    classe.cpp \
    classewindow.cpp \
    controleur.cpp \
    creneau.cpp \
    creneauwindow.cpp \
    ecue.cpp \
    ecuewindow.cpp \
    emploidutemps.cpp \
    enseignant.cpp \
    enseignantwindow.cpp \
    etudiant.cpp \
    etudiantwindow.cpp \
    factory.cpp \
    lierecuewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    personne.cpp \
    salle.cpp \
    sallewindow.cpp \
    style.cpp \
    tests.cpp

HEADERS += \
    classe.h \
    classewindow.h \
    controleur.h \
    creneau.h \
    creneauwindow.h \
    ecue.h \
    ecuewindow.h \
    emploidutemps.h \
    enseignant.h \
    enseignantwindow.h \
    etudiant.h \
    etudiantwindow.h \
    factory.h \
    lierecuewindow.h \
    mainwindow.h \
    personne.h \
    salle.h \
    sallewindow.h \
    style.h \
    tests.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
