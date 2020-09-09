# Sujet de TP 1

Vous travaillerez cette année en binôme. Il ne sera pas possible de changer
de binôme en cours de semestre. 

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
