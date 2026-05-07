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
        bool flag_chemin=false; //flag indiquant l'affichage du chemin optimal

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

        /**
         * @brief Setter du flag indiquant si le joueur veut voir le chemin optimal vers la sortie
         */
        void setFlag(bool flag);

        /**
        * @brief Code d'initialisation de la grille. Récupère les dimensions du plateau, genère une grille de murs et engendre la génération d'un labyrinthe avec entrée, sortie et éléments interactifs
        */
        void initialiserGrille(int largeur,int hauteur); 

        /**
        * @brief Code de tracé des passages du labyrinthe. Creuses les cases de la grille en passages.
        */
        void genererLabyrinthe(vector<vector<Case *>>& grille,int x,int y);
         /**
        * @brief Place aléatoirement des cases de types interactifs en modifiant les case pointées par la grille.
        */
        void placerElement(vector<vector<Case *>>& grille);

         /**
        * @brief Fait en sorte que la case a la coordonées "depart" est un passage.
        */

        void poserEntree(vector<vector<Case *>>& grille);

        /**
        * @brief Fait en sorte que la case a la coordonées "arrivee" est un passage. 
        */

        void poserSortie(vector<vector<Case *>>& grille);

         /**
        * @brief  Affiche les cases de la grille dans le terminal.
        */
        void afficher(pair<int,int> posJoueur,vector<pair<int,int>> chemin);
        /**
        * @brief Traverse le labyrinthe jusqu'à trouver un chemin optimal et le renvoie sous forme de vecteur de coordonnées.
        */
        vector<pair<int,int>> trouverChemin(vector<vector<Case *>>& grille,pair<int,int> depart,pair<int,int> arrivee);
        /**
        * @brief Retrace le chemin menant à l'arrivee et le renvoie sous forme de vecteur de coordonnées.
        */
        vector<pair<int,int>> reconstruireChemin(vector<vector<pair<int,int>>> parent,pair<int,int> depart,pair<int,int> arrivee);
         /**
        * @brief Renvoie la case indiquée par les coordonnées x et y.
        */
        Case* getCase(int x, int y);
};
#endif