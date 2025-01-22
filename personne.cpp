#include "Personne.h"

// Constructeurs
Personne::Personne() {
    prenom = "";
    nom = "";
    id= 0;
}

Personne::Personne(std::string prenom, std::string nom) {
    this->prenom = prenom;
    this->nom = nom;
    //max=maxId+1
    //this->id=max;
}
Personne::Personne(std::string prenom, std::string nom,int id){
    this->prenom = prenom;
    this->nom = nom;
    this->id = id;
}

// Getters
std::string Personne::getNom() const {
    return nom;
}

std::string Personne::getPrenom() const {
    return prenom;
}

//int Personne:getId()
//{}

//Méthode AFFICHE
void Personne::affiche() {
    std::cout << "Nom: " << nom << "Prenom: " << prenom << std::endl;
}

int Personne::getMaxId(){
    int maxIdEtudiant = 0;
    int maxIdEnseignant = 0;

    QFile fileEtudiant("../../data/Etudiant.csv");
    QFile fileEnseignant("../../data/Enseignant.csv");
    fileEtudiant.open(QIODevice::ReadOnly | QIODevice::Text );
    fileEnseignant.open(QIODevice::ReadOnly | QIODevice::Text );

    QTextStream tsEtudiant(&fileEtudiant);
    QTextStream tsEnseignant(&fileEnseignant);

    QString lineEtudiant = tsEtudiant.readLine(); // en-tête
    while(!tsEtudiant.atEnd()){
        lineEtudiant = tsEtudiant.readLine();
        QStringList liste = lineEtudiant.split(";");
        if(liste[0].toInt()>maxIdEtudiant){
            maxIdEtudiant = liste[0].toInt();
        }
    }

    QString lineEnseignant = tsEnseignant.readLine();
    while(!tsEnseignant.atEnd()){
        lineEnseignant = tsEnseignant.readLine();
        QStringList liste = lineEnseignant.split(";");
        if(liste[0].toInt()>maxIdEnseignant){
            maxIdEnseignant = liste[0].toInt();
        }
    }

    fileEtudiant.close();
    fileEnseignant.close();

    if(maxIdEtudiant>maxIdEnseignant){
        return maxIdEtudiant;
    }else{
        return maxIdEnseignant;
    }
}
