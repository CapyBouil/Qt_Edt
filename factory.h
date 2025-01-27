#ifndef FACTORY_H
#define FACTORY_H

#include "etudiant.h"
#include "enseignant.h"
#include "ecue.h"
#include "classe.h"
#include "creneau.h"
#include "salle.h"

class Factory
{
public:
    Factory();

    static void saveEtudiant(Etudiant etudiant);
    static void saveEnseignant(Enseignant enseignant);
    static void saveECUE(ECUE ecue);
    static void saveSalle(Salle salle);
    static void saveCreneau(Creneau creneau);
    static void saveClasse(Classe classe);

    static std::list<Etudiant> listeEtudiant;
    static std::list<Enseignant> listeEnseignant;

    static void loadEtudiant();
    static void loadEnseignant();

};

#endif // FACTORY_H
