/*
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

/*
 * @class Donjon
 * @brief Représente le plateau de jeu composé d'une grille de cases.
 * 
 * Cette classe gère l'initialisation du niveau, l'affichage de la carte
 * et le calcul du chemin optimal entre le départ et l'arrivée.
 */

class Donjon{
    private:
        vector<vector<Case *>> grille;
        int largeur;
        int hauteur;
        vector<vector<bool>> visite_gen;
        pair<int,int> depart;
        pair<int,int> arrivee;
        Aventurier joueur;
        vector<pair<int,int>> chemin_restant;
        bool flag_chemin=false;

    public:
        /*
        @brief Constructeur par défaut de la classe Donjon.
        */
        Donjon();
        Donjon(int largeur,int hauteur);
        Donjon(int largeur,int hauteur,pair<int,int> depart,pair<int,int> arrivee);
        ~Donjon();

        int& getLargeur();
        int& getHauteur();
        vector<vector<Case *>>& getGrille();
        pair<int,int>& getDepart();
        pair<int,int>& getArrivee();
        vector<pair<int,int>>& getChemin();
        void setFlag(bool flag);


        void initialiserGrille(int largeur,int hauteur);
        void genererLabyrinthe(vector<vector<Case *>>& grille,int x,int y);
        void placerElement(vector<vector<Case *>>& grille);
        void poserEntree(vector<vector<Case *>>& grille);
        void poserSortie(vector<vector<Case *>>& grille);

        void afficher(pair<int,int> posJoueur,vector<pair<int,int>> chemin);
        vector<pair<int,int>> trouverChemin(vector<vector<Case *>>& grille,pair<int,int> depart,pair<int,int> arrivee);
        vector<pair<int,int>> reconstruireChemin(vector<vector<pair<int,int>>> parent,pair<int,int> depart,pair<int,int> arrivee);

        Case* getCase(int x, int y);
};
#endif