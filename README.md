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
