// Projet C++ //
// Verdier Adélie --- 21502087 --- //
// Bouizegarene Ines --- 21213221 --- //

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