#include "Donjon.h"
#include "Case.h"
#include "CaseFactory.h"
#include <iostream>
#include <vector>
#include <random>
#include <bits/stdc++.h>
using namespace std;


Donjon::Donjon()
{
    this->largeur=22;
    this->hauteur=22;
    this->grille.assign(22,vector<Case*>(22, nullptr));
    this->depart={1,1};
    this->arrivee={21,21};
}

Donjon::Donjon(int largeur,int hauteur)
{
    this->grille.assign(largeur,vector<Case*>(hauteur, nullptr));
    this->depart={1,1};
    this->arrivee={21,21};
}

Donjon::Donjon(int largeur,int hauteur,pair<int,int> depart,pair<int,int> arrivee){
    this->largeur=largeur;
    this->hauteur=hauteur;
    this->grille.assign(largeur,vector<Case*>(hauteur, nullptr));
    this->depart=depart;
    this->arrivee=arrivee;
}


Donjon::~Donjon()
{
    for (int i = 0; i < largeur; i++){
        for (int j = 0; j < hauteur; j++){
            delete grille[i][j];
        }
    }
}

void Donjon::genererLabyrinthe(vector<vector<Case *>>& grille,int x,int y){
    this->visite_gen[x][y]=true;
    int x_new=x;
    int y_new=y;

    random_device rd;
    mt19937 g(rd());

    vector<int> directions {1,2,3,4}; //HAUT, BAS , DROITE , GAUCHE

    shuffle(directions.begin(),directions.end(),g);

    for (auto dir:directions){
        switch(dir){
            case 1:
                x_new=x;
                y_new=y-2;
                if ((y_new>1) && (this->visite_gen[x_new][y_new]==false)){
                    grille[x_new][y_new]=CaseFactory::createCase(TypeCase::PASSAGE);
                    genererLabyrinthe(grille,x_new,y_new);
                    break;
                }
                    
            case 2:
                x_new=x;
                y_new=y+2;
                if ((y_new<grille[x].size()) && (this->visite_gen[x_new][y_new]==false)){
                    grille[x_new][y_new]=CaseFactory::createCase(TypeCase::PASSAGE);
                    genererLabyrinthe(grille,x_new,y_new);
                    break;
                }
            case 3:
                x_new=x+2;
                y_new=y;
                if ((x_new<grille.size()) && (this->visite_gen[x_new][y_new]==false)){
                    grille[x_new][y_new]=CaseFactory::createCase(TypeCase::PASSAGE);
                    genererLabyrinthe(grille,x_new,y_new);
                    break;
                }
            case 4:
                x_new=x-2;
                y_new=y;
                if ((x_new<grille.size()) && (this->visite_gen[x_new][y_new]==false)){
                    grille[x_new][y_new]=CaseFactory::createCase(TypeCase::PASSAGE);
                    genererLabyrinthe(grille,x_new,y_new);
                    break;
                }
            }
    }
}

void Donjon::initialiserGrille(int largeur,int hauteur)
{
    this->largeur=largeur;
    this->hauteur=hauteur;

    grille.assign(largeur, vector<Case*>(hauteur, nullptr));
    visite_gen.assign(largeur, vector<bool>(hauteur, false));

    for (int i=0; i<largeur;i++){
        for (int j=0;j<hauteur;j++){
            grille[i][j] = CaseFactory::createCase(TypeCase::MUR);
            this->visite_gen[i][j]=false;
        }
    }
    genererLabyrinthe(grille,1,1);
    poserEntree(grille);
    poserSortie(grille);
}

void Donjon::poserEntree(vector<vector<Case *>>& grille){
    grille[1][1]=CaseFactory::createCase(TypeCase::PASSAGE);
}

void Donjon::poserSortie(vector<vector<Case *>>& grille){
    grille[(this->largeur)-1][(this->hauteur)-1]=CaseFactory::createCase(TypeCase::PASSAGE);
}

void Donjon::placerElement(vector<vector<Case*>>& grille){
    for (int i=0;i<grille.size();i++){
        for(int j=0;j<grille[i].size();j++){
            if ((*grille[i][j]).peutPasser()==true){
                int r = rand( ) % 101;
                if (r<5){
                    grille[i][j]=CaseFactory::createCase(TypeCase::TRESOR);
                }
                if (r<10){
                    grille[i][j]=CaseFactory::createCase(TypeCase::MONSTRE);
                }
                if (r<13){
                    grille[i][j]=CaseFactory::createCase(TypeCase::PIEGE);
                }
            }
        }
    }
}

void Donjon::afficher()
{
    cout << "+";
    for(int j=0;j<grille[0].size();j++){
        cout << "-";
    }
    cout << "+"<< endl;

    
    for (int i=0;i<grille.size();i++){
        cout << "|";
        for(int j=0;j<grille[i].size();j++){
            (*grille[i][j]).afficher();
        }
        cout << "|" << endl;
    }

    cout << "+";
    for(int j=0;j<grille[0].size();j++){
        cout << "-";
    }
    cout << "+"<< endl;

}

vector<pair<int,int>> Donjon::trouverChemin(vector<vector<Case *>>& grille,pair<int,int> depart,pair<int,int> arrivee)
{
    queue<pair<int,int>> file;

    vector<vector<bool>> visite;
    visite.assign(largeur, vector<bool>(hauteur, false));

    vector<vector<pair<int,int>>> parent;
    parent.assign(largeur, vector<pair<int,int>>(hauteur, {-1,-1}));

    file.push(depart);
    visite[depart.first][depart.second]=true;

    while (!file.empty()){
        pair<int,int> courant = file.front();
        file.pop();

        int x_courant = courant.first;
        int y_courant = courant.second;
        int x_new = x_courant;
        int y_new = y_courant;

        if (courant==arrivee){
            return reconstruireChemin(parent,depart,arrivee);
        }
        else {
            vector<int> directions {1,2,3,4}; //HAUT, BAS , DROITE , GAUCHE

            for (auto dir:directions){
                switch(dir){

                    case 1:
                        x_new = x_courant;
                        y_new = y_courant - 1;
                        if ((y_new>1) && (visite[x_new][y_new]==false) && (typeid(*grille[x_new][y_new]).name()!="MUR")){
                            visite[x_new][y_new]=true;
                            parent[x_new][y_new]=courant;
                            file.push({x_new,y_new});
                        }
                    break;

                    case 2:
                        x_new = x_courant;
                        y_new = y_courant + 1;
                        if ((y_new<grille[x_new].size()) && (visite[x_new][y_new]==false) && (typeid(*grille[x_new][y_new]).name()!="MUR")){
                            visite[x_new][y_new]=true;
                            parent[x_new][y_new]=courant;
                            file.push({x_new,y_new});
                        }
                    break;

                    case 3:
                        x_new = x_courant + 1;
                        y_new = y_courant;
                        if ((x_new<grille.size()) && (visite[x_new][y_new]==false) && (typeid(*grille[x_new][y_new]).name()!="MUR")){
                            visite[x_new][y_new]=true;
                            parent[x_new][y_new]=courant;
                            file.push({x_new,y_new});
                        }
                    break;

                    case 4:
                        x_new = x_courant - 1;
                        y_new = y_courant;
                        if ((x_new<=1) && (visite[x_new][y_new]==false) && (typeid(*grille[x_new][y_new]).name()!="MUR")){
                            visite[x_new][y_new]=true;
                            parent[x_new][y_new]=courant;
                            file.push({x_new,y_new});
                        }
                    break;

                }
            }
            
        }
        
    }
    return {};
}

vector<pair<int,int>> Donjon::reconstruireChemin(vector<vector<pair<int,int>>> parent,pair<int,int> depart,pair<int,int> arrivee)
{
    vector<pair<int,int>> chemin;
    pair<int,int> courant = arrivee;

    while (courant!=depart){
        chemin.push_back(courant);
        courant=parent[courant.first][courant.second];
    }

    chemin.push_back(depart);
    return chemin;
}
