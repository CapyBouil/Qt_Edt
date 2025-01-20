#include <iostream>

#include "Enseignant.h"
#include "etudiant.h"
#include "ecue.h"
#include "classe.h"
#include "salle.h"
#include "creneau.h"

#include <cassert>



void testEnseignant(){
    // Test du constructeur vide
    Enseignant enseignant1;
    std::cout << "Enseignant 1 (constructeur vide):" << std::endl;
    enseignant1.affiche();

    // Test du constructeur avec prénom, nom et ECUE
    Enseignant enseignant2("John", "Doe", "Mathematics");
    std::cout << "\nEnseignant 2 (constructeur avec prénom, nom, ECUE):" << std::endl;
    enseignant2.affiche();

    // Test du constructeur avec prénom, nom, id, et ECUE
    Enseignant enseignant3("Jane", "Smith", 101, "Physics");
    std::cout << "\nEnseignant 3 (constructeur avec prénom, nom, id, ECUE):" << std::endl;
    enseignant3.affiche();

    // Test des getters
    std::cout << "\nTest des getters pour enseignant3:" << std::endl;
    std::cout << "Nom: " << enseignant3.getNom() << std::endl;
    std::cout << "Prénom: " << enseignant3.getPrenom() << std::endl;
    std::cout << "ECUE: " << enseignant3.getEcue() << std::endl;

    // Test du setter pour ECUE
    enseignant3.setEcue("Chemistry");
    std::cout << "\nAprès modification de l'ECUE pour enseignant3:" << std::endl;
    enseignant3.affiche();
}

void testEtudiant(){
    // Test du constructeur vide
    Etudiant etudiant1;
    std::cout << "Etudiant 1 (constructeur vide):" << std::endl;
    etudiant1.affiche();

    // Test du constructeur avec prénom et nom
    Etudiant etudiant2("Alice", "Dupont");
    std::cout << "\nEtudiant 2 (constructeur avec prénom et nom):" << std::endl;
    etudiant2.affiche();

    // Test du constructeur avec prénom, nom et id
    Etudiant etudiant3("Bob", "Martin", 102);
    std::cout << "\nEtudiant 3 (constructeur avec prénom, nom et id):" << std::endl;
    etudiant3.affiche();

    // Test des getters
    std::cout << "\nTest des getters pour etudiant3:" << std::endl;
    std::cout << "Nom: " << etudiant3.getNom() << std::endl;
    std::cout << "Prénom: " << etudiant3.getPrenom() << std::endl;

}

void testECUE(){
    // Création des enseignants
    Enseignant enseignant1("Alice", "Dupont", "Mathematiques");
    Enseignant enseignant2("Bob", "Martin", "Physique");

    // Création d'un ECUE
    ECUE ecue1("Algebre", "Cours Magistral", 45.0);

    // Test des méthodes d'accès
    std::cout << "Nom de l'ECUE : " << ecue1.getNomECUE() << std::endl;
    std::cout << "Type de l'ECUE : " << ecue1.getTypeECUE() << std::endl;
    std::cout << "Nombre d'heures : " << ecue1.getNbHeures() << std::endl;

    // Modification des attributs de l'ECUE
    ecue1.setNomECUE("Geometrie");
    ecue1.setTypeECUE("TD");
    ecue1.setNomECUE(30.0);

    std::cout << "\nAprès modification : " << std::endl;
    std::cout << "Nom de l'ECUE : " << ecue1.getNomECUE() << std::endl;
    std::cout << "Type de l'ECUE : " << ecue1.getTypeECUE() << std::endl;
    std::cout << "Nombre d'heures : " << ecue1.getNbHeures() << std::endl;

    // Ajout des enseignants
    ecue1.ajouterEnseignant(enseignant1);
    ecue1.ajouterEnseignant(enseignant2);

    // Suppression d'un enseignant
    ecue1.supprimerEnseignant(enseignant1);

    // Affichage de l'ECUE
    ecue1.affiche();
}

void testClasse(){
    // Test du constructeur par défaut
    Classe classe1;
    std::cout << "Classe 1 Details (Constructeur par défaut):" << std::endl;
    classe1.affiche();

    // Test du constructeur avec nom de la classe
    Classe classe2("Informatique");
    std::cout << "\nClasse 2 Details (Constructeur avec nom de classe):" << std::endl;
    classe2.affiche();

    // Test du constructeur avec nom de la classe et ID
    Classe classe3("Mathématiques", 101);
    std::cout << "\nClasse 3 Details (Constructeur avec nom de classe et ID):" << std::endl;
    classe3.affiche();

    // Création d'étudiants pour les tests
    Etudiant etudiant1("Doe", "John", 12345); // Supposons que le constructeur Etudiant prend nom, prénom, et ID
    Etudiant etudiant2("Smith", "Jane", 67890);

    // Ajouter des étudiants à la classe
    classe3.ajouterEtudiant(etudiant1);
    classe3.ajouterEtudiant(etudiant2);

    std::cout << "\nClasse 3 après ajout d'étudiants:" << std::endl;
    classe3.affiche();

    // Supprimer un étudiant
    std::string nom = "Doe";
    std::string prenom = "John";
    classe3.supprimerEtudiant(nom, prenom);

    std::cout << "\nClasse 3 après suppression de John Doe:" << std::endl;
    classe3.affiche();

    // Tentative de suppression d'un étudiant non existant
    nom = "Doe";
    prenom = "Jane";
    classe3.supprimerEtudiant(nom, prenom);
}

void testSalle(){
    // Test du constructeur par défaut
    Salle salle1;
    std::cout << "Salle 1 Details (Constructeur par défaut):" << std::endl;
    salle1.affiche();

    // Test du constructeur avec étage et numéro
    Salle salle2(1, 101);
    std::cout << "\nSalle 2 Details (Constructeur avec étage et numéro):" << std::endl;
    salle2.affiche();

    // Test du constructeur avec étage, numéro et id
    Salle salle3(2, 202, 3);
    std::cout << "\nSalle 3 Details (Constructeur avec étage, numéro et id):" << std::endl;
    salle3.affiche();

    // Test des accesseurs
    std::cout << "\nTest des accesseurs pour Salle 3:" << std::endl;
    std::cout << "Etage: " << salle3.getEtage() << std::endl;
    std::cout << "Numéro: " << salle3.getNumero() << std::endl;
    std::cout << "Numéro Complet: " << salle3.getNumeroComplet() << std::endl;

}

void testCreneau(){
    // Création des objets nécessaires pour tester la classe Creneau
    Salle salle(2, 202, 3);
    Classe classe("E4", 101);
    ECUE ecue("Algebre", "Cours Magistral", 45.0);
    Enseignant enseignant("John", "Doe", "Mathematics");

    // Création d'une date (QDate) et des heures de début et de fin (QTime)
    QDate jour(2025, 1, 20); // 20 janvier 2025
    QTime heure_debut(10, 30); // 10h30
    QTime heure_fin(12, 00); // 12h00

    // Création d'un créneau avec les données précédentes
    Creneau creneau(salle, classe, ecue, enseignant, jour, heure_debut, heure_fin);

    // Affichage des informations sur le créneau
    creneau.affiche();

    // Modification d'un des attributs du créneau
    Classe nouvelle_classe("Classe B");
    creneau.setClasse(nouvelle_classe);

    // Affichage après modification
    std::cout << "\nAprès modification de la classe :\n";
}


int main() {
    //testEnseignant();
    //testEtudiant();
    //testECUE();
    //testClasse();
    //testSalle();
    testCreneau();
    return 0;
}


