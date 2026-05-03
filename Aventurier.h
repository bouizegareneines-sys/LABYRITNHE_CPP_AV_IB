#ifndef AVENTURIER_H
#define AVENTURIER_H

#include <iostream>
using namespace std; 

class Aventurier{

    private: 

        int sante; 
        int inventaire; 
        int pos[2]; 

    public : 

        Aventurier();
        Aventurier(int sante, int inventaire, int pos[2]);

        int getSante();
        int getInventaire();
        void setSante(int s);
        void setInventaire(int i);
        int* getPos();

        int* deplacer(int nx, int ny);
        bool estVivant();
        void afficher();

};

#endif

// a quel point c'est utile que je reecrive en convention pointeur avec des alloca dyn de memoire et des destrcutios?
