#include "enseignantwindow.h"
#include <QFile>
#include <QTextStream>

EnseignantWindow::EnseignantWindow(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Ajouter un enseignant");
    this->setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout;

    nomLineEdit = new QLineEdit;
    prenomLineEdit = new QLineEdit;
    ecueComboBox = new QComboBox;


    // Charger les ECUEs depuis le fichier CSV
    QStringList ecues = chargerECUEs();
    if (ecues.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "La liste des ECUE est vide ou le fichier n'a pas pu être chargé.");
        // Gérer le cas où le chargement échoue (fermer la fenêtre, désactiver le bouton, etc.)
        reject(); // ou autre gestion d'erreur appropriée
        return;
    }

    ecueComboBox->addItems(ecues);

    formLayout->addRow("Nom :", nomLineEdit);
    formLayout->addRow("Prénom :", prenomLineEdit);
    formLayout->addRow("ECUE :", ecueComboBox);
    layout->addLayout(formLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *validerButton = new QPushButton("Valider");
    QPushButton *annulerButton = new QPushButton("Annuler");

    buttonLayout->addWidget(validerButton);
    buttonLayout->addWidget(annulerButton);
    layout->addLayout(buttonLayout);

    connect(validerButton, &QPushButton::clicked, this, &EnseignantWindow::valider);
    connect(annulerButton, &QPushButton::clicked, this, &QDialog::reject);


}

QStringList EnseignantWindow::chargerECUEs() {
    QStringList nomECUEs;
    QFile file("../../data/ECUE.csv"); // Chemin vers le fichier ECUE.csv

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier ECUE.csv");
        return nomECUEs; // Retourner une liste vide en cas d'erreur
    }

    QTextStream in(&file);
    QString header = in.readLine(); // Lire la première ligne (en-têtes)
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(";"); // Séparer les colonnes par une virgule
        if (fields.size() > 0) {
            nomECUEs.append(fields[0].trimmed()); // Ajouter uniquement la colonne NomECUE
        }
    }

    file.close();
    return nomECUEs;
}



void EnseignantWindow::valider() {
    if (nomLineEdit->text().isEmpty() || prenomLineEdit->text().isEmpty() || ecueComboBox->currentText().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
    } else {
        accept();
    }
}

QString EnseignantWindow::getNom() const {
    return nomLineEdit->text();
}

QString EnseignantWindow::getPrenom() const {
    return prenomLineEdit->text();
}

QString EnseignantWindow::getECUE() const {
    return ecueComboBox->currentText();
}
