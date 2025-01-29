#include <iostream>

#include "Enseignant.h"
#include "etudiant.h"
#include "ecue.h"
#include "classe.h"
#include "salle.h"
#include "creneau.h"
#include "emploidutemps.h"

#include "mainwindow.h"
#include <cassert>
#include <QApplication>


#include "tests.h"


int qMain(int argc, char *argv[]) {

    Tests test;

    //testEnseignant();
    //testEtudiant();
    //testECUE();
    //testClasse();
    //testSalle();
    //testCreneau();
    //test.testEdt();
    //test.testFactory();
    test.testFindByNomPrenom();

    //QApplication a(argc,argv);
    //MainWindow w(nullptr);
    //w.show();
    //return a.exec();

    return 0;
}


