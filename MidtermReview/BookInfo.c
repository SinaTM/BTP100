#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Define a structure to represent an author
struct Author
{
    char name[50];
    int birthYear;
};

// Define a structure to represent a book
struct Book
{
    char title[100];
    struct Author author;
    int publicationYear;
};

// Function to display information about a book
void displayBookInfo(struct Book book) {
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author.name);
    printf("Author's Birth Year: %d\n", book.author.birthYear);
    printf("Publication Year: %d\n", book.publicationYear);
    printf("\n");
}

void clearBuffer()
{
    while (getchar() != '\n');
}

int main() {
    // Declare an array of structures to store information about books
    struct Book library[3];

    // Input information about three books
    for (int i = 0; i < 3; i++) {
        printf("Enter details for book %d:\n", i + 1);
        printf("Title: ");
        scanf("%s", library[i].title);
        clearBuffer();
        printf("Author's Name: ");
        scanf("%s", library[i].author.name);
        clearBuffer();
        printf("Author's Birth Year: ");
        scanf("%d", &library[i].author.birthYear);
        clearBuffer();
        printf("Publication Year: ");
        scanf("%d", &library[i].publicationYear);
        clearBuffer();
    }

    // Display information about all books
    printf("\nLibrary Catalog:\n");
    for (int i = 0; i < 3; i++) {
        printf("Book %d:\n", i + 1);
        displayBookInfo(library[i]);
    }

    return 0;
}
