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
    //this->splitter->setCollapsible(0, false);
    //this->splitter->setCollapsible(1, false);

    // Créer les widgets gauche et droit
    this->leftWidget = new QWidget(this);
    this->rightWidget = new QWidget(this);

    // Créer les layouts gauche et droit
    this->leftLayout = new QVBoxLayout();
    this->rightLayout = new QVBoxLayout();

    // Créer les onglets de gauche
    this->tabWidget = new QTabWidget();

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

    // Ajouter les onglets à gauche
    this->leftLayout->addWidget(this->tabWidget);
    this->tabWidget->addTab(this->liste_enseignants, "Enseignants");
    this->tabWidget->addTab(this->liste_classes, "Classes");
    this->tabWidget->addTab(this->liste_ecue, "ECUE");
    this->tabWidget->addTab(this->liste_salles, "Salles");

    // Ajouter les composants aux onglets
    // Enseignants
    this->layout_enseignants->addWidget(this->liste_enseignants);
    this->layout_enseignants->addWidget(this->bouton_ajouter_enseignant);
    this->layout_enseignants->addWidget(this->bouton_modifier_enseignant);
    this->layout_enseignants->addWidget(this->bouton_supprimer_enseignant);

    // Classes
    this->layout_classes->addWidget(this->liste_classes);
    this->layout_classes->addWidget(this->bouton_ajouter_classe);
    this->layout_classes->addWidget(this->bouton_modifier_classe);
    this->layout_classes->addWidget(this->bouton_supprimer_classe);

    // ECUE
    this->layout_ecue->addWidget(this->liste_ecue);
    this->layout_ecue->addWidget(this->bouton_ajouter_ecue);
    this->layout_ecue->addWidget(this->bouton_modifier_ecue);
    this->layout_ecue->addWidget(this->bouton_supprimer_ecue);

    // Salles
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

    /*
    // Configurer le calendrier pour afficher uniquement la semaine en cours
    this->calendrier->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    this->calendrier->setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
    this->calendrier->setNavigationBarVisible(false);
    this->calendrier->setGridVisible(true);

    // Définir la date de début et de fin pour afficher uniquement la semaine en cours
    QDate currentDate = QDate::currentDate();
    QDate startOfWeek = currentDate.addDays(-currentDate.dayOfWeek() + 1);
    QDate endOfWeek = startOfWeek.addDays(6);

    this->calendrier->setMinimumDate(startOfWeek);
    this->calendrier->setMaximumDate(endOfWeek);

    // Ajouter les boutons de navigation pour les semaines
    this->bouton_semaine_precedente = new QPushButton("Semaine précédente");
    this->bouton_semaine_suivante = new QPushButton("Semaine suivante");

    this->rightLayout->addWidget(this->bouton_semaine_precedente);
    this->rightLayout->addWidget(this->bouton_semaine_suivante);

    // Connecter les boutons de navigation aux slots correspondants
    connect(this->bouton_semaine_precedente, &QPushButton::clicked, this, &MainWindow::semainePrecedente);
    connect(this->bouton_semaine_suivante, &QPushButton::clicked, this, &MainWindow::semaineSuivante);

    // Ajouter les horaires à gauche du calendrier
    this->horaires = new QListWidget();
    for (int i = 8; i <= 18; ++i) {
        this->horaires->addItem(QString::number(i) + ":00");
    }
    this->rightLayout->addWidget(this->horaires);
    
    // Ajouter les événements au calendrier
    QTextCharFormat format;
    format.setBackground(Qt::yellow);

    QDate eventDate = QDate::currentDate().addDays(2); // Exemple d'événement dans 2 jours
    this->calendrier->setDateTextFormat(eventDate, format);

    // Ajouter des événements à des heures spécifiques
    QListWidgetItem* eventItem = new QListWidgetItem("Réunion avec les enseignants");
    eventItem->setData(Qt::UserRole, QTime(10, 0)); // Exemple d'événement à 10:00
    this->horaires->addItem(eventItem);
    */
}

void MainWindow::init_slots(void)
{

}




