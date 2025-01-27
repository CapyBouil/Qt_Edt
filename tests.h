#ifndef TESTS_H
#define TESTS_H

#include "Enseignant.h"
#include "etudiant.h"
#include "ecue.h"
#include "classe.h"
#include "salle.h"
#include "creneau.h"
#include "emploidutemps.h"
#include "factory.h"

class Tests
{
public:
    Tests();
    void testEnseignant();
    void testEtudiant();
    void testECUE();
    void testClasse();
    void testSalle();
    void testCreneau();
    QDate stringToQDate(const std::string& dateStr);
    QTime floatToQTime(float heure);
    void testEdt();
    void testFactory();
};

#endif // TESTS_H
