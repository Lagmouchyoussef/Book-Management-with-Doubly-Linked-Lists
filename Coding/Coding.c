#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char title[100];
    char author[100];
    int year;
    struct Book* next;
    struct Book* prev;
} Book;

// Function to create a new book with user input
Book* create_book() {
    Book* new_book = (Book*)malloc(sizeof(Book));
    printf("Enter the book title: ");
    fgets(new_book->title, 100, stdin); 
    printf("Enter the author: ");
    fgets(new_book->author, 100, stdin);
    printf("Enter the year: ");
    scanf("%d", &new_book->year);
    getchar(); // Clear the newline character
    new_book->next = NULL;
    new_book->prev = NULL;
    return new_book;
}

// Function to create a new book with specific data
Book* create_book_data(const char title[], const char author[], int year) {
    Book* new_book = (Book*)malloc(sizeof(Book));
    if (new_book == NULL) {
        return NULL;
    }
    strcpy(new_book->title, title);
    strcpy(new_book->author, author);
    new_book->year = year;
    new_book->next = NULL;
    new_book->prev = NULL;
    return new_book;
}

// Function to get the length of the list
int list_length(Book* head) {
    int length = 0;
    Book* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// Function to insert a book at a specific position
Book* insert_at_position(Book* head, Book* new_book, int position) {
    if (position < 0) {
        return head;
    }
    if (position == 0) {
        new_book->next = head;
        if (head != NULL) {
            head->prev = new_book;
        }
        return new_book;
    }
    Book* current = head;
    int i = 0;
    while (i < position - 1 && current != NULL) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        return head;
    }
    new_book->next = current->next;
    if (current->next != NULL) {
        current->next->prev = new_book;
    }
    current->next = new_book;
    new_book->prev = current;
    return head;
}

// Function to delete a book at a specific position
Book* delete_at_position(Book* head, int position) {
    if (position < 0) {
        return head;
    }
    if (position == 0) {
        Book* next = head->next;
        free(head);
        if (next != NULL) {
            next->prev = NULL;
        }
        return next;
    }
    Book* current = head;
    int i = 0;
    while (i < position - 1 && current != NULL) {
        current = current->next;
        i++;
    }
    if (current == NULL || current->next == NULL) {
        return head;
    }
    Book* to_delete = current->next;
    current->next = to_delete->next;
    if (to_delete->next != NULL) {
        to_delete->next->prev = current;
    }
    free(to_delete);
    return head;
}

// Function to delete all books from a specific year
Book* delete_all_books_by_year(Book* head, int year) {
    Book* current = head;
    while (current != NULL) {
        if (current->year == year) {
            Book* to_delete = current;
            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            current = current->next;
            free(to_delete);
        } else {
            current = current->next;
        }
    }
    return head;
}

// Function to display the list in forward order
void display_list_forward(Book* head) {
    Book* current = head;
    while (current != NULL) {
        printf("%s, %s, %d\n", current->title, current->author, current->year);
        current = current->next;
    }
}

// Function to display the list in backward order
void display_list_backward(Book* head) {
    Book* current = head;
    if (current == NULL) return;
    while (current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        printf("%s, %s, %d\n", current->title, current->author, current->year);
        current = current->prev;
    }
}

// Function to search for a book by title
Book* search_book_by_title(Book* head, char title[]) {
    Book* current = head;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to check if the list is a palindrome
int is_palindrome_list(Book* head) {
    if (head == NULL) return 1;
    Book* start = head;
    Book* end = head;
    while (end->next != NULL) {
        end = end->next;
    }
    while (start != end && start->prev != end) {
        if (strcmp(start->title, end->title) != 0) {
            return 0;
        }
        start = start->next;
        end = end->prev;
    }
    return 1;
}

// Function to reverse the list
Book* reverse_list(Book* head) {
    Book* current = head;
    Book* prev = NULL;
    while (current != NULL) {
        Book* next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to merge two lists
Book* merge_lists(Book* list1, Book* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    Book* head = list1;
    Book* current = list1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = list2;
    list2->prev = current;
    return head;
}

// Function to insert a book in a sorted list (by year)
Book* insert_sorted(Book* head, Book* new_book) {
    if (head == NULL || new_book->year < head->year) {
        new_book->next = head;
        if (head != NULL) {
            head->prev = new_book;
        }
        return new_book;
    }
    Book* current = head;
    while (current->next != NULL && new_book->year > current->next->year) {
        current = current->next;
    }
    new_book->next = current->next;
    if (current->next != NULL) {
        current->next->prev = new_book;
    }
    current->next = new_book;
    new_book->prev = current;
    return head;
}

// Function to remove duplicate books
void remove_duplicates(Book* head) {
    Book* current = head;
    while (current != NULL) {
        Book* next = current->next;
        while (next != NULL) {
            if (strcmp(current->title, next->title) == 0 && strcmp(current->author, next->author) == 0) {
                Book* to_delete = next;
                current->next = next->next;
                if (next->next != NULL) {
                    next->next->prev = current;
                }
                free(to_delete);
            } else {
                next = next->next;
            }
        }
        current = current->next;
    }
}

// Main function
int main() {
    Book* head = NULL;
    int choice;

    do {
        printf("Book Management Menu:\n");
        printf("1. Add a book\n");
        printf("2. Display the list (forward)\n");
        printf("3. Display the list (backward)\n");
        printf("4. Delete a book by position\n");
        printf("5. Delete all books from a given year\n");
        printf("6. Search for a book by title\n");
        printf("7. Remove duplicates\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: {
                char title[100], author[100];
                int year;
                printf("Enter the title: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = '\0';
                printf("Enter the author: ");
                fgets(author, 100, stdin);
                author[strcspn(author, "\n")] = '\0';
                printf("Enter the year: ");
                scanf("%d", &year);
                getchar();
                Book* new_book = create_book_data(title, author, year);
                head = insert_sorted(head, new_book);
                break;
            }
            case 2:
                printf("Book list (forward):\n");
                display_list_forward(head);
                break;
            case 3:
                printf("Book list (backward):\n");
                display_list_backward(head);
                break;
            case 4: {
                int position;
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                getchar();
                head = delete_at_position(head, position);
                break;
            }
            case 5: {
                int year;
                printf("Enter the year to delete: ");
                scanf("%d", &year);
                getchar();
                head = delete_all_books_by_year(head, year);
                break;
            }
            case 6: {
                char title[100];
                printf("Enter the title to search: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = '\0';
                Book* result = search_book_by_title(head, title);
                if (result != NULL) {
                    printf("Book found: %s, %s, %d\n", result->title, result->author, result->year);
                } else {
                    printf("Book not found.\n");
                }
                break;
            }
            case 7:
                remove_duplicates(head);
                printf("Duplicates removed.\n");
                break;
            case 8:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    while (head != NULL) {
        head = delete_at_position(head, 0);
    }

    return 0;
}