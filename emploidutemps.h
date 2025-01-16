#ifndef EMPLOIDUTEMPS_H

#define EMPLOIDUTEMPS_H

#include "Creneau.h"

#include "ECUE.h"


#include <list>

#include <iostream>


class EmploiDuTemps
{

private:

    std::list<Creneau> creneaux;

public:

    EmploiDuTemps();

    void ajouteCreneau();

    void affiche();

}

#endif

