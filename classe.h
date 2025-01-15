#ifndef CLASSE_H
#define CLASSE_H

#include <iostream>
#include <string>
#include <list>
#include "Etudiant.h"

class Classe{
private :
    std::string nomClasse;
    int id;
    std::list<Etudiant> etudiants;

public :
    Classe();
    Classe(std::string nomClasse);
    Classe(std::string nomClasse, int id);
    std::string getNomClasse();
    int getId();
    void ajouterEtudiant(Etudiant& etudiant);
    void supprimerEtudiant(std::string& nom, std::string& prenom);
    void afficherClasse();

}
#endif
