#ifndef ECUE_H
#define ECUE_H

#include <iostream>
#include <string>
#include <vector>
#include "enseignant.h"

using namespace std;

class ECUE
{
    
private:
    std::string nomECUE;
    std::string typeECUE;
    int nbHeures;
    std::vector<Enseignant> enseignants;


    
public:
    ECUE(std::string nom, std::string typeECUE, float nbHeures);
    void ajouterEnseignant(Enseignant e);
    void supprimerEnseignant(Enseignant e);

    std::string getNomECUE();
    void setNomECUE(std::string nom);

    std::string getTypeECUE();
    void setTypeECUE(std::string type);

    float getNbHeures();
    void setNomECUE(float nb);

    void afficherEnseignants();


};

#endif // ECUE_H
