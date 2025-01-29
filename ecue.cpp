#include "ecue.h"

#include <iostream>
#include <string>

using namespace std;

ECUE::ECUE(){
    this->id=getMaxId()+1;
}

ECUE::ECUE(std::string nomECUE, std::string typeECUE, float nbHeures) {
    this->id=getMaxId()+1;
    this->nomECUE = nomECUE;
    this->nbHeures = nbHeures;
    this->typeECUE = typeECUE;
}

ECUE::ECUE(std::string nomECUE, std::string typeECUE, float nbHeures, int id) {
    this->nomECUE = nomECUE;
    this->nbHeures = nbHeures;
    this->typeECUE = typeECUE;
    this->id=id;
}
//Acesseurs

int ECUE::getId() {
    return this->id;
}

std::string ECUE::getNomECUE() const
{
    return this->nomECUE;
}
void ECUE::setNomECUE(std::string nom)
{
    this->nomECUE = nom;
}

std::string ECUE::getTypeECUE() const
{
    return this->typeECUE;
}
void ECUE::setTypeECUE(std::string typeECUE)
{
    this->typeECUE = typeECUE;
}

float ECUE::getNbHeures() const{
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
    for (auto it = enseignants.begin(); it != enseignants.end(); ++it) {
        if (it->getNom() == e.getNom() && it->getPrenom() == e.getPrenom()) {
            enseignants.erase(it);
            std::cout << "Enseignant supprime(e) : " << e.getNom() << " " << e.getPrenom() << "\n";
            return;
        }
    }
}

void ECUE::affiche()
{
    std::cout << nomECUE << std::endl;
}

int ECUE::getMaxId(){
    int maxIdECUE = 0;

    QFile fileECUE("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/ECUE.csv");
    fileECUE.open(QIODevice::ReadOnly | QIODevice::Text );

    QTextStream tsECUE(&fileECUE);

    QString lineECUE = tsECUE.readLine(); // en-tête
    while(!tsECUE.atEnd()){
        lineECUE = tsECUE.readLine();
        QStringList liste = lineECUE.split(";");
        if(liste[0].toInt()>maxIdECUE){
            maxIdECUE = liste[0].toInt();
        }
    }

    fileECUE.close();

    return maxIdECUE;
}
