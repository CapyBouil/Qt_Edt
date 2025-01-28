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
    if (nomClasseLineEdit->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom de la classe ne peut pas être vide.");
    } else {
        accept();
    }
}

QString ClasseWindow::getNomClasse() const {
    return nomClasseLineEdit->text();
}
