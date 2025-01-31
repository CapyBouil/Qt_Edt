#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include "factory.h"
#include <QDebug>
#include <optional>


class Controleur
{
public:
    Controleur();
    QString formaterMinuscule(QString texte);
    //Enseignant findEnseignantByNomPrenom(const QString& nomPrenom) const;
    //Etudiant findEtudiantByNomPrenom(const QString& nomPrenom) const;
    //Salle findSalleByNumero(const QString& numeroComplet) const;
    //ECUE findECUEByNom(const QString& nomECUE) const;
    //Classe findClasseByNomClasse(const QString& nomClasse) const;
    static std::optional<Enseignant> findEnseignantByNomPrenom(const QString& nomPrenom);
    static std::optional<Etudiant> findEtudiantByNomPrenom(const QString& nomPrenom);
    static std::optional<Salle> findSalleByNumero(const QString& numeroComplet);
    static std::optional<ECUE> findECUEByNom(const QString& nomECUE);
    static std::optional<Classe> findClasseByNomClasse(const QString& nomClasse);
    static std::optional<Creneau> findCreneau(Salle& salle, Classe& classe, ECUE& ecue, Enseignant& enseignant, QDate& jour, QTime& heureDebut);

};

#endif
