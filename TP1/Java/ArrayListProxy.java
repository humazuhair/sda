import java.util.ArrayList;

/**
 Cette classe est un proxy pour les ArrayList, c'est à dire les tableaux dynamiques en Java.
 On utilise cette classe afin d'avoir le contrôle sur la gestion de la mémoire.
 */
public class ArrayListProxy<T> {

    /**
        Constructeur de la classe des tableaux dynamiques.
        Complexité en temps/espace, pire et meilleur cas : O(1)
     */
    public ArrayListProxy() {
        this.capacity = 4;
        this.data = new ArrayList<T>(this.capacity);
    }

    /**
     Ajoute une valeur dans le tableau.
     Complexité en temps/espace, pire cas : O(size)
     Complexité en temps/espace, meilleur cas : O(1)
     Complexité amortie : O(1)
     @param x est la valeur que l'on souhaite ajouter.
     @returns true si le tableau a été agrandit, false sinon
     */
    boolean append(T x){
        boolean memory_allocation = false;
        if( enlarging_capacity() ){
            memory_allocation = true;
            capacity *= 2;
            data.ensureCapacity( capacity );
        }
        data.add(x);
        return memory_allocation;
    }

    /**
     Supprime la dernière valeur du tableau.
     Complexité en temps, pire cas : O(size)
     Complexité en temps, meilleur cas : O(1)
     Complexité amortie : O(1)
     @returns true si le tableau a été réduit, false sinon
     */
    boolean pop_back(){
        boolean memory_reduction = false;
        if(!data.isEmpty()){
            if( reducing_capacity() ){
                memory_reduction = true;
                capacity /= 2;
                data.ensureCapacity( capacity );
            }
            data.remove(data.size()-1);
        }
        return memory_reduction;
    }

    /**
     Renvoie la valeur située à la position donnée par l'utilisateur.
     Complexité en temps/espace, pire cas : O(1)
     @param pos est la l'indice de la case on l'utilisateur veut connaître la valeur.
     @returns la valeur située à la position donnée par l'utilisateur.
     */
    T get(int pos){
        return data.get(pos);
    }

    /**
     Renvoie le nombre d'éléments stockés dans le tableau.
     Complexité en temps/espace, pire cas : O(1)
     @returns le nombre d'éléments stockés dans le tableau.
     */
    int get_size(){
        return data.size();
    }

    /**
     Cette fonction détermine la règle selon laquelle un espace mémoire plus grand sera alloué ou non.
     @returns true si le tableau doit être agrandi, false sinon.
     */
    private boolean enlarging_capacity() {
        return data.size() >= (capacity * 3)/4;
    }

    /**
     Cette fonction détermine la règle selon laquelle un espace mémoire plus petit sera alloué ou non.
     @returns true si le tableau doit être réduit, false sinon.
     */
    private boolean reducing_capacity(){
        return data.size() <= capacity/4 && data.size() >4;
    }

    // Tableau dynamique en Java. Sa capacité réelle est masquée, mais on peut avoir un contrôle dessus.
    private ArrayList<T> data;
    // Capacité réelle du tableau data.
    private int capacity;
}