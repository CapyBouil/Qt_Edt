#include "factory.h"

Factory::Factory() {}

/*
 * Save
*/

void Factory::saveEtudiant(Etudiant etudiant){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/Etudiant.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<etudiant.getId() <<";" <<QString::fromStdString(etudiant.getNom()) <<";" <<QString::fromStdString(etudiant.getPrenom());

    file.close();
}

void Factory::saveEnseignant(Enseignant enseignant){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/Enseignant.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<enseignant.getId() <<";" <<QString::fromStdString(enseignant.getNom()) <<";" <<QString::fromStdString(enseignant.getPrenom());

    file.close();
}

void Factory::saveClasse(Classe classe){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/Classe.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<classe.getId() <<";" <<QString::fromStdString(classe.getNomClasse());

    file.close();
}

void Factory::saveECUE(ECUE ecue){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/ECUE.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<QString::fromStdString(ecue.getNomECUE()) <<";" <<QString::fromStdString(ecue.getTypeECUE())<<";"<<ecue.getNbHeures();

    file.close();
}


void Factory::saveSalle(Salle salle){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/Salle.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<salle.getEtage() <<";" <<salle.getNumero();

    file.close();
}

void Factory::saveCreneau(Creneau creneau){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/Creneau.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<creneau.getId() <<";" <<creneau.getSalle().getId() <<";" <<creneau.getClasse().getId() <<";" <<creneau.getECUE().getId() <<";" <<creneau.getEnseignant().getId() <<";" <<creneau.getJour().toString() <<";" <<creneau.getHeureDebut().toString() <<";" <<creneau.getHeureFin().toString();

    file.close();
}

/*
 * Load
*/

std::list<Etudiant> Factory::listeEtudiant;
std::list<Enseignant> Factory::listeEnseignant;


void Factory::loadEtudiant(){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/Etudiant.csv");
    file.open( QIODevice::ReadOnly | QIODevice::Text );
    QTextStream ts(&file);
    QString line = ts.readLine(); //En-tête
    while(!ts.atEnd()){
        line = ts.readLine();
        QStringList liste = line.split(";");
        Etudiant etudiant ( liste[1].toStdString(), liste[2].toStdString(), liste[0].toInt() );
        Factory::listeEtudiant.push_back(etudiant);
    }
    file.close();
    std::cout << listeEtudiant.size() << std::endl;
    //auto it = listeEtudiant.begin();
    //std::advance(it,0);
    //it->affiche();
}

void Factory::loadEnseignant(){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/Enseignant.csv");
    file.open( QIODevice::ReadOnly | QIODevice::Text );
    QTextStream ts(&file);
    QString line = ts.readLine(); //En-tête
    while(!ts.atEnd()){
        line = ts.readLine();
        QStringList liste = line.split(";");
        Enseignant enseignant ( liste[1].toStdString(), liste[2].toStdString(), liste[0].toInt());
        Factory::listeEnseignant.push_back(enseignant);
    }
    file.close();
    std::cout << listeEnseignant.size() << std::endl;

}

void Factory::loadClasse(){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/Enseignant.csv");
    file.open( QIODevice::ReadOnly | QIODevice::Text );
    QTextStream ts(&file);
    QString line = ts.readLine(); //En-tête
    while(!ts.atEnd()){
        line = ts.readLine();
        QStringList liste = line.split(";");
        Enseignant enseignant ( liste[1].toStdString(), liste[2].toStdString(), liste[0].toInt());
        Factory::listeEnseignant.push_back(enseignant);
    }
    file.close();
    std::cout << listeEnseignant.size() << std::endl;

}
