#include "lierecuewindow.h"

LierECUEWindow::LierECUEWindow(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Lier ECUE à un enseignant");
    this->setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(this);

    ecueComboBox = new QComboBox;
    enseignantComboBox = new QComboBox;

    QStringList ecues = chargerECUEs();
    QStringList enseignants = chargerEnseignants();

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

    ecueComboBox->addItems(ecues);
    enseignantComboBox->addItems(enseignants);

    layout->addWidget(ecueComboBox);
    layout->addWidget(enseignantComboBox);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *validerButton = new QPushButton("Valider");
    QPushButton *annulerButton = new QPushButton("Annuler");
    buttonLayout->addWidget(validerButton);
    buttonLayout->addWidget(annulerButton);
    layout->addLayout(buttonLayout);

    connect(validerButton, &QPushButton::clicked, this, &LierECUEWindow::valider);
    connect(annulerButton, &QPushButton::clicked, this, &QDialog::reject);
}

QStringList LierECUEWindow::chargerECUEs() {
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

QStringList LierECUEWindow::chargerEnseignants() {
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
            nomsEnseignants.append(fields[1] + " " + fields[2]);
        }
    }

    file.close();
    return nomsEnseignants;
}

void LierECUEWindow::valider() {
    if (ecueComboBox->currentText().isEmpty() || enseignantComboBox->currentText().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ECUE et un enseignant.");
    } else {
        accept();
    }
}

QString LierECUEWindow::getECUESelectionnee() const {
    return ecueComboBox->currentText();
}

QString LierECUEWindow::getEnseignantSelectionne() const {
    return enseignantComboBox->currentText();
}
