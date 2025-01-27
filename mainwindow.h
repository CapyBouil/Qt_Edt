#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QApplication>
#include <QSplitter>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QCalendarWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QBoxLayout *main_layout;
    QSplitter* splitter;
    QWidget* leftWidget;
    QWidget* rightWidget;
    QVBoxLayout* leftLayout;
    QVBoxLayout* rightLayout;
    QTabWidget* tabWidget;
    QVBoxLayout* layout_enseignants;
    QVBoxLayout* layout_classes;
    QVBoxLayout* layout_ecue;
    QVBoxLayout* layout_salles;
    QListWidget* liste_enseignants;
    QPushButton* bouton_ajouter_enseignant;
    QPushButton* bouton_modifier_enseignant;
    QPushButton* bouton_supprimer_enseignant;
    QListWidget* liste_classes;
    QPushButton* bouton_ajouter_classe;
    QPushButton* bouton_modifier_classe;
    QPushButton* bouton_supprimer_classe;
    QListWidget* liste_ecue;
    QPushButton* bouton_ajouter_ecue;
    QPushButton* bouton_modifier_ecue;
    QPushButton* bouton_supprimer_ecue;
    QListWidget* liste_salles;
    QPushButton* bouton_ajouter_salle;
    QPushButton* bouton_modifier_salle;
    QPushButton* bouton_supprimer_salle;
    QLabel* imageLabel;
    QVBoxLayout* layout_infos;
    QCalendarWidget* calendrier;
    QPushButton* bouton_ajouter_creneau;
    QPushButton* bouton_modifier_creneau;
    QPushButton* bouton_supprimer_creneau;

public:
    MainWindow(QWidget *parent = nullptr);

private:
    void init_composants(void);
    void init_layout(void);
    void init_slots(void);
};

#endif // MAINWINDOW_H
