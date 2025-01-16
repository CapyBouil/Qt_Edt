#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "Personne.h"
#include <string>

class Etudiant : public Personne {
private:

public:
    // Constructeurs
    Etudiant();
    Etudiant(std::string prenom, std::string nom);
    Etudiant(std::string prenom, std::string nom,int id);


    // Getters
    std::string getNom() const;

    std::string getPrenom() const;

    // Méthode affiche
    void affiche();
};

#endif
