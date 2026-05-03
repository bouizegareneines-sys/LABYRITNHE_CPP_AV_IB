#include "Donjon.h"
#include <vector>

void Donjon::Donjon()
{
}

void Donjon::~Donjon()
{
}

void Donjon::genererLabyrinthe(grille,x,y){
    &grille[x][y].visitee=true;
    int x_new=x;
    int y_new=y;

    random_device rd;
    mt19937 g(rd());

    vector<string> directions={1,2,3,4}; //NORD , SUD , EST , OUEST

    random_shuffle(directions.begin(),directions.end(),g);

    for (auto dir:directions){
        switch(dir):
            case 1:
                y_new=y-2;
                x_new=x;
                if ((y_new>=1) && (&grille[x_new][y_new].visitee==false)){
                    &grille[x_new][y_new]=CaseFactory::creerCase(TypeCase::PASSAGE);
                    genererLabyrinthe(grille,x_new,y_new);
                }
                    
            case 2:
                y_new=y+2;
                x_new=x;
                if ((y_new<=grille[x].size()) && (&grille[x_new][y_new].visitee==false)){
                    &grille[x_new][y_new]=CaseFactory::creerCase(TypeCase::PASSAGE);
                    genererLabyrinthe(grille,x_new,y_new);
                }
            case 3:
                y_new=y;
                x_new=x+2;
                if ((y_new<=grille.size()) && (&grille[x_new][y_new].visitee==false)){
                    &grille[x_new][y_new]=CaseFactory::creerCase(TypeCase::PASSAGE);
                    genererLabyrinthe(grille,x_new,y_new);
                }
            case 4:
                y_new=y;
                x_new=x-2;
                if ((y_new<=grille.size()) && (&grille[x_new][y_new].visitee==false)){
                    &grille[x_new][y_new]=CaseFactory::creerCase(TypeCase::PASSAGE);
                    genererLabyrinthe(grille,x_new,y_new);
                }
    }
}

void Donjon::initialiserGrille(int largeur,int hauteur)
{
    for (i=0; i<largeur;i++){
        for (j=0;j<hauteur;j++){
            &grille[i][j] = CaseFactory::creerCase(TypeCase::MUR)
        }
    }
    genererLabyrinthe(grille,1,1)
    poserEntree(grille)
    poserSortie(grille)
}

void Donjon::poserEntree(grille){
    &grille[1][1]=CaseFactory::creerCase(TypeCase::PASSAGE);
}

void Donjon::poserSortie(grille){
    &grille[][]=CaseFactory::creerCase(TypeCase::PASSAGE);
}

void placerElement(grille){
    for (i=0;i<grille.size();i++){
        for(j=0;j<grille[i].size();j++){
            if typeid(grille[i][j]).name()=="PASSAGE":
                int r = rand( ) % 101
                if (r<5){
                    &grille[i][j]=CaseFactory::creerCase(TypeCase::TRESOR)
                }
                if (r<10){
                    &grille[i][j]=CaseFactory::creerCase(TypeCase::MONSTRE)
                }
                if (r<13){
                    &grille[i][j]=CaseFactory::creerCase(TypeCase::PIEGE)
                }
        }
    }
}

void Donjon::afficher()
{
    for (i=0;i<grille.size();i++){
        cout << "+";
        for(j=0;j<grille[i].size();j++){
            cout << "-"
        }
        cout << "+"<< endl;
    }
    for (i=0;i<grille.size();i++){
        cout << "|";
        for(j=0;j<grille[i].size();j++){
            &grille[x][y].afficher();
        }
        cout() << "|" << endl;
    }
    for (i=0;i<grille.size();i++){
        cout << "+";
        for(j=0;j<grille[i].size();j++){
            cout << "-"
        }
        cout << "+"<< endl;
    }

}

vector<pair<int,int>> Donjon::trouverChemin()
{

}
