#include "controleur.h"

Controleur::Controleur() {}

std::optional<Enseignant> Controleur::findEnseignantByNomPrenom(const QString& nomPrenom) const {
    Factory::loadEnseignant();
    if (Factory::listeEnseignant.empty()) {
        qDebug() << "La liste des enseignants est vide.";
    }

    // Parcours de la liste des enseignants
    for (const Enseignant& enseignant : Factory::listeEnseignant) {
        QString nomComplet = QString::fromStdString(enseignant.getPrenom()) + " " + QString::fromStdString(enseignant.getNom());
        // Comparaison en ignorant la casse et les espaces
        if (nomComplet.trimmed().toLower() == nomPrenom.trimmed().toLower()) {
            qDebug() << "Enseignant trouve : " << nomPrenom;
            return enseignant;
        }
    }
    qDebug() << "Enseignant introuvable pour : " << nomPrenom;
    return std::nullopt;
}

std::optional<Etudiant> Controleur::findEtudiantByNomPrenom(const QString& nomPrenom) const {
    Factory::loadEtudiant();
    if (Factory::listeEtudiant.empty()) {
        qDebug() << "La liste des Etudiants est vide.";
    }

    // Parcours de la liste des Etudiants
    for (const Etudiant& etudiant : Factory::listeEtudiant) {
        QString nomComplet = QString::fromStdString(etudiant.getPrenom()) + " " + QString::fromStdString(etudiant.getNom());
        // Comparaison en ignorant la casse et les espaces
        if (nomComplet.trimmed().toLower() == nomPrenom.trimmed().toLower()) {
            qDebug() << "Etudiant trouve : " << nomPrenom;
            return etudiant;
        }
    }

    qDebug() << "Etudiant introuvable pour : " << nomPrenom;
    return std::nullopt;
}

std::optional<Salle> Controleur::findSalleByNumero(const QString& numeroComplet) const {
    Factory::loadSalle();
    if (Factory::listeSalle.empty()) {
        qDebug() << "La liste des Salles est vide.";
    }

    // Parcours de la liste des Salles
    for (const Salle& salle : Factory::listeSalle) {
        QString numeroSalle = QString::number(salle.getNumeroComplet());
        //qDebug() << numeroSalle;
        if (numeroSalle == numeroComplet) {
            qDebug() << "Salle trouvee : " << numeroComplet;
            return salle;
        }
    }

    qDebug() << "Salle introuvable pour : " << numeroComplet;
    return std::nullopt;
}

std::optional<ECUE> Controleur::findECUEByNom(const QString& nomECUE) const {
    Factory::loadEcue();
    if (Factory::listeEcue.empty()) {
        qDebug() << "La liste des ECUEs est vide.";
    }

    // Parcours de la liste des ECUEs
    for (const ECUE& ecue : Factory::listeEcue) {
        QString ecueNom = QString::fromStdString(ecue.getNomECUE());
        // Comparaison en ignorant la casse et les espaces
        if (ecueNom.trimmed().toLower() == nomECUE.trimmed().toLower()) {
            qDebug() << "ECUE trouve : " << nomECUE;
            return ecue;
        }
    }

    qDebug() << "ECUE introuvable pour : " << nomECUE;
    return std::nullopt;
}

std::optional<Classe> Controleur::findClasseByNomClasse(const QString& nomClasse) const {

    Factory::loadClasse();

    if (Factory::listeClasse.empty()) {

        qDebug() << "La liste des classes est vide.";

    }

    for (const Classe& classe : Factory::listeClasse) {

        QString nomClasseComplet = QString::fromStdString(classe.getNomClasse());

        if (nomClasseComplet.trimmed().toLower() == nomClasse.trimmed().toLower()) {

            qDebug() << "Classe trouvée : " << nomClasse;

            return classe;

        }

    }

    qDebug() << "Classe introuvable pour : " << nomClasse;
    return std::nullopt;

}

QString formaterMinuscule(QString texte) {
    QString resultat = texte.toLower();
    return resultat;
}

