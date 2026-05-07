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
    
    if (a.getSante() > 70) {
        a.setSante(a.getSante() - 40);
        return a.getSante();
    } 
    else {
        return 0;
    }

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


