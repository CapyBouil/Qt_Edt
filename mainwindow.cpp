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
    this->showMaximized(); // Maximiser la fenêtre
    this->apply_global_style();
}

// Initialisations
void MainWindow::init_composants(void)
{
    // Séparer la fenetre en 2 parties (droite et gauche)
    this->splitter = new QSplitter(this);

    // Empêcher l'utilisateur de redimensionner les parties
    this->splitter->setHandleWidth(0);  // Masquer la poignée de redimensionnement

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
    this->bouton_lier_ecue = new QPushButton("Lier un ECUE");
    this->bouton_supprimer_enseignant = new QPushButton("Supprimer l'enseignant");

    // Liste et boutons pour les classes
    this->liste_classes = new QListWidget();
    this->bouton_ajouter_classe = new QPushButton("Ajouter une classe");
    this->bouton_supprimer_classe = new QPushButton("Supprimer la classe");

    // Liste et boutons pour les ECUE
    this->liste_ecue = new QListWidget();
    this->bouton_ajouter_ecue = new QPushButton("Ajouter une ECUE");
    this->bouton_lier_enseignant = new QPushButton("Lier un enseignant");
    this->bouton_supprimer_ecue = new QPushButton("Supprimer l'ECUE");

    // Liste et boutons pour les salles
    this->liste_salles = new QListWidget();
    this->bouton_ajouter_salle = new QPushButton("Ajouter une salle");
    this->bouton_supprimer_salle = new QPushButton("Supprimer la salle");

    // Liste et boutons pour les etudiants
    this->liste_etudiants = new QListWidget();
    this->bouton_ajouter_etudiant = new QPushButton("Ajouter etudiant");
    this->bouton_supprimer_etudiant = new QPushButton("Supprimer edudiant");

    // Ajouter une image
    this->imageLabel = new QLabel();
    this->imageLabel->setPixmap(QPixmap("image/eseo-logo.png"));

    // Layout pour les informations
    this->layout_infos = new QVBoxLayout();
    this->label_infos = new QLabel("Informations :");

    // Calendrier pour les emplois du temps
    this->calendrier = new QTableWidget(11,5);
    this->calendrier->setHorizontalHeaderLabels({"Lundi","Mardi","Mercredi","Jeudi","Vendredi"});
    this->calendrier->setVerticalHeaderLabels({"8h","9h","10h","11h","12h","13h","14h","15h","16h","17h","18h"});
    // Configurer la politique de redimensionnement
    this->calendrier->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // Ajuster les colonnes pour qu'elles occupent toute la largeur
    this->calendrier->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    // Boutons pour les creneaux
    this->bouton_layout_creneau = new QHBoxLayout();
    this->bouton_ajouter_creneau = new QPushButton("Ajouter un créneau");
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
    this->bouton_layout_enseignants->addWidget(this->bouton_lier_ecue);
    this->bouton_layout_enseignants->addWidget(this->bouton_supprimer_enseignant);
    this->layout_enseignants->addLayout(this->bouton_layout_enseignants);

    // Classes
    qDebug() << "MainWindow::init_layout() - Ajout des composants aux onglets Classes";
    classeTab->setLayout(this->layout_classes);
    this->layout_classes->addWidget(this->liste_classes);
    // Boutons en horizontal
    this->bouton_layout_classes->addWidget(this->bouton_ajouter_classe);
    this->bouton_layout_classes->addWidget(this->bouton_supprimer_classe);
    this->layout_classes->addLayout(this->bouton_layout_classes);

    // ECUE
    qDebug() << "MainWindow::init_layout() - Ajout des composants aux onglets ECUE";
    ecueTab->setLayout(this->layout_ecue);
    this->layout_ecue->addWidget(this->liste_ecue);
    // Boutons en horizontal
    this->bouton_layout_ecue->addWidget(this->bouton_ajouter_ecue);
    this->bouton_layout_ecue->addWidget(this->bouton_lier_enseignant);
    this->bouton_layout_ecue->addWidget(this->bouton_supprimer_ecue);
    this->layout_ecue->addLayout(this->bouton_layout_ecue);

    // Salles
    qDebug() << "MainWindow::init_layout() - Ajout des composants aux onglets Salles";
    salleTab->setLayout(this->layout_salles);
    this->layout_salles->addWidget(this->liste_salles);
    // Boutons en horizontal
    this->bouton_layout_salles->addWidget(this->bouton_ajouter_salle);
    this->bouton_layout_salles->addWidget(this->bouton_supprimer_salle);
    this->layout_salles->addLayout(this->bouton_layout_salles);

    // Etudiants
    qDebug() << "MainWindow::init_layout() - Ajout des composants aux onglets Salles";
    etudiantTab->setLayout(this->layout_etudiants);
    this->layout_etudiants->addWidget(this->liste_etudiants);
    // Boutons en horizontal
    this->bouton_layout_etudiants->addWidget(this->bouton_ajouter_etudiant);
    this->bouton_layout_etudiants->addWidget(this->bouton_supprimer_etudiant);
    this->layout_etudiants->addLayout(this->bouton_layout_etudiants);

    qDebug() << "MainWindow::init_layout() - Ajout de l'image à droite";

    // Ajouter l'image
    this->rightLayout->addWidget(this->imageLabel);

    // Ajouter le layout pour les informations
    this->rightLayout->addLayout(this->layout_infos);
    this->layout_infos->addWidget(this->label_infos);

    // Separateur
    this->rightLayout->addItem(new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding));

    // Ajouter le calendrier
    this->rightLayout->addWidget(this->calendrier);

    // Ajouter les boutons pour les creneaux
    this->rightLayout->addLayout(this->bouton_layout_creneau);
    this->bouton_layout_creneau->addWidget(this->bouton_ajouter_creneau);
    this->bouton_layout_creneau->addWidget(this->bouton_supprimer_creneau);

    qDebug() << "MainWindow::init_layout() - Fin de la fonction";
}

void MainWindow::init_slots(void)
{
    connect(this->bouton_ajouter_enseignant, &QPushButton::clicked, this, &MainWindow::ajouterEnseignant);
    connect(this->bouton_ajouter_etudiant, &QPushButton::clicked, this, &MainWindow::ajouterEtudiant);
    connect(this->bouton_ajouter_ecue, &QPushButton::clicked, this, &MainWindow::ajouterECUE);
    connect(this->bouton_ajouter_classe, &QPushButton::clicked, this, &MainWindow::ajouterClasse);
    connect(this->bouton_ajouter_salle, &QPushButton::clicked, this, &MainWindow::ajouterSalle);
    connect(this->bouton_lier_ecue, &QPushButton::clicked, this, &MainWindow::lierECUE);
    connect(this->bouton_lier_enseignant, &QPushButton::clicked, this, &MainWindow::lierECUE);

}


void MainWindow::ajouterEtudiant() {
    EtudiantWindow dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString nom = dialog.getNom();
        QString prenom = dialog.getPrenom();

        this->liste_etudiants->addItem(nom + " " + prenom);
    }
}

void MainWindow::ajouterEnseignant() {
    EnseignantWindow dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString nom = dialog.getNom();
        QString prenom = dialog.getPrenom();

        this->liste_enseignants->addItem(nom + " " + prenom );
    }
}
void MainWindow::ajouterECUE() {
    ECUEWindow dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        ECUE ecue = dialog.getECUE();
        this->liste_ecue->addItem(QString::fromStdString(ecue.getNomECUE()) + " (Type: " + QString::fromStdString(ecue.getTypeECUE()) + ", Heures: " + QString::number(ecue.getNbHeures()) + ")");

        Factory::saveECUE(ecue);
    }
}

void MainWindow::ajouterClasse() {
    ClasseWindow dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString nomClasse = dialog.getNomClasse();
        this->liste_classes->addItem(nomClasse);
        // ... autre code pour sauvegarder la classe, etc. ...
    }
}

void MainWindow::ajouterSalle() {
    SalleWindow dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString etage = dialog.getEtage();
        QString numero = dialog.getNumero();
        this->liste_salles->addItem("Salle " + numero + " (Étage " + etage + ")");
        // ... autre code pour sauvegarder la salle, etc. ...
    }
}


void MainWindow::lierECUE() {
    LierECUEWindow dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString ecueSelectionnee = dialog.getECUESelectionnee();
        QString enseignantSelectionne = dialog.getEnseignantSelectionne();

        // ... (Votre code pour lier l'ECUE et l'enseignant) ...

        QMessageBox::information(this, "Information", "ECUE " + ecueSelectionnee + " liée à " + enseignantSelectionne);
    }
}

void MainWindow::ajouterCreneau() {
    SalleWindow dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString etage = dialog.getEtage();
        QString numero = dialog.getNumero();
        this->liste_salles->addItem("Salle " + numero + " (Étage " + etage + ")");
        // ... autre code pour sauvegarder la salle, etc. ...
    }
}



void MainWindow::apply_global_style() {
    this->setStyleSheet(getGlobalStyle());
}
