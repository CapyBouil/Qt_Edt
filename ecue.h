#ifndef ECUE_H
#define ECUE_H

#include <iostream>
#include <string>
#include <vector>
#include "enseignant.h"

#include <Qfile>
#include <QTextStream>
#include <QDir>

using namespace std;

class ECUE
{

private:
    std::string nomECUE;
    std::string typeECUE;
    int nbHeures;
    std::vector<Enseignant> enseignants;



public:
    ECUE();
    ECUE(std::string nom, std::string typeECUE, float nbHeures);
    void ajouterEnseignant(Enseignant e);
    void supprimerEnseignant(Enseignant e);

    std::string getNomECUE();
    void setNomECUE(std::string nom);

    std::string getTypeECUE();
    void setTypeECUE(std::string type);

    float getNbHeures();
    void setNomECUE(float nb);

    void affiche();
    void saveECUE();
    int getMaxId();

};

#endif // ECUE_H
