
#include "factory.h"

    Factory::Factory() {}


/*
 * Méthodes complémentaires
*/

QDate Factory::stringToQDate(const std::string& dateStr) {
    QString dateQString = QString::fromStdString(dateStr); // Convertir std::string en QString
    QDate date = QDate::fromString(dateQString, "yyyy-MM-dd");
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
    out <<"\n" << ecue.getId() << ";" <<QString::fromStdString(ecue.getNomECUE()) <<";" <<QString::fromStdString(ecue.getTypeECUE())<<";"<<ecue.getNbHeures();

    file.close();
}


void Factory::saveSalle(Salle salle){
    QFile file("../../data/Salle.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<salle.getId()<< ";" <<salle.getEtage() <<";" <<salle.getNumero() ;

    file.close();
}

void Factory::saveCreneau(Creneau creneau){
    QFile file("../../data/Creneau.csv");
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
    QFile file("../../data/Etudiant.csv");
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
    QFile file("../../data/Enseignant.csv");
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

void Factory::loadEcue(){
    QFile file("../../data/ECUE.csv");
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
    std::cout << listeEcue.size() << std::endl;
}


void Factory::loadClasse(){
    QFile file("../../data/Classe.csv");
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
    std::cout << listeClasse.size() << std::endl;
}


void Factory::loadSalle(){
    QFile file("../../data/Salle.csv");
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
    std::cout << listeSalle.size() << std::endl;

}


void Factory::loadCreneau(){
    QFile file("../../data/Creneau.csv");
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


        std::cout << liste[5].toStdString() << std::endl;

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
        creneau.affiche();
        Factory::listeCreneau.push_back(creneau);
    }

    file.close();
    std::cout << listeCreneau.size() << std::endl;

}

void Factory::suppCreaneau(Creneau creneau){
    QFile file("../../data/Creneau.csv");
    file.open( QIODevice::ReadWrite | QIODevice::Text );
    QTextStream ts(&file);
    QString line = ts.readLine(); //En-tête
    QStringList lines;
    while(!ts.atEnd()){
        line = ts.readLine();
        QStringList liste = line.split(";");
        if(liste[0].toInt()!=creneau.getId()){
            lines.append(line);
        }
    }
    file.resize(0);
    ts.seek(0);
    ts <<"Id;Salle;Classe;ECUE;Enseignant;Jour;HeureDebut;HeureFin;Duree";
    for (const QString& line : lines) {
        ts << "\n" << line;
    }

    file.close();
}

void Factory::suppSalle(Salle salle){
    QFile file("../../data/Salle.csv");
    file.open( QIODevice::ReadWrite | QIODevice::Text );
    QTextStream ts(&file);
    QString line = ts.readLine(); //En-tête
    QStringList lines;
    while(!ts.atEnd()){
        line = ts.readLine();
        QStringList liste = line.split(";");
        if(liste[0].toInt()!=salle.getId()){
            lines.append(line);
        }
    }
    file.resize(0);
    ts.seek(0);
    ts <<"Id;Etage;Numero";
    for (const QString& line : lines) {
        ts << "\n" << line;
    }
    file.close();
    for (auto it = listeCreneau.begin(); it != listeCreneau.end(); ++it) {
        if (it->getSalle().getId() == salle.getId()){
            Factory::suppCreaneau(*it);
        }
    }
}

void Factory::suppEcue(ECUE ecue){
    QFile file("../../data/ECUE.csv");
    file.open( QIODevice::ReadWrite | QIODevice::Text );
    QTextStream ts(&file);
    QString line = ts.readLine(); //En-tête
    QStringList lines;
    while(!ts.atEnd()){
        line = ts.readLine();
        QStringList liste = line.split(";");
        if(liste[0].toInt()!=ecue.getId()){
            lines.append(line);
        }
    }
    file.resize(0);
    ts.seek(0);
    ts <<"Id;NomECUE;TypeECUE;NbHeure";
    for (const QString& line : lines) {
        ts << "\n" << line;
    }
    file.close();
    for (auto it = listeCreneau.begin(); it != listeCreneau.end(); ++it) {
        if (it->getECUE().getId() == ecue.getId()){
            Factory::suppCreaneau(*it);
        }
    }
}

void Factory::suppClasse(Classe classe){
    QFile file("../../data/Classe.csv");
    file.open( QIODevice::ReadWrite | QIODevice::Text );
    QTextStream ts(&file);
    QString line = ts.readLine(); //En-tête
    QStringList lines;
    while(!ts.atEnd()){
        line = ts.readLine();
        QStringList liste = line.split(";");
        if(liste[0].toInt()!=classe.getId()){
            lines.append(line);
        }
    }
    file.resize(0);
    ts.seek(0);
    ts <<"Id;NomClasse";
    for (const QString& line : lines) {
        ts << "\n" << line;
    }
    file.close();
    for (auto it = listeCreneau.begin(); it != listeCreneau.end(); ++it) {
        if (it->getClasse().getId() == classe.getId()){
            Factory::suppCreaneau(*it);
        }
    }
}

void Factory::suppEtudiant(Etudiant etudiant){
    QFile fileE("../../data/Etudiant.csv");
    fileE.open( QIODevice::ReadWrite | QIODevice::Text );
    QTextStream tsE(&fileE);
    QString lineE = tsE.readLine(); //En-tête
    QStringList linesE;
    while(!tsE.atEnd()){
        lineE = tsE.readLine();
        QStringList liste = lineE.split(";");
        if(liste[0].toInt()!=etudiant.getId()){
            linesE.append(lineE);
        }
    }
    fileE.resize(0);
    tsE.seek(0);
    tsE <<"Id;Nom;Prenom";
    for (const QString& line : linesE) {
        tsE << "\n" << line;
    }
    fileE.close();
    QFile fileC("../../data/Classe.csv");
    fileC.open( QIODevice::ReadWrite | QIODevice::Text );
    QTextStream tsC(&fileC);
    QString lineC = tsC.readLine(); //En-tête
    QStringList linesC;
    bool present = true;
    int supp = 0;
    while(!tsC.atEnd()){
        lineC = tsC.readLine();
        QStringList liste = lineC.split(";");
        if(liste.size()>2){
            for(int i=2; i<liste.size(); i++){
                if(liste[i].toInt()==etudiant.getId()){
                    present = true;
                    supp = i;
                }
            }
        }
        if(present == true){
            QString classe = liste[0] + ";" + liste[1];
            if(supp!=2){
                for(int i=2;i<supp;i++){
                    classe += ";" + liste[i];
                }
                for(int i=supp+1;i<liste.size();i++){
                    classe += ";" + liste[i];
                }
            }else{
                for(int i=3;i<liste.size();i++){
                    classe += ";" + liste[i];
                }
            }
            linesC.append(classe);
        }else{linesC.append(lineC);}
        present = false;
        supp = 0;
    }
    fileC.resize(0);
    tsC.seek(0);
    tsC <<"Id;NomClasse";
    for (const QString& line : linesC) {
        tsC << "\n" << line;
    }
    fileC.close();
}

void Factory::suppEnseignant(Enseignant enseignant){
    QFile fileE("../../data/Enseignant.csv");
    fileE.open( QIODevice::ReadWrite | QIODevice::Text );
    QTextStream tsE(&fileE);
    QString lineE = tsE.readLine(); //En-tête
    QStringList linesE;
    while(!tsE.atEnd()){
        lineE = tsE.readLine();
        QStringList liste = lineE.split(";");
        if(liste[0].toInt()!=enseignant.getId()){
            linesE.append(lineE);
        }
    }
    fileE.resize(0);
    tsE.seek(0);
    tsE <<"Id;Nom;Prenom";
    for (const QString& line : linesE) {
        tsE << "\n" << line;
    }
    fileE.close();
    QFile fileC("../../data/ECUE.csv");
    fileC.open( QIODevice::ReadWrite | QIODevice::Text );
    QTextStream tsC(&fileC);
    QString lineC = tsC.readLine(); //En-tête
    QStringList linesC;
    bool present = true;
    int supp = 0;
    while(!tsC.atEnd()){
        lineC = tsC.readLine();
        QStringList liste = lineC.split(";");
        if(liste.size()>4){
            for(int i=4; i<liste.size(); i++){
                if(liste[i].toInt()==enseignant.getId()){
                    present = true;
                    supp = i;
                }
            }
        }
        if(present == true){
            QString classe = liste[0] + ";" + liste[1] + ";" + liste[2] + ";" + liste[3];
            if(supp!=4){
                for(int i=4;i<supp;i++){
                    classe += ";" + liste[i];
                }
                for(int i=supp+1;i<liste.size();i++){
                    classe += ";" + liste[i];
                }
            }else{
                for(int i=5;i<liste.size();i++){
                    classe += ";" + liste[i];
                }
            }
            linesC.append(classe);
        }else{linesC.append(lineC);}
        present = false;
        supp = 0;
    }
    fileC.resize(0);
    tsC.seek(0);
    tsC <<"Id;NomECUE;TypeECUE;NbHeure";
    for (const QString& line : linesC) {
        tsC << "\n" << line;
    }
    fileC.close();
}
