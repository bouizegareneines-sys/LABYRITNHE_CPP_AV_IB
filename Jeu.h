// Projet C++ //
// Verdier Adélie --- 21502087 --- //
// Bouizegarene Ines --- 21213221 --- //

#ifndef JEU_H
#define JEU_H

/** 
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
        Aventurier joueur; // instance de la classe Aventurier
    public:
        Jeu(); // constructeur par défault de la classe Jeu
        ~Jeu(); //destructeur de la classe Jeu
        
        /**
         * @brief La méthode afficherStatut prend en entrée un élement de type Donjon et permet d'afficher
         * les informations relatives à la partie de jeu comme la position du joueur, son état de santé, son inventaire et le nombre de cases avant l'arrivée
         */
        void afficherStatut(Donjon& plateau); 
        /**
         * @brief Cette méthode applique sur le joueur l'effet de la case sur laquelle il se trouve.
         */
        void resoudreCase(Case* c);
        void Combat(Donjon& plateau,Case* c,int nx, int ny, int posx,int posy);
        /**
         * @brief Cette méthode gère les deux scénari possibles de fin de partie : victoire ou défaite du joueur.
         */
        void EndGame(Donjon& plateau);
        /**
         * @brief Gère le déroulé d'une partie de jeu : fait appel aux méthodes endgame, afficherstatut et résoudre case 
         * Gère les entrées claviers qui permettent à l'utilisateur de se déplacer sur le plateau
         */
        void BoucleDeJeu(Donjon& plateau);
};

#endif