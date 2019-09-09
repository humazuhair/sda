# Cette classe est un simple proxy vers le type "list" de python
# Le langage ne permettant pas de manipuler l'espace mémoire d'une "list",
# on se contente ici d'observer son comportement.
class ArrayListProxy:
    # Constructeur de la classe ArraylistProxy
    def __init__(self):
        self.data = []

    # Ajoute l'élément x au tableau
    #   Complexité en temps/espace, pire cas : O(data.size)
    #   Complexité en temps/espace, meilleur cas : O(1)
    #   Complexité amortie : O(1)
    def append(self, x):
        self.data.append(x)

    # Supprime le dernier élément du tableau
    def pop_back(self):
        self.data.pop()

    # Renvoie l'élément situé à la position 'pos' dans le tableau
    def get(self, pos):
        return self.data[pos]

    # Renvoie le nombre d'éléments dans le tableau
    def get_size(self):
        return len(data)

        
