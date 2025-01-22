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
    enseignant2.saveEnseignant();

    // Test du constructeur avec prénom, nom, id, et ECUE
    Enseignant enseignant3("Jane", "Smith", 101, "Physics");
    std::cout << "\nEnseignant 3 (constructeur avec prénom, nom, id, ECUE):" << std::endl;
    enseignant3.affiche();
    //enseignant3.saveEnseignant();

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
    Etudiant etudiant2("Mauricette", "Maurice");
    std::cout << "\nEtudiant 2 (constructeur avec prénom et nom):" << std::endl;
    etudiant2.affiche();
    etudiant2.saveEtudiant();

    // Test du constructeur avec prénom, nom et id
    Etudiant etudiant3("Bob", "Martin", 102);
    std::cout << "\nEtudiant 3 (constructeur avec prénom, nom et id):" << std::endl;
    etudiant3.affiche();
    //etudiant3.saveEtudiant();  //Il marche


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
    ecue1.saveECUE();
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
    classe2.saveClasse();

    // Test du constructeur avec nom de la classe et ID
    Classe classe3("Mathématiques", 101);
    std::cout << "\nClasse 3 Details (Constructeur avec nom de classe et ID):" << std::endl;
    classe3.affiche();
    //classe3.saveClasse();

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
    salle3.saveSalle();

    // Test des accesseurs
    std::cout << "\nTest des accesseurs pour Salle 3:" << std::endl;
    std::cout << "Etage: " << salle3.getEtage() << std::endl;
    std::cout << "Numéro: " << salle3.getNumero() << std::endl;
    std::cout << "Numéro Complet: " << salle3.getNumeroComplet() << std::endl;

}

void testCreneau(){
    // Créez des objets fictifs pour tester le constructeur
    Salle salle;
    Classe classe;
    ECUE ecue;
    Enseignant enseignant;

    // Test du constructeur avec l'ID généré automatiquement
    Creneau creneau1(salle, classe, ecue, enseignant, "Lundi", 8.0f, 10.0f);
    std::cout << "Test du constructeur avec ID généré automatiquement" << std::endl;
    assert(creneau1.getHeureDebut() == 8.0f);
    assert(creneau1.getHeureFin() == 10.0f);
    std::cout << "Test réussi !" << std::endl;

    // Test du constructeur avec un ID donné
    Creneau creneau2(5, salle, classe, ecue, enseignant, "Mardi", 9.0f, 11.0f);
    std::cout << "Test du constructeur avec un ID donné" << std::endl;
    assert(creneau2.getHeureDebut() == 9.0f);
    assert(creneau2.getHeureFin() == 11.0f);
    std::cout << "Test réussi !" << std::endl;

    // Tester les accesseurs
    std::cout << "Test des accesseurs" << std::endl;
    assert(creneau2.getJour() == "Mardi");
    assert(creneau2.getHeureDebut() == 9.0f);
    assert(creneau2.getHeureFin() == 11.0f);
    assert(creneau2.getDuree() == 2.0f);  // Duree = HeureFin - HeureDebut
    std::cout << "Test réussi !" << std::endl;

    // Tester les mutateurs
    std::cout << "Test des mutateurs" << std::endl;
    creneau2.setHeureDebut(10.0f);
    creneau2.setHeureFin(12.0f);
    assert(creneau2.getHeureDebut() == 10.0f);
    assert(creneau2.getHeureFin() == 12.0f);
    assert(creneau2.getDuree() == 2.0f);
    std::cout << "Test réussi !" << std::endl;

    // Tester la suppression de la salle et de la classe
    std::cout << "Test de la suppression de la salle et de la classe" << std::endl;
    creneau2.supprimeSalle();
    creneau2.supprimeClasse();
    creneau2.supprimeECUE();
    creneau2.supprimeEnseignant();
    std::cout << "Test réussi !" << std::endl;


    // Vérifier la fonction getMaxId
    Creneau creneau3(salle, classe, ecue, enseignant, "Lundi", 8.0, 10.0);  // Création d'un créneau
    std::cout << "Test de getMaxId" << std::endl;
    int maxId = creneau3.getMaxId();  // Utilisation de l'objet creneau pour appeler getMaxId
    assert(maxId >= 0);  // L'ID doit être un nombre positif
    std::cout << "Max ID dans le fichier : " << maxId << std::endl;
    std::cout << "Test réussi !" << std::endl;

    std::cout << "Tous les tests ont réussi !" << std::endl;
}


int main() {
    //testEnseignant();
    //testEtudiant();
    //testECUE();
    //testClasse();
    testSalle();
    //testCreneau();
    return 0;
}


