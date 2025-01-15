#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "Personne.h"
#include <string>

class Etudiant : public Personne {
private:
    
public:
    // Constructeurs
    Etudiant();
    Etudiant(std::string prenom, std::string nom);
    Etudiant(std::string prenom, std::string nom,int id);
    
    
    // Getters
    std::string Etudiant::getNom() const {
        return Personne::getNom();}
    
    std::string Etudiant::getPrenom() const {
        return Personne::getPrenom();}
    
    // Méthode affiche
    void affiche() override;
};

#endif