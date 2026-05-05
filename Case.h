#ifndef CASE_H
#define CASE_H
#include "Aventurier.h"
#include <iostream>
using namespace std;


class Case {
    private :
        bool pass = false;
    public : 
        Case(bool pass) : pass(pass) {};
        bool peutPasser() { return pass; };
        virtual char afficher() = 0;
        virtual ~Case() = default ; 
        virtual int effet (Aventurier & a) = 0; // est ce qu on est obligé de surhcrage une methode virtuelle ?
};


class Mur : public Case {

    public :
        Mur() : Case(false){};
        char afficher () override;
        int effet(Aventurier& a) override;
};

class Passage : public Case {
    public :
        Passage() : Case(true){};
        char afficher () override ;
        int effet(Aventurier& a) override;
};

class Tresor : public Case{
    public :
        Tresor() : Case(true){};
        char afficher () override;
        int effet(Aventurier& a) override;
        
};

class Monstre : public Case {
    public :
        Monstre() : Case(true){};
        char afficher () override;
        int effet(Aventurier& a) override;
 
};

class Piege : public Case{
    public :
        Piege() : Case(true){};
        char afficher () override;
        int effet(Aventurier& a) override; 
        
};

#endif