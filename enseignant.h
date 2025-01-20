#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include "personne.h"
#include <string>

class Enseignant : public Personne {
private:
    std::string ecue;
    
public:
    Enseignant();
    //Constructeur
    Enseignant(std::string prenom, std::string nom, std::string ecue);
    // Constructeur avec trois paramètres
    Enseignant(std::string prenom, std::string nom,int id, std::string ecue);
    
    // Accesseurs
    std::string getEcue() const;
    void setEcue(std::string ecue);

    void affiche();
};

#endif
