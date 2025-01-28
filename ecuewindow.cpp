#include "ecuewindow.h"

ECUEWindow::ECUEWindow(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Ajouter une ECUE");
    this->setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout;

    nomECUELineEdit = new QLineEdit;
    typeECUELineEdit = new QLineEdit;
    nbHeuresLineEdit = new QLineEdit; // Initialisation du QLineEdit pour le nombre d'heures

    formLayout->addRow("Nom ECUE :", nomECUELineEdit);
    formLayout->addRow("Type ECUE :", typeECUELineEdit);
    formLayout->addRow("Nombre d'heures :", nbHeuresLineEdit); // Ajout du champ pour le nombre d'heures
    layout->addLayout(formLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *validerButton = new QPushButton("Valider");
    QPushButton *annulerButton = new QPushButton("Annuler");

    buttonLayout->addWidget(validerButton);
    buttonLayout->addWidget(annulerButton);
    layout->addLayout(buttonLayout);

    connect(validerButton, &QPushButton::clicked, this, &ECUEWindow::valider);
    connect(annulerButton, &QPushButton::clicked, this, &QDialog::reject);
}

void ECUEWindow::valider() {
    bool conversionOk = false; // Pour vérifier la conversion en float
    nbHeuresLineEdit->text().toFloat(&conversionOk); // Essayer de convertir en float


    if (nomECUELineEdit->text().isEmpty() || typeECUELineEdit->text().isEmpty() || nbHeuresLineEdit->text().isEmpty() || !conversionOk) {
        if(!conversionOk)
            QMessageBox::warning(this, "Erreur", "Le nombre d'heures doit être un nombre !");
        else
            QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
    } else {
        accept();
    }
}

ECUE ECUEWindow::getECUE() const
{
    float nbHeures = nbHeuresLineEdit->text().toFloat();
    return ECUE(nomECUELineEdit->text().toStdString(), typeECUELineEdit->text().toStdString(), nbHeures);
}
