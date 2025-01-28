#include "ecuewindow.h"
#include <QIntValidator>


ECUEWindow::ECUEWindow(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Ajouter une ECUE");
    this->setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout;

    nomECUELineEdit = new QLineEdit;
    typeECUELineEdit = new QLineEdit;
    nbHeuresLineEdit = new QLineEdit;

    // Valideur pour les nombres entiers positifs (0 à 999)
    QIntValidator *validator = new QIntValidator(0, 999, this);
    nbHeuresLineEdit->setValidator(validator);

    formLayout->addRow("Nom ECUE :", nomECUELineEdit);
    formLayout->addRow("Type ECUE :", typeECUELineEdit);
    formLayout->addRow("Nombre d'heures :", nbHeuresLineEdit);
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
    if (nomECUELineEdit->text().isEmpty() || typeECUELineEdit->text().isEmpty() || nbHeuresLineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
    } else {
        accept();
    }
}

ECUE ECUEWindow::getECUE() const
{
    int nbHeures = nbHeuresLineEdit->text().toInt();
    return ECUE(nomECUELineEdit->text().toStdString(), typeECUELineEdit->text().toStdString(), nbHeures);
}
