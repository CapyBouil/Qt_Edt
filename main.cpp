#include <iostream>
#include "enseignant.h"
#include "etudiant.h"
#include "classe.h"
#include "salle.h"

int main() {
    // Test enseignant


    // Test avec le constructeur par defaut
    Enseignant enseignant1;
    std::cout << "Test Enseignant 1 (par defaut) : " << std::endl;
    enseignant1.affiche();

    // Test avec le constructeur avec prenom, nom et ecue
    Enseignant enseignant2("Jean", "Dupont", "Mathematiques");
    std::cout << "\nTest Enseignant 2 (avec prenom, nom et ECUE) : " << std::endl;
    enseignant2.affiche();

    // Test avec le constructeur avec prenom, nom, id et ecue
    Enseignant enseignant3("Marie", "Durand", 12345, "Physique");
    std::cout << "\nTest Enseignant 3 (avec prenom, nom, ID et ECUE) : " << std::endl;
    enseignant3.affiche();

    // Test du setter et getter pour ECUE
    std::cout << "\nModification de l'ECUE de l'enseignant 3." << std::endl;
    enseignant3.setEcue("Chimie");
    std::cout << "Nouvelle ECUE de l'enseignant 3 : " << enseignant3.getEcue() << std::endl;

    // Affichage apres modification
    enseignant3.affiche();


    // Test etudiant

    Etudiant etudiant1;
    std::cout << "Test Etudiant 1 (par defaut) : " << std::endl;
    etudiant1.affiche();

    // Test avec le constructeur avec prenom et nom
    Etudiant etudiant2("Alice", "Martin");
    std::cout << "\nTest Etudiant 2 (avec prenom et nom) : " << std::endl;
    etudiant2.affiche();

    // Test avec le constructeur avec prenom, nom et ID
    Etudiant etudiant3("Bob", "Dupont", 12345);
    std::cout << "\nTest Etudiant 3 (avec prenom, nom et ID) : " << std::endl;
    etudiant3.affiche();

    // Test de l'attribut annee
    std::cout << "\nModification de l'annee de l'etudiant 3." << std::endl;
    etudiant3.changeAnnee(); // Si tu as un setter pour l'annee, sinon change l'attribut directement
    std::cout << "Nouvelle annee de l'etudiant 3 : " << etudiant3.getAnnee() << std::endl;

    // Affichage apres modification
    etudiant3.affiche();

    // Test classe
    // Creation d'une classe

    Classe classe1("Informatique", 101);

    // Ajout des etudiants à la classe
    classe1.ajouterEtudiant(etudiant2);
    classe1.ajouterEtudiant(etudiant3);

    // Affichage de la classe avec les etudiants
    std::cout << "\nAffichage de la classe apres ajout des etudiants:" << std::endl;
    classe1.afficherClasse();

    // Suppression d'un etudiant
    std::cout << "\nSuppression d'un etudiant:" << std::endl;
    std::string nom = "Dupont";
    std::string prenom = "Bob";
    classe1.supprimerEtudiant(nom, prenom);

    // Affichage apres suppression
    std::cout << "\nAffichage de la classe apres suppression d'un etudiant:" << std::endl;
    classe1.afficherClasse();

    // Suppression d'un etudiant qui n'existe pas
    std::cout << "\nSuppression d'un etudiant inexistant:" << std::endl;
    nom = "Smith";
    prenom = "John";
    classe1.supprimerEtudiant(nom, prenom);

    // Test salle
    // Test avec le constructeur par defaut
    Salle salle1;
    std::cout << "Test Salle 1 (par defaut) : ";
    salle1.affiche();  // Salle 0

    // Test avec le constructeur avec etage et numero
    Salle salle2(2, 15);
    std::cout << "\nTest Salle 2 (avec etage et numero) : ";
    salle2.affiche();  // Salle 215

    // Test avec le constructeur avec etage, numero et ID
    Salle salle3(3, 22, 101);
    std::cout << "\nTest Salle 3 (avec etage, numero et ID) : ";
    salle3.affiche();  // Salle 322

    // Affichage du numero complet de la salle 3
    std::cout << "\nNumero complet de la salle 3 : " << salle3.getNumeroComplet() << std::endl;

    // Affichage de l'ID de la salle 3
    std::cout << "ID de la salle 3 : " << salle3.getId() << std::endl;

    return 0;
}
