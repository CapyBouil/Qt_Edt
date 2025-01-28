#include "mainwindow.h"
#include <QDebug>

// Constructeur
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("Emploi du temps");
    this->setGeometry(0,0,800,600);
    this->init_composants();
    this->init_layout();
    this->init_slots();
}

// Initialisations
void MainWindow::init_composants(void)
{
    // Séparer la fenetre en 2 parties (droite et gauche)
    this->splitter = new QSplitter(this);
    this->splitter->setStretchFactor(0, 1);
    this->splitter->setStretchFactor(1, 2);

    // Créer les widgets gauche et droit
    this->leftWidget = new QWidget(this);
    this->rightWidget = new QWidget(this);

    // Créer les layouts gauche et droit
    this->leftLayout = new QVBoxLayout();
    this->rightLayout = new QVBoxLayout();

    // Créer les onglets de gauche
    this->tabWidget = new QTabWidget();

    // Layout pour les informations des onglets
    this->layout_enseignants = new QVBoxLayout();
    this->layout_classes = new QVBoxLayout();
    this->layout_ecue = new QVBoxLayout();
    this->layout_salles = new QVBoxLayout();
    this->layout_etudiants = new QVBoxLayout();

    // Layout pour les boutons des onglets
    this->bouton_layout_enseignants = new QHBoxLayout();
    this->bouton_layout_classes = new QHBoxLayout();
    this->bouton_layout_ecue = new QHBoxLayout();
    this->bouton_layout_salles = new QHBoxLayout();
    this->bouton_layout_etudiants = new QHBoxLayout();

    // Liste et boutons pour les enseignants
    this->liste_enseignants = new QListWidget();
    this->bouton_ajouter_enseignant = new QPushButton("Ajouter un enseignant");
    this->bouton_modifier_enseignant = new QPushButton("Modifier l'enseignant");
    this->bouton_supprimer_enseignant = new QPushButton("Supprimer l'enseignant");

    // Liste et boutons pour les classes
    this->liste_classes = new QListWidget();
    this->bouton_ajouter_classe = new QPushButton("Ajouter une classe");
    this->bouton_modifier_classe = new QPushButton("Modifier la classe");
    this->bouton_supprimer_classe = new QPushButton("Supprimer la classe");

    // Liste et boutons pour les ECUE
    this->liste_ecue = new QListWidget();
    this->bouton_ajouter_ecue = new QPushButton("Ajouter une ECUE");
    this->bouton_modifier_ecue = new QPushButton("Modifier l'ECUE");
    this->bouton_supprimer_ecue = new QPushButton("Supprimer l'ECUE");

    // Liste et boutons pour les salles
    this->liste_salles = new QListWidget();
    this->bouton_ajouter_salle = new QPushButton("Ajouter une salle");
    this->bouton_modifier_salle = new QPushButton("Modifier la salle");
    this->bouton_supprimer_salle = new QPushButton("Supprimer la salle");

    // Liste et boutons pour les salles
    this->liste_etudiants = new QListWidget();
    this->bouton_ajouter_etudiant = new QPushButton("Ajouter etudiant");
    this->bouton_modifier_etudiant = new QPushButton("Modifier etudiant");
    this->bouton_supprimer_etudiant = new QPushButton("Supprimer edudiant");

    // Emplacement pour une image dans le coin supérieur droit
    this->imageLabel = new QLabel();
    this->imageLabel->setAlignment(Qt::AlignTop | Qt::AlignRight);

    // Layout pour les informations
    this->layout_infos = new QVBoxLayout();

    // Calendrier pour les emplois du temps
    this->calendrier = new QTableWidget(11,5);
    this->calendrier->setHorizontalHeaderLabels({"Lundi","Mardi","Mercredi","Jeudi","Vendredi"});
    this->calendrier->setVerticalHeaderLabels({"8h","9h","10h","11h","12h","13h","14h","15h","16h","17h","18h"});

    // Boutons pour les creneaux
    this->bouton_ajouter_creneau = new QPushButton("Ajouter un créneau");
    this->bouton_modifier_creneau = new QPushButton("Modifier le créneau");
    this->bouton_supprimer_creneau = new QPushButton("Supprimer le créneau");

}

void MainWindow::init_layout(void)
{
    qDebug() << "MainWindow::init_layout() - Début de la fonction";

    // Ajouter la séparation entre les 2 parties
    this->setCentralWidget(this->splitter);

    qDebug() << "MainWindow::init_layout() - setCentralWidget(this->splitter)";

    // Ajouter les widgets gauche et droit
    this->splitter->addWidget(this->leftWidget);
    qDebug() << "MainWindow::init_layout() - splitter->addWidget(this->leftWidget)";
    this->splitter->addWidget(this->rightWidget);
    qDebug() << "MainWindow::init_layout() - splitter->addWidget(this->rightWidget)";

    // Ajouter les layouts gauche et droit
    this->leftWidget->setLayout(this->leftLayout);
    qDebug() << "MainWindow::init_layout() - leftWidget->setLayout(this->leftLayout)";
    this->rightWidget->setLayout(this->rightLayout);
    qDebug() << "MainWindow::init_layout() - rightWidget->setLayout(this->rightLayout)";

    // Créer des widgets pour les onglets
    QWidget* enseignantTab = new QWidget();
    qDebug() << "MainWindow::init_layout() - QWidget* enseignantTab = new QWidget()";
    QWidget* classeTab = new QWidget();
    qDebug() << "MainWindow::init_layout() - QWidget* classeTab = new QWidget()";
    QWidget* ecueTab = new QWidget();
    qDebug() << "MainWindow::init_layout() - QWidget* ecueTab = new QWidget()";
    QWidget* salleTab = new QWidget();
    qDebug() << "MainWindow::init_layout() - QWidget* salleTab = new QWidget()";
    QWidget* etudiantTab = new QWidget();
    qDebug() << "MainWindow::init_layout() - QWidget* etudiantTab = new QWidget()";

    // Ajouter les onglets à gauche
    qDebug() << "MainWindow::init_layout() - Ajout des onglets à gauche";
    this->leftLayout->addWidget(this->tabWidget);
    this->tabWidget->addTab(enseignantTab, "Enseignants");
    this->tabWidget->addTab(classeTab, "Classes");
    this->tabWidget->addTab(ecueTab, "ECUE");
    this->tabWidget->addTab(salleTab, "Salles");
    this->tabWidget->addTab(etudiantTab, "Etudiants");

    // Ajouter les composants aux onglets
    // Enseignants
    qDebug() << "MainWindow::init_layout() - Ajout des composants aux onglets Enseignants";
    enseignantTab->setLayout(this->layout_enseignants);
    this->layout_enseignants->addWidget(this->liste_enseignants);
    // Boutons en horizontal
    this->bouton_layout_enseignants->addWidget(this->bouton_ajouter_enseignant);
    this->bouton_layout_enseignants->addWidget(this->bouton_modifier_enseignant);
    this->bouton_layout_enseignants->addWidget(this->bouton_supprimer_enseignant);
    this->layout_enseignants->addLayout(this->bouton_layout_enseignants);

    // Classes
    qDebug() << "MainWindow::init_layout() - Ajout des composants aux onglets Classes";
    classeTab->setLayout(this->layout_classes);
    this->layout_classes->addWidget(this->liste_classes);
    // Boutons en horizontal
    this->bouton_layout_classes->addWidget(this->bouton_ajouter_classe);
    this->bouton_layout_classes->addWidget(this->bouton_modifier_classe);
    this->bouton_layout_classes->addWidget(this->bouton_supprimer_classe);
    this->layout_classes->addLayout(this->bouton_layout_classes);

    // ECUE
    qDebug() << "MainWindow::init_layout() - Ajout des composants aux onglets ECUE";
    ecueTab->setLayout(this->layout_ecue);
    this->layout_ecue->addWidget(this->liste_ecue);
    // Boutons en horizontal
    this->bouton_layout_ecue->addWidget(this->bouton_ajouter_ecue);
    this->bouton_layout_ecue->addWidget(this->bouton_modifier_ecue);
    this->bouton_layout_ecue->addWidget(this->bouton_supprimer_ecue);
    this->layout_ecue->addLayout(this->bouton_layout_ecue);

    // Salles
    qDebug() << "MainWindow::init_layout() - Ajout des composants aux onglets Salles";
    salleTab->setLayout(this->layout_salles);
    this->layout_salles->addWidget(this->liste_salles);
    // Boutons en horizontal
    this->bouton_layout_salles->addWidget(this->bouton_ajouter_salle);
    this->bouton_layout_salles->addWidget(this->bouton_modifier_salle);
    this->bouton_layout_salles->addWidget(this->bouton_supprimer_salle);
    this->layout_salles->addLayout(this->bouton_layout_salles);

    // Etudiants
    qDebug() << "MainWindow::init_layout() - Ajout des composants aux onglets Salles";
    etudiantTab->setLayout(this->layout_etudiants);
    this->layout_etudiants->addWidget(this->liste_etudiants);
    // Boutons en horizontal
    this->bouton_layout_etudiants->addWidget(this->bouton_ajouter_etudiant);
    this->bouton_layout_etudiants->addWidget(this->bouton_modifier_etudiant);
    this->bouton_layout_etudiants->addWidget(this->bouton_supprimer_etudiant);
    this->layout_etudiants->addLayout(this->bouton_layout_etudiants);

    qDebug() << "MainWindow::init_layout() - Ajout de l'image à droite";
    // Ajouter l'image
    this->rightLayout->addWidget(this->imageLabel);
    this->imageLabel->setPixmap(QPixmap("image/eseo-logo.png"));

    // Ajouter le layout pour les informations
    this->rightLayout->addLayout(this->layout_infos);

    // Ajouter le calendrier
    this->rightLayout->addWidget(this->calendrier);

    // Ajouter les boutons pour les creneaux
    this->rightLayout->addWidget(this->bouton_ajouter_creneau);
    this->rightLayout->addWidget(this->bouton_modifier_creneau);
    this->rightLayout->addWidget(this->bouton_supprimer_creneau);

    qDebug() << "MainWindow::init_layout() - Fin de la fonction";
}

void MainWindow::init_slots(void)
{
    connect(this->bouton_ajouter_enseignant, &QPushButton::clicked, this, &MainWindow::ajouterEnseignant);
    connect(this->bouton_ajouter_etudiant, &QPushButton::clicked, this, &MainWindow::ajouterEtudiant);
    connect(this->bouton_ajouter_ecue, &QPushButton::clicked, this, &MainWindow::ajouterECUE);
    connect(this->bouton_ajouter_classe, &QPushButton::clicked, this, &MainWindow::ajouterClasse);
    connect(this->bouton_ajouter_salle, &QPushButton::clicked, this, &MainWindow::ajouterSalle);
}


void MainWindow::ajouterEnseignant() {
    // Créer une boîte de dialogue
    QDialog dialog(this);
    dialog.setWindowTitle("Ajouter un enseignant");
    dialog.setModal(true);

    // Layout principal
    QVBoxLayout layout(&dialog);

    // Formulaire pour les champs de saisie
    QFormLayout formLayout;
    QLineEdit nomLineEdit;
    QLineEdit prenomLineEdit;

    formLayout.addRow("Prénom :", &prenomLineEdit);
    formLayout.addRow("Nom :", &nomLineEdit);

    layout.addLayout(&formLayout);

    // Boutons Valider et Annuler
    QHBoxLayout buttonLayout;
    QPushButton validerButton("Valider", &dialog);
    QPushButton annulerButton("Annuler", &dialog);

    buttonLayout.addWidget(&validerButton);
    buttonLayout.addWidget(&annulerButton);

    layout.addLayout(&buttonLayout);

    // Connexion des boutons
    connect(&validerButton, &QPushButton::clicked, [&]() {
        QString prenom = prenomLineEdit.text();
        QString nom = nomLineEdit.text();

        if (nom.isEmpty() || prenom.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        } else {
            // Création de l'enseignant
            Enseignant enseignant(prenom.toStdString(), nom.toStdString());

            // Enregistrement dans le fichier CSV
            Factory::saveEnseignant(enseignant);

            // Ajouter l'enseignant à la liste de l'interface utilisateur
            this->liste_enseignants->addItem(nom + " " + prenom);
            dialog.accept();
        }
    });
    connect(&annulerButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    // Afficher la boîte de dialogue
    dialog.exec();
}

/* SUPPRIMER ENSEIGNANT  PAS A FAIRE POUR L'INSTANT !!!!!!!
void MainWindow::supprimerEnseignant() {
    // Créer une boîte de dialogue
    QDialog dialog(this);
    dialog.setWindowTitle("Supprimer un enseignant");
    dialog.setModal(true);

    // Layout principal
    QVBoxLayout layout(&dialog);

    // Formulaire pour les champs de saisie

    // Charger les ECUEs depuis le fichier CSV
    Factory f = Factory();

    QStringList enseignants = f.loadEnseignants();
    if (enseignants.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "La liste des enseignants est vide ou le fichier n'a pas pu être chargé.");
        return;
    }

    enseignantsComboBox.addItems(enseignants);

    layout.addLayout(&formLayout);

    // Boutons Valider et Annuler
    QHBoxLayout buttonLayout;
    QPushButton validerButton("Valider", &dialog);
    QPushButton annulerButton("Annuler", &dialog);

    buttonLayout.addWidget(&validerButton);
    buttonLayout.addWidget(&annulerButton);

    layout.addLayout(&buttonLayout);

    // Connexion des boutons
    connect(&validerButton, &QPushButton::clicked, [&]() {

        QString enseignant = enseignantsComboBox.currentText();

        if (enseignant.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        } else {

            // Enregistrement dans le fichier CSV
            f.deleteEnseignant(enseignant);

            // Ajouter l'enseignant à la liste de l'interface utilisateur
            dialog.accept();
        }
    });
    connect(&annulerButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    // Afficher la boîte de dialogue
    dialog.exec();
}
*/



void MainWindow::ajouterEtudiant() {
    // Créer une boîte de dialogue
    QDialog dialog(this);
    dialog.setWindowTitle("Ajouter un etudiant");
    dialog.setModal(true);

    // Layout principal
    QVBoxLayout layout(&dialog);

    // Formulaire pour les champs de saisie
    QFormLayout formLayout;
    QLineEdit nomLineEdit;
    QLineEdit prenomLineEdit;

    formLayout.addRow("Prénom :", &prenomLineEdit);
    formLayout.addRow("Nom :", &nomLineEdit);

    layout.addLayout(&formLayout);

    // Boutons Valider et Annuler
    QHBoxLayout buttonLayout;
    QPushButton validerButton("Valider", &dialog);
    QPushButton annulerButton("Annuler", &dialog);

    buttonLayout.addWidget(&validerButton);
    buttonLayout.addWidget(&annulerButton);

    layout.addLayout(&buttonLayout);

    // Connexion des boutons
    connect(&validerButton, &QPushButton::clicked, [&]() {
        QString prenom = prenomLineEdit.text();
        QString nom = nomLineEdit.text();

        if (nom.isEmpty() || prenom.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        } else {
            // Création de l'etudiant
            Etudiant etudiant(prenom.toStdString(), nom.toStdString());

            // Enregistrement dans le fichier CSV
            //Factory f = Factory();
            Factory::saveEtudiant(etudiant);

            // Ajouter l'etudiant à la liste de l'interface utilisateur
            this->liste_etudiants->addItem(nom + " " + prenom);
            dialog.accept();
        }
    });
    connect(&annulerButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    // Afficher la boîte de dialogue
    dialog.exec();
}


void MainWindow::ajouterECUE() {
    // Créer une boîte de dialogue
    QDialog dialog(this);
    dialog.setWindowTitle("Ajouter une ECUE");
    dialog.setModal(true);

    // Layout principal
    QVBoxLayout layout(&dialog);

    // Formulaire pour les champs de saisie
    QFormLayout formLayout;

    QLineEdit nomECUELineEdit;
    QLineEdit typeECUELineEdit;

    // Champ avec validateur pour le nombre d'heures (float)
    QLineEdit nbHeureLineEdit;
    QDoubleValidator* doubleValidator = new QDoubleValidator(0, 1000, 2, &nbHeureLineEdit); // Limite à 1000 heures avec 2 décimales
    nbHeureLineEdit.setValidator(doubleValidator);

    formLayout.addRow("Nom ECUE :", &nomECUELineEdit);
    formLayout.addRow("Type ECUE :", &typeECUELineEdit);
    formLayout.addRow("Nombre d'heures :", &nbHeureLineEdit);

    layout.addLayout(&formLayout);

    // Boutons Valider et Annuler
    QHBoxLayout buttonLayout;
    QPushButton validerButton("Valider", &dialog);
    QPushButton annulerButton("Annuler", &dialog);

    buttonLayout.addWidget(&validerButton);
    buttonLayout.addWidget(&annulerButton);

    layout.addLayout(&buttonLayout);

    // Connexion des boutons
    connect(&validerButton, &QPushButton::clicked, [&]() {
        QString nomECUE = nomECUELineEdit.text();
        QString typeECUE = typeECUELineEdit.text();
        QString nbHeures = nbHeureLineEdit.text();

        if (nomECUE.isEmpty() || typeECUE.isEmpty() || nbHeures.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        } else {
            // Conversion du champ Nombre d'heures en float
            float nbHeuresFloat = nbHeures.toFloat();

            // Création de l'ECUE
            ECUE ecue(nomECUE.toStdString(), typeECUE.toStdString(), nbHeuresFloat);

            // Enregistrement dans le fichier CSV
            Factory::saveECUE(ecue); // Assurez-vous que la méthode saveECUE() est implémentée dans la classe ECUE

            // Ajouter l'ECUE à la liste de l'interface utilisateur
            this->liste_ecue->addItem(nomECUE + " (" + typeECUE + ", " + QString::number(nbHeuresFloat) + " heures)");
            dialog.accept();
        }
    });

    connect(&annulerButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    // Afficher la boîte de dialogue
    dialog.exec();
}

void MainWindow::ajouterClasse() {
    // Créer une boîte de dialogue
    QDialog dialog(this);
    dialog.setWindowTitle("Ajouter une classe");
    dialog.setModal(true);

    // Layout principal
    QVBoxLayout layout(&dialog);

    // Formulaire pour les champs de saisie
    QFormLayout formLayout;
    QLineEdit nomClasseLineEdit;

    formLayout.addRow("Nom Classe :", &nomClasseLineEdit);

    layout.addLayout(&formLayout);

    // Boutons Valider et Annuler
    QHBoxLayout buttonLayout;
    QPushButton validerButton("Valider", &dialog);
    QPushButton annulerButton("Annuler", &dialog);

    buttonLayout.addWidget(&validerButton);
    buttonLayout.addWidget(&annulerButton);

    layout.addLayout(&buttonLayout);

    // Connexion des boutons
    connect(&validerButton, &QPushButton::clicked, [&]() {
        QString nomClasse = nomClasseLineEdit.text();

        if (nomClasse.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        } else {
            // Création de la classe
            Classe classe(nomClasse.toStdString());

            // Enregistrement dans le fichier CSV
            Factory::saveClasse(classe);

            // Ajouter la classe à la liste de l'interface utilisateur
            this->liste_classes->addItem(nomClasse);
            dialog.accept();
        }
    });
    connect(&annulerButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    // Afficher la boîte de dialogue
    dialog.exec();
}

void MainWindow::ajouterSalle() {
    // Créer une boîte de dialogue
    QDialog dialog(this);
    dialog.setWindowTitle("Ajouter une salle");
    dialog.setModal(true);

    // Layout principal
    QVBoxLayout layout(&dialog);

    // Formulaire pour les champs de saisie
    QFormLayout formLayout;
    QLineEdit etageLineEdit;
    QLineEdit numeroLineEdit;

    // Ajouter des validateurs pour les champs "étage" et "numéro"
    QIntValidator* intValidator = new QIntValidator(0, 1000, this); // Limite entre 0 et 1000 pour les entiers
    etageLineEdit.setValidator(intValidator);
    numeroLineEdit.setValidator(intValidator);

    formLayout.addRow("Etage :", &etageLineEdit);
    formLayout.addRow("Numero :", &numeroLineEdit);

    layout.addLayout(&formLayout);

    // Boutons Valider et Annuler
    QHBoxLayout buttonLayout;
    QPushButton validerButton("Valider", &dialog);
    QPushButton annulerButton("Annuler", &dialog);

    buttonLayout.addWidget(&validerButton);
    buttonLayout.addWidget(&annulerButton);

    layout.addLayout(&buttonLayout);

    // Connexion des boutons
    connect(&validerButton, &QPushButton::clicked, [&]() {
        QString etageSalleStr = etageLineEdit.text();
        QString numeroSalleStr = numeroLineEdit.text();

        if (etageSalleStr.isEmpty() || numeroSalleStr.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        } else {
            // Conversion des champs en entier
            int etageSalle = etageSalleStr.toInt();
            int numeroSalle = numeroSalleStr.toInt();

            // Création de l'objet Salle
            Salle salle(etageSalle, numeroSalle);

            // Enregistrement dans le fichier CSV
            Factory::saveSalle(salle); // Assurez-vous que cette méthode est bien définie

            // Ajouter la salle à la liste de l'interface utilisateur
            this->liste_salles->addItem("Salle : " + QString::number(etageSalle) + QString::number(numeroSalle) + " (Etage : " + QString::number(etageSalle) + ", Numero : " + QString::number(numeroSalle) + ")");
            dialog.accept();
        }
    });

    connect(&annulerButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    // Afficher la boîte de dialogue
    dialog.exec();
}
