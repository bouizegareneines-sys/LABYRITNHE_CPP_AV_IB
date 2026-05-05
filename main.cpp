#include <iostream>
#include "Jeu.h"
#include "Donjon.h"
using namespace std;

int main() {
    Donjon plateau;
    plateau.initialiserGrille(21, 21);

    Jeu partie;
    partie.BoucleDeJeu(plateau);

    return 0;
}