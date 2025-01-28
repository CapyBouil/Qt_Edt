#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QSplitter>
#include <QList>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QTableWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QCalendarWidget>
#include <QHBoxLayout>
#include <QHeaderView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QBoxLayout *main_layout;
    QSplitter* splitter;
    QList<int>* sizes;
    QWidget* leftWidget;
    QWidget* rightWidget;
    QVBoxLayout* leftLayout;
    QVBoxLayout* rightLayout;
    QTabWidget* tabWidget;
    QVBoxLayout* layout_enseignants;
    QVBoxLayout* layout_classes;
    QVBoxLayout* layout_ecue;
    QVBoxLayout* layout_salles;
    QVBoxLayout* layout_etudiants;
    QHBoxLayout* bouton_layout_enseignants;
    QHBoxLayout* bouton_layout_classes;
    QHBoxLayout* bouton_layout_ecue;
    QHBoxLayout* bouton_layout_salles;
    QHBoxLayout* bouton_layout_etudiants;
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
    QListWidget* liste_etudiants;
    QPushButton* bouton_ajouter_etudiant;
    QPushButton* bouton_modifier_etudiant;
    QPushButton* bouton_supprimer_etudiant;
    QLabel* imageLabel;
    QVBoxLayout* layout_infos;
    QLabel* label_infos;
    QTableWidget* calendrier;
    QHBoxLayout* bouton_layout_creneau;
    QPushButton* bouton_ajouter_creneau;
    QPushButton* bouton_modifier_creneau;
    QPushButton* bouton_supprimer_creneau;

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void init_composants(void);
    void init_layout(void);
    void init_slots(void);
};

#endif // MAINWINDOW_H
