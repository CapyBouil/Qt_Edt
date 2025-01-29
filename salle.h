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

    int getEtage()const;
    int getNumero()const;

    int getNumeroComplet()const;

    void affiche();

    int getId();
    int getMaxId();
};

#endif // SALLE_H
