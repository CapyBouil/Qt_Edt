#ifndef CRENEAU_H
#define CRENEAU_H

#include "salle.h"
#include "classe.h"
#include "ecue.h"
#include "enseignant.h"
#include <string>

#include <fstream>
#include <string>


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
    std::string jour; // Format: "YYYY-MM-DD" (Année-Mois-Jour)
    float heure_debut; // Format: HH.MM (Heure en format 24 heures)
    float heure_fin; // Format: HH.MM (Heure en format 24 heures)
    float duree;

    // Methodes
    void setDuree();

public:
    Creneau();
    Creneau(Salle salle, Classe classe, ECUE ecue, Enseignant enseignant, std::string jour, float heure_debut, float heure_fin);
    Creneau(int id, Salle salle, Classe classe, ECUE ecue, Enseignant enseignant, std::string jour, float heure_debut, float heure_fin);


    Salle getSalle() const;
    Classe getClasse() const;

    ECUE getECUE() const;


    Enseignant getEnseignant() const;


    std::string getJour() const;

    float getHeureDebut() const;

    float getHeureFin() const;

    float getDuree() const;

    void setSalle(Salle salle);

    void setClasse(Classe classe);


    void setECUE(ECUE ecue);


    void setEnseignant(Enseignant enseignant);


    void setJour(std::string jour);

    void setHeureDebut(float heure_debut);


    void setHeureFin(float heure_fin);


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
