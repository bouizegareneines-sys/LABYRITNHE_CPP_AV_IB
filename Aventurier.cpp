#include <iostream>

#include "Aventurier.h"
using namespace std; 

Aventurier::Aventurier() : sante(100), inventaire(0), pos({1,1}) {}

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
void Aventurier::setPos(int pos_x,int pos_y){ pos.first=pos_x; pos.second=pos_y;}

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

ostream& operator<< (ostream& o, const pair<int, int>& p) {
    
    o << "[" << p.first  << "," << p.second << "]" << endl ;

    return o;

}