#include "Enseignant.h"

//Constructeurs vide
Enseignant::Enseignant() {
    Personne();
}

Enseignant::Enseignant(std::string prenom, std::string nom)
    : Personne(prenom, nom)
{
}

Enseignant::Enseignant(std::string prenom, std::string nom,int id)
    : Personne(prenom, nom, id)
{
}

//Getters
std::string Enseignant::getNom() const {
    return Personne::getNom();}

std::string Enseignant::getPrenom() const {
    return Personne::getPrenom();}


//Méthode AFFICHE
void Enseignant::affiche() const {
}
