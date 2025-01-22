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

void Etudiant::saveEtudiant(){
    QFile file("../../data/Etudiant.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<this->getId() <<";" <<QString::fromStdString(this->getNom()) <<";" <<QString::fromStdString(this->getPrenom());

    file.close();
}
