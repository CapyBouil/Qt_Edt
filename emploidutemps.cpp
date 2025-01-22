#include "EmploiDuTemps.h"

EmploiDuTemps::EmploiDuTemps() : creneaux() {

}

void EmploiDuTemps::ajouterCreneau(Creneau& creneau) {
    // Trouver l'endroit où insérer le créneau
    auto it = creneaux.begin();
    while (it != creneaux.end()) {
        // Compare le jour puis l'heure de début
        if (it->getJour() > creneau.getJour() ||
            (it->getJour() == creneau.getJour() && it->getHeureDebut() > creneau.getHeureDebut())) {
            break; // On s'arrête dès qu'on trouve une place plus tard dans l'emploi du temps
        }
        ++it;
    }
    // Insérer le créneau à la position trouvée
    creneaux.insert(it, creneau);
}

void EmploiDuTemps::supprimerCreneau(int id) {
    auto it = std::find_if(creneaux.begin(), creneaux.end(), [id](Creneau& c) { return c.getId() == id; });
    if (it != creneaux.end()) {
        creneaux.erase(it);  // Supprime le créneau de la liste
    } else {
        std::cerr << "Creneau avec l'ID " << id << " non trouve." << std::endl;
    }
}

// Afficher l'emploi du temps
void EmploiDuTemps::affiche()  {
    for (Creneau& creneau : creneaux) {
        creneau.affiche();
    }
}
