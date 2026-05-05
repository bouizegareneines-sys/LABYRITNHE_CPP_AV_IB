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
        
        void afficherStatut(Donjon& plateau);
        void resoudreCase(Case* c);
        void EndGame(Donjon& plateau);
        void BoucleDeJeu(Donjon& plateau);
        



};

#endif