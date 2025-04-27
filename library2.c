// library.h

#ifndef LIBRARY_H
#define LIBRARY_H

// Structure for a book
typedef struct {
    int bookID;
    char title[100];
    char author[100];
    int availableCopies;
} Book;

// Function Prototypes
void addBook(Book books[], int *bookCount);
void displayBooks(Book books[], int bookCount);
void borrowBook(Book books[], int bookCount);
void returnBook(Book books[], int bookCount);

#endif