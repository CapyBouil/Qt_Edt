#ifndef Creneau.h
#define Creneau.h

#include Salle.h
#include Classe.h
#include ECUE.h

class Creneau{
    
public:
    ajouter_salle(Salle salle);
    supprimer_salle(Salle salle);
    ajouter_classe(Classe classe);
    supprimer_classe(Classe classe);
    ajouter_ECUE(ECUE ecue);
    supprimer_ECUE(ECUE ecue);
    
}

#endif