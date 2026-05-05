#include <iostream>
#include "Aventurier.h"
using namespace std; 

Aventurier::Aventurier(int sante, int inventaire, int pos[2]){
    this -> sante = sante ;
    this ->inventaire = inventaire;
    this -> pos[0] = pos[0];
    this -> pos[1] = pos[1];
}

int Aventurier::getSante() { return sante; }
int Aventurier::getInventaire() { return inventaire; }
void Aventurier::setSante(int s) { sante = s; }
void Aventurier::setInventaire(int i) { inventaire = i; }
int* Aventurier::getPos() { return pos; }

int* Aventurier::deplacer(int nx, int ny) {

    int new_posx = pos[0] + nx ;
    int new_posy = pos[1] + ny ;

    pos[0] = new_posx;
    pos[1] = new_posy;

    return pos;
}

bool Aventurier::estVivant(){
    return sante > 0 ;
}

void Aventurier::afficher(){
    cout <<"@";
}
