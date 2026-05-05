#ifndef JEU_H
#define JEU_H

#include "Aventurier.h"
#include "Donjon.h"
#include "Case.h"
#include "CaseFactory.h"
#include <iostream>
using namespace std;


class Jeu
{

    private :
        Aventurier joueur;
        Donjon plateau;
    public:
        Jeu();
        ~Jeu();
        
        void Jeu :: afficherStatut();
        void BoucleDeJeu(Donjon& plateau);
        void Jeu::resoudreCase(Case* c);
        void Jeu :: EndGame(Donjon& plateau);



};

#endif