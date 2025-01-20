#ifndef SALLE_H
#define SALLE_H

#include <iostream>

class Salle
{
    private:
        int etage;
        int numero;
        int id;
    public:
        Salle();
        Salle(int etage, int numero);
        Salle(int etage, int numero, int id);

        int getId();
        int getEtage();
        int getNumero();

        int getNumeroComplet();

        void affiche();
};

#endif // SALLE_H

