#ifndef CLASSEWINDOW_H
#define CLASSEWINDOW_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFormLayout>

#include "factory.h"
#include "classe.h"

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
