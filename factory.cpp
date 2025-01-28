#include "factory.h"

Factory::Factory() {}


/*
 * Méthodes complémentaires
*/

QDate Factory::stringToQDate(const std::string& dateStr) {
    QString dateQString = QString::fromStdString(dateStr); // Convertir std::string en QString
    QDate date = QDate::fromString(dateQString, "ddd MMM dd yyyy");
    if (!date.isValid()) {
        std::cerr << "Format de date invalide : " << dateStr << std::endl;
        return QDate(); // Retourne une date invalide
    }
    return date;
}

QTime Factory::floatToQTime(float heure) {
    int heures = static_cast<int>(heure);  // Partie entière pour les heures
    int minutes = static_cast<int>((heure - heures) * 60);  // Partie décimale pour les minutes
    return QTime(heures, minutes);
}

void Factory::insertEtudiant(Etudiant etudiant, Classe classe){
    int lineNumberT = 1;
    int lineNumber = 0;
    QFile file("../../data/Classe.csv");
    file.open( QIODevice::ReadWrite | QIODevice::Text );
    QTextStream ts(&file);
    QString line = ts.readLine(); //En-tête
    while(!ts.atEnd()){
        line = ts.readLine();
        QStringList liste = line.split(";");
        if(liste[0].toInt()==classe.getId()){
            lineNumber=lineNumberT;
        }else{lineNumberT+=1;}
    }
    QStringList lines;
    QTextStream stream(&file);
    stream.seek(0);
    stream.readLine();
    while (!stream.atEnd()) {
        lines.append(stream.readLine());
    }
    QString newContent = QString::fromStdString(";"+std::to_string(etudiant.getId()));
    lines[lineNumber-1] += newContent;

    file.resize(0);
    stream.seek(0);
    stream <<"Id;NomClasse";
    for (const QString& line : lines) {
        stream << "\n" << line;
    }

    file.close();
}

void Factory::insertEnseignant(Enseignant enseignant, ECUE ecue){
    int lineNumberT = 1;
    int lineNumber = 0;
    QFile file("../../data/ECUE.csv");
    file.open( QIODevice::ReadWrite | QIODevice::Text );
    QTextStream ts(&file);
    QString line = ts.readLine(); //En-tête
    while(!ts.atEnd()){
        line = ts.readLine();
        QStringList liste = line.split(";");
        if(liste[0].toInt()==ecue.getId()){
            lineNumber=lineNumberT;
        }else{lineNumberT+=1;}
    }
    QStringList lines;
    QTextStream stream(&file);
    stream.seek(0);
    stream.readLine();
    while (!stream.atEnd()) {
        lines.append(stream.readLine());
    }
    QString newContent = QString::fromStdString(";"+std::to_string(enseignant.getId()));
    lines[lineNumber-1] += newContent;

    file.resize(0);
    stream.seek(0);
    stream <<"Id;NomECUE;TypeECUE;NbHeure";
    for (const QString& line : lines) {
        stream << "\n" << line;
    }

    file.close();
}

/*
 * Find by Id
*/

Salle Factory::findSalleById(int id) {
    for (Salle salle : Factory::listeSalle) {
        if (salle.getId() == id) {
            return salle;
        }
    }
    throw std::runtime_error("Salle introuvable avec l'ID : " + std::to_string(id));
}

Classe Factory::findClasseById(int id) {
    for ( Classe classe : Factory::listeClasse) {
        if (classe.getId() == id) {
            return classe;
        }
    }
    throw std::runtime_error("Classe introuvable avec l'ID : " + std::to_string(id));
}

ECUE Factory::findEcueById(int id) {
    for ( ECUE ecue : Factory::listeEcue) {
        if (ecue.getId() == id) {
            return ecue;
        }
    }
    throw std::runtime_error("ECUE introuvable avec l'ID : " + std::to_string(id));
}

Enseignant Factory::findEnseignantById(int id) {
    for ( Enseignant enseignant : Factory::listeEnseignant) {
        if (enseignant.getId() == id) {
            return enseignant;
        }
    }
    throw std::runtime_error("Enseignant introuvable avec l'ID : " + std::to_string(id));
}


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
    out <<"\n" << ecue.getId() << ";" <<QString::fromStdString(ecue.getNomECUE()) <<";" <<QString::fromStdString(ecue.getTypeECUE())<<";"<<ecue.getNbHeures();

    file.close();
}


void Factory::saveSalle(Salle salle){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/Salle.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<salle.getId()<< ";" <<salle.getEtage() <<";" <<salle.getNumero() ;

    file.close();
}

void Factory::saveCreneau(Creneau creneau){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/Creneau.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<creneau.getId() <<";" <<creneau.getSalle().getId() <<";" <<creneau.getClasse().getId() <<";" <<creneau.getECUE().getId() <<";" <<creneau.getEnseignant().getId() <<";"
        <<creneau.getJour().toString() <<";" <<creneau.getHeureDebut().toString() <<";" <<creneau.getHeureFin().toString() <<";" <<creneau.getDuree();

    file.close();
}

/*
 * Load
*/

std::list<Etudiant> Factory::listeEtudiant;
std::list<Enseignant> Factory::listeEnseignant;
std::list<ECUE> Factory::listeEcue;
std::list<Classe> Factory::listeClasse;
std::list<Salle> Factory::listeSalle;
std::list<Creneau> Factory::listeCreneau;


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
    //std::cout << listeEtudiant.size() << std::endl;
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
    //std::cout << listeEnseignant.size() << std::endl;
}

void Factory::loadEcue(){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/ECUE.csv");
    file.open( QIODevice::ReadOnly | QIODevice::Text );
    QTextStream ts(&file);
    QString line = ts.readLine(); //En-tête
    while(!ts.atEnd()){
        line = ts.readLine();
        QStringList liste = line.split(";");
        ECUE ecue ( liste[1].toStdString(), liste[2].toStdString(), liste[2].toFloat(), liste[0].toInt());
        Factory::listeEcue.push_back(ecue);
    }
    file.close();
    //std::cout << listeEcue.size() << std::endl;
}


void Factory::loadClasse(){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/Classe.csv");
    file.open( QIODevice::ReadOnly | QIODevice::Text );
    QTextStream ts(&file);
    QString line = ts.readLine(); //En-tête
    while(!ts.atEnd()){
        line = ts.readLine();
        QStringList liste = line.split(";");
        Classe classe (liste[1].toStdString(), liste[0].toInt());
        Factory::listeClasse.push_back(classe);
    }
    file.close();
    //std::cout << listeClasse.size() << std::endl;

}


void Factory::loadSalle(){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/Salle.csv");
    file.open( QIODevice::ReadOnly | QIODevice::Text );
    QTextStream ts(&file);
    QString line = ts.readLine(); //En-tête
    while(!ts.atEnd()){
        line = ts.readLine();
        QStringList liste = line.split(";");
        Salle salle ( liste[1].toInt(),   liste[2].toInt(), liste[0].toInt());
        Factory::listeSalle.push_back(salle);
    }
    file.close();
    //std::cout << listeSalle.size() << std::endl;

}


void Factory::loadCreneau(){
    QFile file("C:/Users/dinhantho/Documents/GitHub/Qt_Edt/data/Creneau.csv");
    file.open( QIODevice::ReadOnly | QIODevice::Text );
    QTextStream ts(&file);
    QString line = ts.readLine(); //En-tête
    while(!ts.atEnd()){
        line = ts.readLine();
        QStringList liste = line.split(";");

        Salle salle = Factory::findSalleById(liste[1].toInt());
        Classe classe = Factory::findClasseById(liste[2].toInt());
        ECUE ecue = Factory::findEcueById(liste[3].toInt());
        Enseignant enseignant = Factory::findEnseignantById(liste[4].toInt());

        Creneau creneau (
            liste[0].toInt(),
            salle,
            classe,
            ecue,
            enseignant,
            Factory::stringToQDate(liste[5].toStdString()),
            Factory::floatToQTime(liste[6].toFloat()),
            Factory::floatToQTime(liste[7].toFloat())
            );
        Factory::listeCreneau.push_back(creneau);
    }

    file.close();
    //std::cout << listeCreneau.size() << std::endl;

}


