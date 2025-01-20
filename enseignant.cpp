#include "Enseignant.h"

//Constructeurs vide
Enseignant::Enseignant()
{
    Personne();
}

Enseignant::Enseignant(std::string prenom, std::string nom, std::string Ecue)
    : Personne(prenom, nom)
{
    this->Ecue = Ecue;}

Enseignant::Enseignant(std::string prenom, std::string nom,int id, std::string Ecue)
    : Personne(prenom, nom,id)
{
    this->Ecue = Ecue;}

//Getters
std::string Enseignant::getNom() const {
    return Personne::getNom();}

std::string Enseignant::getPrenom() const {
    return Personne::getPrenom();}

std::string Enseignant::getEcue() const{
    return this->Ecue;}

void Enseignant::setEcue(std::string ECUE) {
    this->Ecue = ECUE;}

//Méthode AFFICHE
void Enseignant::affiche() const {
    std::cout << "id: " << this->getId() << std::endl;
    std::cout << "Nom: " << this->getNom() << std::endl;
    std::cout << "Prenom: " << this->getPrenom() << std::endl;
    std::cout << "ECUE: " << this->Ecue << std::endl;
}

//Méthode saveEnseignant
void Enseignant::saveEnseignant(){
    QFile file("../../data/Enseignant.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<this->getId() <<";" <<QString::fromStdString(this->getNom()) <<";" <<QString::fromStdString(this->getPrenom());

    file.close();
}

