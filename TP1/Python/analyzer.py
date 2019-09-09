import math

#  Classe utilisée pour faire des statistiques élémentaires
#  sur une séquence d'opérations.
class Analyzer:
    # Constructeur de la classe analyse
    # Complexité en temps/espace, pire et meilleur cas : O(1)  
    def __init__(self):
        self.cost = [];
        self.cumulative_cost = [];
        self.cumulative_square = 0.;

    # Ajoute un coût, une valeur à l'analyse.
    # Complexité en temps/espace, pire cas : O(size)
    # Complexité en temps/espace, meilleur cas : O(1)
    # Complexité amortie : O(1)
    # @param x est la valeur que l'on souhaite ajouter à l'analyse.
    def append(self, x):
        self.cost.append(x)
        
        self.cumulative_cost.append( self.cumulative_cost[len(self.cumulative_cost)-1]+x if len(self.cumulative_cost)>0 else x)
        self.cumulative_square = self.cumulative_square+x*x

    # Renvoie la somme des coûts enregistrés dans cette analyse.
    # Complexité en temps/espace, meilleur cas : O(1)
    # @returns la somme des coûts enregistrés dans cette analyse.
    def get_total_cost(self):
        return self.cumulative_cost[len(self.cumulative_cost)-1]

    # Renvoie le coût amorti d'une opération.
    # Complexité en temps/espace, meilleur cas : O(1)
    # @param pos est l'indice de l'opération pour laquelle on veut connaître le coût amorti.
    # @returns le coût amorti d'une opération.    
    def get_amortized_cost(self, pos):
        return self.cumulative_cost[pos]/pos if pos>0 else self.cumulative_cost[pos] 

    # Renvoie la moyenne des coûts de toutes les opérations enregistrées dans l'analyse.
    # Complexité en temps/espace, meilleur cas : O(1)
    # @returns la moyenne des coûts de toutes les opérations enregistrées dans l'analyse.
    def get_average_cost(self):
        if len(self.cumulative_cost) == 0:
            raise Exception('List is empty')
        return self.cumulative_cost[len(self.cumulative_cost)-1]/len(self.cumulative_cost);

    # Renvoie la variance des coûts de toutes les opérations enregistrées dans l'analyse.
    # Complexité en temps/espace, meilleur cas : O(1)
    # @returns la variance des coûts de toutes les opérations enregistrées dans l'analyse.
    def get_variance(self):
        mean = self.get_average_cost()
        mean_square = mean*mean
        return self.cumulative_square - mean_square

    # Renvoie l'écart-type des coûts de toutes les opérations enregistrées dans l'analyse.
    # Complexité en temps/espace, meilleur cas : O(1)
    # @returns l'écart-type des coûts de toutes les opérations enregistrées dans l'analyse.
    def get_standard_deviation(self):
        return math.sqrt(self.get_variance())

    # Sauvegarde la liste des coûts et des coûts amortis dans un fichier.
    # Complexité en temps, meilleur/pire cas : O(size)
    # @param path est le chemin du fichier dans lequel la sauvegarde est faite.
    def save_values(self, path):
        f = open(path, 'w')
        for i in range(len(self.cost)):
            f.write(str(i)+" "+str(self.cost[i])+"  "+str(self.get_amortized_cost(i))+"\n")
        f.close()
