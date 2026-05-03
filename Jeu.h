#include <iostream>
using namespace std;
#include "Aventurier.h"
#include "Donjon.h"

class Jeu
{
public:
    Jeu();

    void afficherPlateau(int x,int y);
    void afficherStats(Joueur);

    void run();

    ~Jeu();


private:
    Aventurier Joueur();
    Donjon Plateau();

};