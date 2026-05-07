#ifndef JEU_H
#define JEU_H

/*
 * @file Jeu.h
 * @brief Déroule la logique d'une partie de jeu avec affichage de la grille et boucle de jeu.
 */

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
        void Combat(Donjon& plateau,Case* c,int nx, int ny, int posx,int posy);
        void EndGame(Donjon& plateau);
        void BoucleDeJeu(Donjon& plateau);
        



};

#endif