#include <iostream>

#include "Enseignant.h"
#include "etudiant.h"
#include "ecue.h"
#include "classe.h"
#include "salle.h"
#include "creneau.h"
#include "emploidutemps.h"

#include <cassert>


#include "tests.h"

int main() {
    Tests test;

    //testEnseignant();
    //testEtudiant();
    //testECUE();
    //testClasse();
    //testSalle();
    //testCreneau();
    //test.testEdt();
    test.testFactory();
    return 0;
}


