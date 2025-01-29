#ifndef CONTROLEUR_H
#define CONTROLEUR_H
#include <QString>

#include "enseignant.h"

class Controleur
{
public:
    Controleur();
    QString formaterMinuscule(QString texte);
    Enseignant findEnseignantByNomPrenom(const std::string& nomPrenom) const;
};

#endif // CONTROLEUR_H
