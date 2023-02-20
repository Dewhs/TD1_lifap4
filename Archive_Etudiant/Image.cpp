#include <assert.h>
#include <iostream>
#include "Image.h"

Image::Image()
{
    dimx = 0;
    dimy = 0;
    tab = nullptr;
}

Image::Image(int dimensionX, int dimensionY)
{
    assert(dimensionX > 0 && dimensionY > 0);
    dimx = dimensionX;
    dimy = dimensionY;
    tab = new Pixel[dimensionX * dimensionY];
}

Image::~Image()
{
    delete [] tab;
}

Pixel Image::getPix(int &x, int &y)
{
    assert(x > 0 && y > 0);
    assert(x < dimx && y < dimy);
    return tab[y * dimx + x];
}

void Image::setPix(int &x, int &y, Pixel &couleur)
{
    assert(x > 0 && y > 0);
    assert(x < dimx && y < dimy);
    tab[y * dimx + x] = couleur;
}

void Image::dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, Pixel &couleur)
{
    for (int i = Ymin; i <= Ymax; i++)
    {
        for (int j = Xmin; i <= Xmax; i++)
        {
            setPix(j, i, couleur);
        }
    }
}

void Image::effacer(Pixel &couleur)
{
    dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::testRegression()
{
    std::cout << "## Début du test de régression ##" std::endl;

    std::cout << "--- On va définir notre image en 50*50" << std::endl;
    Image im1(50, 50);

    std::cout << "- On vérifie les dimensions . " <<;
    assert(im1.dimx == 50);
    assert(im2.dimy == 50);
    std::cout << ". [V]" << endl;

    std::cout << "- On vérifie la taille du tableau alloué . " <<;
    assert((sizeof(tab) / sizeof(int)) = 500);
    std::cout << ". [V]" << endl;

    std::cout << "- On vérifie que le pixel est noir . " <<;
    for (int i = 0; i < im1.dimx; i++){
        for (int j = 0; j < im1.dimy; j++){
            assert(im1.getPix(j, i).getRouge()==0);
            assert(im1.getPix(j, i).getBleu()==0);
            assert(im1.getPix(j, i).getVert()==0)
        }
    }
    std::cout << ". [V]" << endl;

    std::cout << "-> On rempli l'image d'une couleur. " <<;
    //TODO remplir
    for (int i = 0; i <= (y * x); i++){
        //TODO assert
    }
    std::cout << ". [V]";

    std::cout << "-> On set un pixel spécifique (au pixel par défaut, à un point tiré en random)" std::endl;
    valx = 0; //TODO
    valy = 0; //TODO
    setPix(valx, valy, pix1);
    assert(tab[valx * valy] = pix1);

    std::cout << "## Test de régression terminé !! " << endl;

}