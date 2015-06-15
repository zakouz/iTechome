## Introduction

Un graphe est une structure de données incontournable en algorithmie. On utilise les graphes dans de nombreux problèmes de la vie de tous les jours, comme par exemple dans le métro, en utilisant le GPS, ou bien en naviguant sur Internet.

## Principe d'un graphe

On peut définir un graphe comme étant un ensemble de *nœuds* (ou de sommets) étant reliés par des 
*arcs* (ou des arêtes).

![Exemple de graphe](https://raw.githubusercontent.com/iTech-/iTechome/master/1%20-%20Algorithme/1%20-%20Structure%20de%20donnees/6%20-%20Graphe/Image/graphe_exemple.png)

## Vocabulaire

Si deux nœuds sont reliés par un arc, on dit qu'ils sont *voisins*.

Le *degré entrant* d'un nœud correspond au nombre d'arcs arrivant sur ce nœud, il en est de même pour le *degré sortant* correspondant alors au nombre d'arcs sortant du nœud.

Un graphe peut avoir de nombreuses caractéristiques différentes, en voici une liste non exhaustive.

### Orienté/non orienté

Un graphe est dit *orienté* si ses arcs ont un sens (représenté par une flèche), comme par exemple ce graphe :

![Graphe orienté](https://raw.githubusercontent.com/iTech-/iTechome/master/1%20-%20Algorithme/1%20-%20Structure%20de%20donnees/6%20-%20Graphe/Image/graphe_oriente.png)

En revanche on dit d'un graphe qu'il est *non orienté* si aucun sens n'est attribué à ses arcs :

![Graphe non orienté](https://raw.githubusercontent.com/iTech-/iTechome/master/1%20-%20Algorithme/1%20-%20Structure%20de%20donnees/6%20-%20Graphe/Image/graphe_non_oriente.png)

### Pondéré/non pondéré

Un graphe est *pondéré* si ses arcs ont un *poids* :

![Graphe pondéré](https://raw.githubusercontent.com/iTech-/iTechome/master/1%20-%20Algorithme/1%20-%20Structure%20de%20donnees/6%20-%20Graphe/Image/graphe_pondere.png)

Dans cet exemple on utilise le graphe pour représenter une carte routière avec comme pondération la distance séparant deux villes.

### Cyclique/acyclique

Un graphe est *cyclique* s'il contient des cycles (un chemin finissant là où il a commencé) :

![Graphe cyclique](https://raw.githubusercontent.com/iTech-/iTechome/master/1%20-%20Algorithme/1%20-%20Structure%20de%20donnees/6%20-%20Graphe/Image/graphe_cyclique.png)

Un graphe qui ne contient aucun cycle est donc caractérisé d'*acyclique* :

![Graphe acyclique](https://raw.githubusercontent.com/iTech-/iTechome/master/1%20-%20Algorithme/1%20-%20Structure%20de%20donnees/6%20-%20Graphe/Image/graphe_acyclique.png)

### Dense/creux

On peut dire d'un graphe qu'il est *dense* si le nombre d'arcs est proche du nombre maximum possible de ce graphe :

![Graphe dense](https://raw.githubusercontent.com/iTech-/iTechome/master/1%20-%20Algorithme/1%20-%20Structure%20de%20donnees/6%20-%20Graphe/Image/graphe_dense.png)

Lorsque le nombre d'arcs est faible, on parle d'un graphe *creux* :

![Graphe creux](https://raw.githubusercontent.com/iTech-/iTechome/master/1%20-%20Algorithme/1%20-%20Structure%20de%20donnees/6%20-%20Graphe/Image/graphe_creux.png)

## Implémentation

// TODO : représentation + code + explication

On peut implémenter un graphe de différentes façons :

   - **Matrice d'adjacence** : tableau 2D stockant pour chaque nœud les nœuds auquel il est relié (le tableau peut être un tableau de booléen, ou bien un tableau d'entier pouvant alors stocker le poids des arcs reliant les deux nœuds). Cette représentation a donc une complexité en mémoire de *O(N²)* mais permet de vérifier si deux nœuds sont voisins en *O(1*).
   - **Liste d'adjacence** : complexité en mémoire de O(N + M) -> vector \<Noeud\>
   - **Liste d'arcs** : complexité en mémoire (OM) -> vector \<Arc\>

## Parcourir un graphe

Afin de parcourir notre graphe, on peut utiliser deux algorithmes différents :

- [Parcours en profondeur](https://itechome.wordpress.com/algorithme/structure-de-donnees/graphe/parcours-en-profondeur/) : DFS (*Depth First Search*)
- [Parcours en largeur](https://itechome.wordpress.com/algorithme/structure-de-donnees/graphe/parcours-en-largeur/) : BFS (*Breadth First Search*)

## Opérations utiles sur un graphe

Voici une liste non exhaustive d'opérations utiles lorsqu'on manipule un graphe : 

- Détection de cycle
- Tri topologique
- Arc essentiel
- Circuit eulérien
- Recherche du plus court chemin
- Arbre couvrant minimal
- Composante fortement connexe

*Plusieurs articles sur chacunes des opérations sont prévus*

## Conclusion

Un graphe est une structure de données incontournable, cette structure est utilisée dans de très nombreux problèmes (plus ou moins complexes).

// TODO : meilleure conclusion
