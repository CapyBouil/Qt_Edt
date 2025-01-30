#include "mainwindow.h"

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

    afficherEnseignants();
    afficherEtudiants();
    afficherSalles();
    afficherClasses();
    afficherEcues();
    afficherCreneaux(this->refDate);
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
    this->bouton_lier_etudiant = new QPushButton("Lier un etudiant");
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

    // Boutons pour changer de semaine
    this->bouton_semaine_precedente = new QPushButton("Semaine précédente");
    this->bouton_semaine_suivante = new QPushButton("Semaine suivante");
    this->bouton_layout_semaine = new QHBoxLayout();

    // Calendrier pour les emplois du temps
    this->calendrier = new QTableWidget(11,5);
    // Configurer la politique de redimensionnement
    this->calendrier->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // Ajuster les colonnes pour qu'elles occupent toute la largeur
    this->calendrier->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // Désactiver l'édition directe des cellules
    this->calendrier->setEditTriggers(QAbstractItemView::NoEditTriggers);

    this->refDate = QDate::currentDate();

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
    this->bouton_layout_classes->addWidget(this->bouton_lier_etudiant);
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
    this->rightLayout->addItem(new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding));

    // Boutons pour changer de semaine
    this->rightLayout->addLayout(this->bouton_layout_semaine);
    this->bouton_layout_semaine->addWidget(this->bouton_semaine_precedente);
    this->bouton_layout_semaine->addWidget(this->bouton_semaine_suivante);

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
    connect(this->bouton_ajouter_creneau, &QPushButton::clicked, this, &MainWindow::ajouterCreneau);

    connect(liste_enseignants, &QListWidget::itemClicked, this, &MainWindow::infoEnseignant);
    connect(liste_etudiants, &QListWidget::itemClicked, this, &MainWindow::infoEtudiant);
    connect(liste_salles, &QListWidget::itemClicked, this, &MainWindow::infoSalle);
    connect(liste_classes, &QListWidget::itemClicked, this, &MainWindow::infoClasse);
    connect(liste_ecue, &QListWidget::itemClicked, this, &MainWindow::infoEcue);
    connect(this->bouton_lier_etudiant, &QPushButton::clicked, this, &MainWindow::lierEtudiant);

    connect(this->bouton_supprimer_salle, &QPushButton::clicked, this, &MainWindow::suppSalle);
    connect(this->bouton_supprimer_classe, &QPushButton::clicked, this, &MainWindow::suppClasse);
    connect(this->bouton_supprimer_etudiant, &QPushButton::clicked, this, &MainWindow::suppEtudiant);
    connect(this->bouton_supprimer_enseignant, &QPushButton::clicked, this, &MainWindow::suppEnseignant);
    connect(this->bouton_supprimer_ecue, &QPushButton::clicked, this, &MainWindow::suppEcue);

    // Connexions pour les boutons de changement de semaine
    connect(this->bouton_semaine_precedente, &QPushButton::clicked, this, &MainWindow::semainePrecedente);
    connect(this->bouton_semaine_suivante, &QPushButton::clicked, this, &MainWindow::semaineSuivante);
}


void MainWindow::lierECUE() {
    LierECUEWindow dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString ecueSelectionnee = dialog.getECUESelectionnee();
        QString enseignantSelectionne = dialog.getEnseignantSelectionne();
        ECUE ecue = Controleur::findECUEByNom(ecueSelectionnee).value();
        Enseignant enseignant =Controleur::findEnseignantByNomPrenom(enseignantSelectionne).value();
        Factory::insertEnseignant(enseignant,ecue);

        QMessageBox::information(this, "Information", "ECUE " + ecueSelectionnee + " liée à " + enseignantSelectionne);
    }
}

void MainWindow::lierEtudiant() {
    LierEtudiantWindow dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString classeSelectionnee = dialog.getClasseSelectionne();
        QString etudiantSelectionne = dialog.getEtudiantSelectionnee();
        Classe classe = Controleur::findClasseByNomClasse(classeSelectionnee).value();
        Etudiant etudiant = Controleur::findEtudiantByNomPrenom(etudiantSelectionne).value();
        Factory::insertEtudiant(etudiant,classe);

        QMessageBox::information(this, "Information", "ECUE " + classeSelectionnee + " liée à " + etudiantSelectionne);
    }
}

void MainWindow::ajouterCreneau() {
    Controleur controleur;
    Factory factory;
    CreneauWindow dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString salle = dialog.getSalle();
        Salle salleObj = controleur.findSalleByNumero(salle).value();
        QString classe = dialog.getClasse();
        Classe classeObj = controleur.findClasseByNomClasse(classe).value();
        QString ecue = dialog.getECUE();
        ECUE ecueObj = controleur.findECUEByNom(ecue).value();
        QString enseignant = dialog.getEnseignant();
        Enseignant enseignantObj = controleur.findEnseignantByNomPrenom(enseignant).value();
        QString jour = dialog.getJour();
        QDate jourDate = QDate::fromString(jour, "MM/dd/yyyy");
        QString heureDebut = dialog.getHeureDebut();
        QTime heureDebutTime = QTime::fromString(heureDebut, "HH");
        QString heureFin = dialog.getHeureFin();
        QTime heureFinTime = QTime::fromString(heureFin, "HH");

        Creneau *creneau = new Creneau(salleObj, classeObj, ecueObj, enseignantObj, jourDate, heureDebutTime, heureFinTime);
        factory.saveCreneau(*creneau);
        MainWindow::afficherCreneaux(this->refDate);
    }
}

void MainWindow::afficherCreneaux(QDate refDate)
{
    // Charger les salles via Factory
    Factory::listeCreneau.clear();
    Factory factory;
    factory.loadCreneau();

    // Verifier que la liste statique n'est pas vide
    if (Factory::listeSalle.empty()) {
        QMessageBox::warning(this, "Erreur", "Aucun creneau trouve dans le fichier !");
        return;
    }

    // Vider la liste graphique avant de la recharger
    MainWindow::resetCalendrier(refDate);

    int refWeekNumber = refDate.weekNumber();

    // Ajouter les salles a  la liste graphique
    for (const Creneau& creneau : Factory::listeCreneau) {
        Salle salle = creneau.getSalle();
        Classe classe = creneau.getClasse();
        ECUE ecue = creneau.getECUE();
        Enseignant enseignant = creneau.getEnseignant();
        QDate jour = creneau.getJour();
        QTime heureDebut = creneau.getHeureDebut();
        QTime heureFin = creneau.getHeureFin();

        int creneauWeekNumber = jour.weekNumber();

        // Vérifier si le créneau est dans la même semaine que la date de référence
        if (creneauWeekNumber != refWeekNumber) {
            continue; // Passer au créneau suivant
        }

        int colonne = jour.dayOfWeek() - 1; // 0 pour lundi, 1 pour mardi, etc.

        // Convertir l'heure de début et l'heure de fin en indices de lignes
        int ligneDebut = -1;
        int ligneFin = -1;
        QStringList heures = {"08:00:00", "09:00:00", "10:00:00", "11:00:00", "12:00:00", "13:00:00", "14:00:00", "15:00:00",
                              "16:00:00", "17:00:00", "18:00:00"};
        for (int i = 0; i < heures.size(); ++i) {
            if (heures[i] == heureDebut.toString()) ligneDebut = i;
            if (heures[i] == heureFin.toString()) ligneFin = i;
        }

        if (ligneDebut == -1 || ligneFin == -1) {
            QMessageBox::warning(this, "Erreur", "Heure invalide.");
            return;
        }

        // Vérifier que l'heure de début est avant l'heure de fin
        if (ligneDebut >= ligneFin) {
            QMessageBox::warning(this, "Erreur", "L'heure de début doit être avant l'heure de fin.");
            return;
        }

        // Vérification des conflits
        bool conflit = false;
        for (int ligne = ligneDebut; ligne <= ligneFin; ++ligne) {
            if (this->calendrier->item(ligne, colonne) != nullptr) {
                conflit = true;
                break;
            }
        }

        if (conflit) {
            QMessageBox::warning(this, "Erreur", "Conflit détecté : un créneau existe déjà à cet horaire.");
            return;
        }

        // Créer le texte du créneau
        QString texteCreneau = QString("Salle: %1\nClasse: %2\nECUE: %3\nEnseignant: %4 %5")
                                   .arg(QString::number(salle.getNumeroComplet()))
                                   .arg(QString::fromStdString(classe.getNomClasse()))
                                   .arg(QString::fromStdString(ecue.getNomECUE()))
                                   .arg(QString::fromStdString(enseignant.getNom()))
                                   .arg(QString::fromStdString(enseignant.getPrenom()));

        qDebug() << texteCreneau;

        // Ajouter le créneau dans le tableau
        QTableWidgetItem* item = new QTableWidgetItem(texteCreneau);
        item->setTextAlignment(Qt::AlignCenter); // Centrer le texte

        this->calendrier->setItem(ligneDebut, colonne, item);

        // Fusionner les cellules si le créneau dure plusieurs heures
        if (ligneFin > ligneDebut + 1) {
            this->calendrier->setSpan(ligneDebut, colonne, ligneFin - ligneDebut + 1, 1);
        }

        // Ajuster les lignes pour qu'elles s'adaptent à la hauteur de leur contenu
        this->calendrier->resizeRowsToContents();
   }
}

void MainWindow::resetCalendrier(QDate referenceDate)
{
    this->calendrier->clearContents();

    // Dé-fusionner toutes les cellules
    for (int row = 0; row < this->calendrier->rowCount(); ++row) {
        for (int column = 0; column < this->calendrier->columnCount(); ++column) {
            if (this->calendrier->columnSpan(row, column) > 1 || this->calendrier->rowSpan(row, column) > 1) {
                this->calendrier->setSpan(row, column, 1, 1);
            }
        }
    }

    this->calendrier->resizeRowsToContents();

    // Calculer le lundi de la semaine actuelle
    QDate mondayDate = referenceDate.addDays(-(referenceDate.dayOfWeek() - 1)); // Lundi est le jour 1 dans Qt
    QDate tuesdayDate = referenceDate.addDays(-(referenceDate.dayOfWeek() - 2));
    QDate wednesdayDate = referenceDate.addDays(-(referenceDate.dayOfWeek() - 3));
    QDate thursdayDate = referenceDate.addDays(-(referenceDate.dayOfWeek() - 4));
    QDate fridayDate = referenceDate.addDays(-(referenceDate.dayOfWeek() - 5));

    this->calendrier->setHorizontalHeaderLabels({mondayDate.toString(),tuesdayDate.toString(),wednesdayDate.toString(),
                                                 thursdayDate.toString(),fridayDate.toString()});
    this->calendrier->setVerticalHeaderLabels({"8h","9h","10h","11h","12h","13h","14h","15h","16h","17h","18h"});
}

// Fonction pour passer à la semaine précédente
void MainWindow::semainePrecedente()
{
    this->refDate = this->refDate.addDays(-7);
    MainWindow::afficherCreneaux(this->refDate);
}

// Fonction pour passer à la semaine suivante
void MainWindow::semaineSuivante()
{
    this->refDate = this->refDate.addDays(7);
    MainWindow::afficherCreneaux(this->refDate);
}

void MainWindow::infoEnseignant(QListWidgetItem *item) {
    QString enseignantText = item->text();

    // Extraire le nom et le prénom (et l'ECUE si présente)
    QStringList parts = enseignantText.split(" ");
    QString nom = parts[1];
    QString prenom = parts[0];
    QString ecue = "";
    if (parts.size() > 3 && parts[2] == "(ECUE:") { // Vérifier si l'ECUE est présente
        ecue = parts[3].left(parts[3].length() - 1); // Enlever la parenthèse fermante
    }

    // Afficher les informations de manière formattée
    QString infoText = "Informations sur l'enseignant :\n";
    infoText += "Nom : " + nom + "\n";
    infoText += "Prénom : " + prenom + "\n";
    if (!ecue.isEmpty()) {
        infoText += "ECUE : " + ecue + "\n";
    }

    label_infos->setText(infoText);
}

void MainWindow::infoEtudiant(QListWidgetItem *item) {
    QString etudiantText = item->text();

    QStringList parts = etudiantText.split(" ");
    QString nom = parts[0];
    QString prenom = parts[1];


    QString infoText = "Informations sur l'étudiant :\n";
    infoText += "Nom : " + nom + "\n";
    infoText += "Prénom : " + prenom + "\n";

    label_infos->setText(infoText);
}

void MainWindow::infoSalle(QListWidgetItem *item) {
    QString salleText = item->text();


    QStringList parts = salleText.split(" ");
    QStringList partEtage = parts[5].split(',');
    QString etage = partEtage[0];
    QString numerosalle = parts[8];

    // Afficher les informations de manière formattée
    QString infoText = "Informations sur la salle :\n";
    infoText += "Étage : " + etage + "\n";
    infoText += "Numero de salle : " + numerosalle + "\n";

    label_infos->setText(infoText);
}

void MainWindow::infoClasse(QListWidgetItem *item) {
    QString classeText = item->text();

    QStringList parts = classeText.split(" ");
    QString NomClasse = parts[2];

    // Afficher les informations de manière formattée
    QString infoText = "Informations sur la classe :\n";
    infoText += "Nom de la classe : " + NomClasse + "\n";

    label_infos->setText(infoText);
}

void MainWindow::infoEcue(QListWidgetItem *item) {
    QString classeText = item->text();

    QStringList parts = classeText.split(" ");
    QString NomEcue = parts[2];
    QString Type = parts[6];
    QString NbHeures = parts[11];


    // Afficher les informations de manière formatée
    QString infoText = "Informations sur la classe :\n";
    infoText += "Nom de l'ECUE : " + NomEcue+ "\n";
    infoText += "Type de l'ECUE : " + Type+ "\n";
    infoText += "Nombre d'heures : " + NbHeures+ "\n";

    label_infos->setText(infoText);
}


void MainWindow::apply_global_style() {
    this->setStyleSheet(getGlobalStyle());
}

//SALLE : ajouter et afficher

void MainWindow::ajouterSalle() {
    // Créer une boite de dialogue
    QDialog dialog(this);
    dialog.setWindowTitle("Ajouter une salle");
    dialog.setModal(true);

    // Layout principal
    QVBoxLayout layout(&dialog);

    // Formulaire pour les champs de saisie
    QFormLayout formLayout;
    QLineEdit etageLineEdit;
    QLineEdit numeroLineEdit;

    // Ajouter des validateurs pour les champs "Ã©tage" et "numÃ©ro"
    QIntValidator* intValidator = new QIntValidator(0, 10000000, this); // Limite entre 0 et 1000 pour les entiers
    etageLineEdit.setValidator(intValidator);
    numeroLineEdit.setValidator(intValidator);

    formLayout.addRow("Étage :", &etageLineEdit);
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
        }else if(etageSalleStr.toInt()>9 || numeroSalleStr.toInt()>99){
            QMessageBox::warning(this, "Erreur", "Étage ou Numéro supérieur à la valeur maximale !");
        } else {
            // Conversion des champs en entier
            int etageSalle = etageSalleStr.toInt();
            int numeroSalle = numeroSalleStr.toInt();

            // CrÃ©ation de l'objet Salle
            Salle salle(etageSalle, numeroSalle);

            // Enregistrement dans le fichier CSV
            Factory::saveSalle(salle); // Assurez-vous que cette mÃ©thode est bien dÃ©finie

            Factory::listeSalle.clear();
            Factory::loadSalle();

            afficherSalles();

            // Ajouter la salle Ã  la liste de l'interface utilisateur
            //this->liste_salles->addItem("Salle : " + QString::number(etageSalle) + QString::number(numeroSalle) + " (Etage : " + QString::number(etageSalle) + ", Numero : " + QString::number(numeroSalle) + " )");
            dialog.accept();
        }
    });

    connect(&annulerButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    // Afficher la boÃ®te de dialogue
    dialog.exec();
}

void MainWindow::afficherSalles()
{
    // Charger les salles via Factory
    Factory::listeSalle.clear();
    Factory factory;
    factory.loadSalle();

    // VÃ©rifier que la liste statique n'est pas vide
    if (Factory::listeSalle.empty()) {
        QMessageBox::warning(this, "Erreur", "Aucune salle trouvée dans le fichier !");
        return;
    }

    // Vider la liste graphique avant de la recharger
    this->liste_salles->clear();

    // Ajouter les salles à la liste graphique
    for (const Salle& salle : Factory::listeSalle) {
        QString salleStr = "Salle : " + QString::number(salle.getNumeroComplet()) + " (Étage : " +
                           QString::number(salle.getEtage()) + ", Numéro : " +
                           QString::number(salle.getNumero()) + " )";
        this->liste_salles->addItem(salleStr);
    }
}

// CLASSE : ajouter et afficher


void MainWindow::ajouterClasse() {
    // Créer une boite de dialogue
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
            // CrÃ©ation de la classe
            Classe classe(nomClasse.toStdString());

            // Enregistrement dans le fichier CSV
            Factory::saveClasse(classe);

            Factory::listeClasse.clear();
            Factory::loadClasse();

            afficherClasses();

            // Ajouter la classe à la liste de l'interface utilisateur
                       //this->liste_classes->addItem(nomClasse);
            dialog.accept();
        }
    });
    connect(&annulerButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    // Afficher la boÃ®te de dialogue
    dialog.exec();
}


void MainWindow::afficherClasses()
{
    // Charger les classe via Factory
    Factory::listeClasse.clear();
    Factory factory;
    factory.loadClasse();

    // VÃ©rifier que la liste statique n'est pas vide
    if (Factory::listeClasse.empty()) {
        QMessageBox::warning(this, "Erreur", "Aucune classe trouvée dans le fichier !");
        return;
    }

    // Vider la liste graphique avant de la recharger
    this->liste_classes->clear();

    // Ajouter les classe à la liste graphique
       for (const Classe& classe : Factory::listeClasse) {
    QString classeStr = "Classe : " + QString::fromStdString(classe.getNomClasse());
    this->liste_classes->addItem(classeStr);
}
}

//ECUE : Ajouter et afficher

void MainWindow::ajouterECUE() {
    // CrÃ©er une boite de dialogue
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
    QDoubleValidator* doubleValidator = new QDoubleValidator(0, 1000, 2, &nbHeureLineEdit); // Limite Ã  1000 heures avec 2 dÃ©cimales
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

            Factory::listeEcue.clear();
            Factory::loadEcue();

            afficherEcues();


            // Ajouter l'ECUE à la liste de l'interface utilisateur
                       //this->liste_ecue->addItem(nomECUE + " (" + typeECUE + ", " + QString::number(nbHeuresFloat) + " heures)");
            dialog.accept();
        }
    });

    connect(&annulerButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    // Afficher la boite de dialogue
    dialog.exec();
}

void MainWindow::afficherEcues()
{
    // Charger les ECUE via Factory
    Factory::listeEcue.clear();
    Factory factory;
    factory.loadEcue();

    // VÃ©rifier que la liste statique n'est pas vide
    if (Factory::listeEcue.empty()) {
        QMessageBox::warning(this, "Erreur", "Aucune ECUE trouvée dans le fichier !");
        return;
    }

    // Vider la liste graphique avant de la recharger
    this->liste_ecue->clear();

    // Ajouter les ECUE à la liste graphique
       for (const ECUE& ecue : Factory::listeEcue) {
    QString ecueStr = "ECUE : " + QString::fromStdString(ecue.getNomECUE()) +
                      " | Type : " + QString::fromStdString(ecue.getTypeECUE()) +
                      " | Nb Heures : " + QString::number(ecue.getNbHeures(), 'f', 2); // 'f' pour format flottant, 2 dÃ©cimales
    this->liste_ecue->addItem(ecueStr);
}
}


//ETUDIANTS : ajouter et afficher

void MainWindow::ajouterEtudiant() {
    // Créer une boite de dialogue
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

            Factory::listeEtudiant.clear();
            Factory::loadEtudiant();

            afficherEtudiants();

            // Ajouter l'etudiant à la liste de l'interface utilisateur
                       //this->liste_etudiants->addItem(nom + " " + prenom);
            dialog.accept();
        }
    });
    connect(&annulerButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    // Afficher la boite de dialogue
    dialog.exec();
}

void MainWindow::afficherEtudiants()
{
    // Charger les enseignants via Factory
    Factory::listeEtudiant.clear();
    Factory factory;
    factory.loadEtudiant();

    // Vérifier que la liste statique n'est pas vide
    if (Factory::listeEtudiant.empty()) {
        QMessageBox::warning(this, "Erreur", "Aucun etudiant trouve dans le fichier !");
        return;
    }

    // Vider la liste graphique avant de la recharger
    this->liste_etudiants->clear();

    // Ajouter les enseignants à la liste graphique
       for (const Etudiant& etudiant : Factory::listeEtudiant) {
            QString etudiantStr = QString::fromStdString(etudiant.getNom()) + " " +
                          QString::fromStdString(etudiant.getPrenom());
    this->liste_etudiants->addItem(etudiantStr);
}
}

//ENSEIGANTS : ajouter et afficher

void MainWindow::ajouterEnseignant() {
    // Créer une boite de dialogue
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
            // CrÃ©ation de l'enseignant
            Enseignant enseignant(prenom.toStdString(), nom.toStdString());

            // Enregistrement dans le fichier CSV
            Factory::saveEnseignant(enseignant);

            Factory::listeEnseignant.clear();
            Factory::loadEnseignant();

            afficherEnseignants();

            // Ajouter l'enseignant à la liste de l'interface utilisateur
                       //this->liste_enseignants->addItem(nom + " " + prenom);
            dialog.accept();
        }
    });
    connect(&annulerButton, &QPushButton::clicked, &dialog, &QDialog::reject);

    // Afficher la boite de dialogue
    dialog.exec();
}

void MainWindow::afficherEnseignants()
{
    // Charger les enseignants via Factory
    Factory::listeEnseignant.clear();
    Factory factory;
    factory.loadEnseignant();

    // VÃ©rifier que la liste statique n'est pas vide
    if (Factory::listeEnseignant.empty()) {
        QMessageBox::warning(this, "Erreur", "Aucun enseignant trouvé dans le fichier !");
        return;
    }

    // Vider la liste graphique avant de la recharger
    this->liste_enseignants->clear();

    // Ajouter les enseignants à la liste graphique
       for (const Enseignant& enseignant : Factory::listeEnseignant) {
                QString enseignantStr = QString::fromStdString(enseignant.getNom()) + " " +
                QString::fromStdString(enseignant.getPrenom());
    this->liste_enseignants->addItem(enseignantStr);
    }
}

void MainWindow::suppSalle(){
    QListWidgetItem* infos = liste_salles->currentItem();
    if(infos != nullptr){
        QString info = infos->text();
        QStringList infoSplit = info.split(" ");
        Salle salle = Controleur::findSalleByNumero(infoSplit[2]).value();
        Factory::suppSalle(salle);
        Factory::listeSalle.clear();
        Factory::loadSalle();
        liste_salles->clear();
        MainWindow::afficherSalles();
    }
}
void MainWindow::suppClasse(){
    QListWidgetItem* infos = liste_classes->currentItem();
    if(infos != nullptr){
        QString info = infos->text();
        QStringList infoSplit = info.split(" ");
        Classe classe = Controleur::findClasseByNomClasse(infoSplit[2]).value();
        Factory::suppClasse(classe);
        Factory::listeClasse.clear();
        Factory::loadClasse();
        liste_classes->clear();
        MainWindow::afficherClasses();
    }
}
void MainWindow::suppEtudiant(){
    QListWidgetItem* infos = liste_etudiants->currentItem();
    if(infos != nullptr){
        QString info = infos->text();
        Etudiant etudiant = Controleur::findEtudiantByNomPrenom(info).value();
        Factory::suppEtudiant(etudiant);
        Factory::listeEtudiant.clear();
        Factory::loadEtudiant();
        liste_etudiants->clear();
        MainWindow::afficherEtudiants();
    }
}
void MainWindow::suppEnseignant(){
    QListWidgetItem* infos = liste_enseignants->currentItem();
    if(infos != nullptr){
        QString info = infos->text();
        Enseignant enseignant = Controleur::findEnseignantByNomPrenom(info).value();
        Factory::suppEnseignant(enseignant);
        Factory::listeEnseignant.clear();
        Factory::loadEnseignant();
        liste_enseignants->clear();
        MainWindow::afficherEnseignants();
    }
}
void MainWindow::suppEcue(){
    QListWidgetItem* infos = liste_ecue->currentItem();
    if(infos != nullptr){
        QString info = infos->text();
        QStringList infoSplit = info.split(" ");
        ECUE ecue = Controleur::findECUEByNom(infoSplit[2]).value();
        Factory::suppEcue(ecue);
        Factory::listeEcue.clear();
        Factory::loadEcue();
        liste_ecue->clear();
        MainWindow::afficherEcues();
    }
}

