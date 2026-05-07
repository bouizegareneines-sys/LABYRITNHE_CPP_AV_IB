// Projet C++ //
// Verdier Adélie --- 21502087 --- //
// Bouizegarene Ines --- 21213221 --- //

#include "CaseFactory.h"
#include "Case.h"
#include "Aventurier.h"
#include <iostream>


Case* CaseFactory :: createCase(TypeCase type){

    if (type == TypeCase :: MUR){
            return new Mur(); 
        }
    if (type == TypeCase :: MONSTRE){
            return new Monstre(); 
        }
    if (type == TypeCase :: PIEGE){
            return new Piege(); 
        }
    if (type == TypeCase :: PASSAGE){
            return new Passage(); 
        }
    if (type == TypeCase :: TRESOR){
        return new Tresor();
    }
    return nullptr;
}

