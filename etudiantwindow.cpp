#include "etudiantwindow.h"

EtudiantWindow::EtudiantWindow(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Ajouter un étudiant");
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

    connect(validerButton, &QPushButton::clicked, this, &EtudiantWindow::valider);
    connect(annulerButton, &QPushButton::clicked, this, &QDialog::reject);
}


void EtudiantWindow::valider() {
    if (nomLineEdit->text().isEmpty() || prenomLineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
    } else {
        accept();
    }
}

QString EtudiantWindow::getNom() const {
    return nomLineEdit->text();
}

QString EtudiantWindow::getPrenom() const {
    return prenomLineEdit->text();
}


