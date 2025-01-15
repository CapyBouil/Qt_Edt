#ifndef CRENEAU_H
#define CRENEAU_H

#include "salle.h"
#include "classe.h"
#include "ecue.h"
#include "enseignant.h"
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
        /**
         * @brief Calcule et définit la durée du créneau en heures.
         * 
         * La durée est calculée en soustrayant l'heure de début de l'heure de fin.
         * Cette méthode est appelée automatiquement lors de la définition des heures de début et de fin.
         */
        void setDuree();

    public:
        /**
         * @brief Constructeur par défaut de la classe Creneau.
         */
        Creneau();

        /**
         * @brief Constructeur de la classe Creneau.
         * 
         * @param salle La salle associée au créneau.
         * @param classe La classe associée au créneau.
         * @param ecue L'ECUE associé au créneau.
         * @param enseignant L'enseignant associé au créneau.
         * @param jour Le jour du créneau au format "YYYY-MM-DD".
         * @param heure_debut L'heure de début du créneau au format HH.MM (24 heures).
         * @param heure_fin L'heure de fin du créneau au format HH.MM (24 heures).
         */
        Creneau(Salle salle, Classe classe, ECUE ecue, Enseignant enseignant, std::string jour, float heure_debut, float heure_fin);

        /**
         * @brief Constructeur de la classe Creneau avec un identifiant.
         * 
         * @param id L'identifiant du créneau.
         * @param salle La salle associée au créneau.
         * @param classe La classe associée au créneau.
         * @param ecue L'ECUE associé au créneau.
         * @param enseignant L'enseignant associé au créneau.
         * @param jour Le jour du créneau au format "YYYY-MM-DD".
         * @param heure_debut L'heure de début du créneau au format HH.MM (24 heures).
         * @param heure_fin L'heure de fin du créneau au format HH.MM (24 heures).
         */
        Creneau(int id, Salle salle, Classe classe, ECUE ecue, Enseignant enseignant, std::string jour, float heure_debut, float heure_fin);

        /**
         * @brief Obtient la salle associée au créneau.
         * @return La salle associée au créneau.
         */
        Salle getSalle() const;

        /**
         * @brief Obtient la classe associée au créneau.
         * @return La classe associée au créneau.
         */
        Classe getClasse() const;

        /**
         * @brief Obtient l'ECUE associé au créneau.
         * @return L'ECUE associé au créneau.
         */
        ECUE getECUE() const;

        /**
         * @brief Obtient l'enseignant associé au créneau.
         * @return L'enseignant associé au créneau.
         */
        Enseignant getEnseignant() const;

        /**
         * @brief Obtient le jour du créneau.
         * @return Le jour du créneau au format "YYYY-MM-DD".
         */
        std::string getJour() const;

        /**
         * @brief Obtient l'heure de début du créneau.
         * @return L'heure de début du créneau au format HH.MM (24 heures).
         */
        float getHeureDebut() const;

        /**
         * @brief Obtient l'heure de fin du créneau.
         * @return L'heure de fin du créneau au format HH.MM (24 heures).
         */
        float getHeureFin() const;

        /**
         * @brief Obtient la durée du créneau.
         * @return La durée du créneau en heures.
         */
        float getDuree() const;

        /**
         * @brief Définit la salle associée au créneau.
         * @param salle La salle à associer au créneau.
         */
        void setSalle(Salle salle);

        /**
         * @brief Définit la classe associée au créneau.
         * @param classe La classe à associer au créneau.
         */
        void setClasse(Classe classe);

        /**
         * @brief Définit l'ECUE associé au créneau.
         * @param ecue L'ECUE à associer au créneau.
         */
        void setECUE(ECUE ecue);

        /**
         * @brief Définit l'enseignant associé au créneau.
         * @param enseignant L'enseignant à associer au créneau.
         */
        void setEnseignant(Enseignant enseignant);

        /**
         * @brief Définit le jour du créneau.
         * @param jour Le jour du créneau au format "YYYY-MM-DD".
         */
        void setJour(std::string jour);

        /**
         * @brief Définit l'heure de début du créneau.
         * @param heure_debut L'heure de début du créneau au format HH.MM (24 heures).
         */
        void setHeureDebut(float heure_debut);

        /**
         * @brief Définit l'heure de fin du créneau.
         * @param heure_fin L'heure de fin du créneau au format HH.MM (24 heures).
         */
        void setHeureFin(float heure_fin);

        /**
         * @brief Affiche les informations du créneau.
         */
        void affiche();

        /**
         * @brief Ajoute une salle au créneau.
         * @param salle La salle à ajouter.
         */
        void ajouteSalle(Salle salle);

        /**
         * @brief Supprime la salle associée au créneau.
         */
        void supprimeSalle();

        /**
         * @brief Ajoute une classe au créneau.
         * @param classe La classe à ajouter.
         */
        void ajouteClasse(Classe classe);

        /**
         * @brief Supprime la classe associée au créneau.
         */
        void supprimeClasse();

        /**
         * @brief Ajoute un ECUE au créneau.
         * @param ecue L'ECUE à ajouter.
         */
        void ajouteECUE(ECUE ecue);

        /**
         * @brief Supprime l'ECUE associé au créneau.
         */
        void supprimeECUE();

        /**
         * @brief Ajoute un enseignant au créneau.
         * @param enseignant L'enseignant à ajouter.
         */
        void ajouteEnseignant(Enseignant enseignant);

        /**
         * @brief Supprime l'enseignant associé au créneau.
         */
        void supprimeEnseignant();

        /**
         * @brief Obtient l'identifiant maximal des créneaux.
         * @return L'identifiant maximal des créneaux.
         */
        int getMaxId();
};

#endif