#ifndef FACTORY_H
#define FACTORY_H

#include "etudiant.h"
#include "enseignant.h"
#include "ecue.h"
#include "classe.h"
#include "creneau.h"
#include "salle.h"
#include "tests.h"

class Factory
{
public:
    Factory();

    static QDate stringToQDate(const std::string& dateStr);
    static QTime floatToQTime(float heure);
    static void insertEtudiant(Etudiant etudiant, Classe classe);
    static void insertEnseignant(Enseignant enseignant, ECUE ecue);

    static Salle findSalleById(int id);
    static Classe findClasseById(int id);
    static ECUE findEcueById(int id);
    static Enseignant findEnseignantById(int id);

    static void saveEtudiant(Etudiant etudiant);
    static void saveEnseignant(Enseignant enseignant);
    static void saveECUE(ECUE ecue);
    static void saveSalle(Salle salle);
    static void saveCreneau(Creneau creneau);
    static void saveClasse(Classe classe);

    static std::list<Etudiant> listeEtudiant;
    static std::list<Enseignant> listeEnseignant;
    static std::list<ECUE> listeEcue;
    static std::list<Classe> listeClasse;
    static std::list<Salle> listeSalle;
    static std::list<Creneau> listeCreneau;


    static void loadEtudiant();
    static void loadEnseignant();
    static void loadEcue();
    static void loadClasse();
    static void loadSalle();
    static void loadCreneau();

    static void suppEtudiant(Etudiant etudiant);
    static void suppEnseignant(Enseignant enseignant);
    static void suppEcue(ECUE ecue);
    static void suppClasse(Classe classe);
    static void suppSalle(Salle salle);
    static void suppCreaneau(Creneau creneau);


};

#endif // FACTORY_H
