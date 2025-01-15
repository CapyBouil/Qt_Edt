#include "creneau.h"


// Constructeurs
Creneau::Creneau()
{
    this->id = getMaxId() + 1;
}

Creneau::Creneau(Salle salle, Classe classe, ECUE ecue, Enseignant enseignant, std::string jour, float heure_debut, float heure_fin)
{
    this->id = getMaxId() + 1;
    this->salle = salle;
    this->classe = classe;
    this->ecue = ecue;
    this->enseignant = enseignant;
    this->jour = jour;
    this->heure_debut = heure_debut;
    this->heure_fin = heure_fin;
    setDuree();
}

Creneau::Creneau(int id, Salle salle, Classe classe, ECUE ecue, Enseignant enseignant, std::string jour, float heure_debut, float heure_fin)
{
    this->id = id;
    this->salle = salle;
    this->classe = classe;
    this->ecue = ecue;
    this->enseignant = enseignant;
    this->jour = jour;
    this->heure_debut = heure_debut;
    this->heure_fin = heure_fin;
    setDuree();
}

// Accesseurs
Salle Creneau::getSalle() const
{
    return salle; // Retourner la salle du créneau
}

Classe Creneau::getClasse() const
{
    return classe; // Retourner la classe du créneau
}
ECUE Creneau::getECUE() const
{
    return ecue; // Retourner l'ECUE du créneau
}

Enseignant Creneau::getEnseignant() const
{
    return enseignant; // Retourner l'enseignant du créneau
}

std::string Creneau::getJour() const
{
    return jour; // Retourner le jour du créneau
}

float Creneau::getHeureDebut() const
{
    return heure_debut; // Retourner l'heure de début du créneau
}

float Creneau::getHeureFin() const
{
    return heure_fin; // Retourner l'heure de fin du créneau
}

float Creneau::getDuree() const
{
    return duree; // Retourner la durée du créneau
}

// Mutateurs
void Creneau::setSalle(Salle salle)
{
    this->salle = salle; // Assigner la nouvelle salle
}

void Creneau::setClasse(Classe classe)
{
    this->classe = classe; // Assigner la nouvelle classe
}

void Creneau::setECUE(ECUE ecue)
{
    this->ecue = ecue; // Assigner le nouvel ecue
}


void Creneau::setEnseignant(Enseignant enseignant)
{
    this->enseignant = enseignant; // Assigner le nouvel enseignant
}

void Creneau::setJour(std::string jour)
{
    this->jour = jour; // Assigner le nouveau jour
}


void Creneau::setHeureDebut(float heure_debut)
{
    if (heure_debut >= 8.0 && heure_debut < this->heure_fin) { // Conditions de modification
        this->heure_debut = heure_debut; // Assigner la nouvelle heure de début
        setDuree(); // Met à jour la durée du créneau
    } else {
        std::cerr << "Erreur: L'heure de début doit être supérieure ou égale à 8h et inférieure à l'heure de fin." << std::endl;
    }
}


void Creneau::setHeureFin(float heure_fin)
{
    if (heure_fin > this->heure_debut && heure_fin <= 18.0) { // Conditions de modification
        this->heure_fin = heure_fin; // Assigner la nouvelle heure de fin
        setDuree(); // Met à jour la durée du créneau
    } else {
        std::cerr << "Erreur: L'heure de fin doit être après l'heure de début et inférieure ou égale à 18h." << std::endl;
    }
}

void Creneau::setDuree()
{
    this->duree = heure_fin - heure_debut; // Calculer la durée du créneau
}

// Methodes
void Creneau::affiche()
{
    salle.affiche();
    classe.affiche();
    ecue.affiche();
    enseignant.affiche();
    std::cout << "Jour : " << getJour() << std::endl;
    std::cout << "Heure de debut : " << getHeureDebut() << std::endl;
    std::cout << "Heure de fin : " << getHeureFin() << std::endl;
    std::cout << "Duree : " << getDuree() << std::endl;
}

void Creneau::ajouteSalle(Salle salle)
{
    this->salle = salle;
}

void Creneau::supprimeSalle()
{
    this->salle = NULL;
}

void Creneau::ajouteClasse(Classe classe)
{
    this->classe = classe;
}

void Creneau::supprimeClasse()
{
    this->classe = NULL;
}

void Creneau::ajouteECUE(ECUE ecue)
{
    this->ecue = ecue;
}

void Creneau::supprimeECUE()
{
    this->ecue = NULL;
}

void Creneau::ajouteEnseignant(Enseignant enseignant)
{
    this->enseignant = enseignant;
}

void Creneau::supprimeEnseignant()
{
    this->enseignant = NULL;
}

int getMaxId()
{
    #include <fstream>
    #include <string>

    int getMaxId()
    {
        std::ifstream file("data.csv");
        if (!file.is_open()) {
            std::cerr << "Erreur: Impossible d'ouvrir le fichier." << std::endl;
            return -1;
        }

        std::string line;
        int maxId = 0;
        while (std::getline(file, line)) {
            // Do nothing, just read till the last line
        }
        if (!line.empty()) {
            // Assuming the ID is the first value in the CSV line
            maxId = std::stoi(line.substr(0, line.find(',')));
        }

        file.close();
        return maxId;
    }
}