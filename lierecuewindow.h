// lierecuewindow.h
#ifndef LIERECUEWINDOW_H
#define LIERECUEWINDOW_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QStringList>
#include <QFile>
#include <QTextStream>



class LierECUEWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LierECUEWindow(QWidget *parent = nullptr);
    QString getECUESelectionnee() const;
    QString getEnseignantSelectionne() const;

private slots:
    void valider();

private:
    QStringList chargerECUEs();
    QStringList chargerEnseignants();

    QComboBox *ecueComboBox;
    QComboBox *enseignantComboBox;
};

#endif // LIERECUEWINDOW_H
