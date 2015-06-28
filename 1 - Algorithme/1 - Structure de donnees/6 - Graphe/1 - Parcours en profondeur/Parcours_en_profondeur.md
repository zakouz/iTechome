## Introduction

Le parcours en profondeur (ou  plus communément *DFS* pour *Depth First Search*) permet de parcourir un graphe en utilisant le principe de la [récursivité](https://fr.wikipedia.org/wiki/Algorithme_r%C3%A9cursif). De plus, ce parcours de graphe est simple et rapide à implémenter.

## Principe du parcours en profondeur

Un parcours en profondeur a la particularité de parcourir les nœuds du graphe les plus "profonds" en premier (c'est-à-dire les plus éloignés du nœud d'où commence le parcours) avant de "remonter" progressivement dans le graphe.

On va donc chercher dans le graphe a aller le plus loin possible, puis une fois qu'on a atteint le bout, on remonte pour faire de même sur d'autre partie du graphe non explorée.

// TODO : explication à améliorer

## Exemple

Pour bien comprendre un DFS je pense qu'il est nécessaire de commencer par le visualiser sur un [arbre](https://itechome.wordpress.com/algorithme/structure-de-donnees/arbre/) (je rappelle au passage qu'un arbre n'est qu'un graphe particulier).

Voici donc un arbre, et on peut apercevoir l'effet d'un parcours en profondeur dessus :

![Exemple d'un arbre parcouru en utilisant un DFS]()

Chaque nœud possède un numéro, correspondant à l'ordre de parcours de l'arbre. On commence donc à la racine, puis on visite le fils gauche (le nœud 2), on continue à descendre dans l'arbre jusqu'au nœud 3 et on arrive à une feuille de l'arbre, ce qui signifie que l'on va remonter (puisqu'on a fini de parcourir cette partie de l'arbre), on revient donc au nœud 2 et on visite son fils droit non visité (le nœud 4), de même on visite le nœud 5, c'est une feuille on remonte donc et on visite le nœud 6, on remonte de nouveau au nœud 4, et on remonte encore une fois jusqu'au nœud 2 (plus rien à visiter à partir du nœud 4), on remonte enfin jusqu'au nœud 1 (rien d'autre à visiter à partir du nœud 2), on recommence l'opération sur la partie droite, on visite le nœud 7, puis le nœud 8, le nœud 9, on remonte au nœud 8, et on visite le nœud 10, on remonte en passant par le nœud 8, puis le 7 puis le 1 pour s'apercevoir qu'on a plus rien à visiter. Le parcours en profondeur s'arrête donc ici.

On peut résumer l'ordre de parcours grâce à ce schéma :

![Schéma représentant l'ordre de parcours d'un DFS]()

Maintenant qu'on a vu l'exemple sur un arbre, on peut l'appliquer sur un graphe quelconque :

![Exemple d'un DFS sur un graphe quelconque]()

Pour déterminer l'ordre de parcours, il va falloir choisir un nœud de départ (sur un arbre le nœud de départ est très souvent la racine). Une fois ce nœud choisi, on applique le principe du parcours en profondeur comme pour l'exemple avec l'arbre.

// TODO : finir les exemples

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

// TODO : difficile de comprendre si on ne connait pas la récursivité

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

recursif.c : 

### Version itérative

iteratif.c :

## Conclusion

Le parcours en profondeur n'est pas forcément le parcours le plus simple à comprendre, mais une fois compris il peut s'avérer très utile et reste simple à coder.
