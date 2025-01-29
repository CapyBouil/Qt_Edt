// lierecuewindow.h
#ifndef LIERETUDIANTWINDOW_H
#define LIERETUDIANTWINDOW_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QStringList>
#include <QFile>
#include <QTextStream>



class LierEtudiantWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LierEtudiantWindow(QWidget *parent = nullptr);
    QString getEtudiantSelectionnee() const;
    QString getClasseSelectionne() const;

private slots:
    void valider();

private:
    QStringList chargerClasses();
    QStringList chargerEtudiants();

    QComboBox *etudiantComboBox;
    QComboBox *classeComboBox;
};

#endif // LIERETUDIANTWINDOW_H
