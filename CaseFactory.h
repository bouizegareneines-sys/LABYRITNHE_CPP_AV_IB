#ifndef CASEFACTORY_H
#define CASEFACTORY_H

#include "Case.h"
#include <iostream>



enum class TypeCase {MUR, PASSAGE, MONSTRE, TRESOR, PIEGE};

class CaseFactory {
    public:
        static Case* createCase(TypeCase type);

};

#endif 
