#ifndef SALLEWINDOW_H
#define SALLEWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFormLayout>
#include <QValidator>
#include <iostream>

class SalleWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SalleWindow(QWidget *parent = nullptr);
    QString getEtage() const;
    QString getNumero() const;


private slots:
    void valider();

private:
    QLineEdit *etageLineEdit;
    QLineEdit *numeroLineEdit;
};

#endif // SALLEWINDOW_H
