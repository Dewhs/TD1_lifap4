
# Exemple de SDL2 et imgui ensemble


## SDL2_image
SDL2_simple est du code C++ issu de l'UE LIFAP4 pour illustré l'usage de SDL2 au étudiants.

## imgui
Dear ImGui is a bloat-free graphical user interface library for C++.
https://github.com/ocornut/imgui


# git 
Ce code fait partie du dépôt git de LIFAP4
https://forge.univ-lyon1.fr/Alexandre.Meyer/L2_ConceptionDevApp



# Installation

Ce code n'a été testé que sous Linux. le makefile ne marche que sous Linux.
le code devrait marcher sous MacOS et Windows mais il faut chager le makefile.

Sous Linux il faut installer SDL2 et libglew-dev avec
sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev libglew-dev


# Compilation
cd SDL2_IMGUI_Simple
make

=> produit 2 executables
bin/simple
bin/demo


# Usage

~/L2_ConceptionDevApp.gituniv/SDL2_IMGUI_Simple$ bin/simple

Vos devriez voir une fenêtre SDL s'ouvrir affichage un pacman et une ihm imgui.



