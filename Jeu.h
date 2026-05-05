#ifndef JEU_H
#define JEU_H

#include "Aventurier.h"
#include "Donjon.h"
#include "Case.h"
#include "CaseFactory.h"
#include <iostream>
#include <utility> // pour std::pair
using namespace std;



class Jeu
{

    private :
        Aventurier joueur;
    public:
        Jeu();
        ~Jeu();
        
        void Jeu :: afficherStatut(Donjon& Plateau);
        ostream& operator<<(ostream& o, const pair<int, int>& p);
        void Jeu::resoudreCase(Case* c);
        void Jeu :: EndGame(Donjon& plateau);
        void BoucleDeJeu(Donjon& plateau);
        



};

#endif