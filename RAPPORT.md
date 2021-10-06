INTRO
Nous avons décidé de faire le tp en C++ mais nous avons remarqué que pour les questions du rapport il fallait modifier les fichiers en C. Donc nous avons refait le TP en C.


1-Tentez d'expliquer pourquoi certains langages sont plus rapides que d'autres dans cette expérience.

Tout d'abord on sait que les langages de haut niveau tel que le python sont moins rapide que les langages de bas niveau (c, c++), car ils permettent de simplifier le travail du programmeur alors que ceux de bas niveau permettent de produire un code plus efficace. On peut d'ailleurs affirmer d'après les fichiers pdf généré avec la variable 2 que le langage C est plus rapide que le langage c++ qui est lui meme est plus rapide que le langage java qui est lui meme plus rapide que le langage python. On sait aussi que les concepts de programmation de haut niveau tels que les structures de données génériques, de l'interprétation à l'exécution, sont souvent lents à l'exécution et grands consommateurs mémoire. Ce qui explique donc bien la hiérarchie des langages précédents.


2-Observez l'espace mémoire inutilisé au fur et à mesure du programme. Qu'en pensez vous? Imaginez un scénario dans lequel cela pourrait poser problème.

Avec la constante 2, on obsere que la gestion de mémoire est mieux gérée en. En effet, on remarque que lorsque le tableau est rempli, on double sa taille ce qui permet d'augmenter la taille du tableau moins fréquement qu'avec PYTHON. Pour PYTHON nous n'avons pas bien compris comment la taille du tableau augmentait lorsque ce dernier est plein.

scénario problématique:en C par exemple si on double la taille du tableau, et qu'on insère un seul élément alors on se retrouve avec une grande quantité de mémoire inutilisée.



3-Décrivez les différences obtenues en faisant varier alpha dans les deux expériences.

Lorsque l'on fait varier le alpha, on observe une différence sur 2 fichiers uniquements :
-dynamic_array_copy_alpha.pdf
-dynamic_array_wasted_memory_alpha.pdf

Pour -dynamic_array_copy_alpha.pdf le nombre de copies de valeurs effectuée en C est moins fréquent lorsque alpha vaut 4.5 contrairement à 2.

Pour dynamic_array_wasted_memory_alpha.pdf on observe que la quantité de mémoire inutilisée augmente énormément il faut beaucoup de temps pour remplir le tableau. La réallocation se fait donc moins fréquement. (pour alpha égal à 4.5).

Pour PYTHON nous ne faisons pas varier le alpha donc aucun changement. 

