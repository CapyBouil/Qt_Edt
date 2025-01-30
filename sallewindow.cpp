#include "sallewindow.h"


SalleWindow::SalleWindow(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Ajouter une salle");
    setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout();

    etageLineEdit = new QLineEdit;
    numeroLineEdit = new QLineEdit;

    // Valideur pour les nombres entiers positifs
    QIntValidator *validatorEtage = new QIntValidator(0, 9, this);
    QIntValidator *validatorNumero = new QIntValidator(0, 99, this);

    // Assigner les validateurs
    etageLineEdit->setValidator(validatorEtage);
    numeroLineEdit->setValidator(validatorNumero);

    // Limiter la longueur des entrées
    etageLineEdit->setInputMask("9");   // Un seul chiffre (0-9)
    numeroLineEdit->setInputMask("99"); // Deux chiffres obligatoires (00-99)


    formLayout->addRow("Numéro de l'étage :", etageLineEdit);
    formLayout->addRow("Numéro de la salle :", numeroLineEdit);
    layout->addLayout(formLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *validerButton = new QPushButton("Valider");
    QPushButton *annulerButton = new QPushButton("Annuler");
    buttonLayout->addWidget(validerButton);
    buttonLayout->addWidget(annulerButton);
    layout->addLayout(buttonLayout);

    connect(validerButton, &QPushButton::clicked, this, &SalleWindow::valider);
    connect(annulerButton, &QPushButton::clicked, this, &QDialog::reject);
}

void SalleWindow::valider() {
    if (etageLineEdit->text().isEmpty() || numeroLineEdit->text().isEmpty() ) {
        QMessageBox::warning(this, "Erreur", "Le numéro d'étage et le numéro de la salle ne peuvent pas être vides.");
    }else{accept();}
}

QString SalleWindow::getEtage() const {
    return etageLineEdit->text();
}

QString SalleWindow::getNumero() const {
    return numeroLineEdit->text();
}
