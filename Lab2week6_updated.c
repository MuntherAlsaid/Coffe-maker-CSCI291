#include <stdio.h>
#include <stdlib.h>

// Define ingredients and prices for each coffee type
#define ESPRESSO_BEANS 8       // Espresso needs 8 grams of coffee beans
#define ESPRESSO_WATER 30      // Espresso needs 30 ml of water
#define CAPPUCCINO_BEANS 8     // Cappuccino needs 8 grams of coffee beans
#define CAPPUCCINO_WATER 30    // Cappuccino needs 30 ml of water
#define CAPPUCCINO_MILK 70     // Cappuccino needs 70 ml of milk
#define MOCHA_BEANS 8          // Mocha needs 8 grams of coffee beans
#define MOCHA_WATER 39         // Mocha needs 39 ml of water
#define MOCHA_MILK 160         // Mocha needs 160 ml of milk
#define MOCHA_CHOCOLATE 30     // Mocha needs 30 ml of chocolate syrup

// Prices for each coffee type
float espresso_price = 3.5;    // Price of Espresso
float cappuccino_price = 4.5;  // Price of Cappuccino
float mocha_price = 5.5;       // Price of Mocha
float Hot_water_price = 1;     // Price for hot water

// ingredients available
int coffee_beans = 100;        // Initial stock of coffee beans
int water = 500;               // Initial stock of water 
int milk = 300;                // Initial stock of milk
int chocolate_syrup = 100;     // Initial stock of chocolate syrup
int sales = 0;                 // Initial number of sales

// Admin password
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
    int choice;                // Variable to store users choice
    while (1) {                // Infinite loop to keep showing the menu
        printf("\nWelcome to the Coffee Machine!\n");
        printf("1: Order Coffee\n");
        printf("2: Admin Mode\n");
        printf("3: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Get users input

        switch (choice) {      // Switch case depending on the users choice
            case 1:
                order_coffee();  // Call function coffee order
                break;
            case 2:
                admin_mode();    // Call function to enter admin mode
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;        // Exit the program
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

void order_coffee() {
    int coffee_choice;         // Variable to store coffee choice
    while (1) {
        printf("\nSelect a coffee:\n");
        printf("1: Espresso (3.5 AED)\n");
        printf("2: Cappuccino (4.5 AED)\n");
        printf("3: Mocha (5.5 AED)\n");
        printf("4. Hot water (1 AED\n");
        printf("0: Go back to the main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &coffee_choice);    // Get users coffee choice

        switch (coffee_choice) {       // Handle users coffee choice
            case 1:
                if (coffee_beans >= ESPRESSO_BEANS && water >= ESPRESSO_WATER) { // Check if enough ingredients for Espresso
                    process_payment(espresso_price);  // Call payment function
                    printf("\nMaking your Espresso...\n");
                    coffee_beans -= ESPRESSO_BEANS;   // Deducting used beans
                    water -= ESPRESSO_WATER;          // Deducting used water
                    sales++;                          // Increment sales count
                } else {
                    printf("\nInsufficient ingredients for Espresso.\n");  // Warn if ingredients are not enough
                }
                break;
            case 2:
                if (coffee_beans >= CAPPUCCINO_BEANS && water >= CAPPUCCINO_WATER && milk >= CAPPUCCINO_MILK) {
                    process_payment(cappuccino_price);  // Call payment function
                    printf("\nMaking your Cappuccino...\n");
                    coffee_beans -= CAPPUCCINO_BEANS;   // Deducting used beans
                    water -= CAPPUCCINO_WATER;          // Deducting used water
                    milk -= CAPPUCCINO_MILK;            // Deducting used milk
                    sales++;                            // Increment sales count
                } else {
                    printf("\nInsufficient ingredients for Cappuccino.\n");  // Warn if ingredients are not enough
                }
                break;
            case 3:
                if (coffee_beans >= MOCHA_BEANS && water >= MOCHA_WATER && milk >= MOCHA_MILK && chocolate_syrup >= MOCHA_CHOCOLATE) {
                    process_payment(mocha_price);  // Call payment function
                    printf("\nMaking your Mocha...\n");
                    coffee_beans -= MOCHA_BEANS;   // Deducting used beans
                    water -= MOCHA_WATER;          // Deducting used water
                    milk -= MOCHA_MILK;            // Deducting used milk
                    chocolate_syrup -= MOCHA_CHOCOLATE;  // Deducting used chocolate syrup
                    sales++;                            // Increment sales count
                } else {
                    printf("\n Insufficient ingredients for Mocha.\n");  // Warns the user if ingredients are not enough
                }
                break;
            case 4:
                if (water > 5){
                    process_payment(Hot_water_price);  // Calls payment function
                    printf("\n making Hot water\n ");
                }
                else {
                    printf("\nunavailable\n");     // Warns the user if not enough water
                }
                break;
            case 0:
                return;                            // Go back to main menu
            default:
                printf("\n Invalid choice, please try again.\n");  // invalid input
        }

        check_stock_levels();  // After each order, check stock levels
    }
}

void process_payment(float price) {
    float total_paid = 0.0;    // Initialize total amount paid by the user
    float coin;

    printf("The total price is: %f AED\n", price);  // Display price of the coffee
    while (total_paid < price) {                    // Loop until the user pays enough
        printf("Insert coin (1 AED or 0.5 AED): ");
        scanf("%f", &coin);                         // Get coin input from user

        if (coin == 1.0 || coin == 0.5) {           // Validate the coin (1 AED or 0.5 AED)
            total_paid += coin;                     // Add coin value to total
            printf("You have inserted: %f AED. Total paid: %f AED.\n", coin, total_paid);  // Show how much was inserted
        } else {
            printf("Invalid coin, please try again.\n");  // Warning for invalid coin
        }
    }
    printf("Payment complete! You paid %f AED.\n", total_paid);  // Notify payment completion
}

void check_stock_levels() {
    if (coffee_beans <= 16 || water <= 100 || milk <= 20 || chocolate_syrup <= 30) {  // Checks if any stock is low
        printf("\nWarning: Ingredient levels are low. Please replenish the stock.\n");
        admin_mode();  // Prompt admin mode if stock is low
    }
}

void admin_mode() {
    int password_attempts = 0;  // Track password attempts

    while (password_attempts < 3) {  // Allow 3 password attempts
        printf("Enter admin password: ");
        int entered_password;
        scanf("%d", &entered_password);  // Get password from admin

        if (entered_password == admin_password) {  // checks password
            printf("Access granted.\n");
            handle_admin_tasks();  // Call function for admin tasks
            return;
        } else {
            password_attempts++;   // adds 1 to the attempt count for wrong password
            printf("Incorrect password. Attempt (%d/3).\n", password_attempts);
        }
    }
    printf("Too many failed attempts. Exiting to main menu...\n");  // goes back to menue after 3 failed attempts
}

void handle_admin_tasks() {
    int admin_choice;

    while (1) {  // Admin menu loop
        printf("\nAdmin Menu:\n");
        printf("1: Display stock levels and sales\n");
        printf("2: Replenish ingredients\n");
        printf("3: Change coffee prices\n");
        printf("4: Reset sales to zero\n");
        printf("0: Exit Admin Mode\n");
        printf("Enter your choice: ");
        scanf("%d", &admin_choice);  // Get admin's choice

        switch (admin_choice) {
            case 1:
                printf("\nStock levels:\n");
                printf("Coffee beans: %d\n", coffee_beans);
                printf("Water: %d\n", water);
                printf("Milk: %d\n", milk);
                printf("Chocolate syrup: %d\n", chocolate_syrup);
                printf("Total sales: %d\n", sales);  // Display current stock and sales
                break;
            case 2:
                replenish_stock();  // Replenish ingredients
                break;
            case 3:
                change_coffee_price();  // Change prices for coffee
                break;
            case 4:
                reset_sales();  // Reset sales to zero
                break;
            case 0:
                return;  // Exit admin mode
            default:
                printf("Invalid choice, please try again.\n");  // warning if user inpus invalid choice
        }
    }
}

void replenish_stock() {
    coffee_beans = 50 + (rand() % 51 + 100);  // Randomly Replenishes the stock for beans
    water = 250 + (rand() % 151 + 100);       // Randomly Replenishes the stock for water
    milk = 150 + (rand() % 76 + 75);          // Randomly Replenishes the stock for milk
    chocolate_syrup = 50 + (rand() % 51 + 100);  // Randomly Replenishes the stock for chocolate syrup
    printf("Ingredients replenished.\n");  // Notify that stock has been replenished
}

void change_coffee_price() {
    int coffee_choice;
    float new_price;

    printf("Select coffee to change price:\n");
    printf("1: Espresso\n");
    printf("2: Cappuccino\n");
    printf("3: Mocha\n");
    scanf("%d", &coffee_choice);  // Get choice of coffee to change price

    switch (coffee_choice) {
        case 1:
            printf("Enter new price for Espresso: ");
            scanf("%f", &new_price);  // Get new price for Espresso
            espresso_price = new_price;  // Update price
            printf("Espresso price updated to %f AED.\n", espresso_price);
            break;
        case 2:
            printf("Enter new price for Cappuccino: ");
            scanf("%f", &new_price);  // Get new price for Cappuccino
            cappuccino_price = new_price;  // Update price
            printf("Cappuccino price updated to %f AED.\n", cappuccino_price);
            break;
        case 3:
            printf("Enter new price for Mocha: ");
            scanf("%f", &new_price);  // Get new price for Mocha
            mocha_price = new_price;  // Update price
            printf("Mocha price updated to %f AED.\n", mocha_price);
            break;
        default:
            printf("Invalid choice.\n");  // Handles the invalid choices
    }
}

void reset_sales() {
    printf("\nTotal sales before reset: %d AED\n", sales);  // Display total sales before reset
    printf("Please collect the total sales amount.\n");
    printf("Do you want to reset sales to zero? (y/n): ");
    char reset_choice;
    scanf(" %c", &reset_choice);  // Get confirmation from admin
    if (reset_choice == 'y' || reset_choice == 'Y') {
        sales = 0;  // Reset sales to zero
        printf("Sales have been reset to zero.\n");
    } else {
        printf("Sales were not reset.\n");  // Sales not changing
    }
}
