/**\
  * @file    game-tools.cpp
  * @author T.Planche
  * @brief  Corps du module game-tools
\**/

#include "game-tools.h"

# ifdef _WIN32
    #include <conio.h>
# else
    #include <unistd.h>
# endif

using namespace OS;

#define RESET "\033[0m"
#define ROUGE "\033[0;31m"
#define VERT "\033[0;32m"
#define JAUNE "\033[0;33m"
#define BLEU "\033[0;34m"
#define VIOLET "\033[0;35m"
#define CYAN "\033[0;36m"
#define BLANC "\033[0;37m"


#include <chrono>  // pour la fonction now() utilisée dans la fonction random()
#include <random>  // pour la fonction random

using namespace std::chrono;


# ifdef __APPLE__
    // Retourne le code couleur de la couleur passé en paramètre
    string getCodeCouleur (Couleur couleur) {
        string codeCouleur;
        switch (couleur)
        {
        case bleu:
            codeCouleur = BLEU;
            break;

        case vert:
            codeCouleur = VERT;
            break;

        case cyan:
            codeCouleur = CYAN;
            break;

        case rouge:
            codeCouleur = ROUGE;
            break;

        case violet:
            codeCouleur = VIOLET;
            break;

        case jaune:
            codeCouleur = JAUNE;
            break;

        case blanc:
            codeCouleur = BLANC;
            break;

        default:
            codeCouleur = RESET;
            break;
        }

        return codeCouleur;
    }
# endif

int OS::random(int min, int max) {
    std::default_random_engine generateur;
    std::uniform_int_distribution<int> distributionNombres;
    unsigned int tempsActuel = static_cast<unsigned int>(steady_clock::now().time_since_epoch().count());
    generateur.seed(tempsActuel);

    return ((distributionNombres(generateur) % (max - min + 1)) + min);
}

void OS::pause(unsigned int dureeEnSecondes) {
    if (dureeEnSecondes == 0) {
        # ifdef _WIN32
            char touche;
            touche = char(getch());
            touche = ' ';
            cout << touche << endl;
        # else
            std::cin.ignore();
        # endif
    } else {
        # ifdef _WIN32
            const unsigned short int UNE_MILLISECONDE = 1000;
            Sleep(dureeEnSecondes * UNE_MILLISECONDE);
        # else
            const unsigned int MICRO_SECONDE = 1000000;
            usleep(dureeEnSecondes * MICRO_SECONDE);
        # endif
    }
}


