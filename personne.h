#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <iostream>

#include <Qfile>
#include <QTextStream>
#include <QDir>

class Personne {
private:
    std::string prenom;
    std::string nom;
    int id;

public:
    // Constructeurs
    Personne();
    Personne(std::string prenom, std::string nom);
    Personne(std::string prenom, std::string nom, int id);

    // Getters
    std::string getNom() const;
    std::string getPrenom() const;
    int getId() const;

    //Méthode AFFICHE
    void affiche();

    //Méthode MaxiD
    int getMaxId();
};

#endif
