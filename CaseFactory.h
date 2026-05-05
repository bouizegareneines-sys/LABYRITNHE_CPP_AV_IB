#ifndef CASEFACTORY_H
#define CASEFACTORY_H

/** 
 * @file CaseFactory.h
 * @brief Usine de création pour les différents types de cases.
 */

#include "Case.h"
#include <iostream>

enum class TypeCase {MUR, PASSAGE, MONSTRE, TRESOR, PIEGE};

class CaseFactory {
    public:
        /**
     * @brief Crée dynamiquement une instance de Case selon le type demandé.
     
     * Selon le type passé en paramètre, la méthode retourne un pointeur 
     * vers une nouvelle instance de Mur, Monstre, Tresor, etc.
     * 
     * @param type Un des types disponible dans l'énum.
     * @return Case* Un pointeur vers l'objet créé, ou nullptr si le type est inconnu.
     * Le destructeur virtuel de la classe Case libère la mémoire.
     */
        static Case* createCase(TypeCase type);

};

#endif 
