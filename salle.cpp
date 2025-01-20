#include "salle.h"

Salle::Salle() {
    this->etage = 0;
    this->numero = 0;
    //this->id;
}

Salle::Salle(int etage, int numero) {
    this->etage = etage;
    this->numero = numero;
    //this->id;
}

Salle::Salle(int etage, int numero, int id) {
    this->etage = etage;
    this->numero = numero;
    this->id = id;
}

int Salle::getId() {
    return this->id;
}

int Salle::getEtage() {
    return this->etage;
}

int Salle::getNumero() {
    return this->numero;
}

int Salle::getNumeroComplet() {
    return 100 * etage + numero;
}

void Salle::affiche() {
    std::cout << "Salle " << getNumeroComplet() << std::endl;
}
