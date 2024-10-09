/*Coffe machine simulator*/
#include <stdio.h>
#include <stdlib.h>

/* define ingredient of espresso */
#define esspresso_coffe_bean 8
#define esspresso_water 30
float espresso_price = 3.5;

/*Define ingredients of cappucino*/
#define Cappuccino_coffe_bean 8
#define Cappuccino_water 30
#define Cappuccino_milk 70
float Cappuccino_price = 4.5;

/*Define ingredients of mocha*/
#define Mocha_coffe_bean 8
#define Mocha_water 39
#define Mocha_milk 160
#define Mocha_choclate_syrup 30
float Mocha_price = 5.5;

int coffee_beans = 100;
int water = 500;
int milk = 300;
int chocolate_syrup = 100;
int Admin_password = 1234;
int pass_check;
int coffe_choice;
float price;

int current_beans;

int choice;
int sales;

void order_coffe();
void Admin();
void Admin_granted();
void payments();
int changing_choice;

int main()
{
    printf("\nWelcome!\n");
    printf("1: order a coffe\n");
    printf("2: Admin\n");
    printf("3: exit! \n");
    scanf("%d", &choice);

    if (choice == 1){
        sales = sales +1;
        order_coffe();
    }
    else if (choice == 2){
        Admin();
    }
    else if (choice == 3){
        printf("Closing Program!...");
        return 0;
    }
}

void order_coffe()
{


    while(1) { 
        printf("Choose coffee type:\n 1: Espresso (3.5 AED)\n 2: Cappuccino (4.5 AED)\n 3: Mocha (5.5 AED)\n 0: Exit to main menu\n");
        scanf("%d", &coffe_choice);

        switch (coffe_choice) {
            case 1:
                if (coffee_beans >= 8 && water >= 30) {
                    payments();
                    printf("Making your Espresso...\n");
                    coffee_beans -= 8;
                    water -= 30;
                } else {
                    printf("Espresso unavailable.\n");
                }
                break;

            case 2:
                if (coffee_beans >= 8 && water >= 30 && milk >= 70) {
                    payments();
                    printf("Making your Cappuccino...\n");
                    coffee_beans -= 8;
                    water -= 30;
                    milk -= 70;
                } else {
                    printf("Cappuccino unavailable.\n");
                }
                break;

            case 3:
                if (coffee_beans >= 8 && water >= 39 && milk >= 160 && chocolate_syrup >= 30) {
                    payments();
                    printf("Making your Mocha...\n");
                    coffee_beans -= 8;
                    water -= 39;
                    milk -= 160;
                    chocolate_syrup -= 30;
                } else {
                    printf("Mocha unavailable.\n");
                }
                break;

            case 0:
                printf("Returning to main menu...\n");
                main(); 
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}

void payments(){
    float total_paid = 0.0;
    float coin;
switch (coffe_choice) {
            case 1:
                price = 3.5;
                break;
            case 2:
                price = 4.5;
                break;
            case 3:
                price = 5.5;
                break;
}

    printf("The total price is: %f AED\n", price);
    while (total_paid < price) {
        printf("Insert coin (1 AED or 0.5 AED): ");
        scanf("%f", &coin);

        if (coin == 1.0 || coin == 0.5) {
            total_paid += coin;
            printf("You have inserted: %.2f AED. Total paid: %.2f AED.\n", coin, total_paid);
        } else {
            printf("Invalid coin! please collect your coin and insert a valid one.\n");
        }

        if (total_paid >= price) {
            printf("Payment complete! You have paid: %f AED.\n", total_paid);
            break;
        }
    }
}



void Admin(){
    int pass_count = 0;
    while (pass_count < 3) {
        printf(" Enter Admin Password: ");
        scanf("%d", &pass_check);
        
        if (pass_check == Admin_password) {
            printf("Access Granted!\n");
            Admin_granted();
        } else {
            pass_count++;
            printf("Password Incorrect!!... Try again (%d/3)\n", pass_count);
        }
    }
    
    printf("Password wrong more than 3 times, Exiting...\n");
    main();
}

void Admin_granted (){
    int choice_admin;
    if (pass_check == Admin_password){
        printf("password correct... \n");
        printf(" 1: Display the quantity of each ingredient in the machine and the total sale amount \n 2: Replenish ingredients in the machine \n 3: Change coffee price \n 0: Exit the Admin Mode function \n");
        scanf("%d", &choice_admin);

        switch (choice_admin){
            case 1:
            printf(" int coffee_beans = %d, water = %d, milk = %d, chocolate_syrup = %d, sales = %d ",coffee_beans, water, milk, chocolate_syrup, sales);
            main();
            break;

            case 2:
            coffee_beans = coffee_beans + (rand() %51 + 100);   
            water = water + (rand() %150 + 100);
            milk = milk + (rand() %75 + 75);
            chocolate_syrup = chocolate_syrup + (rand() %25 + 25);
            printf("Ingredients have been replenished");
            break;

            case 3:
                printf("Select coffee type to change price: \n");
                printf("1. Espresso\n");
                printf("2. Cappuccino\n");
                printf("3. Mocha\n");
                printf("Please enter your choice: ");
                scanf("%d", &changing_choice);
                switch (changing_choice){
                    float new_price;
                    case 1:
                    printf("Enter new price for Espresso: ");
                    scanf("%f", &espresso_price);
                    printf("Price updated. Espresso new price %f", espresso_price);
                    break;
                    case 2:
                    printf("Enter new price for cappuccino: ");
                    scanf("%f", &Cappuccino_price);
                    printf("Price updated. Cappuccino new price %f", Cappuccino_price);
                    break;
                    case 3:
                    printf("Enter new price for Mocha: ");
                    scanf("%f", &Mocha_price);
                    break;
            default:
                printf("invalid Choice \n ");
                }
                break;
                case 0:
                printf("Going to Main Page... \n");
                main();

        }
    }
}

