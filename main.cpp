/**\
  * @file   main.cpp
  * @author TomPlanche
  * @brief  main du game-tools-universel
\**/

// . Importation Des Bibliothèques Nécessaires.
#include <iostream>
#include "game-tools.h"

using OS::afficherNombreEnCouleur;
using OS::afficherTexteEnCouleur;
using OS::random;
using OS::effacer;
using OS::pause;

// .  ==========================================================================
// .                                  MAIN                                      
// .  ==========================================================================

int main(void) {
    /**\
      * @goal                           :  Montrer comment utiliser la fonction 'effacer'
      * @author :                       :  T.Planche
    \**/

    // . Afficher des nombres en couleur
    cout << "** Des nombres en couleur **" << endl;
    afficherNombreEnCouleur(5, bleu, true);
    afficherNombreEnCouleur(4.5, vert, true);
    afficherNombreEnCouleur(3, cyan, true);
    afficherNombreEnCouleur(2.5, rouge, true);
    afficherNombreEnCouleur(1, violet, true);
    afficherNombreEnCouleur(0.5, jaune, true);
    afficherNombreEnCouleur(0, blanc, true);
    cout << endl;

    // . Mettre en pause le programme
    cout << "Appuyer sur Entree pour effacer l'ecran et afficher du texte en couleur...";
    pause();
    effacer();

    // . Afficher des textes en couleur
    cout << "** Du texte en couleur **" << endl;
    afficherTexteEnCouleur("Tous ", bleu, false);
    afficherTexteEnCouleur("les ", vert, false);
    afficherTexteEnCouleur("programmeurs ", cyan, false);
    afficherTexteEnCouleur("sont ", rouge, false);
    afficherTexteEnCouleur("des ", violet, false);
    afficherTexteEnCouleur("optimistes", jaune, true);

    // . Mettre en pause le programme
    cout << endl;
    cout << "Appuyer sur Entree pour afficher progressivement un triangle en couleur...";
    pause();
    effacer();

    // . Afficher un triangle coloré de manière progressive
    cout << "** Un triangle en couleur qui s'affiche progressivement **" << endl;
    afficherTexteEnCouleur("*", bleu, true);
    pause(1);
    afficherTexteEnCouleur("**", vert, true);
    pause(1);
    afficherTexteEnCouleur("***", cyan, true);
    pause(1);
    afficherTexteEnCouleur("****", rouge, true);
    pause(1);
    afficherTexteEnCouleur("******", jaune, true);

    // . Mettre en pause le programme
    cout << endl;
    cout << "Appuyer sur Entree pour effacer l'ecran ";
    cout << "et generer un nombre aleatoire compris entre 0 et 100...";
    pause();
    effacer();

    // . Afficher un entier aléatoire compris en 0 et 100
    cout << "Un entier aleatoire compris entre 0 et 100 : ";
    cout << random(0, 100) << endl << endl;

    return 0;
}
