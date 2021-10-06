RED='\033[0;31m'
NC='\033[0m' # No Color


# Compilation et exécution en Java:

echo "${RED} Compilation du code source en Java ${NC}"
cd Java

javac *

echo "${RED} Exécution des benchmarks en Java ${NC}"
java Main

echo "${RED} Nettoyage ${NC}"
rm *.class

cd ..



# Observation des résultats
### Dans le répertoire plots, lisez le contenu du fichier plot_result

cd plots
more my_plot_result

### puis lancez ce script avec gnuplot

gnuplot my_plot_result


