#ifndef _PIXELS
#define _PIXELS

class Pixel
{
private:
    unsigned char r, g, b;

public:
    /** Constructeur d'un pixel avec des valeurs par défaut
    */
    Pixel();

    /** Constructeur d'un pixel avec des valeurs définies
    * @param nr La composante rouge
    * @param ng La composante verte
    * @param nb La composante bleu
    */
    Pixel(unsigned char nr, unsigned char ng, unsigned char nb);

    /** Accesseur de la composante rouge
    * @return récupère la composante rouge du pixel
    */
    unsigned char getRouge() const;

    /** Accesseur de la composante verte
    * @return récupère la composante verte du pixel
    */
    unsigned char getVert() const;

    /** Accesseur de la composante bleue
    * @return récupère la composante bleue du pixel
    */
    unsigned char getBleu() const;

    /** Mutateur de la composante rouge
    * @param nr composante rouge souhaité
    * @return défini la composante rouge du pixel
    */
    void setRouge(unsigned char nr);

    /** Mutateur de la composante verte
    * @param ng composante verte souhaité
    * @return défini la composante verte du pixel
    */
    void setVert(unsigned char ng);

    /** Mutateur de la composante bleue
    * @param nb composante bleue souhaité
    * @return défini la composante bleue du pixel
    */
    void setBleu(unsigned char nb);

    /** Destructeur d'un pixel
    */
    ~Pixel();
};
#endif