#include "mainwindow.h"

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
    this->splitter->setCollapsible(0, false);
    this->splitter->setCollapsible(1, false);

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

    // Emplacement pour une image dans le coin supérieur droit
    this->imageLabel = new QLabel();
    this->imageLabel->setAlignment(Qt::AlignTop | Qt::AlignRight);

    // Layout pour les informations
    this->layout_infos = new QVBoxLayout();

    // Calendrier pour les emplois du temps
    this->calendrier = new QCalendarWidget();

    // Boutons pour les creneaux
    this->bouton_ajouter_creneau = new QPushButton("Ajouter un créneau");
    this->bouton_modifier_creneau = new QPushButton("Modifier le créneau");
    this->bouton_supprimer_creneau = new QPushButton("Supprimer le créneau");

}

void MainWindow::init_layout(void)
{
    // Ajouter la séparation entre les 2 parties
    this->setCentralWidget(this->splitter);

    // Ajouter les widgets gauche et droit
    this->splitter->addWidget(this->leftWidget);
    this->splitter->addWidget(this->rightWidget);

    // Ajouter les layouts gauche et droit
    this->leftWidget->setLayout(this->leftLayout);
    this->rightWidget->setLayout(this->rightLayout);

    // Créer des widgets pour les onglets
    QWidget* enseignantTab = new QWidget();
    QWidget* classeTab = new QWidget();
    QWidget* ecueTab = new QWidget();
    QWidget* salleTab = new QWidget();

    // Ajouter les onglets à gauche
    this->leftLayout->addWidget(this->tabWidget);
    this->tabWidget->addTab(enseignantTab, "Enseignants");
    this->tabWidget->addTab(classeTab, "Classes");
    this->tabWidget->addTab(ecueTab, "ECUE");
    this->tabWidget->addTab(salleTab, "Salles");

    // Ajouter les composants aux onglets
    // Enseignants
    enseignantTab->setLayout(this->layout_enseignants);
    this->layout_enseignants->addWidget(this->liste_enseignants);
    this->layout_enseignants->addWidget(this->bouton_ajouter_enseignant);
    this->layout_enseignants->addWidget(this->bouton_modifier_enseignant);
    this->layout_enseignants->addWidget(this->bouton_supprimer_enseignant);

    // Classes
    classeTab->setLayout(this->layout_classes);
    this->layout_classes->addWidget(this->liste_classes);
    this->layout_classes->addWidget(this->bouton_ajouter_classe);
    this->layout_classes->addWidget(this->bouton_modifier_classe);
    this->layout_classes->addWidget(this->bouton_supprimer_classe);

    // ECUE
    ecueTab->setLayout(this->layout_ecue);
    this->layout_ecue->addWidget(this->liste_ecue);
    this->layout_ecue->addWidget(this->bouton_ajouter_ecue);
    this->layout_ecue->addWidget(this->bouton_modifier_ecue);
    this->layout_ecue->addWidget(this->bouton_supprimer_ecue);

    // Salles
    salleTab->setLayout(this->layout_salles);
    this->layout_salles->addWidget(this->liste_salles);
    this->layout_salles->addWidget(this->bouton_ajouter_salle);
    this->layout_salles->addWidget(this->bouton_modifier_salle);
    this->layout_salles->addWidget(this->bouton_supprimer_salle);

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

}

void MainWindow::init_slots(void)
{

}
