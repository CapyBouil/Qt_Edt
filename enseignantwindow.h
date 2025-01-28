#ifndef ENSEIGNANTWINDOW_H
#define ENSEIGNANTWINDOW_H

#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QComboBox>

class EnseignantWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EnseignantWindow(QWidget *parent = nullptr);
    QString getNom() const;
    QString getPrenom() const;

private slots:
    void valider();
private:


private:
    QLineEdit *nomLineEdit;
    QLineEdit *prenomLineEdit;
};

#endif // ENSEIGNANTWINDOW_H
