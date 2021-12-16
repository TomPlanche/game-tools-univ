/**\
  * @file   game-tools.h
  * @author T.Planche
  * @brief  Fichier d'entête du module game-tools
\**/


# ifndef GAME_TOOLS_H
# define GAME_TOOLS_H

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::flush;

/**\
  * @brief Si la machine est sous Windows®, importation de cette bibilothèque
  * 
\**/
# if defined(WIN32) || defined(_WIN32) || defined(__WIN32) 
    #include <windows.h>
# endif

/**\
  * @brief Liste de couleurs utilisables avec les procedures #afficherTexteEnCouleur et #afficherNombreEnCouleur
  * 
\**/
# ifdef _WIN32
    enum Couleur {
        /** La couleur gris a pour code couleur 7*/
        gris = 7,
        /** La couleur bleu a pour code couleur 9*/
        bleu = 9,
        /** La couleur vert a pour code couleur 10*/
        vert = 10,
        /** La couleur cyan a pour code couleur 11*/
        cyan = 11,
        /** La couleur rouge a pour code couleur 12*/
        rouge = 12,
        /** La couleur violet a pour code couleur 13*/
        violet = 13,
        /** La couleur jaune a pour code couleur 14*/
        jaune = 14,
        /** La couleur blanc a pour code couleur 15*/
        blanc = 15
    };
# else
    enum Couleur {gris = 0, rouge, vert, jaune, bleu, violet, cyan, blanc};
# endif


/**\
  * @brief Permet d'afficher un nombre en couleur.
  * 
  * @param nombre le nombre à afficher. Il peut s'agit d'un nombre entier ou d'un nombre à virgule.
  * @param couleur la couleur à utiliser pour afficher le nombre. La couleur doit faire partie.
  * @param retourALaLigne true si retour à la ligne en fin de ligne.
\**/
void afficherNombreEnCouleur(double nombre, Couleur couleur, bool retourALaLigne = false);


/**\
  * @brief Permet d'afficher une chaine de caractères en couleur.
  * 
  * @param chaine La chaine à afficher. 
  * @param couleur Couleur à utiliser pour afficher le caractère.
  *     La couleur doit faire partie des valeurs proposées par le type #Couleur
  * @param retourALaLigne 
\**/
void afficherTexteEnCouleur(string chaine, Couleur couleur, bool retourALaLigne = false);


/**\
  * @brief Permet d'afficher un caractère en couleur.
  * 
  * @param caractere le caractère à afficher.
  * @param couleur Couleur à utiliser pour afficher le caractère.
  *     La couleur doit faire partie des valeurs proposées par le type #Couleur
  * @param retourALaLigne 
\**/
void afficherTexteEnCouleur(char caractere, Couleur couleur, bool retourALaLigne = false);


/**\
  * @brief Retourne une couleur aléatoire.
  * 
  * @return Couleur Générée aléatoirement.
\**/
Couleur couleurAleatoire(int nombre);


/**\
  * @brief Efface le contenu du terminal.
  * 
\**/
void effacer();



/**\
  * @brief Met en pause l'exécution du programme durant un temps.
  * 
  * @param dureeEnSecondes la durée en secondes de la pause.
 *      Si ce paramètre est égal à 0, le programme s'interrompt jusqu'à ce que
 *      l'utilisateur appuie sur une touche.
\**/
void pause(unsigned int dureeEnSecondes = 0);


/**\
  * @brief Génère un nombre entier aléatoire compris dans un intervalle donné.
  * 
  * @param min la borne min de l'intervalle.
  * @param max la borne max de l'intervalle.
  * @return int le nombre aléatoire généré.
\**/
int random(int min, int max);


# endif