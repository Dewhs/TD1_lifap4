#include "Pixel.h"

Pixel::Pixel()
{
    r, g, b = 0;
}

// Constructeur de la classe: initialise r,g,b avec les paramètresL
Pixel::Pixel(unsigned char nr, unsigned char ng, unsigned char nb) : r(nr), g(ng), b(nb)
{
}

// Accesseur : récupère la composante rouge du pixel
unsigned char Pixel::getRouge() const
{
    return r;
}
// Accesseur : récupère la composante verte du pixel
unsigned char Pixel::getVert() const 
{
    return g;
}
// Accesseur : récupère la composante bleue du pixel
unsigned char Pixel::getBleu() const
{
    return b;
}

// Mutateur : modifie la composante rouge du pixel
void Pixel::setRouge(unsigned char nr)
{
    r = nr;
}
// Mutateur : modifie la composante verte du pixel
void Pixel::setVert(unsigned char ng)
{
    g = ng;
}
// Mutateur : modifie la composante bleue du pixel
void Pixel::setBleu(unsigned char nb)
{
    b = nb;
}