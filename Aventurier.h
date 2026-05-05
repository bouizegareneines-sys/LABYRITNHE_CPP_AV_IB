#ifndef AVENTURIER_H
#define AVENTURIER_H

#include <iostream>
using namespace std; 

class Aventurier{

    private: 

        int sante; 
        int inventaire; 
        pair<int,int> pos; 

    public : 

        Aventurier();
        Aventurier(int sante, int inventaire, pair<int,int> pos);

        int getSante();
        int getInventaire();
        void setSante(int s);
        void setInventaire(int i);
        pair<int,int> getPos();

        pair<int,int> deplacer(int nx, int ny);
        bool estVivant();
        void afficher();

};

#endif

// a quel point c'est utile que je reecrive en convention pointeur avec des alloca dyn de memoire et des destrcutios?
