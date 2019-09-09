import time
import sys

from arraylist import ArrayListProxy
from analyzer import Analyzer

# Tableau dynamique.
a = ArrayListProxy()
# Analyse du temps pris par les opérations.
time_analysis = Analyzer();

for i in range(1000000):
    before = time.time()
    a.append(i)
    after = time.time()
    # Enregistrement du temps pris par l'opération
    time_analysis.append((after - before)*10**9)

# Affichage de quelques statistiques sur l'expérience.
sys.stderr.write("Total cost : " + str(time_analysis.get_total_cost())+"\n")
sys.stderr.write("Average cost : " + str(time_analysis.get_average_cost())+"\n")
sys.stderr.write("Variance :" + str(time_analysis.get_variance())+"\n")
sys.stderr.write("Standard deviation :" + str(time_analysis.get_standard_deviation())+"\n")

// Sauvegarde les données de l'expérience: temps et temps amorti par opération.
time_analysis.save_values("../dynamic_array_time_python.plot")
