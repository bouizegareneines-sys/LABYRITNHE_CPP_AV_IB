#ifndef AVENTURIER_H
#define AVENTURIER_H

/** 
 * @file Aventurier.h
 * @brief Définit les caracteristiques du joueur et les actions qui lui sont reliés à lui ou son inventaire.
 */

#include <iostream>
#include <utility>
using namespace std;


class Aventurier{

    private: 

        int sante; // Point de santé du joueur/100
        int inventaire; // Nombre de trésor dans l'inventaire du joueur
        pair<int,int> pos; // Paire représentant la position du joueur dans la grille

    public : 
        /**
        * @brief Constructeur par défault 
        */
        Aventurier(); 
        /**
        * @brief Constructeur avec arguments 
        */
        Aventurier(int sante, int inventaire, pair<int,int> pos);

        /**
        * @brief Setters permettant de modifier la valeur des attributs privés de la classe 
        *  et getters permet de lire les attributs privés de la classe dans d'autre classe.
        */
        int getSante();
        int getInventaire();
        void setSante(int s);
        void setInventaire(int i);

        pair<int,int> getPos();
        void setPos(int pos_x,int pos_y);

        /**
        * @brief Permet de déplacer le joueur sur la grille
        * @return Une paire représentant la nouvelle position 
        */
        pair<int,int> deplacer(int nx, int ny);

        /**
        * @brief Retourne true si la santé du joueur est plus grande que 0/100
        */
        bool estVivant();

        /**
        * @brief Affiche le symbole du joueur sur la grille "@"
        */
        void afficher();

};

/**
        * @brief Surcharge de l'opérateur << pour pouvor afficher la position du joueur. 
        */
ostream& operator<<(ostream& o, const pair<int, int>& p);

#endif

