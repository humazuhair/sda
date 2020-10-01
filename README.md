# Sujet de TP 2: Benchmarks optimisation

## Règles pour ce semestre

Vous travaillerez en binôme durant les TPs. Il ne sera pas possible de changer
de binôme en cours de semestre. 

Il est interdit de partager du code avec d'autres binômes ou de "s'en inspirer".

Toute ressemblance suspecte sera AUTOMATIQUEMENT considérée comme de la fraude
et sévèrement sanctionnée.

Chaque semaine, un rendu vous sera demandé (vous aurez jusqu'au dimanche soir pour 
rendre le TP si vous ne finissez pas à temps) via gitlab.

Vos travaux seront évalués une fois à mi-semestre et une fois à la fin du semestre.

## Exercice 1: Optimisation de la structure, en faisant uniquement des ajouts.

Le nom de votre branche est constitué de vos numéros d'étudiants séparés par un _

`git checkout tp2`

`git checkout -b tp2_NUMERO1_NUMERO2`

Rajouter le fichier `AUTHORS.md` avec vos noms, prénoms et numéros d'étudiants.

Dans le langage de votre choix, effectuez un benchmark permettant
d'identifier la valeur de `alpha` qui permet d'otenir le plus petit temps amorti 
pour l'ajout d'une valeur dans le tableau dynamique.

Vous produirez des fichiers pdf sur lequel toutes les courbes de toutes vos experiences
apparaîtront. Le nom des fichiers terminera par `alpha_bench.pdf`.


## Exercice 2: ajout et suppression

Créer second programme (avec une nouvelle fonction `main` donc), dans lequel vous reproduirez
l'expérience précédente, avec une modification: au lieu d'ajouter un élément dans la table à chaque itération,
vous ajouterez l'élément `i` avec une probabilité `p` et vous supprimerez le dernier élément du tableau
avec une probabilité `1-p`.

Dans vos expériences, vous fixerez `alpha` à `1.5` et ferez varier `p`.
Le nom des fichiers pdf terminera par `alpha_1.5_p_bench.pdf`.


## Exercice 3: Au rapport

Commentez le resultat de vos expériences dans un fichier `RAPPORT.md`

1) Dans l'exercice 1, quel est l'alpha le plus efficace en temps? Est-il également le plus efficace 
en terme de mémoire gaspillée? Quel est le lien entre temps gagné et mémoire gaspillée?

2) Dans l'exercice 2, commentez les différents benchmarks quand `p=0.5`, `p < 0.5` et `p > 0.5`
Tentez d'expliquer ces différents résultats.


A RENDRE AVANT DIMANCHE!
