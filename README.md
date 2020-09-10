# Sujet de TP 4: Tas Binaire, suite

## Règles pour ce semestre

Vous travaillerez en binôme durant les TPs. Il ne sera pas possible de changer
de binôme en cours de semestre. 

Il est interdit de partager du code avec d'autres binômes ou de "s'en inspirer".

Toute ressemblance suspecte sera AUTOMATIQUEMENT considérée comme de la fraude
et sévèrement sanctionnée.

Chaque semaine, un rendu vous sera demandé (vous aurez jusqu'au dimanche soir pour 
rendre le TP si vous ne finissez pas à temps) via gitlab.

Vos travaux seront évalués une fois à mi-semestre et une fois à la fin du semestre.

## Exercice 1: Tas binaire avec extraction


Le nom de votre branche est constitué de vos numéros d'étudiants séparés par un _

### Pour conserver les données du tp3 et récupérer le tp4
Placez vous dans votre branche du tp3.
`git checkout tp3_NUMERO1_NUMERO2`
Créez la branche du tp4 à partir de celle du tp3.
`git checkout -b tp4_NUMERO1_NUMERO2`
Fusionnez cette nouvelle branche avec le tp4
`git merge -Xtheirs tp4`

Modifier la strcture de tas pour pouvoir extraire la clé de plus petite valeur.
On voudra connaître le nombre d'échanges effectués par cette opération.

## Exercice 2: Benchmark

Effectuez des expériences sur l’efficacité en temps et en mémoire de cette structure :

- dans le cas où l'on ajoute une valeur aléatoire avec un probabilité `p` et on extrait
la clé de valeur minimale avec probabilité `1-p`.

Les noms des fichiers pdf seront de la forme `fixed_binary_heap_extract_MESURE_LANGAGE.pdf`

## Exercice 3: Tas binaire dynamique

Modifier la structure de tas binaire en remplacant le tableau de taille fixe par un tableau dynamique.

Relancer toutes les expériences faites sur les tas binaires de taille fixe sur les tas binaires dynamiques.

Vous devez impérativement créer un programme distinct pour chaque expérience.

Le nom des fichiers `pdf` commencera par `dynamic_binary_heap_*`

## Exercice 4:  

Commentez le resultat de vos expériences dans un fichier `RAPPORT.md`

- Que se passe t-il lorsque l'on ajoute des opérations de suppression? En temps? En mémoire?

- La complexité amortie des opérations d’ajout et de suppression/extraction a t-elle changé sur les expériences
utilisant un tableau dynamique ? Pourquoi ?

A RENDRE AVANT DIMANCHE!