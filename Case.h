#ifndef CASE_H
#define CASE_H
#include "Aventurier.h"
#include <iostream>
using namespace std;


class Case {
    public : 
        virtual char afficher() = 0;
        virtual ~Case() = default ; 
        virtual int effet (Aventurier & a) = 0; // est ce qu on est obligé de surhcrage une methode virtuelle ?
};


class Mur : public Case {
    public :
        char afficher () override;
        int effet(Aventurier& a) override;
};

class Passage : public Case {
    public :
        char afficher () override ;
        int effet(Aventurier& a) override;
};

class Tresor : public Case{
    public :
        char afficher () override;
        int effet(Aventurier& a) override;
        
};

class Monstre : public Case {
    public :
        char afficher () override;
        int effet(Aventurier& a) override;
 
};

class Piege : public Case{
    public :
        char afficher () override;
        int effet(Aventurier& a) override; 
        
};

#endif