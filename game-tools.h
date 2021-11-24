/**\
  * @file    game-tools.h
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


# if defined(WIN32) || defined(_WIN32) || defined(__WIN32) 
    #include <windows.h>
# endif

/**\
  * @brief Liste de couleurs utilisables avec les procedures #afficherTexteEnCouleur et #afficherNombreEnCouleur
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
    enum Couleur {gris, bleu, vert,  cyan, rouge, violet, jaune, blanc};
# endif

namespace OS {
    /**
     * @brief Permet d'afficher une chaine de caractères en couleur.
     *
     * @param [in] chaine la chaine à afficher.
     * @param [in] couleur la couleur à utiliser pour afficher la chaine. La couleur doit faire partie
     * des valeurs proposées par le type #Couleur
     * @param [in] retourALaLigne indique si l'affichage de la chaine doit être suivi d'un
     * retour à la ligne (true) ou pas (false).
     */
    void afficherTexteEnCouleur(string chaine, Couleur couleur, bool retourALaLigne = false);


    /**
     * @brief Permet d'afficher un caractère en couleur.
     *
     * @param [in] caractere le caractère à afficher.
     * @param [in] couleur la couleur à utiliser pour afficher le caractère. La couleur doit faire partie
     * des valeurs proposées par le type #Couleur
     * @param [in] retourALaLigne indique si l'affichage du caractère doit être suivi d'un
     * retour à la ligne (true) ou pas (false).
     */
    void afficherTexteEnCouleur(char caractere, Couleur couleur, bool retourALaLigne = false);
    

    /**
     * @brief Permet d'afficher un nombre en couleur.
     *
     * @param [in] nombre le nombre à afficher. Il peut s'agit d'un nombre entier ou d'un nombre à virgule.
     * @param [in] couleur la couleur à utiliser pour afficher le nombre. La couleur doit faire partie
     * des valeurs proposées par le type #Couleur
     * @param [in] retourALaLigne indique si l'affichage du nombre doit être suivi d'un
     * retour à la ligne (true) ou pas (false).
     */
    void afficherNombreEnCouleur(double nombre, Couleur couleur, bool retourALaLigne = false);


    /**
     * @brief Génère un nombre entier aléatoire compris dans un intervalle donné.
     *
     * @param [in] min la borne min de l'intervalle.
     * @param [in] max la borne max de l'intervalle.
     * @return int le nombre aléatoire généré.
     */
    int random(int min, int max);


    /**
     * @brief Met en pause l'exécution du programme durant un temps
     * déterminé ou jusqu'à ce que l'utilisateur appuie sur une touche.
     *
     * @param [in] dureeEnSecondes la durée en secondes de la pause. Si ce 
     * paramètre est égal à 0, le programme s'interrompt jusqu'à ce que
     * l'utilisateur appuie sur une touche.
     */
    void pause(unsigned int dureeEnSecondes = 0);


    /**
     * @brief Efface le contenu du terminal
     *
     */
    void effacer();


} // namespace OS


# endif