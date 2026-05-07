// Projet C++ //
// Verdier Adélie --- 21502087 --- //
// Bouizegarene Ines --- 21213221 --- //

#ifndef CASE_H
#define CASE_H

/** 
 * @file Case.h
 * @brief Créer les différents types de cases qui héritent de la classse mère virtuelle. Indique également si une case est franchissable. 
 */

#include "Aventurier.h"
#include <iostream>
using namespace std;


class Case {
    private :
        // Booléen qui indique si la case est franchissable par le joueur
        bool pass = false;
        bool battable = false;
    public : 
        Case(bool pass,bool battable) : pass(pass),battable(battable) {};
        bool peutPasser() { return pass; };
        bool peutSeBattre() {return battable;}
        virtual char afficher() = 0;
        virtual ~Case() = default ; 
        virtual int effet (Aventurier & a) = 0;
};


class Mur : public Case {
    /**
     * @brief Classe enfant de Case (polymorphisme) qui génére un objet de type case : ici un mur 
     * Les méthodes sont définit dans la classe parente et sont override ici. 
     * Mur n'est pas franchissable, on a donc Mur(): Case(false)
     */
    public :
        Mur() : Case(false,false){};
        char afficher () override;
        int effet(Aventurier& a) override;
};

class Passage : public Case {
       /**
     * @brief Classe enfant de Case (polymorphisme) qui génére un objet de type case : ici un passage 
     * Les méthodes sont définit dans la classe parente et sont override ici. 
     * Passage est franchissable, on a donc Passage(): Case(true)
     */
    public :
        Passage() : Case(true,false){};
        char afficher () override ;
        int effet(Aventurier& a) override;
};

class Tresor : public Case{
       /**
     * @brief Classe enfant de Case (polymorphisme) qui génére un objet de type case : ici un trésor 
     * Les méthodes sont définit dans la classe parente et sont override ici. 
     * Trésor est franchissable, on a donc Trésor(): Case(true)
     */
    public :
        Tresor() : Case(true,false){};
        char afficher () override;
        int effet(Aventurier& a) override;
        
};

class Monstre : public Case {
    /**
     * @brief Classe enfant de Case (polymorphisme) qui génére un objet de type case : ici un monstre 
     * Les méthodes sont définit dans la classe parente et sont override ici. 
     * Monstre est franchissable, on a donc Monstre(): Case(true)
     */
    public :
        Monstre() : Case(true,true){};
        char afficher () override;
        int effet(Aventurier& a) override;
 
};

class Piege : public Case{
    /**
     * @brief Classe enfant de Case (polymorphisme) qui génére un objet de type case : ici un piège 
     * Les méthodes sont définit dans la classe parente et sont override ici. 
     * Piège est franchissable, on a donc piege(): Case(true)
     */
    public :
        Piege() : Case(true,false){};
        char afficher () override;
        int effet(Aventurier& a) override; 
        
};

#endif