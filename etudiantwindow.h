#ifndef ETUDIANTWINDOW_H
#define ETUDIANTWINDOW_H

#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <qiodevice.h>

class EtudiantWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EtudiantWindow(QWidget *parent = nullptr);
    QString getNom() const;
    QString getPrenom() const;


private slots:
    void valider();

private:
    QLineEdit *nomLineEdit;
    QLineEdit *prenomLineEdit;

};

#endif // ETUDIANTWINDOW_H
