// Projet C++ //
// Verdier Adélie --- 21502087 --- //
// Bouizegarene Ines --- 21213221 --- //

/** 
 * @file Donjon.h
 * @brief Gestion de la grille de jeu et de la navigation.
 */

#ifndef DONJON_H
#define DONJON_H

#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include "Case.h"
#include "Aventurier.h"

using namespace std;
/** 
 * @class Donjon
 * @brief Représente le plateau de jeu composé d'une grille de cases.
 * 
 * Cette classe gère l'initialisation du niveau, l'affichage de la carte
 * et le calcul du chemin optimal entre le départ et l'arrivée.
 */

class Donjon{
    private:
        vector<vector<Case *>> grille; // Vecteur contenant toutes les cases de la grille
        int largeur; // largeur du plateau
        int hauteur; // hauteur du plateau
        vector<vector<bool>> visite_gen; // 
        pair<int,int> depart; // coordonnées de la case de départ
        pair<int,int> arrivee; // coordonnées de la case d'arrivée
        Aventurier joueur; // instance de la classe Aventurier
        vector<pair<int,int>> chemin_restant; // Vecteur de coordonnées restsantes
        bool flag_chemin=false;

    public:
    
        Donjon(); // Constructeur par défault 
        Donjon(int largeur,int hauteur);// Constructeur de la grille
        Donjon(int largeur,int hauteur,pair<int,int> depart,pair<int,int> arrivee);// Constructeur de la grille avec le départ et l'arrivée
        ~Donjon(); //Destructeur

        /**
         * @brief Getters pour obtenir la Largeur et la Hauteur d'avant ainsi que la grille, le chemin, la case de départ et d'arrivée
         */
        int& getLargeur();
        int& getHauteur();
        vector<vector<Case *>>& getGrille(); 
        pair<int,int>& getDepart();
        pair<int,int>& getArrivee();
        vector<pair<int,int>>& getChemin();
        void setFlag(bool flag);

        /**
        * @brief A COMPLETER.
        */
        void initialiserGrille(int largeur,int hauteur); 

        /**
        * @brief A COMPLETER.
        */
        void genererLabyrinthe(vector<vector<Case *>>& grille,int x,int y);
         /**
        * @brief A COMPLETER
        */
        void placerElement(vector<vector<Case *>>& grille);

         /**
        * @brief A COMPLETER
        */

        void poserEntree(vector<vector<Case *>>& grille);

        /**
        * @brief  /**
        * @brief Setters permettant de modifier la valeur des attributs privés de la classe 
        *  et getters permet de lire les attributs privés de la classe dans d'autre classe.
        */

        void poserSortie(vector<vector<Case *>>& grille);

         /**
        * @brief  A COMPLETER
        */
        void afficher(pair<int,int> posJoueur,vector<pair<int,int>> chemin);
        /**
        * @brief A COMPLETER
        */
        vector<pair<int,int>> trouverChemin(vector<vector<Case *>>& grille,pair<int,int> depart,pair<int,int> arrivee);
        /**
        * @brief A COMPLETER
        */
        vector<pair<int,int>> reconstruireChemin(vector<vector<pair<int,int>>> parent,pair<int,int> depart,pair<int,int> arrivee);
         /**
        * @brief A COMPLETER
        */
        Case* getCase(int x, int y);
};
#endif