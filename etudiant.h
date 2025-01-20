#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "Personne.h"
#include <string>

class Etudiant : public Personne {
private:
    int annee;
    
public:
    // Constructeurs
    Etudiant();
    Etudiant(std::string prenom, std::string nom);
    Etudiant(std::string prenom, std::string nom,int id);
    
    // Getters
    int getAnnee();

    void changeAnnee();

    // Méthode affiche
    void affiche();

};

#endif
