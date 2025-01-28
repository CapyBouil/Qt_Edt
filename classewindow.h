#ifndef CLASSEWINDOW_H
#define CLASSEWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFormLayout> // Ajouté pour le layout du formulaire


class ClasseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ClasseWindow(QWidget *parent = nullptr);
    QString getNomClasse() const;

private slots:
    void valider();

private:
    QLineEdit *nomClasseLineEdit;
};

#endif // CLASSEWINDOW_H
