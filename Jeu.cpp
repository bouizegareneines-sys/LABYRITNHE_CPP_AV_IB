#include <iostream>
#include "Jeu.h"



void Jeu::afficherStatut() {
    cout << "----------------------------------\n";
    cout << "Position du joueur : " << joueur.getPos() << "\n"; 
    cout << "Sante du joueur : " << joueur.getSante() << "/100\n";
    cout << "Inventaire : " << joueur.getInventaire() << " tresors\n";
    cout << "Nombre de cases restantes : " << plateau.getChemin().size() << endl; ///
    cout << "----------------------------------\n";
}

void Jeu::resoudreCase(Case* c) {
    if (c != nullptr) {
        c->effet(this->joueur); 
    }
}

void Jeu::EndGame(Donjon& plateau) {
    if (!joueur.estVivant()) {
        cout << "Fin de la partie : Vous etes mort ...." << endl;
    } else if(joueur.estVivant() && (joueur.getPos()[0],joueur.getPos()[1] == plateau.getArrivee())) {
        cout << "Fin de la partie : Vous avez gagne !!! " << endl;
    }
}

void Jeu::BoucleDeJeu(Donjon& plateau) {
    char commande;
    
    while (joueur.estVivant() && !(joueur.getPos() == plateau.getArrivee())) {
        plateau.afficher();
        afficherStatut();

        cout << "(z,q,s,d) pour bouger, p pour aide : ";
        cin >> commande; 

        switch(commande) {
            case 'z': joueur.deplacer(0, 1);  break;
            case 's': joueur.deplacer(0, -1); break;
            case 'q': joueur.deplacer(-1, 0); break;
            case 'd': joueur.deplacer(1, 0);  break;
            case 'p': plateau.trouverChemin(); break;
            default: cout << "Mauvaise touche " << endl; break;
        }

        Case* caseActuelle = plateau.getCase(joueur.getPos());
        resoudreCase(caseActuelle);
    }
    
    EndGame();
}
