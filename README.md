# Sujet de TP 3: Tas Binaire

## Règles pour ce semestre

Vous travaillerez en binôme durant les TPs. Il ne sera pas possible de changer
de binôme en cours de semestre. 

Il est interdit de partager du code avec d'autres binômes ou de "s'en inspirer".

Toute ressemblance suspecte sera AUTOMATIQUEMENT considérée comme de la fraude
et sévèrement sanctionnée.

Chaque semaine, un rendu vous sera demandé (vous aurez jusqu'au dimanche soir pour 
rendre le TP si vous ne finissez pas à temps) via gitlab.

Vos travaux seront évalués une fois à mi-semestre et une fois à la fin du semestre.

## Exercice 1: Tas binaire borné

Le nom de votre branche est constitué de vos numéros d'étudiants séparés par un _

`git checkout -b tp3_NUMERO1_NUMERO2`

Rajouter le fichier `AUTHORS.md` avec vos noms, prénoms et numéros d'étudiants.

Développez une structure/classe de tas binaire dans laquelle le tableau servant
à stocker les clés est de taille fixe. Cette taille est fixée à la création du tas. Si
l’utilisateur tente d’ajouter une valeur dans un tas plein, un programme en C
affichera une erreur et un programme en C++, Python ou Java jettera une exception. La
structure de tas ne permettra pour l'instant que d’ajouter des clés.
Pour chaque opération, on veut pouvoir récupérer le nombre d'échanges que la fonction a effectué.


## Exercice 2: Benchmark

Effectuez des expériences sur l’efficacité en temps et en mémoire de cette structure :

- dans le cas où l’on ne fait qu’ajouter des clés dans l’ordre croissant,
- dans le cas où l’on ne fait qu’ajouter des clés dans l’ordre décroissant,
- dans le cas où l’on ne fait qu’ajouter des clés aléatoires.

Inspirez vous des expériences menées sur les tableaux dynamiques. Attention, pour
chaque expérience, vous devez impérativement écrire de nouvelles fonctions `main`
dans de nouveaux fichiers et sauvegarder les différents fichiers `pdf` que vous ob-
tenez grâce à vous expériences. 

Les noms des fichiers pdf seront de la forme `fixed_binary_heap_MESURE_LANGAGE_ORDRE.pdf`

### Exemple:

Pour la mesure du temps amorti de l'ajout d'un élément dans l'ordre croissant en `C`,
le fichier de sortie sera `fixed_binary_heap_amortized_time_C_INCREASING.pdf`

On a donc:
- MESURE peut valoir \{ amortized_time, wasted_memory, swap \}. 
- LANGAGE peut valoir \{ C, CPP, Java, Python\}
- ORDRE peut valoir \{ increasing, descrasing, random\}

## Exercice 3: 

Commentez le resultat de vos expériences dans un fichier `RAPPORT.md`


A RENDRE AVANT DIMANCHE!