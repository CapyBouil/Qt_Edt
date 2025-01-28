#ifndef ECUE_H
#define ECUE_H

#include <iostream>
#include <string>
#include <list>
#include "enseignant.h"

#include <Qfile>
#include <QTextStream>
#include <QDir>

using namespace std;

class ECUE
{

private:
    int id;
    std::string nomECUE;
    std::string typeECUE;
    int nbHeures;
    std::list<Enseignant> enseignants;


public:
    ECUE();
    ECUE(std::string nom, std::string typeECUE, float nbHeures);
    ECUE(std::string nom, std::string typeECUE, float nbHeures, int id);

    int getId();

    void ajouterEnseignant(Enseignant e);
    void supprimerEnseignant(Enseignant e);


    std::string getNomECUE();
    void setNomECUE(std::string nom);

    std::string getTypeECUE();
    void setTypeECUE(std::string type);

    float getNbHeures();
    void setNomECUE(float nb);

    void affiche();

    int getMaxId();
};

#endif // ECUE_H
