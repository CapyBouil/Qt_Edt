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
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QDate>

#include "etudiantwindow.h"
#include "enseignantwindow.h"
#include"ecuewindow.h"
#include "style.h"
#include"sallewindow.h"
#include "classewindow.h"
#include "lierecuewindow.h"
#include "creneauwindow.h"
#include "controleur.h"
#include"factory.h"

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
    QPushButton* bouton_lier_ecue;
    QPushButton* bouton_supprimer_enseignant;
    QListWidget* liste_classes;
    QPushButton* bouton_ajouter_classe;
    QPushButton* bouton_supprimer_classe;
    QListWidget* liste_ecue;
    QPushButton* bouton_ajouter_ecue;
    QPushButton* bouton_lier_enseignant;
    QPushButton* bouton_supprimer_ecue;
    QListWidget* liste_salles;
    QPushButton* bouton_ajouter_salle;
    QPushButton* bouton_supprimer_salle;
    QListWidget* liste_etudiants;
    QPushButton* bouton_ajouter_etudiant;
    QPushButton* bouton_supprimer_etudiant;
    QLabel* imageLabel;
    QVBoxLayout* layout_infos;
    QLabel* label_infos;
    QPushButton* bouton_semaine_precedente;
    QPushButton* bouton_semaine_suivante;
    QHBoxLayout* bouton_layout_semaine;
    QTableWidget* calendrier;
    QDate refDate;
    QHBoxLayout* bouton_layout_creneau;
    QPushButton* bouton_ajouter_creneau;
    QPushButton* bouton_supprimer_creneau;

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void init_composants(void);
    void init_layout(void);
    void init_slots(void);
    void ajouterEnseignant();
    void ajouterEtudiant();
    void ajouterECUE();
    void ajouterSalle();
    void ajouterClasse();
    void apply_global_style();
    void lierECUE();
    void ajouterCreneau();
    void resetCalendrier(QDate referenceDate);
    void semainePrecedente();
    void semaineSuivante();
};

#endif // MAINWINDOW_H
