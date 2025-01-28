#include "tests.h"

Tests::Tests(){

}

void Tests::testEnseignant(){
    // Test du constructeur vide
    Enseignant enseignant1;
    std::cout << "Enseignant 1 (constructeur vide):" << std::endl;
    enseignant1.affiche();

    // Test du constructeur avec prenom, nom et ECUE
    Enseignant enseignant2("John", "Doe");
    std::cout << "\nEnseignant 2 (constructeur avec prénom, nom, ECUE):" << std::endl;
    enseignant2.affiche();

    // Test du constructeur avec prénom, nom, id, et ECUE
    Enseignant enseignant3("Jane", "Smith", 101);
    std::cout << "\nEnseignant 3 (constructeur avec prenom, nom, id, ECUE):" << std::endl;
    enseignant3.affiche();

    // Test des getters
    std::cout << "\nTest des getters pour enseignant3:" << std::endl;
    std::cout << "Nom: " << enseignant3.getNom() << std::endl;
    std::cout << "Prenom: " << enseignant3.getPrenom() << std::endl;

    std::cout << "\nAprès modification de l'ECUE pour enseignant3:" << std::endl;
    enseignant3.affiche();
}

void Tests::testEtudiant(){
    // Test du constructeur vide
    Etudiant etudiant1;
    std::cout << "Etudiant 1 (constructeur vide):" << std::endl;
    etudiant1.affiche();

    // Test du constructeur avec prénom et nom
    Etudiant etudiant2("Alice", "Dupont");
    std::cout << "\nEtudiant 2 (constructeur avec prenom et nom):" << std::endl;
    etudiant2.affiche();

    // Test du constructeur avec prénom, nom et id
    Etudiant etudiant3("Bob", "Martin", 102);
    std::cout << "\nEtudiant 3 (constructeur avec prenom, nom et id):" << std::endl;
    etudiant3.affiche();

    // Test des getters
    std::cout << "\nTest des getters pour etudiant3:" << std::endl;
    std::cout << "Nom: " << etudiant3.getNom() << std::endl;
    std::cout << "Prénom: " << etudiant3.getPrenom() << std::endl;

}

void Tests::testECUE(){
    // Création des enseignants
    Enseignant enseignant1("Alice", "Dupont");
    Enseignant enseignant2("Bob", "Martin");

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

void Tests::testClasse(){
    // Test du constructeur par défaut
    Classe classe1;
    std::cout << "Classe 1 Details (Constructeur par defaut):" << std::endl;
    classe1.affiche();

    // Test du constructeur avec nom de la classe
    Classe classe2("Informatique");
    std::cout << "\nClasse 2 Details (Constructeur avec nom de classe):" << std::endl;
    classe2.affiche();

    // Test du constructeur avec nom de la classe et ID
    Classe classe3("Mathematiques", 101);
    std::cout << "\nClasse 3 Details (Constructeur avec nom de classe et ID):" << std::endl;
    classe3.affiche();

    // Création d'étudiants pour les tests
    Etudiant etudiant1("Doe", "John", 12345); // Supposons que le constructeur Etudiant prend nom, prenom, et ID
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

void Tests::testSalle(){
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

void Tests::testCreneau(){
    // Création des objets nécessaires pour tester la classe Creneau
    Salle salle(2, 202, 3);
    Classe classe("E4e A", 101);
    ECUE ecue("Algebre", "Cours Magistral", 45.0);
    Enseignant enseignant("John", "Doe");

    // Création d'une date (QDate) et des heures de début et de fin (QTime)
    QDate jour(2025, 1, 20); // 20 janvier 2025
    QTime heure_debut(10, 30); // 10h30
    QTime heure_fin(12, 00); // 12h00

    // Création d'un créneau avec les données précédentes
    Creneau creneau(salle, classe, ecue, enseignant, jour, heure_debut, heure_fin);

    // Affichage des informations sur le créneau
    creneau.affiche();

    // Modification d'un des attributs du créneau
    Classe nouvelle_classe("E4e B");
    creneau.setClasse(nouvelle_classe);

    // Affichage après modification
    std::cout << "\nAprès modification de la classe :\n";
}

QDate Tests::stringToQDate(const std::string& dateStr) {
    QString dateQString = QString::fromStdString(dateStr); // Convertir std::string en QString
    QDate date = QDate::fromString(dateQString, "yyyy-MM-dd");
    if (!date.isValid()) {
        std::cerr << "Format de date invalide : " << dateStr << std::endl;
        return QDate(); // Retourne une date invalide
    }
    return date;
}

QTime Tests::floatToQTime(float heure) {
    int heures = static_cast<int>(heure);  // Partie entière pour les heures
    int minutes = static_cast<int>((heure - heures) * 60);  // Partie décimale pour les minutes
    return QTime(heures, minutes);
}

void Tests::testEdt() {
    // Création des objets nécessaires pour tester la classe Creneau
    Salle salle(2, 202, 3);
    Classe classe("Mathematiques", 101);
    ECUE ecue("Mathematiques", "Cours Magistral", 45.0);
    Enseignant enseignant("John", "Doe");

    // Création de quelques créneaux
    Creneau creneau1(salle, classe, ecue, enseignant, stringToQDate("2025-01-21"), floatToQTime(9.0f), floatToQTime(12.0f));
    Creneau creneau2(salle, classe, ecue, enseignant, stringToQDate("2025-01-20"), floatToQTime(14.0f), floatToQTime(16.0f));
    Creneau creneau3(salle, classe, ecue, enseignant, stringToQDate("2025-01-20"), floatToQTime(10.0f), floatToQTime(12.0f));

    // Création d'un emploi du temps
    EmploiDuTemps edt;

    // Ajout des créneaux
    std::cout << "Ajout des créneaux à l'emploi du temps : " << std::endl;
    edt.ajouterCreneau(creneau1);
    edt.ajouterCreneau(creneau2);
    edt.ajouterCreneau(creneau3);

    // Affichage de l'emploi du temps
    std::cout << "Affichage de l'emploi du temps après ajout : " << std::endl;
    edt.affiche();

    // Suppression d'un créneau
    std::cout << "\nSuppression du créneau avec ID 2 (2025-01-20, 14:00 - 16:00) : " << std::endl;
    edt.supprimerCreneau(creneau2.getId());

    // Affichage de l'emploi du temps après suppression
    std::cout << "\nAffichage de l'emploi du temps après suppression : " << std::endl;
    edt.affiche();

    // Tentative de suppression d'un créneau avec un ID non existant
    std::cout << "\nTentative de suppression d'un créneau avec un ID non existant (ID: 999) : " << std::endl;
    edt.supprimerCreneau(999);
}

void Tests::testFactory() {
    // Instanciation de Factory
    //Factory factory;

    // Création de quelques objets
    Salle salle(2, 204);
    Classe classe("E4");
    ECUE ecue("Factory", "Cours Magistral", 45.0);
    Enseignant enseignant("Factory", "Doe");
    Etudiant etudiant("Factory", "Martin");
    Creneau creneau(salle, classe, ecue, enseignant, stringToQDate("2025-01-21"), floatToQTime(9.0f), floatToQTime(12.0f));


    // Sauvegarde des objets dans les fichiers correspondants
    try {
        Factory::saveEtudiant(etudiant);
        std::cout << "Etudiant enregistre avec succes." << std::endl;

        Factory::saveEnseignant(enseignant);
        std::cout << "Enseignant enregistre avec succes." << std::endl;

        Factory::saveClasse(classe);
        std::cout << "Classe enregistree avec succes." << std::endl;

        Factory::saveECUE(ecue);
        std::cout << "ECUE enregistre avec succes." << std::endl;

        Factory::saveSalle(salle);
        std::cout << "Salle enregistree avec succes." << std::endl;

        Factory::saveCreneau(creneau);
        std::cout << "Creneau enregistre avec succes." << std::endl;


        Factory::loadEtudiant();
        Factory::loadEnseignant();
        Factory::loadClasse();
        Factory::loadSalle();
        Factory::loadEcue();
        Factory::loadCreneau();


    } catch (std::exception& e) {
        std::cerr << "Erreur lors de l'enregistrement : " << e.what() << std::endl;
    }
}
