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
    // Constructeur par défaut de la classe : initialise à 0
    // ce constructeur n'alloue pas de pixel
    Image();
    // Constructeur de la classe : initialise selon dimensionX et dimensionY
    // puis alloue le tableau de pixel dans le tas (image noire)
    Image(int dimensionX, int dimensionY);

    // Destructeur de la classe : désallocation de la mémoire du tableau de pixels
    // et mise à jour des champs dimx et dimy à 0
    ~Image();

    // Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
    Pixel getPix(const unsigned int &x, const unsigned int &y) const;

    // Mutateur : modifie le pixel de coordonnée (x, y)
    void setPix(const unsigned int& x,const unsigned int& y, Pixel& couleur);

    // Dessine un rectangle plein de la couleur de l'image
    void dessinerRectangle (unsigned int Xmin,unsigned int Ymin,unsigned int Xmax,unsigned int Ymax, Pixel& couleur);

    // Efface l'image en la remplissant de la couleur en paramètre
    void effacer(Pixel& couleur);

    //Sauvegarde une image dans un fichier
    void sauver(const string & filename) const;

    //Ouvre une image depuis un fichier
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