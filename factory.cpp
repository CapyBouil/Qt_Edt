#include "factory.h"

Factory::Factory() {}

void Factory::zob(){
    std::cout << QDir::currentPath().toStdString() << std::endl;
}

void Factory::saveEtudiant(Etudiant etudiant){
    QFile file("../../data/Etudiant.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<etudiant.getId() <<";" <<QString::fromStdString(etudiant.getNom()) <<";" <<QString::fromStdString(etudiant.getPrenom());

    file.close();
}

void Factory::saveEnseignant(Enseignant enseignant){
    QFile file("../../data/Enseignant.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<enseignant.getId() <<";" <<QString::fromStdString(enseignant.getNom()) <<";" <<QString::fromStdString(enseignant.getPrenom());

    file.close();
}

void Factory::saveClasse(Classe classe){
    QFile file("../../data/Classe.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<classe.getId() <<";" <<QString::fromStdString(classe.getNomClasse());

    file.close();
}

void Factory::saveECUE(ECUE ecue){
    QFile file("../../data/ECUE.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<QString::fromStdString(ecue.getNomECUE()) <<";" <<QString::fromStdString(ecue.getTypeECUE())<<";"<<ecue.getNbHeures();

    file.close();
}


void Factory::saveSalle(Salle salle){
    QFile file("../../data/Salle.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<salle.getEtage() <<";" <<salle.getNumero();

    file.close();
}

void Creneau::saveCreneau(){
    QFile file("../../data/Creneau.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<this->getId() <<";" <<this->getSalle().getId() <<";" <<this->getClasse().getId() <<";" <<this->getECUE().getId() <<";" <<this->getEnseignant().getId() <<";" <<this->getJour().toString() <<";" <<this->getHeureDebut().toString() <<";" <<this->getHeureFin().toString();

    file.close();
}