/**\
  * @file    game-tools.cpp
  * @author T.Planche
  * @brief  Corps du module game-tools
\**/

#include "game-tools.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    #include <conio.h>
#else
    #include <unistd.h>
#endif

using namespace OS;


#include <chrono>  // pour la fonction now() utilisée dans la fonction random()
#include <random>  // pour la fonction random

using namespace std::chrono;


# ifdef __APPLE__

    #define RESET "\033[0m"
    #define ROUGE "\033[0;31m"
    #define VERT "\033[0;32m"
    #define JAUNE "\033[0;33m"
    #define BLEU "\033[0;34m"
    #define VIOLET "\033[0;35m"
    #define CYAN "\033[0;36m"
    #define BLANC "\033[0;37m"

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


void OS::effacer() {
    # ifdef _WIN32
        HANDLE idTerminal;
        CONSOLE_SCREEN_BUFFER_INFO caracteristiquesTerminal;
        DWORD count;
        DWORD nbreCellulesDansTerminal;
        COORD coordonneesOrigine = {0, 0};

        idTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
        if (idTerminal == INVALID_HANDLE_VALUE)
        {
            return;
        }

        /* Calculer le nombre de cellules du terminal */
        if (!GetConsoleScreenBufferInfo(idTerminal, &caracteristiquesTerminal))
        {
            return;
        }
        nbreCellulesDansTerminal = caracteristiquesTerminal.dwSize.X * caracteristiquesTerminal.dwSize.Y;

        /* Remplir le terminal avec des espaces */
        if (!FillConsoleOutputCharacter(idTerminal, (TCHAR)' ', nbreCellulesDansTerminal, coordonneesOrigine, &count))
        {
            return;
        }

        /*Remplir le terminal avec les couleurs courantes */
        if (!FillConsoleOutputAttribute(
                idTerminal,
                caracteristiquesTerminal.wAttributes,
                nbreCellulesDansTerminal,
                coordonneesOrigine,
                &count))
        {
            return;
        }

        /* Déplacer le curseur au début du terminal */
        SetConsoleCursorPosition(idTerminal, coordonneesOrigine);
    #else
        cout << "\033[2J\033[1;1H";
    #endif
}


void OS::afficherTexteEnCouleur(string chaine, Couleur couleur, bool retourALaLigne) {
    # ifdef _WIN32
        HANDLE idTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(idTerminal, couleur);
        cout << chaine << flush;
        SetConsoleTextAttribute(idTerminal, gris);
    # else
        string codeCouleur = getCodeCouleur(couleur);
        cout << codeCouleur << chaine << RESET << flush;
    # endif

    if (retourALaLigne) {
        cout << endl;
    }
}


void OS::afficherTexteEnCouleur(char caractere, Couleur couleur, bool retourALaLigne) {
    # ifdef _WIN32
        HANDLE idTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(idTerminal, couleur);
        cout << caractere << flush;
        SetConsoleTextAttribute(idTerminal, gris);
    # else
        string codeCouleur = getCodeCouleur(couleur);
        cout << codeCouleur << caractere << RESET << flush;
    # endif

    if (retourALaLigne) {
        cout << endl;
    }
}


void OS::afficherNombreEnCouleur(double nombre, Couleur couleur, bool retourALaLigne) {
    # ifdef _WIN32
        HANDLE idTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(idTerminal, couleur);
        cout << nombre << flush;
        SetConsoleTextAttribute(idTerminal, gris);
    # else
        string codeCouleur = getCodeCouleur(couleur);
        cout << codeCouleur << nombre << RESET << flush;
    # endif

    if (retourALaLigne) {
        cout << endl;
    }
}
