#include <stdio.h>
#include <stdlib.h>

// Define ingredients and prices for each coffee type
#define ESPRESSO_BEANS 8
#define ESPRESSO_WATER 30
#define CAPPUCCINO_BEANS 8
#define CAPPUCCINO_WATER 30
#define CAPPUCCINO_MILK 70
#define MOCHA_BEANS 8
#define MOCHA_WATER 39
#define MOCHA_MILK 160
#define MOCHA_CHOCOLATE 30

float espresso_price = 3.5;
float cappuccino_price = 4.5;
float mocha_price = 5.5;
float Hot_water_price = 1;

// Initial stock levels
int coffee_beans = 100;
int water = 500;
int milk = 300;
int chocolate_syrup = 100;
int sales = 0;

// Admin settings
#define admin_password 1234

// Function prototypes
void order_coffee();
void admin_mode();
void handle_admin_tasks();
void process_payment(float price);
void check_stock_levels();
void replenish_stock();
void change_coffee_price();
void reset_sales();

int main() {
    int choice;
    while (1) {
        printf("\nWelcome to the Coffee Machine!\n");
        printf("1: Order Coffee\n");
        printf("2: Admin Mode\n");
        printf("3: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                order_coffee();
                break;
            case 2:
                admin_mode();
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

void order_coffee() {
    int coffee_choice;
    while (1) {
        printf("\nSelect a coffee:\n");
        printf("1: Espresso (3.5 AED)\n");
        printf("2: Cappuccino (4.5 AED)\n");
        printf("3: Mocha (5.5 AED)\n");
        printf("4. Hot water (1 AED\n");
        printf("0: Go back to the main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &coffee_choice);

        switch (coffee_choice) {
            case 1:
                if (coffee_beans >= ESPRESSO_BEANS && water >= ESPRESSO_WATER) {
                    process_payment(espresso_price);
                    printf("Making your Espresso...\n");
                    coffee_beans -= ESPRESSO_BEANS;
                    water -= ESPRESSO_WATER;
                    sales++;
                } else {
                    printf("Insufficient ingredients for Espresso.\n");
                }
                break;
            case 2:
                if (coffee_beans >= CAPPUCCINO_BEANS && water >= CAPPUCCINO_WATER && milk >= CAPPUCCINO_MILK) {
                    process_payment(cappuccino_price);
                    printf("Making your Cappuccino...\n");
                    coffee_beans -= CAPPUCCINO_BEANS;
                    water -= CAPPUCCINO_WATER;
                    milk -= CAPPUCCINO_MILK;
                    sales++;
                } else {
                    printf("Insufficient ingredients for Cappuccino.\n");
                }
                break;
            case 3:
                if (coffee_beans >= MOCHA_BEANS && water >= MOCHA_WATER && milk >= MOCHA_MILK && chocolate_syrup >= MOCHA_CHOCOLATE) {
                    process_payment(mocha_price);
                    printf("Making your Mocha...\n");
                    coffee_beans -= MOCHA_BEANS;
                    water -= MOCHA_WATER;
                    milk -= MOCHA_MILK;
                    chocolate_syrup -= MOCHA_CHOCOLATE;
                    sales++;
                } else {
                    printf("\n Insufficient ingredients for Mocha.\n");
                }
                break;
            case 4:
            if (water > 5){
                process_payment(Hot_water_price);
                printf("\n making Hot water\n ");
            }
            else {
                printf("\nunavailable\n");
            }
            
            case 0:
                return;
            default:
                printf("\n Invalid choice, please try again.\n");
        }

        check_stock_levels();
    }
}

void process_payment(float price) {
    float total_paid = 0.0;
    float coin;

    printf("The total price is: %f AED\n", price);
    while (total_paid < price) {
        printf("Insert coin (1 AED or 0.5 AED): ");
        scanf("%f", &coin);

        if (coin == 1.0 || coin == 0.5) {
            total_paid += coin;
            printf("You have inserted: %f AED. Total paid: %f AED.\n", coin, total_paid);
        } else {
            printf("Invalid coin, please try again.\n");
        }
    }
    printf("Payment complete! You paid %f AED.\n", total_paid);
}

void check_stock_levels() {
    if (coffee_beans <= 16 || water <= 100 || milk <= 20 || chocolate_syrup <= 30) {
        printf("\nWarning: Ingredient levels are low. Please replenish the stock.\n");
        admin_mode();
    }
}

void admin_mode() {
    int password_attempts = 0;

    while (password_attempts < 3) {
        printf("Enter admin password: ");
        int entered_password;
        scanf("%d", &entered_password);

        if (entered_password == admin_password) {
            printf("Access granted.\n");
            handle_admin_tasks();
            return;
        } else {
            password_attempts++;
            printf("Incorrect password. Attempt (%d/3).\n", password_attempts);
        }
    }
    printf("Too many failed attempts. Exiting to main menu...\n");
}

void handle_admin_tasks() {
    int admin_choice;

    while (1) {
        printf("\nAdmin Menu:\n");
        printf("1: Display stock levels and sales\n");
        printf("2: Replenish ingredients\n");
        printf("3: Change coffee prices\n");
        printf("4: Reset sales to zero\n");
        printf("0: Exit Admin Mode\n");
        printf("Enter your choice: ");
        scanf("%d", &admin_choice);

        switch (admin_choice) {
            case 1:
                printf("\nStock levels:\n");
                printf("Coffee beans: %d\n", coffee_beans);
                printf("Water: %d\n", water);
                printf("Milk: %d\n", milk);
                printf("Chocolate syrup: %d\n", chocolate_syrup);
                printf("Total sales: %d\n", sales);
                break;
            case 2:
                replenish_stock();
                break;
            case 3:
                change_coffee_price();
                break;
            case 4:
                reset_sales();
                break;
            case 0:
                return;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

void replenish_stock() {
    coffee_beans = 50 + (rand() %51 + 100);
    water = 250 + (rand() %151 + 100);
    milk = 150 + (rand() %76 + 75);
    chocolate_syrup = 50 + (rand() %51 + 100);
    printf("Ingredients replenished.\n");
}

void change_coffee_price() {
    int coffee_choice;
    float new_price;

    printf("Select coffee to change price:\n");
    printf("1: Espresso\n");
    printf("2: Cappuccino\n");
    printf("3: Mocha\n");
    scanf("%d", &coffee_choice);

    switch (coffee_choice) {
        case 1:
            printf("Enter new price for Espresso: ");
            scanf("%f", &new_price);
            espresso_price = new_price;
            printf("Espresso price updated to %f AED.\n", espresso_price);
            break;
        case 2:
            printf("Enter new price for Cappuccino: ");
            scanf("%f", &new_price);
            cappuccino_price = new_price;
            printf("Cappuccino price updated to %f AED.\n", cappuccino_price);
            break;
        case 3:
            printf("Enter new price for Mocha: ");
            scanf("%f", &new_price);
            mocha_price = new_price;
            printf("Mocha price updated to %f AED.\n", mocha_price);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

void reset_sales() {
    printf("\nTotal sales before reset: %d AED\n", sales);
    printf("Please collect the total sales amount.\n");
    printf("Do you want to reset sales to zero? (y/n): ");
    char reset_choice;
    scanf(" %c", &reset_choice);
    if (reset_choice == 'y' || reset_choice == 'Y') {
        sales = 0;
        printf("Sales have been reset to zero.\n");
    } else {
        printf("Sales were not reset.\n");
    }
}

