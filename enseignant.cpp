#include "Enseignant.h"

//Constructeurs
Enseignant::Enseignant() {
    }

Enseignant::Enseignant(std::string prenom, std::string nom, std::string ecue)
        : Personne(prenom, nom)
{
    this->ecue = ecue;
}


Enseignant::Enseignant(std::string prenom, std::string nom,int id, std::string ecue)
    : Personne(prenom, nom,id)
{
    this->ecue = ecue;}

//Getters
std::string Enseignant::getEcue() const{
    return this->ecue;
}

void Enseignant::setEcue(std::string ecue) {
    this->ecue = ecue;
}

//Méthode AFFICHE
void Enseignant::affiche() {
    Personne::affiche();
    std::cout << "ECUE: " << ecue << std::endl;
}
