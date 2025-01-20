#include "Etudiant.h"
#include <iostream>

// Constructeurs
Etudiant::Etudiant() : Personne(), annee(1) {
}

Etudiant::Etudiant(std::string prenom, std::string nom)
    : Personne(prenom, nom), annee(1) {

}

Etudiant::Etudiant(std::string prenom, std::string nom, int id)
    : Personne(prenom, nom,id), annee(1)
{}

int Etudiant::getAnnee()
{
    return this->annee;
}

void Etudiant::changeAnnee() {
    ++annee;
}

// Méthode affiche
void Etudiant::affiche() {
    Personne::affiche();
    if (annee == 1) {
        std::cout << "- 1ere annee" << std::endl;
    } else {
        std::cout << "- " << annee << "eme annee" << std::endl;
    }
}

