#ifndef CONTROLEUR_H
#define CONTROLEUR_H
#include <QString>

#include "factory.h"
#include <QDebug>
#include <optional>


class Controleur
{
public:
    Controleur();
    QString formaterMinuscule(QString texte);
    std::optional<Enseignant> findEnseignantByNomPrenom(const QString& nomPrenom) const;
    std::optional<Etudiant> findEtudiantByNomPrenom(const QString& nomPrenom) const;
    std::optional<Salle> findSalleByNumero(const QString& numeroComplet) const;
    std::optional<ECUE> findECUEByNom(const QString& nomECUE) const;
    std::optional<Classe> findClasseByNomClasse(const QString& nomClasse) const;



};

#endif // CONTROLEUR_H
