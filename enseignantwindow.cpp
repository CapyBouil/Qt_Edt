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

    formLayout->addRow("Nom :", nomLineEdit);
    formLayout->addRow("Prénom :", prenomLineEdit);
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


void EnseignantWindow::valider() {
    QString prenom = prenomLineEdit->text();
    QString nom = nomLineEdit->text();

    if (nom.isEmpty() || prenom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
    } else {
        // Création de l'enseignant
        Enseignant enseignant(prenom.toStdString(), nom.toStdString());

        // Enregistrement dans le fichier CSV
        Factory::saveEnseignant(enseignant);

        Factory::listeEnseignant.clear();
        Factory::loadEnseignant();

        accept();
    }
}

QString EnseignantWindow::getNom() const {
    return nomLineEdit->text();
}

QString EnseignantWindow::getPrenom() const {
    return prenomLineEdit->text();
}


