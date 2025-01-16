#include "Enseignant.h"

//Constructeurs vide
Enseignant::Enseignant() {
    this->Ecue = " ";}

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
    std::cout << "ECUE: " << this->Ecue << std::endl;}
