#include "Image.h"

using namespace std;

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

Pixel Image::getPix(const int &x, const int &y) const
{
    assert(x >= 0 && y >= 0);
    assert(x <= dimx && y <= dimy);
    return tab[y * dimx + x];
}

void Image::setPix(int &x, int &y, Pixel &couleur)
{
    assert(x >= 0 && y >= 0);
    assert(x <= dimx && y <= dimy);

    tab[y * dimx + x] = couleur;
}

void Image::dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, Pixel &couleur)
{
    for (int i = Xmin; i <= Xmax; i++)
    {
        for (int j = Ymin; i <= Ymax; j++)
        {
            setPix(i, j, couleur);
        }
    }
}

void Image::effacer(Pixel &couleur)
{
    dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::sauver(const string & filename) const {
    ofstream fichier (filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            const Pixel pix = getPix(x,y);
            fichier << pix.getRouge() << " " << pix.getVert() << " " << pix.getBleu() << " ";
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string & filename) {
    ifstream fichier (filename.c_str());
    assert(fichier.is_open());
    char r,g,b;
    string mot;
    dimx = dimy = 0;
    fichier >> mot >> dimx >> dimy >> mot;
    assert(dimx > 0 && dimy > 0);
    if (tab != NULL) delete [] tab;
    tab = new Pixel [dimx*dimy];
    for(unsigned int y=0; y<dimy; ++y)
        for(unsigned int x=0; x<dimx; ++x) {
            fichier >> r >> b >> g;
            getPix(x,y).setRouge(r);
            getPix(x,y).setVert(g);
            getPix(x,y).setBleu(b);
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole(){
    cout << dimx << " " << dimy << endl;
    for(unsigned int y=0; y<dimy; ++y) {
        for(unsigned int x=0; x<dimx; ++x) {
            const Pixel pix = getPix(x,y);
            cout << pix.getRouge() << " " << pix.getVert() << " " << pix.getBleu() << " ";
        }
        cout << endl;
    }
}

void Image::testRegression()
{
    cout << "## Début du test de régression ##" << endl;

    cout << "--- On défini une image par défaut (0*0)" << endl;
    Image im0;

    cout << "- On vérifie qu'elle est bien existante & vide . ";
    assert(im0.dimx == 0);
    assert(im0.dimy == 0);
    assert(im0.tab == nullptr);
    cout << ". [V]" << endl;


    cout << "--- On va définir notre image en 50*50" << endl;
    Image im1(50, 50);

    cout << "- On vérifie les dimensions . ";
    assert(im1.dimx == 50);
    assert(im1.dimy == 50);
    cout << ". [V]" << endl;

    //cout << "- On vérifie la taille du tableau alloué . ";
    //assert((sizeof(tab) / sizeof(int)) == 500);
    //cout << ". [V] " << endl;

    cout << "- On vérifie que le pixel est noir . ";
    for (int i = 0; i < im1.dimx; i++){
        for (int j = 0; j < im1.dimy; j++){
            assert(im1.getPix(j, i).getRouge()==0);
            assert(im1.getPix(j, i).getBleu()==0);
            assert(im1.getPix(j, i).getVert()==0);
        }
    }
    cout << ". [V]" << endl;

    cout << "- On crées un pixel et on défini ce pixel . ";
    Pixel px1;
    px1.setBleu(10);
    px1.setRouge(15);
    px1.setVert(20);
    assert(px1.getBleu() == 10);
    assert(px1.getRouge() == 15);
    assert(px1.getVert() == 20);
    cout << ". [V]" << endl;

    cout << "-> On rempli l'image d'une couleur . ";
    im1.dessinerRectangle(0, 0, 50, 50, px1);
    for (int i = 0; i < im1.dimx; i++){
        for (int j = 0; j < im1.dimy; j++){
            cout << "PX : " << i << j << endl;
            assert(im1.getPix(i, j).getRouge() == px1.getRouge());
            assert(im1.getPix(i, j).getBleu() == px1.getBleu());
            assert(im1.getPix(i, j).getVert() == px1.getVert());
        }
    }
    cout << ". [V]";

    cout << "-> On set un pixel spécifique (au pixel par défaut, à un point tiré en random) .";
    //TODO set un pixel spécifique
    cout << ". [V]" << endl;

    cout << "## Test de régression terminé !! " << endl;
}