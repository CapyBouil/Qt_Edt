#include "salle.h"

Salle::Salle() {
    this->etage = 0;
    this->numero = 0;
    this->id=getMaxId()+1;
}

Salle::Salle(int etage, int numero) {
    this->etage = etage;
    this->numero = numero;
    this->id=getMaxId()+1;
}

Salle::Salle(int etage, int numero, int id) {
    this->etage = etage;
    this->numero = numero;
    this->id = id;
}

int Salle::getEtage() const {
    return etage;
}

int Salle::getNumero() const{
    return numero;
}

int Salle::getId()  {
    return id;
}

int Salle::getNumeroComplet() const{
    return 100 * etage + numero;
}

void Salle::affiche() {
    std::cout << "Salle " << getNumeroComplet() << std::endl;
}



int Salle::getMaxId(){
    int maxIdSalle= 0;

    QFile fileSalle("../../data/Salle.csv");
    fileSalle.open(QIODevice::ReadOnly | QIODevice::Text );

    QTextStream tsSalle(&fileSalle);

    QString lineSalle = tsSalle.readLine(); // en-tête
    while(!tsSalle.atEnd()){
        lineSalle = tsSalle.readLine();
        QStringList liste = lineSalle.split(";");
        if(liste[0].toInt()>maxIdSalle){
            maxIdSalle = liste[0].toInt();
        }
    }

    fileSalle.close();

    return maxIdSalle;
}
