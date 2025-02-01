#include "classewindow.h"

ClasseWindow::ClasseWindow(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Ajouter une classe");
    setModal(true);

    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout();

    nomClasseLineEdit = new QLineEdit;
    formLayout->addRow("Nom de la classe :", nomClasseLineEdit);
    layout->addLayout(formLayout);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QPushButton *validerButton = new QPushButton("Valider");
    QPushButton *annulerButton = new QPushButton("Annuler");
    buttonLayout->addWidget(validerButton);
    buttonLayout->addWidget(annulerButton);
    layout->addLayout(buttonLayout);

    connect(validerButton, &QPushButton::clicked, this, &ClasseWindow::valider);
    connect(annulerButton, &QPushButton::clicked, this, &QDialog::reject);
}

void ClasseWindow::valider() {
    QString nomClasse = nomClasseLineEdit->text();

    if (nomClasse.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
    } else {
        // Creation de la classe
        Classe classe(nomClasse.toStdString());

        // Enregistrement dans le fichier CSV
        Factory::saveClasse(classe);

        Factory::listeClasse.clear();
        Factory::loadClasse();

        accept();
    }
}

QString ClasseWindow::getNomClasse() const {
    return nomClasseLineEdit->text();
}
