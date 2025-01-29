#include "creneauwindow.h"

CreneauWindow::CreneauWindow(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Ajouter creneau");
    this->setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout;

    salleComboBox = new QComboBox;
    classeComboBox = new QComboBox;
    ecueComboBox = new QComboBox;
    enseignantComboBox = new QComboBox;
    jourQDateEdit = new QDateEdit(QDate::currentDate());
    heureDebutQTimeEdit = new QTimeEdit();
    heureFinQTimeEdit = new QTimeEdit();

    // Définir le pas pour les QTimeEdit
    heureDebutQTimeEdit->setDisplayFormat("HH");
    heureDebutQTimeEdit->setTimeRange(QTime(8, 0), QTime(18, 0));
    //heureDebutQTimeEdit->setInterval(60); // Pas de 1 heure

    heureFinQTimeEdit->setDisplayFormat("HH");
    heureFinQTimeEdit->setTimeRange(QTime(8, 0), QTime(18, 0));
    //heureFinQTimeEdit->setInterval(60); // Pas de 1 heure

    formLayout->addRow("Salle :", salleComboBox);
    formLayout->addRow("Classe :", classeComboBox);
    formLayout->addRow("ECUE :", ecueComboBox);
    formLayout->addRow("Enseignant :", enseignantComboBox);
    formLayout->addRow("Jour :", jourQDateEdit);
    formLayout->addRow("Heure de debut :", heureDebutQTimeEdit);
    formLayout->addRow("Heure de fin :", heureFinQTimeEdit);
    layout->addLayout(formLayout);

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


