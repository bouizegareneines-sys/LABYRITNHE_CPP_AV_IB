// Projet C++ //
// Verdier Adélie --- 21502087 --- //
// Bouizegarene Ines --- 21213221 --- //

#include <iostream>
#include "Jeu.h"

Jeu::Jeu(): joueur(){}
Jeu::~Jeu(){}

void Jeu::afficherStatut(Donjon& plateau) {
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

void Jeu::Combat(Donjon& plateau,Case* c,int nx, int ny, int posx,int posy){
    cout << "Un Monstre apparait! Voulez-vous vous battre? (y/n):" ;
    char rep;
    cin >> rep;
    switch (rep){
        case 'y':
            resoudreCase(c);
            joueur.deplacer(nx, ny);
            cout << "Le Monstre est vaincu! Mais il a fait quelques degats" <<endl;
            delete plateau.getGrille()[posx+nx][posy+ny];
            plateau.getGrille()[posx+nx][posy+ny] = CaseFactory::createCase(TypeCase::PASSAGE);
            break;
        case 'n':
            cout << "Vous arrivez a fuir!" << endl;
            break;
    }
}

void Jeu::EndGame(Donjon& plateau) {
    if (!joueur.estVivant()) {
        cout << "Fin de la partie : Vous etes mort ...." << endl;
    } else if(joueur.estVivant() && (joueur.getPos() == plateau.getArrivee())) {
        cout << "Fin de la partie : Vous avez gagne !!! " << endl;
    }
}

void Jeu::BoucleDeJeu(Donjon& plateau) {
    char commande;
    vector<pair<int,int>> chemin_opti;

    while (joueur.estVivant() && !(joueur.getPos() == plateau.getArrivee())) {
        
        plateau.afficher(joueur.getPos(),chemin_opti);
        afficherStatut(plateau); 

        cout << "(z,q,s,d) pour bouger, p pour demander chemin ideal : ";
        cin >> commande; 

        switch(commande) {
            case 'z': if (plateau.getCase(joueur.getPos().first-1,joueur.getPos().second)->peutPasser()) 
                { 
                    if (plateau.getCase(joueur.getPos().first-1,joueur.getPos().second)->peutSeBattre()){ 
                        Combat(plateau,plateau.getCase(joueur.getPos().first-1,joueur.getPos().second),-1,0,joueur.getPos().first,joueur.getPos().second);
                        continue;
                    }                   
                    else {joueur.deplacer(-1, 0);}
                }  
                break;
            case 's': if (plateau.getCase(joueur.getPos().first+1,joueur.getPos().second)->peutPasser()) 
                {
                    if (plateau.getCase(joueur.getPos().first+1,joueur.getPos().second)->peutSeBattre()){
                        Combat(plateau,plateau.getCase(joueur.getPos().first+1,joueur.getPos().second),1,0,joueur.getPos().first,joueur.getPos().second);
                        continue;
                    }
                    else {joueur.deplacer(1, 0);}
                } 
                break;
            case 'q': if (plateau.getCase(joueur.getPos().first,joueur.getPos().second-1)->peutPasser()) 
            {
                if (plateau.getCase(joueur.getPos().first,joueur.getPos().second-1)->peutSeBattre()){
                    Combat(plateau,plateau.getCase(joueur.getPos().first,joueur.getPos().second-1),0,-1,joueur.getPos().first,joueur.getPos().second);
                    continue;
                }
                else {joueur.deplacer(0, -1);}
            } 
                break;
            case 'd': if (plateau.getCase(joueur.getPos().first,joueur.getPos().second+1)->peutPasser()) 
            {
                if (plateau.getCase(joueur.getPos().first,joueur.getPos().second+1)->peutSeBattre()){
                    Combat(plateau,plateau.getCase(joueur.getPos().first,joueur.getPos().second+1),0,1,joueur.getPos().first,joueur.getPos().second);
                    continue;
                }
                else {joueur.deplacer(0, 1);}
            }  
                break;
            case 'p': 
                chemin_opti = plateau.trouverChemin(plateau.getGrille(), joueur.getPos(), plateau.getArrivee());
                plateau.setFlag(true);
                break;
            default: cout << "Mauvaise touche " << endl; 
            continue; // 'continue' évite de résoudre la case si on n'a pas bougé
        }


        Case* caseActuelle = plateau.getCase(joueur.getPos().first, joueur.getPos().second);
        resoudreCase(caseActuelle);
    }
    
    EndGame(plateau);
}


