#include "creneauwindow.h"

CreneauWindow::CreneauWindow(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Ajouter creneau");
    this->setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout;

    this->salleComboBox = new QComboBox;
    this->classeComboBox = new QComboBox;
    this->ecueComboBox = new QComboBox;
    this->enseignantComboBox = new QComboBox;
    this->jourQDateEdit = new QDateEdit(QDate::currentDate());
    this->heureDebutQTimeEdit = new QTimeEdit();
    this->heureFinQTimeEdit = new QTimeEdit();

    // Définir la format de la date
    this->jourQDateEdit->setDisplayFormat("MM/dd/yyyy");

    // Définir le pas pour les QTimeEdit
    heureDebutQTimeEdit->setDisplayFormat("HH");
    heureDebutQTimeEdit->setTimeRange(QTime(8, 0), QTime(18, 0));

    heureFinQTimeEdit->setDisplayFormat("HH");
    heureFinQTimeEdit->setTimeRange(QTime(8, 0), QTime(18, 0));

    formLayout->addRow("Salle :", salleComboBox);
    formLayout->addRow("Classe :", classeComboBox);
    formLayout->addRow("ECUE :", ecueComboBox);
    formLayout->addRow("Enseignant :", enseignantComboBox);
    formLayout->addRow("Jour :", jourQDateEdit);
    formLayout->addRow("Heure de debut :", heureDebutQTimeEdit);
    formLayout->addRow("Heure de fin :", heureFinQTimeEdit);
    layout->addLayout(formLayout);

    QStringList salles = chargerSalles();
    QStringList classes = chargerClasses();
    QStringList ecues = chargerECUEs();
    QStringList enseignants = chargerEnseignants();

    if (salles.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "La liste des salles est vide ou le fichier n'a pas pu être chargé.");
        reject();
        return;
    }

    if (classes.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "La liste des classes est vide ou le fichier n'a pas pu être chargé.");
        reject();
        return;
    }

    if (ecues.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "La liste des ECUE est vide ou le fichier n'a pas pu être chargé.");
        reject();
        return;
    }

    if (enseignants.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "La liste des enseignants est vide ou le fichier n'a pas pu être chargé.");
        reject();
        return;
    }

    salleComboBox->addItems(salles);
    classeComboBox->addItems(classes);
    ecueComboBox->addItems(ecues);
    enseignantComboBox->addItems(enseignants);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *validerButton = new QPushButton("Valider");
    QPushButton *annulerButton = new QPushButton("Annuler");
    buttonLayout->addWidget(validerButton);
    buttonLayout->addWidget(annulerButton);
    layout->addLayout(buttonLayout);

    connect(validerButton, &QPushButton::clicked, this, &CreneauWindow::valider);
    connect(annulerButton, &QPushButton::clicked, this, &QDialog::reject);
}

void CreneauWindow::valider() {
    if (salleComboBox->currentText().isEmpty() || classeComboBox->currentText().isEmpty() || ecueComboBox->currentText().isEmpty()
        || enseignantComboBox->currentText().isEmpty() || jourQDateEdit->text().isEmpty() || heureDebutQTimeEdit->text().isEmpty()
        || heureFinQTimeEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
    } else {
        accept();
    }
}

QString CreneauWindow::getSalle() const {
    return salleComboBox->currentText();
}

QString CreneauWindow::getClasse() const {
    return classeComboBox->currentText();
}

QString CreneauWindow::getECUE() const {
    return ecueComboBox->currentText();
}

QString CreneauWindow::getEnseignant() const {
    return enseignantComboBox->currentText();
}

QString CreneauWindow::getJour() const {
    return jourQDateEdit->text();
}

QString CreneauWindow::getHeureDebut() const {
    return heureDebutQTimeEdit->text();
}

QString CreneauWindow::getHeureFin() const {
    return heureFinQTimeEdit->text();
}

QStringList CreneauWindow::chargerSalles() {
    QStringList nomSalle;
    QFile file("../../data/salle.csv"); // Adaptez le chemin si nécessaire

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier classe.csv");
        return nomSalle;
    }

    QTextStream in(&file);
    in.readLine(); // Ignorer l'en-tête
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(";");
        if (!fields.isEmpty()) {
            nomSalle.append(fields[1].trimmed()+fields[2].trimmed());
        }
    }
    file.close();
    return nomSalle;
}

QStringList CreneauWindow::chargerClasses() {
    QStringList nomClasse;
    QFile file("../../data/classe.csv"); // Adaptez le chemin si nécessaire

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier classe.csv");
        return nomClasse;
    }

    QTextStream in(&file);
    in.readLine(); // Ignorer l'en-tête
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(";");
        if (!fields.isEmpty()) {
            nomClasse.append(fields[1].trimmed());
        }
    }
    file.close();
    return nomClasse;
}

QStringList CreneauWindow::chargerECUEs() {
    QStringList nomECUEs;
    QFile file("../../data/ECUE.csv"); // Adaptez le chemin si nécessaire

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier ECUE.csv");
        return nomECUEs;
    }

    QTextStream in(&file);
    in.readLine(); // Ignorer l'en-tête
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(";");
        if (!fields.isEmpty()) {
            nomECUEs.append(fields[1].trimmed());
        }
    }
    file.close();
    return nomECUEs;
}

QStringList CreneauWindow::chargerEnseignants() {
    QStringList nomsEnseignants;
    QFile file("../../data/Enseignant.csv"); // Adaptez le chemin et le format

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier Enseignants.csv");
        return nomsEnseignants;
    }

    QTextStream in(&file);
    in.readLine();
    while (!in.atEnd()) {                      //J'ai enlevé la ligne d'en tete pour lire la premiere ligne
        QString line = in.readLine();
        QStringList fields = line.split(";");
        if (fields.size() >= 2) {
            nomsEnseignants.append(fields[1].trimmed()+" "+fields[2].trimmed());
        }
    }

    file.close();
    return nomsEnseignants;
}


