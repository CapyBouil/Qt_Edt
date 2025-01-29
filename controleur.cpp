#include "controleur.h"

Controleur::Controleur() {}

/*
Enseignant Controleur::findEnseignantByNomPrenom(const std::string& nomPrenom) const {
    // Parcourt la liste des enseignants
    auto it = std::find_if(listeEnseignants.begin(), listeEnseignants.end(), [&nomPrenom](const Enseignant& enseignant) {
        std::string fullName = enseignant.getNom() + " " + enseignant.getPrenom();
        return fullName == nomPrenom;}
        );

    if (it != listeEnseignants.end()) {
        return *it; // Si trouvé, retourner l'objet Enseignant
    } else {
        throw std::runtime_error("Enseignant introuvable pour : " + nomPrenom);
    }
}
*/

QString formaterMinuscule(QString texte) {
    QString resultat = texte.toLower();
    return resultat;
}

