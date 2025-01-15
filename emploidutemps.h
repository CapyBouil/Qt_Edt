#ifndef EMPLOIDUTEMPS_H
#define EMPLOIDUTEMPS_H

#include Creneau.h
#include ECUE.h

#include <vector>

class Creneau
{
private:
    std::vector<Creneau> creneaux;


public:
    void ajouteCreneau();
    void afficheEdt(); 
}
