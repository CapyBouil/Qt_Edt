#include "controleur.h"

Controleur::Controleur() {}

Enseignant Controleur::findEnseignantByNomPrenom(const QString& nomPrenom) const {
    Factory::loadEnseignant();
    if (Factory::listeEnseignant.empty()) {
        qDebug() << "La liste des enseignants est vide.";
    }

    // Parcours de la liste des enseignants
    for (const Enseignant& enseignant : Factory::listeEnseignant) {
        QString nomComplet = QString::fromStdString(enseignant.getPrenom()) + " " + QString::fromStdString(enseignant.getNom());
        // Comparaison en ignorant la casse et les espaces
        if (nomComplet.trimmed().toLower() == nomPrenom.trimmed().toLower()) {
            qDebug() << "Enseignant trouvé : " << nomPrenom;
            return enseignant;
        }
    }

    qDebug() << "Enseignant introuvable pour : " << nomPrenom;
    throw std::runtime_error("Enseignant non trouvé");
}

Etudiant Controleur::findEtudiantByNomPrenom(const QString& nomPrenom) const {
    Factory::loadEtudiant();
    if (Factory::listeEtudiant.empty()) {
        qDebug() << "La liste des Etudiants est vide.";
    }

    // Parcours de la liste des Etudiants
    for (const Etudiant& etudiant : Factory::listeEtudiant) {
        QString nomComplet = QString::fromStdString(etudiant.getPrenom()) + " " + QString::fromStdString(etudiant.getNom());
        // Comparaison en ignorant la casse et les espaces
        if (nomComplet.trimmed().toLower() == nomPrenom.trimmed().toLower()) {
            qDebug() << "Etudiant trouvé : " << nomPrenom;
            return etudiant;
        }
    }

    qDebug() << "Etudiant introuvable pour : " << nomPrenom;
    throw std::runtime_error("Etudiant non trouvé");
}


QString formaterMinuscule(QString texte) {
    QString resultat = texte.toLower();
    return resultat;
}

