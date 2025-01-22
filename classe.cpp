#include "Classe.h"

Classe::Classe() {
    this->id=getMaxId()+1;
    this->nomClasse = "";
}

Classe::Classe(std::string nomClasse)
{
    this->nomClasse = nomClasse;
    this->id=getMaxId()+1;
}

Classe::Classe(std::string nomClasse, int id)
{
    this->nomClasse = nomClasse;
    this->id = id;
}

int Classe::getId()
{
    return this->id;
}

std::string Classe::getNomClasse()
{
    return this->nomClasse;
}

void Classe::ajouterEtudiant(Etudiant& etudiant)
{
    etudiants.push_back(etudiant);
}

void Classe::supprimerEtudiant(std::string& nom, std::string& prenom)
{
    for(auto liste = etudiants.begin(); liste != etudiants.end(); ++liste)
    {
        if (liste->getNom() == nom && liste->getPrenom() == prenom)
        {
            etudiants.erase(liste);
            std::cout << "Etudiant " << nom << " " << prenom << " supprimé." << std::endl;
            return;
        }
    }
    std::cout << "Etudiant non trouvé: " << nom << " " << prenom << std::endl;
}

void Classe::affiche()
{
    std::cout << "Classe: " << nomClasse << " (ID: " << id << ")" << std::endl;
    if (etudiants.empty())
    {
        std::cout << "Aucun étudiant dans la classe" << std::endl;
    } else
    {
        for (auto liste = etudiants.begin(); liste != etudiants.end(); liste++)
        {
            liste->affiche();
        }
    }
}

int Classe::getMaxId(){
    int maxIdClasse = 0;

    QFile fileClasse("../../data/Classe.csv");
    fileClasse.open(QIODevice::ReadOnly | QIODevice::Text );

    QTextStream tsClasse(&fileClasse);

    QString lineClasse = tsClasse.readLine(); // en-tête
    while(!tsClasse.atEnd()){
        lineClasse = tsClasse.readLine();
        QStringList liste = lineClasse.split(";");
        if(liste[0].toInt()>maxIdClasse){
            maxIdClasse = liste[0].toInt();
        }
    }

    fileClasse.close();

    return maxIdClasse;
}

void Classe::saveClasse(){
    QFile file("../../data/Classe.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::ExistingOnly | QIODevice::Append );
    QTextStream out(&file);
    out <<"\n" <<this->getId() <<";" <<QString::fromStdString(this->getNomClasse());

    file.close();
}
