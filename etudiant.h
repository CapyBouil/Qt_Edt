#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "Personne.h"
#include <string>

#include <Qfile>
#include <QTextStream>
#include <QDir>

class Etudiant : public Personne {
private:

public:
    // Constructeurs
    Etudiant();
    Etudiant(std::string prenom, std::string nom);
    Etudiant(std::string prenom, std::string nom,int id);


    // Getters
    std::string getNom() const;

    std::string getPrenom() const;

    // Méthode affiche
    void affiche();
    static Etudiant etudiant[];
    void saveEtudiant();
};

#endif
