#ifndef ECUEWINDOW_H
#define ECUEWINDOW_H

#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QValidator>
#include "ecue.h"

class ECUEWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ECUEWindow(QWidget *parent = nullptr);
    ECUE getECUE() const;

private slots:
    void valider();

private:
    QLineEdit *nomECUELineEdit;
    QLineEdit *typeECUELineEdit;
    QLineEdit *nbHeuresLineEdit; // Pour la saisie du nombre d'heures


};

#endif // ECUEWINDOW_H
