#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    Product product;
    printf("Enter product name: ");
    scanf("%s", product.name);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter product price: ");
    scanf("%f", &product.price);
    products[num_products++] = product;
}

void display_products() {
    printf("%-20s%-10s%-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < num_products; i++) {
        printf("%-20s%-10d%-10.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void sell_product() {
    char name[50];
    printf("Enter product name to sell: ");
    scanf("%s", name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            int quantity;
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            if (quantity <= products[i].quantity) {
                products[i].quantity -= quantity;
                printf("Sold %d units of %s\n", quantity, name);
                return;
            } else {
                printf("Not enough stock to sell\n");
                return;
            }
        }
    }
    printf("Product not found\n");
}

void generate_report() {
    float total_sales = 0;
    int total_quantity = 0;
    printf("%-20s%-10s%-10s%-10s\n", "Name", "Quantity", "Price", "Sales");
    for (int i = 0; i < num_products; i++) {
        float sales = products[i].quantity * products[i].price;
        printf("%-20s%-10d%-10.2f%-10.2f\n", products[i].name, products[i].quantity, products[i].price, sales);
        total_sales += sales;
        total_quantity += products[i].quantity;
    }
    printf("Total quantity: %d\n", total_quantity);
    printf("Total sales: %.2f\n", total_sales);
}

int main() {
    while (1) {
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Sell product\n");
        printf("4. Generate report\n");
        printf("5. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                sell_product();
                break;
            case 4:
                generate_report();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
