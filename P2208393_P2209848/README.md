# Module Image
![C++](https://img.shields.io/badge/made_with-C++-green.svg)
![platform](https://img.shields.io/badge/platform-Linux-red.svg)
![CLion](https://img.shields.io/badge/CLion-000000?style=flat&logo=clion&logoColor=white)
![VSCode](https://img.shields.io/badge/Visual_Studio_Code-0078D4?style=flat&logo=visual%20studio%20code&logoColor=white)


Module image est un projet pour l'UE LifAPCD (L2 Informatique de l'UCBL).
L'objectif est de proposer un programme permettant de générer, d'enregistrer au format ppm et d'afficher une image en console, ou graphiquement via SDL2 

## Contenu 

```Makefile``` et ```readme.md``` \
```/src``` contient le code source \
```/bin``` contiendra les exécutables générés par le makefile \
```/obj``` contiendra les objets générés par le makefile \
```/data``` contiendra les images générés au format .ppm \
```/doc``` contient une documentation Doxygen du projet

## Usage 
Pour compiler, utilisez le makefile fourni dans l'archive à la racine de celle-ci
````text
make bin/test && make bin/exemple && make bin/affichage
````

Vous pouvez après exécuter les trois exécutables. 

```bin/test``` lance un test de régression \
```bin/exemple``` permet de lancer un exemple sans affichage \
```bin/affichage``` permet de lancer un exemple avec un affichage graphique


## Auteurs
- DELGADO Roger (p2208393)
- JACOB Yaël-Alexandre (p2209849) 

