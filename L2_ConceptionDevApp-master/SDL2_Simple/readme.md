
# SDL2_image

SDL2_simple est du code C++ issu de l'UE LIFAP4 pour illustré l'usage de SDL2 au étudiants.


# git 

Ce code fait partie du dépôt git de LIFAP4
https://forge.univ-lyon1.fr/Alexandre.Meyer/L2_ConceptionDevApp



# Installation

Les comandes d'installation de SDL2 sont données pour Linux/Ubuntu

Pour installer SDL2 
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev

Pour compiler, utilisez la commande make

~/L2_ConceptionDevApp.gituniv/SDL2_exemple$ make clean
rm -rf simple.o simple

~/L2_ConceptionDevApp.gituniv/SDL2_exemple$ make
g++ -o simple.o simple.cpp -c -ISDL2
g++ -o simple simple.o -lSDL2 -lSDL2_ttf -lSDL2_image


# Usage

Lancez le programme comme ceci

~/L2_ConceptionDevApp.gituniv/SDL2_Simple$ ./simple

Vos devriez voir une fenêtre SDL s'ouvrir affichage un pacman.


# Générer un fichier d'exclusion d'erreurs à Valgrind
make valgrind



# Contribution et License
Contributeur :
- Alexandre Meyer
- Nicolas Pronost

Toute idée d'amélioration est bienvenue.
Passez par un pull request via la forge.

Vous pouvez réutliser ce code comme bon cous semble pour le cours de LIFAP4. Il est là pour ca.

Pour une license plus standard, voyez par exemple
[MIT](https://choosealicense.com/licenses/mit/)
