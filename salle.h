#ifndef SALLE_H
#define SALLE_H

#include <iostream>

#include <Qfile>
#include <QTextStream>
#include <QDir>

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

    int getEtage();
    int getNumero();

    int getNumeroComplet();

    void affiche();

    void saveSalle();
    int getMaxId();
};

#endif // SALLE_H
