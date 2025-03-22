#  BOOK MANAGEMENT WITH DOUBLY LINKED LISTS

##  PROBLEM

###  Basic Concepts
In this practical work, we will manipulate a doubly linked list where each node represents a book in a library. Each node is modeled by the `Book` structure, which stores essential book information and allows navigation both forward and backward through the list.

###  List Structure in C

```c
typedef struct Book {
    char title[100];
    char author[100];
    int year;
    struct Book* next;
    struct Book* prev;
} Book;
```

##  Tasks to Complete

1. **`Book* create_book()`**  
   → Creates a new `Book` node by entering information (title, author, year) from the keyboard.

2. **`Book* create_book_data(char title[], char author[], int year)`**  
   → Creates a `Book` node with data passed as parameters (no keyboard input).

3. **`int list_length(Book* head)`**  
   → Returns the total number of books in the list.

4. **`Book* insert_at_position(Book* head, Book* new_book, int position)`**  
   → Inserts a new book at a given position in the list (beginning, middle, or end).

5. **`Book* delete_at_position(Book* head, int position)`**  
   → Deletes the book at a given position in the list.

6. **`Book* delete_all_books_by_year(Book* head, int year)`**  
   → Deletes all books published in a given year.

7. **`void display_list_forward(Book* head)`**  
   → Displays the list of books in forward order (from first to last).

8. **`void display_list_backward(Book* head)`**  
   → Displays the list of books in reverse order (from last to first).

9. **`Book* search_book_by_title(Book* head, char title[])`**  
   → Searches for a book by its title and returns a pointer to the corresponding node (or `NULL` if not found).

10. **`int is_palindrome_list(Book* head)`**  
   → Checks if the titles of the books form a palindrome in the order of the list.

11. **`Book* reverse_list(Book* head)`**  
   → Reverses the order of books in the doubly linked list.

12. **`Book* merge_lists(Book* list1, Book* list2)`**  
   → Merges two book lists into a single linked list.

13. **`Book* insert_sorted(Book* head, Book* new_book)`**  
   → Inserts a new book into a list sorted by ascending year.

14. **`void remove_duplicates(Book* head)`**  
   → Removes books with the same title and author (duplicates in the list).

##  Main Function

Write a `main()` function that performs the following:

1. Initializes an empty list.
2. Inserts elements at different positions.
3. Displays the list in both forward and backward order.
4. Deletes an element at a given position.
5. Searches for an element by title.
6. Reverses the list.
7. Checks if the list is a palindrome.
8. Merges two lists.
9. Uses additional functions (optional)

# GESTION DE LIVRES AVEC LISTES DOUBLEMENT CHAÎNÉES

## PROBLÈME

### Concepts de Base
Dans ce travail pratique, nous allons manipuler une liste doublement chaînée où chaque nœud représente un livre dans une bibliothèque. Chaque nœud est modélisé par la structure `Livre`, qui stocke les informations essentielles d'un livre et permet la navigation vers l'avant et l'arrière dans la liste.

### Structure de la Liste en C

```c
typedef struct Livre {
    char titre[100];
    char auteur[100];
    int annee;
    struct Livre* suivant;
    struct Livre* precedent;
} Livre;
```

## Tâches à Réaliser

1. **`Livre* creer_livre()`**  
   → Crée un nouveau nœud `Livre` en saisissant les informations (titre, auteur, année) depuis le clavier.

2. **`Livre* creer_livre_donnees(char titre[], char auteur[], int annee)`**  
   → Crée un nœud `Livre` avec les données passées en paramètres (sans saisie au clavier).

3. **`int longueur_liste(Livre* tete)`**  
   → Retourne le nombre total de livres dans la liste.

4. **`Livre* inserer_a_position(Livre* tete, Livre* nouveau_livre, int position)`**  
   → Insère un nouveau livre à une position donnée dans la liste (début, milieu ou fin).

5. **`Livre* supprimer_a_position(Livre* tete, int position)`**  
   → Supprime le livre à une position donnée dans la liste.

6. **`Livre* supprimer_tous_livres_par_annee(Livre* tete, int annee)`**  
   → Supprime tous les livres publiés à une année donnée.

7. **`void afficher_liste_avant(Livre* tete)`**  
   → Affiche la liste des livres dans l'ordre croissant (du premier au dernier).

8. **`void afficher_liste_arriere(Livre* tete)`**  
   → Affiche la liste des livres dans l'ordre inverse (du dernier au premier).

9. **`Livre* rechercher_livre_par_titre(Livre* tete, char titre[])`**  
   → Recherche un livre par son titre et retourne un pointeur vers le nœud correspondant (ou `NULL` si non trouvé).

10. **`int est_liste_palindrome(Livre* tete)`**  
   → Vérifie si les titres des livres forment un palindrome dans l'ordre de la liste.

11. **`Livre* inverser_liste(Livre* tete)`**  
   → Inverse l'ordre des livres dans la liste doublement chaînée.

12. **`Livre* fusionner_listes(Livre* liste1, Livre* liste2)`**  
   → Fusionne deux listes de livres en une seule liste chaînée.

13. **`Livre* inserer_trie(Livre* tete, Livre* nouveau_livre)`**  
   → Insère un nouveau livre dans une liste triée par année croissante.

14. **`void supprimer_doublons(Livre* tete)`**  
   → Supprime les livres ayant le même titre et auteur (doublons dans la liste).

## Fonction Principale

Écrire une fonction `main()` qui effectue les actions suivantes :

1. Initialise une liste vide.
2. Insère des éléments à différentes positions.
3. Affiche la liste dans l'ordre croissant et inverse.
4. Supprime un élément à une position donnée.
5. Recherche un élément par titre.
6. Inverse la liste.
7. Vérifie si la liste est un palindrome.
8. Fusionne deux listes.
9. Utilise des fonctions supplémentaires (optionnel).


