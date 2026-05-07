#ifndef CASE_H
#define CASE_H

/*
 * @file Case.h
 * @brief Créer les différents types de cases qui héritent de la classse mère virtuelle. Indique également si une case est franchissable. 
 */

#include "Aventurier.h"
#include <iostream>
using namespace std;


class Case {
    private :
        bool pass = false;
        bool battable = false;
    public : 
        Case(bool pass,bool battable) : pass(pass),battable(battable) {};
        bool peutPasser() { return pass; };
        bool peutSeBattre() {return battable;}
        virtual char afficher() = 0;
        virtual ~Case() = default ; 
        virtual int effet (Aventurier & a) = 0;
};


class Mur : public Case {

    public :
        Mur() : Case(false,false){};
        char afficher () override;
        int effet(Aventurier& a) override;
};

class Passage : public Case {
    public :
        Passage() : Case(true,false){};
        char afficher () override ;
        int effet(Aventurier& a) override;
};

class Tresor : public Case{
    public :
        Tresor() : Case(true,false){};
        char afficher () override;
        int effet(Aventurier& a) override;
        
};

class Monstre : public Case {
    public :
        Monstre() : Case(true,true){};
        char afficher () override;
        int effet(Aventurier& a) override;
 
};

class Piege : public Case{
    public :
        Piege() : Case(true,false){};
        char afficher () override;
        int effet(Aventurier& a) override; 
        
};

#endif