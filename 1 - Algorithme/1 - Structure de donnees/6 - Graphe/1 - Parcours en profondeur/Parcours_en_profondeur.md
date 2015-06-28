## Introduction

Le parcours en profondeur (ou  plus communément *DFS* pour *Depth First Search*) permet de parcourir un graphe en utilisant le principe de la [récursivité](https://fr.wikipedia.org/wiki/Algorithme_r%C3%A9cursif). De plus, ce parcours de graphe est simple et rapide à implémenter.

## Principe du parcours en profondeur

Un parcours en profondeur a la particularité de parcourir les nœuds du graphe les plus "profonds" en premier (c'est-à-dire les plus éloignés du nœud d'où commence le parcours) avant de "remonter" progressivement dans le graphe.

On va donc chercher dans le graphe a aller le plus loin possible, puis une fois qu'on a atteint le bout, on remonte pour repartir de nouveau le plus loin possible dans une autre partie du graphe que l'on a pas encore explorée, et ainsi de suite jusqu'à la fin du parcours.

## Exemple

Avant de prendre des exemples en utilisant des graphes, on peut citer un exemple d'utilisation de parcours en profondeur dans un graphe dit *implicite* : le labyrinthe. Imaginons que vous êtes dans un labyrinthe et que vous voulez trouver la sortie. Vous décidez alors qu'à chaque croisement vous prenez à gauche, une fois que vous avez visité entièrement un chemin et qu'il ne mène à rien, vous revenez naturellement sur vos pas jusqu'au dernier croisement que vous avez rencontré et cette fois ci vous allez à droite, vous continuez ainsi jusqu'à avoir trouvé la sortie. Et bien cet manière de réfléchir et d'agir pour trouver la sortie d'un labyrinthe utilise un parcours en profondeur. En effet vous parcourez un chemin en entier avant de revenir sur vos pas pour parcourir un autre chemin en entier et ainsi de suite. Maintenant que vous avez cette idée en tête on peut appliquer l'algorithme sur des graphes dit *explicites*.

Pour bien comprendre un DFS je pense qu'il est nécessaire de commencer par visualiser son fonctionnement sur un [arbre](https://itechome.wordpress.com/algorithme/structure-de-donnees/arbre/) (je rappelle au passage qu'un arbre n'est qu'un graphe particulier).

Voici donc un arbre, et on peut apercevoir l'effet d'un parcours en profondeur dessus :

![Exemple d'un arbre parcouru en utilisant un DFS](https://raw.githubusercontent.com/iTech-/iTechome/master/1%20-%20Algorithme/1%20-%20Structure%20de%20donnees/6%20-%20Graphe/1%20-%20Parcours%20en%20profondeur/Image/arbre_dfs.png)

Chaque nœud possède un numéro, correspondant à l'ordre de parcours de l'arbre. On commence donc à la racine, puis on visite le fils gauche (le nœud 2), on continue à descendre dans l'arbre jusqu'au nœud 3 et on arrive à une feuille de l'arbre, ce qui signifie que l'on va remonter (puisqu'on a fini de parcourir cette partie de l'arbre), on revient donc au nœud 2 et on visite son fils droit non visité (le nœud 4), de même on visite le nœud 5, c'est une feuille on remonte donc et on visite le nœud 6, on remonte de nouveau au nœud 4, et on remonte encore une fois jusqu'au nœud 2 (plus rien à visiter à partir du nœud 4), on remonte enfin jusqu'au nœud 1 (rien d'autre à visiter à partir du nœud 2), on recommence l'opération sur la partie droite, on visite le nœud 7, puis le nœud 8, le nœud 9, on remonte au nœud 8, et on visite le nœud 10, on remonte en passant par le nœud 8, puis le 7 puis le 1 pour s'apercevoir qu'on a plus rien à visiter. Le parcours en profondeur s'arrête donc ici.

On peut résumer l'ordre de parcours grâce à ce schéma :

![Schéma représentant l'ordre de parcours d'un DFS](https://raw.githubusercontent.com/iTech-/iTechome/master/1%20-%20Algorithme/1%20-%20Structure%20de%20donnees/6%20-%20Graphe/1%20-%20Parcours%20en%20profondeur/Image/arbre_dfs_fleche.png)

Maintenant qu'on a vu l'exemple sur un arbre, on peut l'appliquer sur un graphe quelconque :

![Exemple d'un DFS sur un graphe quelconque]()

Pour déterminer l'ordre de parcours, il va falloir choisir un nœud de départ (sur un arbre le nœud de départ est très souvent la racine). Une fois ce nœud choisi, on applique le principe du parcours en profondeur comme pour l'exemple avec l'arbre.

// TODO : finir exemple graphe quelconque

## Pseudo-code

Le pseudo-code du parcours en profondeur est très simple au final, puisqu'on peut facilement utiliser la récursivité, mais nous allons voir qu'il est aussi possible d'en faire une version itérative.

// TODO : améliorer et détailler les explications

### Version récursive

La version récursive est la plus simple et rapide à coder :

```
DFS(Nœud) :
   Si on a déjà parcouru le nœud
      Arrêter ici
   Marquer le nœud comme visité

   Pour chaque voisin du nœud
      DFS(voisin)
```

On fait en sorte de vérifier qu'on n'a pas déjà visité le nœud pour ne pas tomber dans une récursion infinie en utilisant tout simplement un tableau de booléen. Ensuite pour chacun des voisins du nœud, on va faire un appel récursif pour créer cette idée de parcours en profondeur. Par exemple si l'on reprend le parcours en profondeur effectué sur l'arbre dans la dernière partie, on commence à la racine (le nœud 1), on entre dans la boucle, on effectue l'appel récursif en donnant comme argument le nœud 2, on rentre dans la boucle, on effectue l'appel récursif en donnant comme argument le nœud 3, on rentre dans la boucle, aucun voisin donc l'appel se termine, on revient là où on s'était arrêté pour le nœud 2, on effectue donc l'appel récursif sur son prochain voisin (le nœud 4) etc.

Cette notion d'appels récursifs imbriqués peut être difficile à comprendre si l'on est pas familier avec la récursivité.

// TODO : détailler dernière phrase

### Version itérative

Une fois qu'on a compris la version récursive, on peut assez facilement passer à une version itérative en simulant la pile d'appel récursif, avec une pile et en utilisant donc uniquement une boucle. Je trouve cette version plus longue et plus compliqué à comprendre au premier coup d'œil, mais elle peut s'avérer utile quand le nombre d'appels récursifs est trop important.

```
DFS(Départ) :
   Empiler le nœud de départ dans la pile

   Tant que la pile n'est pas vide ( = tant qu'on a pas visité tout le graphe)
      Dépiler le nœud actuel

      Si on l'a déjà visité
         Passer au prochain nœud
      Marquer le nœud comme visité

      Pour chaque voisin du nœud
         Empiler le voisin
```

Si vous n'êtes pas convaincu d'avoir compris le pseudo-code (la version récursive ou itérative), je vous invite fortement a essayé de simuler le pseudo-code sur les exemples vus plus haut (n'hésitez pas à inventer d'autres graphes et d'appliquer l'algorithme du DFS dessus pour être sûr d'avoir compris son fonctionnement).

*Pour la version récursive, je vous conseille de noter les appels récursifs au fur et à mesure du DFS, et pour la version itérative, vous pouvez faire pareil en notant l'état de la pile dans un coin à chaque tour de boucle.*

## Complexité

Le calcul de la complexité d'un parcours en profondeur est plutôt simple. Le but du parcours est de visiter tous les nœuds du graphe en visitant donc dans le pire des cas tous les arcs. On obtient donc une complexité en temps de *O(M)* avec *M* le nombre d'arcs du graphe.

## Implémentation

Pour l'implémentation, j'utilise une liste d'adjacence afin de stocker les voisins de chaque nœud du graphe, c'est sans aucun doute la solution la plus adaptée dans notre cas.

### Version récursive 

recursif.cpp : [http://git.io/vt2cZ](http://git.io/vt2cZ)

Comme précisé dans le code j'ai utilisé le même arbre que vu dans les exemples pour la démonstration. Quand on lance le programme on remarque qu'il affiche bien : `1 2 3 4 5 6 7 8 9 10` comme prévu. Le code est simple à comprendre et ne change en rien du pseudo-code.

### Version itérative

iteratif.cpp : [http://git.io/vt2cm](http://git.io/vt2cm)

De même que pour la version récursive, le code ne change pas beaucoup du pseudo-code. Il faut noter que lorsqu'on exécute le code on obtient : `1 7 8 10 9 2 4 6 5 3`, non le résultat n'est pas faux, non le code n'est pas faux, c'est uniquement du au fait que lorsqu'on empile par exemple deux nœuds voisins, le deuxième va forcément finir au dessus du premier, alors que si on avait fait un appel récursif sur les nœuds voisins, le premier serait passé avant le deuxième. Ici notre parcours est bien un parcours en profondeur, mais dans "l'autre sens", vous pouvez vérifier, l'algorithme va juste à droite au lieu d'aller à gauche en premier, mais l'idée du parcours est la même (on peut reprendre le schéma illustrant le parcours en profondeur sur un arbre, et dessiner la flèche dans l'autre sens, c'est ce que fait la version itérative ici).

## Conclusion

Le parcours en profondeur n'est pas forcément le parcours le plus simple à comprendre, mais une fois compris il peut s'avérer très utile et reste simple à coder.

// TODO : meilleure conclusion 
