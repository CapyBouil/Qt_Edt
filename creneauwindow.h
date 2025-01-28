#ifndef CRENEAUWINDOW_H
#define CRENEAUWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include <QTimeEdit>
#include <QMessageBox>

class CreneauWindow : public QDialog
{
    Q_OBJECT

public:
    CreneauWindow(QWidget *parent);

    QString getSalle() const;
    QString getClasse() const;
    QString getECUE() const;
    QString getEnseignant() const;
    QString getJour() const;
    QString getHeureDebut() const;
    QString getHeureFin() const;

private:
    QComboBox *salleComboBox;
    QComboBox *classeComboBox;
    QComboBox *ecueComboBox;
    QComboBox *enseignantComboBox;
    QDateEdit *jourQDateEdit;
    QTimeEdit *heureDebutQTimeEdit;
    QTimeEdit *heureFinQTimeEdit;

private:
    void valider();
};

#endif // CRENEAUWINDOW_H
