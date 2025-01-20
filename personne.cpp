#include "Personne.h"

// Constructeurs
Personne::Personne() {
    prenom = "";
    nom = "";
    id= 0;
}

Personne::Personne(std::string prenom, std::string nom) {
    this->prenom = prenom;
    this->nom = nom;
    //max=maxId+1
    //this->id=max;
}
Personne::Personne(std::string prenom, std::string nom,int id){
    this->prenom = prenom;
    this->nom = nom;
    this->id = id;
}

// Getters
std::string Personne::getNom() const {
    return nom;
}

std::string Personne::getPrenom() const {
    return prenom;
}

int Personne::getId() const
{
    return id;
}

//Méthode AFFICHE
void Personne::affiche() {
    std::cout << "Nom: " << nom << " Prenom: " << prenom << std::endl;
}

