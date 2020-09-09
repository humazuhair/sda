# Compilation et exécution en C:

cd C/

make

./arraylist_analysis

make clean

cd ..

# Compilation et exécution en C++:

cd CPP/

make

./arraylist_analysis

make clean

cd ..

# Compilation et exécution en Java:

cd Java

javac *

java Main

cd ..

# Exécution en Python

cd Python

python main.py

cd ..

# Observation des résultats
### Dans le répertoire plots, lisez le contenu du fichier plot_result

cd plots
more plot_result

### puis lancez ce script avec gnuplot

gnuplot plot_result

### Regardez à présent les courbes obtenus dans le répertoire eps/

gv eps/dynamic_array_amortized_time_alpha_2.eps

