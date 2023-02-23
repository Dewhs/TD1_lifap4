#include "Pixel.h"

Pixel::Pixel()
{
    r = 0;
    g = 0;
    b = 0;

}

/**
 * Constructeur d'un pixel
 * @param nr La composante rouge
 * @param ng La composante verte
 * @param nb La composante bleu
 */
Pixel::Pixel(unsigned char nr, unsigned char ng, unsigned char nb) : r(nr), g(ng), b(nb)
{
}

/**
 * Destructeur d'un pixel
 */
Pixel::~Pixel() {
    
}

/**
 * Accesseur de la composante rouge
 * @return récupère la composante rouge du pixel
 */
unsigned char Pixel::getRouge() const
{
    return r;
}

/**
 * Accesseur de la composante verte
 * @return récupère la composante verte du pixel
 */
unsigned char Pixel::getVert() const
{
    return g;
}

/**
 * Accesseur de la composante bleue
 * @return récupère la composante bleue du pixel
 */
unsigned char Pixel::getBleu() const
{
    return b;
}

/**
 * Mutateur de la composante rouge
 * @param nr composante rouge souhaité
 * @return défini la composante rouge du pixel
 */
void Pixel::setRouge(unsigned char nr)
{
    r = nr;
}

/**
 * Mutateur de la composante verte
 * @param ng composante verte souhaité
 * @return défini la composante verte du pixel
 */
void Pixel::setVert(unsigned char ng)
{
    g = ng;
}

/**
 * Mutateur de la composante bleue
 * @param nb composante bleue souhaité
 * @return défini la composante bleue du pixel
 */
void Pixel::setBleu(unsigned char nb)
{
    b = nb;
}

