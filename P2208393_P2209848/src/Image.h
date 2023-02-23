#ifndef _IMAGE
#define _IMAGE

#include "Pixel.h"
#include <assert.h>
#include <iostream>
#include <fstream>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

using namespace std;

class Image {
private:
    unsigned int dimx, dimy; // les dimensions de l'image
    Pixel* tab; // le tableau 1D de pixel
public:

    /** Constructeur d'une image par défaut
    */
    Image();
    /** Constructeur d'une image avec une dimension précise
    * @param dimensionX dimension sur l'axe x de l'image
    * @param dimensionY dimension sur l'axe y de l'image
    */
    Image(int dimensionX, int dimensionY);

    /** Détruit l'image
    */
    ~Image();

    /** Accesseur : Retourne le pixel de coordonnées (x, y) de l'image
    * @param x La coordonnée x du pixel
    * @param y La coordonnée y du pixel
    * @return Le pixel demandé
    */
    Pixel getPix(const unsigned int &x, const unsigned int &y) const;

    /** Mutateur : Défini la valeur d'un pixel de l'image
    * @param x La coordonnée x du pixel
    * @param y La coordonnée y du pixel
    * @param couleur Le pixel couleur souhaité
    */
    void setPix(const unsigned int& x,const unsigned int& y, Pixel& couleur);

    /** Permet de remplir une image pixel par pixel de façon rectangulaire par une couleur (un pixel) défini
    * @param Xmin La coordonnée x du premier pixel
    * @param Ymin La coordonnée y du premier pixel
    * @param Xmax La coordonnée x du dernier pixel
    * @param Ymax La coordonnée y du dernier pixel
    * @param couleur Le pixel couleur souhaité
    */
    void dessinerRectangle (unsigned int Xmin,unsigned int Ymin,unsigned int Xmax,unsigned int Ymax, Pixel& couleur);

    /** Permet d'effacer (ou de remplir) entièrement une image par un pixel couleur spécifié
    * @param couleur Le pixel couleur souhaité
    */
    void effacer(Pixel& couleur);

    /** Permet de sauvegarder une image en fichier .ppm
    * @param filename La destination du fichier souhaité
    */
    void sauver(const string & filename) const;

    /** Permet d'ouvrir une image depuis un fichier .ppm
    * @param filename Le chemin du fichier source
    */
    void ouvrir(const string & filename);

    /** Permet d'afficher l'image en console
    */
    void afficherConsole();

    /** Initialise l'affichage SDL
    */
    void afficherInit();

    /** Gère les évènements de l'image SDL
    */
    void afficherBoucle();

    /** Détruit l'image SDL
    */
    void afficherDetruit();

    /** Permet d'afficher l'image en mode graphique avec SDL
    */
    void afficher();

    /** Effectue une série de tests sur toutes les fonctions de Image.cpp, vérifie le bon fonctionnement des fonctions et vérifie que les données sont conformes
    */
    void testRegression();

};
#endif 