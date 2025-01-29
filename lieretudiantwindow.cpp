#include "lieretudiantwindow.h"

LierEtudiantWindow::LierEtudiantWindow(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Lier classe à un etudiant");
    this->setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(this);

    classeComboBox = new QComboBox;
    etudiantComboBox = new QComboBox;

    QStringList classe = chargerClasses();
    QStringList etudiant = chargerEtudiants();

    if (etudiant.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "La liste des etudiants est vide ou le fichier n'a pas pu être chargé.");
        reject();
        return;
    }

    if (classe.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "La liste des classe est vide ou le fichier n'a pas pu être chargé.");
        reject();
        return;
    }

    classeComboBox->addItems(classe);
    etudiantComboBox->addItems(etudiant);

    layout->addWidget(etudiantComboBox);
    layout->addWidget(classeComboBox);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *validerButton = new QPushButton("Valider");
    QPushButton *annulerButton = new QPushButton("Annuler");
    buttonLayout->addWidget(validerButton);
    buttonLayout->addWidget(annulerButton);
    layout->addLayout(buttonLayout);

    connect(validerButton, &QPushButton::clicked, this, &LierEtudiantWindow::valider);
    connect(annulerButton, &QPushButton::clicked, this, &QDialog::reject);
}

QStringList LierEtudiantWindow::chargerClasses() {
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

QStringList LierEtudiantWindow::chargerEtudiants() {
    QStringList nomsEtudiants;
    QFile file("../../data/Etudiant.csv"); // Adaptez le chemin et le format

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier Enseignants.csv");
        return nomsEtudiants;
    }

    QTextStream in(&file);
    in.readLine();
    while (!in.atEnd()) {                      //J'ai enlevé la ligne d'en tete pour lire la premiere ligne
        QString line = in.readLine();
        QStringList fields = line.split(";");
        if (fields.size() >= 2) {
            nomsEtudiants.append(fields[1].trimmed());
        }
    }

    file.close();
    return nomsEtudiants;
}

void LierEtudiantWindow::valider() {
    if (classeComboBox->currentText().isEmpty() || etudiantComboBox->currentText().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une classe et un etudiant.");
    } else {
        accept();
    }
}

QString LierEtudiantWindow::getClasseSelectionne() const {
    return classeComboBox->currentText();
}

QString LierEtudiantWindow::getEtudiantSelectionnee() const {
    return etudiantComboBox->currentText();
}
