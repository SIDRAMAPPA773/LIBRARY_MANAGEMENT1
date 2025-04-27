// library.c

#include <stdio.h>
#include "library.h"

// Function to add a book to the library
void addBook(Book books[], int *bookCount) {
    if (*bookCount >= 10) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &books[*bookCount].bookID);
    getchar(); // to consume newline character
    printf("Enter Book Title: ");
    fgets(books[*bookCount].title, 100, stdin);
    books[*bookCount].title[strcspn(books[*bookCount].title, "\n")] = '\0';  // Remove trailing newline
    printf("Enter Author Name: ");
    fgets(books[*bookCount].author, 100, stdin);
    books[*bookCount].author[strcspn(books[*bookCount].author, "\n")] = '\0';  // Remove trailing newline
    printf("Enter Number of Available Copies: ");
    scanf("%d", &books[*bookCount].availableCopies);
    (*bookCount)++;
    printf("Book added successfully!\n");
}

// Function to display all books in the library
void displayBooks(Book books[], int bookCount) {
    printf("\nBooks Available in the Library:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("Book ID: %d\n", books[i].bookID);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Available Copies: %d\n\n", books[i].availableCopies);
    }
}

// Function to borrow a book
void borrowBook(Book books[], int bookCount) {
    int bookID;
    printf("\nEnter Book ID to Borrow: ");
    scanf("%d", &bookID);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].bookID == bookID) {
            if (books[i].availableCopies > 0) {
                books[i].availableCopies--;
                printf("You have successfully borrowed the book: %s\n", books[i].title);
                return;
            } else {
                printf("Sorry, no copies available for borrowing.\n");
                return;
            }
        }
    }
    printf("Book not found.\n");
}

// Function to return a book
void returnBook(Book books[], int bookCount) {
    int bookID;
    printf("\nEnter Book ID to Return: ");
    scanf("%d", &bookID);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].bookID == bookID) {
            books[i].availableCopies++;
            printf("You have successfully returned the book: %s\n", books[i].title);
            return;
        }
    }
    printf("Book not found.\n");
}