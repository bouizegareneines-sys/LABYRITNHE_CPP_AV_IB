#include "Case.h"
#include <iostream>

enum class TypeCase {MUR, PASSAGE, MONSTRE, TRESOR, PIEGE};

class Factory {
    public:
        static Case* createCase(TypeCase type){ // utilité du cnst ? 
        // est ce que ca apport vrmt qlqch de mettre un switch ?
            if (type == TypeCase :: MUR){
                    return new Mur(); }
            if (type == TypeCase :: MONSTRE){
                    return new Monstre(); }
            if (type == TypeCase :: PIEGE){
                    return new Piege(); }
            if (type == TypeCase :: PASSAGE){
                    return new Passage(); }
            if (type == TypeCase :: TRESOR){
                    return new Tresor(); }
            }

};