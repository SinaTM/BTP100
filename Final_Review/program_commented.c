// Disable the CRT secure warning, often used with older versions of MSVC.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NAME_LEN 25 // Defines the maximum length of the product name.
#define MAX_PARTS 6 // Defines the maximum number of products that can be stored in the inventory.

// Defines the data structure for a product in the inventory.
struct Part
{
    int sku;  // SKU of the product.
    double price;  // Price of the product.
    char name[NAME_LEN + 1];  // Name of the product. +1 for the null-terminating character.
    int in_stock;  // Stock status. 1 if in stock, 0 otherwise.
};

// Function to clear the input buffer.
void clearBuffer(void)
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        // Do nothing, just iterate until buffer is clear.
    }
}

// Function to display the list of products in the inventory.
void showProducts(const struct Part* database, const int arrSZ)
{
    for (int i = 0; i < arrSZ; i++)
    {
        // Print product details and stock status.
        printf("SKU = %d; Part price = %.2lf; Part name = %s; in-stock = : %c\n",
            database[i].sku, database[i].price, database[i].name,
            database[i].in_stock == 0 ? 'N' : 'Y');
    }
    puts("--------------------------------------------------");
}

// Function to search for a product using its SKU.
void searchdatabase(const struct Part* database, const int arrSZ)
{
    int userSKU;
    int foundIndex = -1; // Initialized to -1, indicating product not found.

    printf("Please enter an SKU:\n");
    scanf("%d", &userSKU);
    clearBuffer();

    for (int i = 0; i < arrSZ; i++)
    {
        if (database[i].sku == userSKU)
        {
            foundIndex = i;  // Update foundIndex if the product is located.
            break;  // Exit the loop once the product is found.
        }
    }

    // Display the product details based on the search results.
    if (foundIndex != -1)
    {
        printf("SKU = %d; Part price = %.2lf; Part name = %s; %s\n\n",
            database[foundIndex].sku, database[foundIndex].price,
            database[foundIndex].name, database[foundIndex].in_stock ? "in stock" : "not in stock");
    }
    else
    {
        printf("No product is found!\n");
        puts("--------------------------------------------------");
    }
}

// Function to find and display the cheapest in-stock product.
void findCheapest(const struct Part* database, const int arrSZ)
{
    int cheapestIndex = 0;
    double cheapest = database[cheapestIndex].price;

    for (int i = 1; i < arrSZ; i++)
    {
        if (database[i].price < cheapest && database[i].in_stock)
        {
            cheapestIndex = i;
            cheapest = database[i].price;
        }
    }

    printf("The cheapest in-stock product is %s with price = %.2lf\n\n",
        database[cheapestIndex].name, database[cheapestIndex].price);
}

int main(void) 
{
    struct Part inventory[MAX_PARTS] = { {123, 190.21, "Disk drive", 1}, {234, 120.0, "CPU", 1},
        {456, 540.34, "GPU", 1}, {678, 60.15, "RAM", 0}, {198, 550.12, "PSU", 1}, {573, 21.1, "Mouse", 0} };
    int option;
    int keepGoing = 1;  // Flag to determine if the program should continue running.

    // Display the main menu until the user chooses to exit.
    while (keepGoing)
    {
        printf("Please select from this menu:\n");
        printf("1. Show products\n2. Search the database\n");
        printf("3. Find and show the cheapest in-stock product\n");
        puts("4. Exit the program");
        puts("--------------------------------------------------");

        do
        {
            scanf("%d", &option);
            clearBuffer();
            if (option < 1 || option > 4)
            {
                puts("Please select a valid option");
            }
        } while (option < 1 || option > 4);

        switch (option)
        {
        case 1:
            showProducts(inventory, MAX_PARTS);
            break;
        case 2:
            searchdatabase(inventory, MAX_PARTS);
            break;
        case 3:
            findCheapest(inventory, MAX_PARTS);
            break;
        case 4:
            keepGoing = 0;  // End the program.
            break;
        }
    }

    return 0;
}
