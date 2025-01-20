#ifndef CRENEAU_H
#define CRENEAU_H

#include "salle.h"
#include "classe.h"
#include "ecue.h"
#include "enseignant.h"
#include <string>

#include <QDate>
#include <QTime>
#include <QDateTime>

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

#include <sstream>   // Pour std::istringstream
#include <iomanip>   // Pour std::get_time
#include <stdexcept> // Pour std::invalid_argument
#include <iostream>  // Pour std::cout
#include <fstream>   // Pour std::ifstream


/**
 * @class Creneau
 * @brief Représente un créneau horaire avec une salle, une classe, un ECUE et un enseignant.
 *
 * Cette classe permet de gérer les créneaux horaires en associant une salle, une classe, un ECUE et un enseignant
 * à un jour et une plage horaire spécifique.
 */
class Creneau
{
private:
    // Attributs
    int id;
    Salle salle;
    Classe classe;
    ECUE ecue;
    Enseignant enseignant;
    QDate jour;
    QTime heure_debut;
    QTime heure_fin;
    int duree;

    // Methodes
    void setDuree();

public:
    Creneau();
    Creneau(Salle salle, Classe classe, ECUE ecue, Enseignant enseignant, QDate jour, QTime heure_debut, QTime heure_fin);
    Creneau(int id, Salle salle, Classe classe, ECUE ecue, Enseignant enseignant, QDate jour, QTime heure_debut, QTime heure_fin);


    int getId();
    Salle getSalle() const;
    Classe getClasse() const;
    ECUE getECUE() const;
    Enseignant getEnseignant() const;
    QDate getJour() const;
    QTime getHeureDebut() const;
    QTime getHeureFin() const;
    int getDuree() const;

    void setSalle(Salle salle);

    void setClasse(Classe classe);

    void setECUE(ECUE ecue);

    void setEnseignant(Enseignant enseignant);

    void setJour(const QString& jourStr);

    void setHeureDebut(QTime heureDebut);

    void setHeureFin(QTime heureFin);


    void affiche();


    void ajouteSalle(Salle salle);

    void supprimeSalle();

    void ajouteClasse(Classe classe);


    void supprimeClasse();


    void ajouteECUE(ECUE ecue);


    void supprimeECUE();


    void ajouteEnseignant(Enseignant enseignant);


    void supprimeEnseignant();


    int getMaxId();
};

#endif
