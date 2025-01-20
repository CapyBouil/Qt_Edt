#include "creneau.h"

// Constructeurs
Creneau::Creneau(Salle salle, Classe classe, ECUE ecue, Enseignant enseignant, QDate jour, QTime heure_debut, QTime heure_fin)
{
    this->id = getMaxId() + 1;
    this->salle = salle;
    this->classe = classe;
    this->ecue = ecue;
    this->enseignant = enseignant;
    this->jour = jour;
    this->heure_debut = heure_debut;
    this->heure_fin = heure_fin;
    setDuree();
}

Creneau::Creneau(int id, Salle salle, Classe classe, ECUE ecue, Enseignant enseignant, QDate jour, QTime heure_debut, QTime heure_fin)
{
    this->id = id;
    this->salle = salle;
    this->classe = classe;
    this->ecue = ecue;
    this->enseignant = enseignant;
    this->jour = jour;
    this->heure_debut = heure_debut;
    this->heure_fin = heure_fin;
    setDuree();
}

// Accesseurs
Salle Creneau::getSalle() const
{
    return salle;
}

Classe Creneau::getClasse() const
{
    return classe;
}

ECUE Creneau::getECUE() const
{
    return ecue;
}

Enseignant Creneau::getEnseignant() const
{
    return enseignant;
}

QDate Creneau::getJour() const
{
    return jour;
}

QTime Creneau::getHeureDebut() const
{
    return heure_debut;
}

QTime Creneau::getHeureFin() const
{
    return heure_fin;
}

int Creneau::getDuree() const
{
    return duree;
}

// Mutateurs
void Creneau::setSalle(Salle salle)
{
    this->salle = salle;
}

void Creneau::setClasse(Classe classe)
{
    this->classe = classe;
}

void Creneau::setECUE(ECUE ecue)
{
    this->ecue = ecue;
}

void Creneau::setEnseignant(Enseignant enseignant)
{
    this->enseignant = enseignant;
}

void Creneau::setJour(const QString& jourStr)
{
    QDate date = QDate::fromString(jourStr, "yyyy-MM-dd");
    if (!date.isValid()) {
        throw std::invalid_argument("Format de date invalide. Attendu: YYYY-MM-DD");
    }
    jour = date;
}

void Creneau::setHeureDebut(QTime heureDebut)
{
    this->heure_debut = heureDebut;
}

void Creneau::setHeureFin(QTime heureFin)
{
    this->heure_fin = heureFin;
}

void Creneau::setDuree()
{
    duree = heure_debut.secsTo(heure_fin) / 60; // Durée en minutes
}

// Methodes
void Creneau::affiche()
{
    salle.affiche();
    classe.affiche();
    ecue.affiche();
    enseignant.affiche();
    std::cout << "Jour : " << jour.toString("yyyy-MM-dd").toStdString() << std::endl;
    std::cout << "Heure de début : " << heure_debut.toString("HH:mm").toStdString() << std::endl;
    std::cout << "Heure de fin : " << heure_fin.toString("HH:mm").toStdString() << std::endl;
    std::cout << "Durée : " << duree << " minutes" << std::endl;
}

void Creneau::ajouteSalle(Salle salle)
{
    this->salle = salle;
}

void Creneau::supprimeSalle()
{
    this->salle = Salle();
}

void Creneau::ajouteClasse(Classe classe)
{
    this->classe = classe;
}

void Creneau::supprimeClasse()
{
    this->classe = Classe();
}

void Creneau::ajouteECUE(ECUE ecue)
{
    this->ecue = ecue;
}

void Creneau::supprimeECUE()
{
    this->ecue = ECUE();
}

void Creneau::ajouteEnseignant(Enseignant enseignant)
{
    this->enseignant = enseignant;
}

void Creneau::supprimeEnseignant()
{
    this->enseignant = Enseignant();
}

int Creneau::getMaxId()
{
    QFile file("creneau.csv"); // Vérifiez si le fichier peut être ouvert en lecture
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Impossible d'ouvrir le fichier :" << file.errorString(); return -1;
    }
    QTextStream in(&file);
    QString lastLine; // Lire les lignes du fichier jusqu'à la fin
    while (!in.atEnd()) {
        lastLine = in.readLine();
    }
    file.close(); // Séparer la dernière ligne par les virgules
    QStringList fields = lastLine.split(','); // Retourner la valeur de la première colonne (id) convertie en entier
    return fields.at(0).toInt();
}
