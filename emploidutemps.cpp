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
void ECUE::setTypeECUE(std::string type)
{
    this->typeUCUE = type;
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

}

void ECUE::spprimerEnseignant(Enseignant enseignant)
{

}
