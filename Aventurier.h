#include <iostream>
using namespace std; 

class Aventurier{

    private: 

        int sante; //nombre de vie restantes
        int inventaire; // nombre de trésors dans l'inventaire
        int pos[2]; //position en x pour pos[0] et en y pour pos[1]


    public : 

        Aventurier(int sante, int inventaire, int pos[2]){
            this -> sante = sante ;
            this ->inventaire = inventaire;
            this -> pos[0] = pos[0];
            this -> pos[1] = pos[1];
        }

        int getSante() { return sante; }
        int getInventaire() { return inventaire; }
        void setSante(int s) { sante = s; }
        void setInventaire(int i) { inventaire = i; }
        int* getPos() { return pos; }

        int* deplacer(int nx, int ny) {

            int new_posx = pos[0] + nx ;
            int new_posy = pos[1] + ny ;

            pos[0] = new_posx;
            pos[1] = new_posy;

            return pos;
        }

        bool estVivant(){
            return sante > 0 ;
        }

        void afficher(){
            cout <<"@";
        }

};

// a quel point c'est utile que je reecrive en convention pointeur avec des alloca dyn de memoire et des destrcutios?
