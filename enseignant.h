#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include "Personne.h"
#include <string>

class Enseignant : public Personne {
private:
    std::string ECUE;
    
public:
    //Constructeur
    Enseignant();
    // Constructeur avec trois paramètres
    Enseignant(std::string prenom, std::string nom,int id, std::string ECUE);
    
    // Accesseurs
    std::string getEcue() const;
    void setEcue(std::string ECUE);
    std::string getNom() const;
    std::string getPrenom() const ;
};

// Méthode AFFICHE
void affiche() const override;
#endif