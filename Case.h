#include <iostream>
using namespace std;
#include "Aventurier.h"

#define pass (void)0

class Case {
    public : 
        virtual char afficher() = 0;
        virtual ~Case() = default ; 
        virtual int effet (Aventurier & a) = 0; // est ce qu on est obligé de surhcrage une methode virtuelle ?
};


class Mur : public Case {
    public :
        char afficher () override {
        return '#' ;
        }
        int effet(Aventurier& a) override { return 0; }
};

class Passage : public Case {
    public :
        char afficher () override{
        return ' ';
        }
        int effet(Aventurier& a) override { return 0; }
};

class Tresor : public Case{
    
    public :
        char afficher () override {
        return '+';
        }
        int effet(Aventurier& a) override { 
            a.setInventaire(a.getInventaire() + 1);
            return a.getInventaire();
        }
    };

class Monstre : public Case {

    public :
        char afficher() override{
            return 'M';
        }
        int effet(Aventurier& a){
            if (a.getSante() > 70){
                a.setSante(a.getSante() -50);
                return a.getSante();
            }
            else{
                a.getPos()[0] = 0;
                a.getPos()[1] = 0;
                return 0;;
            }
         }
};

class Piege : public Case{
   
    public :
        char afficher () override{
            return 'T';
        }
        int effet(Aventurier& a){
           a.setSante(a.getSante() -50) ;
            if (a.getInventaire() != 0){
                a.setInventaire(a.getInventaire() -1) ; 
                return a.getInventaire(); 
            }
        }
};

