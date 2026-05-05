#include <iostream>
#include "Aventurier.h"
using namespace std; 

Aventurier::Aventurier(int sante, int inventaire,pair<int,int> pos){
    this -> sante = sante ;
    this ->inventaire = inventaire;
    this -> pos = pos;
}

int Aventurier::getSante() { return sante; }
int Aventurier::getInventaire() { return inventaire; }
void Aventurier::setSante(int s) { sante = s; }
void Aventurier::setInventaire(int i) { inventaire = i; }
pair<int,int> Aventurier::getPos() { return pos; }

pair<int,int> Aventurier::deplacer(int nx, int ny) {

    int new_posx = pos.first + nx ;
    int new_posy = pos.second + ny ;

    pos.first = new_posx;
    pos.second = new_posy;

    return pos;
}

bool Aventurier::estVivant(){
    return sante > 0 ;
}

void Aventurier::afficher(){
    cout <<"@";
}

ostream& operator<< (ostream &pos, const &pos) {
    
    cout << "Coordonées actuelles du joueur : [" << pos.first  << "," << pos.second << "]" << endl ;
}