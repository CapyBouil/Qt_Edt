#ifndef ENSEIGNANT_H
#define ENSEIGNANT_H

#include "Personne.h"

#include <string>

#include <Qfile>
#include <QTextStream>
#include <QDir>

class Enseignant : public Personne {
private:

public:
    //Constructeur
    Enseignant();
    // Constructeur avec trois paramètres
    //Enseignant(std::string prenom, std::string nom);

    Enseignant(std::string nom, std::string prenom);

    Enseignant(std::string prenom, std::string nom,int id);

    // Accesseurs
    std::string getNom() const;
    std::string getPrenom() const ;

    // Méthode AFFICHE
    void affiche() const;

    static Enseignant enseignant[];
};


#endif
