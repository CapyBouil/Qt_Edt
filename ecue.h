#ifndef ECUE_H
#define ECUE_H

#include <iostream>
#include <string>
#include "enseignant.h"

using namespace std;

class ECUE
{
    
private:
    std::string nomECUE;
    int nbHeures;
    
public:
    ECUE(std::string nom, float nbHeures);
    void ECUE::ajouterEnseignant(Enseignant enseignant);
    void ECUE::supprimerEnseignant(Enseignant enseignant);
};

#endif // ECUE_H
