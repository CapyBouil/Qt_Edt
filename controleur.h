#ifndef CONTROLEUR_H
#define CONTROLEUR_H
#include <QString>

#include "factory.h"
#include <QDebug>

class Controleur
{
public:
    Controleur();
    QString formaterMinuscule(QString texte);
    Enseignant findEnseignantByNomPrenom(const QString& nomPrenom) const;
    Etudiant findEtudiantByNomPrenom(const QString& nomPrenom) const;

};

#endif // CONTROLEUR_H
