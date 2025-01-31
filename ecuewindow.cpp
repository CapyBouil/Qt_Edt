#include "ecuewindow.h"

ECUEWindow::ECUEWindow(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Ajouter une ECUE");
    this->setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout;

    nomECUELineEdit = new QLineEdit;
    typeECUEComboBox = new QComboBox;
    nbHeuresLineEdit = new QLineEdit;

    // Ajouter les éléments au comboBox
    typeECUEComboBox->addItem("CM");
    typeECUEComboBox->addItem("TD");
    typeECUEComboBox->addItem("TP");
    typeECUEComboBox->addItem("NT");

    // Valideur pour les nombres entiers positifs (0 à 999)
    QIntValidator *validator = new QIntValidator(0, 999, this);
    nbHeuresLineEdit->setValidator(validator);

    formLayout->addRow("Nom ECUE :", nomECUELineEdit);
    formLayout->addRow("Type ECUE :", typeECUEComboBox);
    formLayout->addRow("Nombre d'heures :", nbHeuresLineEdit);
    layout->addLayout(formLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *validerButton = new QPushButton("Valider");
    QPushButton *annulerButton = new QPushButton("Annuler");
    buttonLayout->addWidget(validerButton);
    buttonLayout->addWidget(annulerButton);
    layout->addLayout(buttonLayout);

    // Connexion des boutons
    connect(validerButton, &QPushButton::clicked, this, &ECUEWindow::valider);
    connect(annulerButton, &QPushButton::clicked, this, &QDialog::reject);
}

void ECUEWindow::valider() {
    QString nomECUE = nomECUELineEdit->text();
    QString typeECUE = typeECUEComboBox->currentText();
    QString nbHeures = nbHeuresLineEdit->text();

    if (nomECUE.isEmpty() || typeECUE.isEmpty() || nbHeures.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
    } else {
        // Conversion du champ Nombre d'heures en float
        float nbHeuresFloat = nbHeures.toFloat();

        // Création de l'ECUE
        ECUE ecue(nomECUE.toStdString(), typeECUE.toStdString(), nbHeuresFloat);

        // Enregistrement dans le fichier CSV
        Factory::saveECUE(ecue); // Assurez-vous que la méthode saveECUE() est implémentée dans la classe ECUE

        Factory::listeEcue.clear();
        Factory::loadEcue();

        // Ajouter l'ECUE à la liste de l'interface utilisateur
        //this->liste_ecue->addItem(nomECUE + " (" + typeECUE + ", " + QString::number(nbHeuresFloat) + " heures)");
        accept();
    }
}

ECUE ECUEWindow::getECUE() const
{
    int nbHeures = nbHeuresLineEdit->text().toInt();
    return ECUE(nomECUELineEdit->text().toStdString(), typeECUEComboBox->currentText().toStdString(), nbHeures);
}
