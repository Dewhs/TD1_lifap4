#include "Image.h"

using namespace std;

Image::Image() : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false)
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
    delete[] tab;
    /*SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;*/
}

Pixel Image::getPix(const unsigned int &x, const unsigned int &y) const
{
    assert(x >= 0 && y >= 0);
    assert(x <= dimx && y <= dimy);
    return tab[y * dimx + x];
}

void Image::setPix(const unsigned int &x, const unsigned int &y, Pixel &couleur)
{
    assert(x >= 0 && y >= 0);
    assert(x <= dimx && y <= dimy);

    tab[y * dimx + x] = couleur;
}

void Image::dessinerRectangle(unsigned int Xmin, unsigned int Ymin, unsigned int Xmax, unsigned int Ymax, Pixel &couleur)
{
    for (unsigned int i = Xmin; i < Xmax; i++)
    {
        for (unsigned int j = Ymin; j < Ymax; j++)
        {
            setPix(i, j, couleur);
        }
    }
}

void Image::effacer(Pixel &couleur)
{
    dessinerRectangle(0, 0, dimx, dimy, couleur);
}

void Image::sauver(const string &filename) const
{
    ofstream fichier(filename.c_str());
    assert(fichier.is_open());
    fichier << "P3" << endl;
    fichier << dimx << " " << dimy << endl;
    fichier << "255" << endl;
    for (unsigned int y = 0; y < dimy; ++y)
        for (unsigned int x = 0; x < dimx; ++x)
        {
            const Pixel pix = getPix(x, y);
            fichier << pix.getRouge() << " " << pix.getVert() << " " << pix.getBleu() << " ";
        }
    cout << "Sauvegarde de l'image " << filename << " ... OK\n";
    fichier.close();
}

void Image::ouvrir(const string &filename)
{
    ifstream fichier(filename.c_str());
    assert(fichier.is_open());
    char r, g, b;
    string mot;
    dimx = dimy = 0;
    fichier >> mot >> dimx >> dimy >> mot;
    assert(dimx > 0 && dimy > 0);
    if (tab != NULL)
        delete[] tab;
    tab = new Pixel[dimx * dimy];
    for (unsigned int y = 0; y < dimy; ++y)
        for (unsigned int x = 0; x < dimx; ++x)
        {
            fichier >> r >> b >> g;
            getPix(x, y).setRouge(r);
            getPix(x, y).setVert(g);
            getPix(x, y).setBleu(b);
        }
    fichier.close();
    cout << "Lecture de l'image " << filename << " ... OK\n";
}

void Image::afficherConsole()
{
    cout << dimx << " " << dimy << endl;
    for (unsigned int y = 0; y < dimy; ++y)
    {
        for (unsigned int x = 0; x < dimx; ++x)
        {
            const Pixel pix = getPix(x, y);
            cout << pix.getRouge() << " " << pix.getVert() << " " << pix.getBleu() << " ";
        }
        cout << endl;
    }
}

void Image::afficherInit(int win_dimx, int win_dimy)
{

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    window = SDL_CreateWindow("Module_Image", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, win_dimx, win_dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
}

void Image::afficherBoucle()
{
    SDL_Event events;
    bool exited = false;

    // Si la fenêtre est toujours existante
    while (!exited)
    {
        // Si il reste des évènements à traiter
        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT)
            {
                exited = true; // Si un utilisateur quitte la fenêtre
            }

            else if (events.type == SDL_KEYDOWN)
            { // Si un utilisateur presse une touche
                switch (events.key.keysym.scancode)
                {
                case SDL_SCANCODE_T:
                    // TODO ZOOM
                    break;
                case SDL_SCANCODE_G:
                    // TODO DEZOOM
                    break;
                case SDL_SCANCODE_ESCAPE:
                    exited = true;
                    break;
                default:
                    break;
                }
            }
        }
    }
}

void Image::afficherDetruit()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Image::afficher()
{
    const int win_dimx = 200;
    const int win_dimy = 200;
    afficherInit(win_dimx, win_dimy);
    
    
    // Parcourir tous les pixels de l'image et les dessiner à l'écran
    for (unsigned int x = 0; x < dimx; x++) {
        for (unsigned int y = 0; y < dimy; y++) {
            // Récupérer la couleur du pixel
            int r = getPix(x, y).getRouge();
            int g = getPix(x, y).getVert();
            int b = getPix(x, y).getBleu();
            cout << "( " << r << " , " << g <<" , "<< b << " )" << endl;
            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            
            // Dessiner le pixel à l'écran
            SDL_RenderDrawPoint(renderer, (win_dimx-dimx)/2 + x, (win_dimx-dimx)/2 + y);
        }
    }
    
    
    SDL_RenderPresent(renderer);

    afficherBoucle();
    
    afficherDetruit();
}

void Image::testRegression()
{
    cout << "-- Test de régression --" << endl;

    cout << "-> Avec une image de dimension par défaut" << endl;
    Image im0;

    cout << "> Existante & vide . ";
    assert(im0.dimx == 0);
    assert(im0.dimy == 0);
    assert(im0.tab == nullptr);
    cout << ". [V]" << endl;

    cout << "-> Avec une nouvelle image en 50*50" << endl;
    Image im1(50, 50);

    cout << "> Dimensions . ";
    assert(im1.dimx == 50);
    assert(im1.dimy == 50);
    cout << ". [V]" << endl;

    cout << "> Image vide (tout les pixels sont noirs) . ";
    for (unsigned int i = 0; i < im1.dimx; i++)
    {
        for (unsigned int j = 0; j < im1.dimy; j++)
        {
            assert(im1.getPix(j, i).getRouge() == 0);
            assert(im1.getPix(j, i).getBleu() == 0);
            assert(im1.getPix(j, i).getVert() == 0);
        }
    }
    cout << ". [V]" << endl;

    cout << "> Création d'un pixel & définition du pixel . ";
    Pixel px1;
    px1.setBleu(10);
    px1.setRouge(15);
    px1.setVert(20);
    assert(px1.getBleu() == 10);
    assert(px1.getRouge() == 15);
    assert(px1.getVert() == 20);
    cout << ". [V]" << endl;

    cout << "> Remplissage de l'image avec ce pixel . ";
    im1.dessinerRectangle(0, 0, 50, 50, px1);
    for (unsigned int i = 0; i < im1.dimx; i++)
    {
        for (unsigned int j = 0; j < im1.dimy; j++)
        {
            assert(im1.getPix(i, j).getRouge() == px1.getRouge());
            assert(im1.getPix(i, j).getBleu() == px1.getBleu());
            assert(im1.getPix(i, j).getVert() == px1.getVert());
        }
    }
    cout << ". [V]" << endl;

    cout << "-- Test de régression terminé !! -- " << endl;
}