#ifndef _IMAGE
#define _IMAGE

#include "Pixel.h"
#include <assert.h>
#include <iostream>
#include <fstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

//! \brief Pour gérer une image avec SDL2
class Image {
private:
    unsigned int dimx, dimy; // les dimensions de l'image
    Pixel* tab; // le tableau 1D de pixel
public:
    // Constructeur par défaut de la classe : initialise à 0
    // ce constructeur n'alloue pas de pixel
    Image();
    /** Constructeur d'une image avec une dimension précise
    * @param dimensionX dimension sur l'axe x de l'image
    * @param dimensionY dimension sur l'axe y de l'image
    */
    Image(int dimensionX, int dimensionY);

    // Destructeur de la classe : désallocation de la mémoire du tableau de pixels
    // et mise à jour des champs dimx et dimy à 0
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

    //Affiche une image dans la console
    void afficherConsole();

    //SDL : Permet l'initialisation de l'affichage de l'image.
    void afficherInit();

    //SDL : Permet la gestion des évènements de l'image (zoom/désoom)
    void afficherBoucle();

    //SDL : Permet de détruire une image affichée
    void afficherDetruit();

    //SDL : Permet l'affichage d'une image
    void afficher();

    // Effectue une série de tests vérifiant que le module fonctionne et que les données membres de l'objet sont conformes
    void testRegression();

};
#endif 