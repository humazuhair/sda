# Sujet de TP 1: Gitlab, Benchmarks et tableaux dynamiques

## Règles pour ce semestre

Vous travaillerez en binôme durant les TPs. Il ne sera pas possible de changer
de binôme en cours de semestre. 

Il est interdit de partager du code avec d'autres binômes ou de "s'en inspirer".

Toute ressemblance suspecte sera AUTOMATIQUEMENT considérée comme de la fraude
et sévèrement sanctionnée.

Chaque semaine, un rendu vous sera demandé (vous aurez jusqu'au dimanche soir pour 
rendre le TP si vous ne finissez pas à temps) via gitlab.

Vos travaux seront évalués une fois à mi-semestre et une fois à la fin du semestre.

## Exercice 1: git 
### Clonez le projet sda sur votre compte étudiant

Dans votre terminal, placez vous dans le répertoire où vous souhaitez créer le dossier
`git clone git@depot.lipn.univ-paris13.fr:david/sda.git`

`cd sda` 

### Vérifiez que vous êtes dans la branche tp1

`git branch`

Si n'êtes pas dans la branche tp1, tapez

`git checkout tp1`

### Créez votre propre branche

Le nom de votre branche est constitué de vos numéros d'étudiants séparés par un `_`

`git checkout -b NUMERO1_NUMERO2`

### Ajoutez un fichier `AUTHORS.md` à votre branche

A la racine du projet, créez un fichier `AUTHORS.md` contenant 2 lignes avec vos noms, prénoms et numéros d'étudiants.

Ajoutez ensuite ce fichier au projet

`git add AUTHORS.md`

`git commit -am "Ajout du fichier AUTHORS.md"`

### Poussez votre branche sur gitlab
`git push`

### Vérifiez sur gitlab

Sur la page de gitlab:
- vérifiez que la branche a été poussée dans `Repository -> Branches`
- vérifiez que le pipeline a échoué (car vous n'avez pas encore fini le TP), dans `CI/CD -> Pipelines`
- cliquez sur `failed` pour voir le détail des tests effectués


## Exercice 2: Lancer les benchmarks

Vérifiez que le répertoire `plots` ne contient que le fichier `plot_result`.

Nous allons à présent tester différentes implémentations des tableaux dynamiques dans différents langages.

Lisez les fichiers `main` de chaque langage et vérifiez que la même expérience est bien effectuée à chaque fois.  

Exécutez le script `SHELL` (le lire ne vous fera pas de mal non plus):

`sh launch_analysis.sh`

Une fois les calculs effectués, regardez les fichiers `pdf` obtenus dans le répertoire `plots`

Ajoutez tous les fichiers pdf obtenus à votre branche en utilisant les commandes 

`git add plots/*.pdf`

`git commit -am "Première expérience"`

`git push`

## Exercice 3: A vous de jouer!

Dans le langage de votre choix (C, C++, JAVA, pas possible en Python), modifiez la fonction `enlarge_capacity` 
afin de multiplier la capacité du tableaux par une autre constante `alpha` que 2 (Demandez à votre chargé de TP
de choisir une constante alpha pour votre binôme).


Dans la fonction `main`, changez le nom de fichiers de sortie en ramplaçant `alpha_2` par `alpha_votre_valeur`

Dans le répertoire `plots`, faites une copie du fichier `plot_result`

`cp plot_result my_plot_result`

Modifiez le fichier `my_plot_result` pour ne fournir que des courbes dans le langage que vous avez choisi.
Modifiez également le nom des fichiers pdf en sortie afin qu'ils contiennent la bonne valeur de alpha.

Modifiez le fichier `launch_analysis.sh` afin qu'il exécute gnuplot à partir de `my_plot_result`

Relancez le script `launch_analysis.sh`

Ajoutez les résultats (fichiers pdf) à votre branche.

## Exercice 4: Au rapport!

Créez un fichier RAPPORT.md à la racine projet.

1) Tentez d'expliquer pourquoi certains langages sont plus rapides que d'autres dans cette expérience.

2) Observez l'espace mémoire inutilisé au fur et à mesure du programme. Qu'en pensez vous? 
Imaginez un scénario dans lequel cela pourrait poser problème.

3) Décrivez les différences obtenues en faisant varier alpha dans les deux expériences.

