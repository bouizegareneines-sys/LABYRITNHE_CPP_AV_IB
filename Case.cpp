// Projet C++ //
// Verdier Adélie --- 21502087 --- //
// Bouizegarene Ines --- 21213221 --- //

#include <iostream>
#include "CaseFactory.h"
#include "Aventurier.h"

using namespace std;



char Mur::afficher() {
    return '#';
}
int Mur::effet(Aventurier& a) {
    return 0;
}

char Passage :: afficher () {
    return ' ';
}
int Passage :: effet(Aventurier& a) { return 0; }


char Tresor::afficher() {
    return '+';
}
int Tresor::effet(Aventurier& a) {
    a.setInventaire(a.getInventaire() + 1);
    return a.getInventaire();
}

char Monstre::afficher() {
    return 'M';
}

int Monstre::effet(Aventurier& a) {
    int degat = 10;
    if (a.getInventaire() >= 2) {
        degat = 5;
    }
    if ((a.getSante() - degat) <= 0) {
        a.setPos(1, 1);
        a.setSante(100); 
        cout << "Vous vous reveillez a l'entree du donjon..." << endl;
    } 
    else {
        a.setSante(a.getSante() - degat);
    }
    return a.getSante();
}
        


char Piege ::  afficher (){
    return 'T';
}
int Piege :: effet(Aventurier& a){
    a.setSante(a.getSante() -10) ;
    if (a.getInventaire() != 0){
        a.setInventaire(a.getInventaire() -1) ; 
        return a.getInventaire(); 
    }
    else {return a.getInventaire();}
}


