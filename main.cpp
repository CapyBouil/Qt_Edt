#include <iostream>
#include "Enseignant.h"
#include "etudiant.h"


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


int main() {
    testEnseignant();
    testEtudiant();
    return 0;
}


