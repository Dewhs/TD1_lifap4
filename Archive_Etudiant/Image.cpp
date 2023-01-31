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
    std::cout << "Test de Regression" << std::endl;
}