## Introduction

Un graphe est une structure de données incontournable en algorithmie. On utilise les graphes dans de nombreux problèmes de la vie de tous les jours, comme par exemple dans le métro, en utilisant le GPS, ou bien en naviguant sur Internet.

## Principe d'un graphe

On peut définir un graphe comme étant un ensemble de *nœuds* (ou de sommets) étant reliés par des 
*arcs*.

// TODO : image graphe (exemple)

## Vocabulaire

Un graphe peut avoir de nombreuses caractéristiques différentes, en voici une liste non exhaustive.

### Orienté/non orienté

### Pondéré/non pondéré

### Cyclique/acyclique

### Dense/creux

// TODO : notion de voisin, de degré entrant/sortant, prédécesseurs

## Implémentation

On peut implémenter un graphe de différentes façons :

   - matrice d'adjacence : complexité en mémoire de O(N²) -> tableau 2D
   - liste d'adjacence : complexité en mémoire de O(N + M) -> vector \<Noeud\>
   - liste d'arcs : complexité en mémoire (OM) -> vector \<Arc\>

## Parcourir un graphe

- DFS
- BFS

## Opérations utiles sur un graphe

- détection de cycle
- tri topologique
- arc essentiel
- circuit eulérien
- recherche du plus court chemin
- arbre couvrant minimal
- composante fortement connexe

## Conclusion
