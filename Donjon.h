#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include "Case.h"

using namespace std;

class Donjon{
private:
    vector<vector<Case *>> grille;
    int largeur;
    int hauteur;
    vector<vector<bool>> visite_gen;
    pair<int,int> depart;
    pair<int,int> arrivee;
public:
    Donjon();
    Donjon(int largeur,int hauteur);
    Donjon(int largeur,int hauteur,pair<int,int> depart,pair<int,int> arrivee);
    ~Donjon();

    int getLargeur();
    int getHauteur();
    pair<int,int> getDepart();
    pair<int,int> getArrivee();


    void initialiserGrille(int largeur,int hauteur);
    void genererLabyrinthe(vector<vector<Case *>>& grille,int x,int y);
    void placerElement(vector<vector<Case *>>& grille);
    void poserEntree(vector<vector<Case *>>& grille);
    void poserSortie(vector<vector<Case *>>& grille);

    void afficher();
    vector<pair<int,int>> trouverChemin(vector<vector<Case *>>& grille,pair<int,int> depart,pair<int,int> arrivee);
    vector<pair<int,int>> reconstruireChemin(vector<vector<pair<int,int>>> parent,pair<int,int> depart,pair<int,int> arrivee);};