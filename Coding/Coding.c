#include <stdio.h>
#include <stdlib.h>

// Structure to represent a book
typedef struct Book {
    char title[100];
    char author[100];
    int year;
    struct Book* next;
    struct Book* prev;
} Book;

// 1. Create a book by asking the user for information
Book* create_book() {
    Book* new_book = (Book*)malloc(sizeof(Book));
    printf("Enter book title: ");
    scanf("%99s", new_book->title); 
    printf("Enter author: ");
    scanf("%99s", new_book->author); 
    printf("Enter year: ");
    scanf("%d", &new_book->year);
    new_book->next = NULL;
    new_book->prev = NULL;
    return new_book;
}

// 2. Create a book with provided data
Book* create_book_data(const char title[], const char author[], int year) {
    Book* new_book = (Book*)malloc(sizeof(Book));
    int i = 0;
    while (title[i] != '\0') {
        new_book->title[i] = title[i];
        i++;
    }
    new_book->title[i] = '\0'; 
    i = 0;
    while (author[i] != '\0') {
        new_book->author[i] = author[i];
        i++;
    }
    new_book->author[i] = '\0'; 

    new_book->year = year;
    new_book->next = NULL;
    new_book->prev = NULL;
    return new_book;
}

// 3. Return the length of the list
int list_length(Book* head) {
    int length = 0;
    Book* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

// 4. Insert a book at a given position
Book* insert_at_position(Book* head, Book* new_book, int position) {
    if (position == 1) {
        new_book->next = head;
        if (head != NULL) head->prev = new_book;
        return new_book;
    }

    Book* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        new_book->next = temp->next;
        if (temp->next != NULL) temp->next->prev = new_book;
        temp->next = new_book;
        new_book->prev = temp;
    }
    return head;
}

// 5. Delete a book at a given position
Book* delete_at_position(Book* head, int position) {
    if (head == NULL) return NULL;

    if (position == 1) {
        Book* new_head = head->next;
        if (new_head != NULL) new_head->prev = NULL;
        free(head);
        return new_head;
    }

    Book* temp = head;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        if (temp->prev != NULL) temp->prev->next = temp->next;
        if (temp->next != NULL) temp->next->prev = temp->prev;
        free(temp);
    }
    return head;
}

// 6. Delete all books published in a given year
Book* delete_all_books_by_year(Book* head, int year) {
    Book* current = head;
    while (current != NULL) {
        Book* next = current->next;
        if (current->year == year) {
            if (current->prev != NULL) current->prev->next = current->next;
            if (current->next != NULL) current->next->prev = current->prev;
            if (current == head) head = current->next;
            free(current);
        }
        current = next;
    }
    return head;
}

// 7. Display the list in forward order
void display_list_forward(Book* head) {
    Book* temp = head;
    while (temp != NULL) {
        printf("Title: %s, Author: %s, Year: %d\n", temp->title, temp->author, temp->year);
        temp = temp->next;
    }
}

// 8. Display the list in reverse order
void display_list_backward(Book* head) {
    if (head == NULL) return;
    Book* temp = head;
    while (temp->next != NULL) temp = temp->next; 
    while (temp != NULL) {
        printf("Title: %s, Author: %s, Year: %d\n", temp->title, temp->author, temp->year);
        temp = temp->prev;
    }
}

// 9. Search for a book by title
Book* search_book_by_title(Book* head, const char title[]) {
    Book* temp = head;
    while (temp != NULL) {
        int i = 0;
        while (temp->title[i] != '\0' && title[i] != '\0' && temp->title[i] == title[i]) {
            i++;
        }
        if (temp->title[i] == '\0' && title[i] == '\0') return temp; // Strings are equal
        temp = temp->next;
    }
    return NULL;
}

// 10. Check if the list is a palindrome
int is_palindrome_list(Book* head) {
    if (head == NULL) return 1;
    Book* start = head;
    Book* end = head;
    while (end->next != NULL) end = end->next; 

    while (start != end && start->prev != end) {
        int i = 0;
        while (start->title[i] != '\0' && end->title[i] != '\0' && start->title[i] == end->title[i]) {
            i++;
        }
        if (start->title[i] != '\0' || end->title[i] != '\0') return 0; // Not equal
        start = start->next;
        end = end->prev;
    }
    return 1;
}

// 11. Reverse the list
Book* reverse_list(Book* head) {
    Book* temp = NULL;
    Book* current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) head = temp->prev;
    return head;
}

// 12. Merge two lists
Book* merge_lists(Book* list1, Book* list2) {
    if (list1 == NULL) return list2;
    Book* temp = list1;
    while (temp->next != NULL) temp = temp->next;
    temp->next = list2;
    if (list2 != NULL) list2->prev = temp;
    return list1;
}

// 13. Insert into a sorted list (ascending year)
Book* insert_sorted(Book* head, Book* new_book) {
    if (head == NULL || new_book->year < head->year) {
        new_book->next = head;
        if (head != NULL) head->prev = new_book;
        return new_book;
    }

    Book* temp = head;
    while (temp->next != NULL && temp->next->year < new_book->year) {
        temp = temp->next;
    }

    new_book->next = temp->next;
    if (temp->next != NULL) temp->next->prev = new_book;
    temp->next = new_book;
    new_book->prev = temp;
    return head;
}

// 14. Remove duplicates (same title and author)
void remove_duplicates(Book* head) {
    Book* current = head;
    while (current != NULL) {
        Book* runner = current->next;
        while (runner != NULL) {
            Book* next = runner->next;
            int title_match = 1;
            int author_match = 1;
            int i = 0;
            while (current->title[i] != '\0' && runner->title[i] != '\0' && current->title[i] == runner->title[i]) {
                i++;
            }
            if (current->title[i] != '\0' || runner->title[i] != '\0') title_match = 0;

            i = 0;
            while (current->author[i] != '\0' && runner->author[i] != '\0' && current->author[i] == runner->author[i]) {
                i++;
            }
            if (current->author[i] != '\0' || runner->author[i] != '\0') author_match = 0;

            if (title_match && author_match) {
                if (runner->prev != NULL) runner->prev->next = runner->next;
                if (runner->next != NULL) runner->next->prev = runner->prev;
                free(runner);
            }
            runner = next;
        }
        current = current->next;
    }
}

// Main function
int main() {
    Book* library = NULL;
    Book* book1 = create_book_data("BookA", "AuthorX", 2000);
    Book* book2 = create_book_data("BookB", "AuthorY", 2010);
    library = insert_sorted(library, book1);
    library = insert_sorted(library, book2);

    printf("Books in forward order:\n");
    display_list_forward(library);

    printf("\nBooks in backward order:\n");
    display_list_backward(library);

    return 0;
}