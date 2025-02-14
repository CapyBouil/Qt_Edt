#include "ecue.h"

#include <iostream>
#include <string>

using namespace std;

ECUE::ECUE(std::string nomECUE, std::string typeECUE, float nbHeures) {
    this->nomECUE = nomECUE;
    this->nbHeures = nbHeures;
    this->typeECUE = typeECUE;
}

//Acesseurs

std::string ECUE::getNomECUE()
{
    return this->nomECUE;
}
void ECUE::setNomECUE(std::string nom)
{
    this->nomECUE = nom;
}

std::string ECUE::getTypeECUE()
{
    return this->typeECUE;
}
void ECUE::setTypeECUE(std::string typeECUE)
{
    this->typeECUE = typeECUE;
}

float ECUE::getNbHeures()
{
    return this->nbHeures;
}
void ECUE::setNomECUE(float nb)
{
    this->nbHeures = nb;
}



//Methodes pour affecter un enseigant a un ECUE
void ECUE::ajouterEnseignant(Enseignant e)
{
    enseignants.push_back(e);
}

void ECUE::supprimerEnseignant(Enseignant e)
{
    for (size_t i = 0; i < enseignants.size(); ++i) {
        if (enseignants[i].getNom() == e.getNom() && enseignants[i].getPrenom() == e.getPrenom()) {
            enseignants.erase(enseignants.begin() + i);
            std::cout << "Enseignant supprimé : " << e.getNom() << " " << e.getPrenom() << "\n";
            return;
        }
    }
}

void ECUE::afficherEnseignants()
{
    std::cout << "Enseignants pour l'ECUE " << nomECUE << " :\n";
    for (const auto& e : enseignants) {
        std::cout << "- " << e.getNom() << " " << e.getPrenom() << "\n";
    }
}
