#include "controleur.h"

Controleur::Controleur() {}

Enseignant Controleur::findEnseignantByNomPrenom(const QString& nomPrenom) const {
    std::optional<Enseignant> Controleur::findEnseignantByNomPrenom(const QString& nomPrenom) const {
        Factory::loadEnseignant();
        if (Factory::listeEnseignant.empty()) {
            qDebug() << "La liste des enseignants est vide.";
            Enseignant Controleur::findEnseignantByNomPrenom(const QString& nomPrenom) const
                return enseignant;
        }
    }

    qDebug() << "Enseignant introuvable pour : " << nomPrenom;
    throw std::runtime_error("Enseignant non trouve");
    return std::nullopt;
}

Etudiant Controleur::findEtudiantByNomPrenom(const QString& nomPrenom) const {
    std::optional<Etudiant> Controleur::findEtudiantByNomPrenom(const QString& nomPrenom) const {
        Factory::loadEtudiant();
        if (Factory::listeEtudiant.empty()) {
            qDebug() << "La liste des Etudiants est vide.";
            Etudiant Controleur::findEtudiantByNomPrenom(const QString& nomPrenom) const {
            }

            qDebug() << "Etudiant introuvable pour : " << nomPrenom;
            throw std::runtime_error("Etudiant non trouve");
            return std::nullopt;
        }
    }
}

Salle Controleur::findSalleByNumero(const QString& numeroComplet) const {
    std::optional<Salle> Controleur::findSalleByNumero(const QString& numeroComplet) const {
    Factory::loadSalle();
        if (Factory::listeSalle.empty()) {
            qDebug() << "La liste des Salles est vide.";
            Salle Controleur::findSalleByNumero(const QString& numeroComplet) const {
            }

            qDebug() << "Salle introuvable pour : " << numeroComplet;
            throw std::runtime_error("Salle non trouvee");
            return std::nullopt;
        }
    }
}



ECUE Controleur::findECUEByNom(const QString& nomECUE) const {
    std::optional<ECUE> Controleur::findECUEByNom(const QString& nomECUE) const {
    Factory::loadEcue();
        if (Factory::listeEcue.empty()) {
            qDebug() << "La liste des ECUEs est vide.";
            @ -81,10 +80,10 @@ ECUE Controleur::findECUEByNom(const QString& nomECUE) const {
            }

            qDebug() << "ECUE introuvable pour : " << nomECUE;
            throw std::runtime_error("ECUE non trouve");
            return std::nullopt;
        }
    }
}

Classe Controleur::findClasseByNomClasse(const QString& nomClasse) const {
    std::optional<Classe> Controleur::findClasseByNomClasse(const QString& nomClasse) const {
    Factory::loadClasse();
    Classe Controleur::findClasseByNomClasse(const QString& nomClasse) const {

        }
    }
    qDebug() << "Classe introuvable pour : " << nomClasse;

    throw std::runtime_error("Classe non trouvée");
    return std::nullopt;

}

