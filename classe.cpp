#include "Classe.h"

Classe::Classe() {
    //this->id;
    this->nomClasse = "";
}

Classe::Classe(std::string nomClasse)
{
    this->nomClasse = nomClasse;
    //this->id;
}

Classe::Classe(std::string nomClasse, int id)
{
    this->nomClasse = nomClasse;
    this->id = id;
}

int Classe::getId()
{
    return this->id;
}

std::string Classe::getNomClasse()
{
    return this->nomClasse;
}

void Classe::ajouterEtudiant(Etudiant& etudiant)
{
    etudiants.push_back(etudiant);
}

void Classe::supprimerEtudiant(std::string& nom, std::string& prenom)
{
    for(auto liste = etudiants.begin(); liste != etudiants.end(); ++liste)
    {
        if (liste->getNom() == nom && liste->getPrenom() == prenom)
        {
            etudiants.erase(liste);
            std::cout << "Etudiant " << nom << " " << prenom << " supprimé." << std::endl;
            return;
        }
    }
    std::cout << "Etudiant non trouvé: " << nom << " " << prenom << std::endl;
}

void Classe::afficherClasse()
{
    std::cout << "Classe: " << nomClasse << " (ID: " << id << ")/n";
    if (etudiants.empty())
    {
        std::cout << "Aucun étudiant dans la classe" << std::endl;
    } else
    {
        for (auto liste = etudiants.begin(); liste != etudiants.end(); liste++)
        {
            liste->affiche();
        }
    }
}
