// main.c

#include <stdio.h>
#include "library.h"

#define MAX_BOOKS 10

int main() {
    Book books[MAX_BOOKS] = {
        {1, "Book One", "Author A", 5},
        {2, "Book Two", "Author B", 3},
        {3, "Book Three", "Author C", 2},
        {4, "Book Four", "Author D", 4},
        {5, "Book Five", "Author E", 6},
        {6, "Book Six", "Author F", 8},
        {7, "Book Seven", "Author G", 1},
        {8, "Book Eight", "Author H", 7},
        {9, "Book Nine", "Author I", 0},
        {10, "Book Ten", "Author J", 10}
    };

    int bookCount = 10;
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &bookCount);
                break;
            case 2:
                displayBooks(books, bookCount);
                break;
            case 3:
                borrowBook(books, bookCount);
                break;
            case 4:
                returnBook(books, bookCount);
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}