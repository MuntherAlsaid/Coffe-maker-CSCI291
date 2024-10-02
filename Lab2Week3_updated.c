/*Coffe machine simulator*/
#include <stdio.h>

/* define ingredient of espresso */
#define esspresso_coffe_bean 8
#define esspresso_water 30
#define espresso_price 3.5

/*Define ingredients of cappucino*/
#define Cappuccino_coffe_bean 8
#define Cappuccino_water 30
#define Cappuccino_milk 70
#define Cappuccino_price 4.5

/*Define ingredients of mocha*/
#define Mocha_coffe_bean 8
#define Mocha_water 39
#define Mocha_milk 160
#define Mocha_choclate_syrup 30
#define Mocha_price 5.5

int coffee_beans = 100;
int water = 500;
int milk = 300;
int chocolate_syrup = 100;
int Admin_password = 1234;
int pass_check;

int current_beans;

char order(char coffe_type);

int choice;
int sales;

void order_coffe();
void Admin();
int changing_choice;

int main() 
{
    printf("Welcome!\n");
    printf("order a coffe press 1\n");
    printf("Admin? press 2\n");
    printf("exit! \n");
    scanf("%d", &choice);

    if (choice == 1){
        sales = sales +1;
        order_coffe();
    }
    else if (choice == 2){
        Admin();
    }




}

void order_coffe()
{
    int coffe_choice;
    printf("chose coffe type \n 1: Espresso (3.5 AED), 2: Cappucino (4.5 AED), 3: Mocha (5.5 AED)\n ");
    scanf("%d", &coffe_choice);

    if (coffe_choice == 1 && coffee_beans >= 8 && water >= 30 ){
        printf("Making your Esspreso...");
        coffee_beans = coffee_beans - 8;
        water = water - 30; }
        else if (coffe_choice == 1) {
            printf("Espresso unavailable. \n");
            }

    if ( coffe_choice == 2 && coffee_beans >= 8 && water >= 30 && milk >= 70){
        printf("making your Capucino...");
        coffee_beans = coffee_beans - 8;
        water = water - 30;
        milk = milk - 70; }
        else if (coffe_choice == 2) {
            printf("Espresso unavailable. \n");
            }
    if ( coffe_choice == 3 && coffee_beans >= 8 && water >= 39 && milk >= 160 && chocolate_syrup >= 30){
        printf( "making your MOcha... ");
        coffee_beans = coffee_beans - 8;
        water = water - 39;
        milk = milk - 160;
        chocolate_syrup = chocolate_syrup - 30; }
        else if (coffe_choice == 3){
            printf("Mocha unavailable! \n");
        }

}
void Admin(){
    int pass_count = 1;
    printf(" Enter Admin Password: ");
    scanf("%d", &pass_check);
    if (pass_count <= 3){
        while (pass_check != Admin_password && pass_count <= 3){
            pass_count = pass_count + 1;
            printf("Password Incorrect!!...Try again \n");
            printf(" Enter Admin Password: \n");
            scanf("%d", &pass_check);
    }
    printf("Password wrong more 3 times, Exiting... \n");
    }
    int choice_admin;
    if (pass_check == Admin_password){
        printf("password correct... ");
        printf(" 1: Display the quantity of each ingredient in the machine and the total sale amount \n 2: Replenish ingredients in the machine \n 3: Change coffee price // 0: Exit the Admin Mode function");
        scanf("%d", &choice_admin);

        switch (choice_admin){
            case 1:
            printf(" int coffee_beans = %d, water = %d, milk = %d, chocolate_syrup = %d, sales = %d",coffee_beans, water, milk, chocolate_syrup, sales);
            break;
            case 2:
            coffee_beans = coffee_beans + 50;
            water = water + 250;
            milk = milk + 150;
            chocolate_syrup = chocolate_syrup + 50;
            printf("Ingredients have been replenished");
            case 3:
                printf("Select coffee type to change price: \n");
                printf("1. Espresso\n");
                printf("2. Cappuccino\n");
                printf("3. Mocha\n");
                printf("Please enter your choice: ");
                scanf("%d", &changing_choice);
                
            

        }
    }
}

