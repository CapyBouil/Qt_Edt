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
    if (nomLineEdit->text().isEmpty() || prenomLineEdit->text().isEmpty()){
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
