#include "Enseignant.h"

//Constructeurs
Enseignant::Enseignant() {
    }

Enseignant::Enseignant(std::string prenom, std::string nom, std::string Ecue)
    : Personne(prenom, nom)
{
    this->ECUE = Ecue;}

Enseignant::Enseignant(std::string prenom, std::string nom,int id, std::string Ecue)
    : Personne(prenom, nom,id)
{
    this->ECUE = Ecue;}

//Getters
std::string Enseignant::getNom() const {
    return Personne::nom();}

std::string Enseignant::getPrenom() const {
    return Personne::prenom();}

std::string Enseignant::getEcue() const{
    return this->matiere;}

void Enseignant::setECUE(std::string ECUE) {
    this->ECUE = ecue;}

//Méthode AFFICHE
void Enseignant::affiche() const {
    Personne::affiche();
    std::cout << "ECUE: " << ecue << std::endl;}
