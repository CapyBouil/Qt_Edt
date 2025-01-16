#include "Etudiant.h"
#include <iostream>

// Constructeurs
Etudiant::Etudiant() : Personne() {}

Etudiant::Etudiant(std::string prenom, std::string nom)
    : Personne(prenom, nom)
{}

Etudiant::Etudiant(std::string prenom, std::string nom, int id)
    : Personne(prenom, nom,id)
{}

//Getters
std::string Etudiant::getNom() const {
    return Personne::getNom();}

std::string Etudiant::getPrenom() const {
    return Personne::getPrenom();}

// Méthode affiche
void Etudiant::affiche() {
    Personne::affiche();
}
