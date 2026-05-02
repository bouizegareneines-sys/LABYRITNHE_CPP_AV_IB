#include <iostream>
#include <vector>
#include <Case.h>


using namespace std;

class Donjon{
private:
vector<vector<Case*>> grille;
public:

    void initialiserGrille(int largeur,int hauteur);
    void genererLabyrinthe(grille,x,y);
    void placerElements(grille);
    void poserEntree(grille);
    void poserSortie(grille);

    void afficher();
    vector<pair<int,int>> trouverChemin();s
}