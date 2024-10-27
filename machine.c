#include <stdio.h>                          // Standard I/O library
#include <windows.h>                        // Windows command library

// COFFEE BEANS
#define coffee_beans_espresso 8
#define coffee_beans_cappuccino 8
#define coffee_beans_mocha 8
int coffee_beans = 20;

// WATER
#define water_espresso 30
#define water_cappuccino 30
#define water_mocha 39
int water = 100;

//MILK
#define milk_espresso 0
#define milk_cappuccino 70
#define milk_mocha 160
int milk = 400;

//CHOCOLATE SYRUP
#define chocolate_syrup_espresso 0
#define chocolate_syrup_cappuccino 0
#define chocolate_syrup_mocha 30
int chocolate_syrup = 90;

//PRICES
float price_espresso = 3.5;
float price_cappuccino = 4.5;
float price_mocha = 5.5;

float total_amount = 0.0;                   // Total sales amount

#define admin_password 1234                 // ADMIN password


// Initializing other functions
int exit_func;
float change;

// Initializing all functions [Working of each functions explained later]
void ordercoffee();
void sleep();
void adminmode();
void admincommands();
void remaining_ingredients();
void total_sales();
void replenish_ingredients();
void change_coffee_price();
void refill_beans();
void refill_water();
void refill_milk();
void refill_syrup();
int check_ingredients();
int payment(float);



int main()              // Main function
{
    while (1)           // While loop to keep the program running after ordering coffee
    {
        int interface_choice;
        printf("\nCOFFEE VENDING MACHINE\n\n\n");       // Formatted texts displayed
        printf("Sn.\t\tOption\n\n");
        printf("1.\t\tBuy coffee\n");
        printf("2.\t\tAdmin mode\n");
        printf("0.\t\tEXIT\n\n\n");
        printf("Your selection: ");
        scanf("%d", &interface_choice);                 // Stores input value in interface_choice

        switch (interface_choice)
        {
        case 1:
            printf("\033[H\033[J");                     // This printf statement clears the console
            ordercoffee();                              // Calls the ordercoffee() function
            break;                                      // breaks from switch case

        case 2:
            printf("\033[H\033[J");
            adminmode();                                // Calls the adminmode() function
            break;

        case 0:
            return 0;                                   // Exits program

        default:                                        // This branch of code runs when an invalid input is typed
            printf("\nInvalid input!");
            sleep(1);
            printf("\033[H\033[J");
            break;
        }
    }
}



void ordercoffee()                      // Function to order coffee
{
    while (1)                           // While loop to keep the function running
    {
        int coffee_selection, coffee_confirmation;                      // Initialize variables


        printf("\nCOFFEE VENDING MACHINE\n\n\n");                       // Displays statements with formatting
        printf("Please select a coffee to buy\n\n");
        printf("Sn.\t\tCoffee\t\t\tPrice\n\n");
        printf("1.\t\tEspresso\t\tAED %.2f\n",price_espresso);
        printf("2.\t\tCappuccino\t\tAED %.2f\n",price_cappuccino);
        printf("3.\t\tMocha\t\t\tAED %.2f\n",price_mocha);
        printf("0.\t\tEXIT\n\n");

        printf("Your selection: ");                 // Confirms coffee
        scanf("%d", &coffee_selection);

        switch(coffee_selection)                    // Conditional statement for coffee statement
        {
        case 1:

            printf("\033[H\033[J");
            if (check_ingredients(coffee_beans_espresso, water_espresso, milk_espresso, chocolate_syrup_espresso))      // Checks if there are enough ingredients
            {
                printf("\nCOFFEE VENDING MACHINE\n\n\n");
                printf("Coffee selected\t\tPrice\n");
                printf("Espresso\t\tAED %.2f",price_espresso);
                printf("\n\n1 -- CONFIRM\n0 -- RETURN\n\n");
                printf("Your selection: ");
                scanf("%d", &coffee_confirmation);

                switch(coffee_confirmation)                                             // Conditional statement for coffee type confirmation
                {
                case 1:
                    printf("\033[H\033[J");

                    if(payment(price_espresso))
                    {
                        printf("\nCOFFEE VENDING MACHINE\n\n\n");                       // Displays user the coffee they bought, how much it costs, and the change they receive
                        printf("Preparing: Espresso\n\n");
                        printf("Price: AED %.2f\n", price_espresso);
                        printf("Your change: AED %.2f\n\n",change);
                        sleep(2);
                        printf("Your drink is ready. Thank you for ordering!");
                        sleep(2);
                        printf("\033[H\033[J");

                        total_amount = total_amount + price_espresso;                   // Depletes ingredients depending on which coffee is brewing
                        coffee_beans -= coffee_beans_espresso;
                        water -= water_espresso;
                        milk -= milk_espresso;
                        chocolate_syrup -= chocolate_syrup_espresso;

                        return;
                    }


                case 0:
                    printf("\033[H\033[J");
                    break;

                default:                                                // Handles invalid inputs
                    printf("\033[H\033[J");
                    printf("\nCOFFEE VENDING MACHINE\n\n\n");
                    printf("Invalid input");
                    sleep(2);
                    printf("\033[H\033[J");

                }
            }

            break;

        case 2:

            printf("\033[H\033[J");

            if (check_ingredients(coffee_beans_cappuccino, water_cappuccino, milk_cappuccino, chocolate_syrup_cappuccino))      // Checks if there are enough ingredients
            {
                printf("\nCOFFEE VENDING MACHINE\n\n\n");
                printf("Coffee selected\t\tPrice\n");
                printf("Cappuccino\t\tAED %.2f",price_cappuccino);
                printf("\n\n1 -- CONFIRM\n0 -- RETURN\n\n");
                printf("Your selection: ");
                scanf("%d", &coffee_confirmation);

                switch(coffee_confirmation)                                                         // Conditional statement for coffee type confirmation
                {
                case 1:
                    printf("\033[H\033[J");

                    if (payment(price_cappuccino))
                    {
                        printf("\nCOFFEE VENDING MACHINE\n\n\n");                                   // Displays user the coffee they bought, how much it costs, and the change they receive
                        printf("Preparing: Cappuccino\n\n");
                        printf("Price: AED %.2f\n", price_cappuccino);
                        printf("Your change: AED %.2f\n\n",change);
                        sleep(2);
                        printf("Your drink is ready. Thank you for ordering!");
                        sleep(2);
                        printf("\033[H\033[J");

                        total_amount = total_amount + price_cappuccino;                             // Depletes ingredients depending on which coffee is brewing
                        coffee_beans -= coffee_beans_cappuccino;
                        water -= water_cappuccino;
                        milk -= milk_cappuccino;
                        chocolate_syrup -= chocolate_syrup_cappuccino;

                        return;
                    }


                case 0:
                    printf("\033[H\033[J");
                    break;

                default:                                                // Handles invalid inputs
                    printf("\033[H\033[J");
                    printf("\nCOFFEE VENDING MACHINE\n\n\n");
                    printf("Invalid input");
                    sleep(2);
                    printf("\033[H\033[J");

                }
            }

            break;


        case 3:

            printf("\033[H\033[J");

            if (check_ingredients(coffee_beans_mocha, water_mocha, milk_mocha, chocolate_syrup_mocha))
            {
                printf("\nCOFFEE VENDING MACHINE\n\n\n");
                printf("Coffee selected\t\tPrice\n");
                printf("Mocha\t\t\tAED %.2f",price_mocha);
                printf("\n\n1 -- CONFIRM\n0 -- RETURN\n\n");
                printf("Your selection: ");
                scanf("%d", &coffee_confirmation);

                switch(coffee_confirmation)                                                             // Conditional statement for coffee type confirmation
                {
                case 1:
                    printf("\033[H\033[J");

                    if (payment(price_mocha))
                    {
                        printf("\nCOFFEE VENDING MACHINE\n\n\n");
                        printf("Preparing: Mocha\n\n");
                        printf("Price: AED%.2f\n", price_mocha);
                        printf("Your change: AED%.2f\n\n",change);                                        // Displays user the coffee they bought, how much it costs, and the change they receive
                        sleep(2);
                        printf("Your drink is ready. Thank you for ordering!");
                        sleep(2);
                        printf("\033[H\033[J");

                        total_amount = total_amount + price_mocha;                                      // Depletes ingredients depending on which coffee is brewing
                        coffee_beans -= coffee_beans_mocha;
                        water -= water_mocha;
                        milk -= milk_mocha;
                        chocolate_syrup -= chocolate_syrup_mocha;
                        return;
                    }


                case 0:
                    printf("\033[H\033[J");                                                             // Exits function
                    break;

                default:                                                                                // Handles invalid inputs
                    printf("\033[H\033[J");
                    printf("\nCOFFEE VENDING MACHINE\n\n\n");
                    printf("Invalid input");
                    sleep(2);
                    printf("\033[H\033[J");

                }
            }

            break;


        case 0:                                                                                         // Exits function

            printf("\033[H\033[J");
            printf("\nCOFFEE VENDING MACHINE\n\n\n");
            printf("EXITING...");
            sleep(1);
            printf("\033[H\033[J");
            return;

        default:                                                                                        // Handles invalid inputs
            printf("\033[H\033[J");
            printf("\nCOFFEE VENDING MACHINE\n\n\n");
            printf("\nInvalid input!");
            sleep(2);
            printf("\033[H\033[J");
        }
    }
}


void adminmode()                                                            // Admin mode function
{
    int pswd;                                                               // Initialize the variables

    printf("\nCOFFEE VENDING MACHINE [ADMIN MODE]\n\n\n");
    printf("Enter admin password: ");
    scanf("%d", &pswd);                                                     // Stores password into variable pswd

    if (pswd == admin_password)                                             // checks if the input password is the same as admin password
    {
        printf("\033[H\033[J");
        admincommands();                                                    // Lets user have admin access
    }

    else
    {
        printf("WRONG PASSWORD\n");                                         // Returns user to main menu
        sleep(1);
        printf("Returning to main menu...");
        sleep(2);
        printf("\033[H\033[J");
    }
}

void admincommands()                                                        // All admin commands
{
    int adminselection;

    while(1)
    {
        printf("\nCOFFEE VENDING MACHINE [ADMIN MODE]\n\n\n");              // Lists all commands
        printf("What would you like to do?\n\n");
        printf("Sn.\t\tOptions\n\n");
        printf("1.\t\tDisplay remaining ingredients\n");
        printf("2.\t\tDisplay total sales\n");
        printf("3.\t\tReplenish ingredients in the machine\n");
        printf("4.\t\tChange coffee price\n");
        printf("0.\t\tEXIT\n\n");

        printf("Your selection: ");
        scanf("%d", &adminselection);                                       // Stores user selection in admin selection

        switch(adminselection)                                              // Switch case for which command
        {
        case 1:
            remaining_ingredients();                                        // Calls remaining ingredients function
            break;

        case 2:
            total_sales();                                                  // Calls total sales function
            break;
        case 3:
            replenish_ingredients();                                        // Calls replenish ingredients function
            break;

        case 4:
            change_coffee_price();                                          // Calls change coffee price function
            break;

        case 0:
            printf("\033[H\033[J");                                         // Exits function
            printf("\nCOFFEE VENDING MACHINE\n\n\n");
            printf("EXITING...");
            sleep(1);
            printf("\033[H\033[J");
            return;

        default:                                                            // Handles error
            printf("\033[H\033[J");
            printf("\nCOFFEE VENDING MACHINE\n\n\n");
            printf("Invalid input");
            sleep(2);
            printf("\033[H\033[J");

        }

    }
    return;
}

void remaining_ingredients()                                                // Function to display the ingredients remaining in a formatted style
{

    printf("\033[H\033[J");
    printf("\nCOFFEE VENDING MACHINE [ADMIN MODE]\n\n\n");
    printf("Sn.\t\tIngredients\t\tRemaining\n\n");
    printf("1.\t\tCoffee beans\t\t%d beans\n",coffee_beans);
    printf("2.\t\tWater\t\t\t%d mL\n",water);
    printf("3.\t\tMilk\t\t\t%d mL\n",milk);
    printf("4.\t\tChocolate syrup\t\t%d mL\n\n",chocolate_syrup);

    printf("Enter any key to EXIT: ");
    scanf("%d",&exit_func);
    printf("\033[H\033[J");

    return;
}


void total_sales()                                                          // Function to display total sales and reset the amount
{
    while(1)
    {
    int reset_choice;
        printf("\033[H\033[J");
        printf("\nCOFFEE VENDING MACHINE [ADMIN MODE]\n\n\n");

        printf("Total sales: AED %.2f\n",total_amount);
        printf("Would you like to set the total sales to AED 0.00?\n\n");

        printf("0 -- EXIT\n1 -- RESET\n");
        printf("Your selection: ");
        scanf("%d",&reset_choice);

        switch (reset_choice)
        {
        case 1:
            total_amount = 0;
            printf("RESETTING...");
            sleep(1);
            printf("\033[H\033[J");
            break;
        case 0:
            printf("\033[H\033[J");
            return;

        default:
            printf("\033[H\033[J");
            printf("\nCOFFEE VENDING MACHINE\n\n\n");
            printf("Invalid input");
            sleep(2);
            printf("\033[H\033[J");

        }
    }

}


void replenish_ingredients()                                                        // Function to replenish ingredients
{
    int replenish_selection;

    while(1)
    {
        printf("\033[H\033[J");
        printf("\nCOFFEE VENDING MACHINE [ADMIN MODE]\n\n\n");

        printf("Refill for:\n\n\n");
        printf("Sn.\t\t\tIngredient\t\t\tRemaining\n\n");
        printf("1.\t\t\tCoffee beans\t\t\t%d beans\n",coffee_beans);
        printf("2.\t\t\tWater\t\t\t\t%d mL\n",water);
        printf("3.\t\t\tMilk\t\t\t\t%d mL\n",milk);
        printf("4.\t\t\tChocolate syrup\t\t\t%d mL\n",chocolate_syrup);
        printf("5.\t\t\tRefill all%\n");
        printf("0.\t\t\tRETURN\n\n");

        printf("Your selection: ");
        scanf("%d", &replenish_selection);

        switch(replenish_selection)
        {
        case 1:
            refill_beans();
            break;

        case 2:
            refill_water();
            break;

        case 3:
            refill_milk();
            break;

        case 4:
            refill_syrup();
            break;

        case 5:
            refill_beans();
            refill_water();
            refill_milk();
            refill_syrup();
            break;

        case 0:
            printf("\033[H\033[J");
            return;

        default:
            printf("\033[H\033[J");
            printf("\nCOFFEE VENDING MACHINE\n\n\n");
            printf("Invalid input");
            sleep(2);
            printf("\033[H\033[J");
        }
    }
}

void change_coffee_price()                                                      // Function to change coffee prices
{
    int change_price;

    while(1)
    {
        printf("\033[H\033[J");
        printf("\nCOFFEE VENDING MACHINE [ADMIN MODE]\n\n\n");

        printf("Change item price [ ENTER 0 TO EXIT ]\n\n");
        printf("S.no\t\t\tItem\t\t\tCurrent Price\n\n");
        printf("1.\t\t\tEspresso\t\tAED %.2f\n",price_espresso);
        printf("2.\t\t\tCappuccino\t\tAED %.2f\n",price_cappuccino);
        printf("3.\t\t\tMocha\t\t\tAED %.2f\n\n",price_mocha);

        printf("Your selection: ");
        scanf("%d", &change_price);

        switch(change_price)
        {
        case 1:
            printf("New cost for espresso: ");
            scanf("%f",&price_espresso);
            break;

        case 2:
            printf("New cost for cappuccino: ");
            scanf("%f",&price_cappuccino);
            break;

        case 3:
            printf("New cost for mocha: ");
            scanf("%f",&price_mocha);
            break;

        case 0:
            printf("\033[H\033[J");
            return;

        default:
            printf("\nInvalid option!");
            sleep(2);
            break;
        }

    }
}

void refill_beans()                                                             // Refills beans
{
    int min_beans = 100;
    int max_beans = 200;

    coffee_beans = rand()%(max_beans - min_beans + 1) + min_beans;              // Formula for random integer between two numbers
}

void refill_water()                                                             // Refills water
{
    int min_water = 500;
    int max_water = 1000;

    water = rand()%(max_water - min_water + 1) + min_water;
}

void refill_milk()                                                              // Refills milk
{
    int min_milk = 1000;
    int max_milk = 2000;

    milk = rand()%(max_milk - min_milk + 1) + min_milk;
}

void refill_syrup()                                                             // Refills syrup
{
    int min_syrup = 200;
    int max_syrup = 500;

    chocolate_syrup = rand()%(max_syrup - min_syrup + 1) + min_syrup;
}

int check_ingredients(int beans_required, int water_required, int milk_required, int syrup_required)                // Checks for ingredient availability
{

    printf("\033[H\033[J");

    if (coffee_beans <= beans_required || water <= water_required || milk <= milk_required || chocolate_syrup <= syrup_required)
    {
        printf("\nCOFFEE VENDING MACHINE\n\n\n");
        printf("Unavailable due to temporarily insufficient ingredients\n");
        sleep(3);
        printf("\033[H\033[J");
        return 0;
    }

    return 1;
}

int payment(float to_pay)                                               // Function for payment
{
    float amount_inserted = 0.0;
    float coin;

    printf("\nCOFFEE VENDING MACHINE\n\n\n");
    printf("Please pay AED %.2f for your coffee\n", to_pay);

    while(amount_inserted < to_pay)
    {
        printf("Insert AED 1 or AED 0.5: ");
        scanf("%f",&coin);

        if (coin == 1.0 || coin == 0.5)
        {
            amount_inserted += coin;                                        // Adds coin amount into amount inserted
            printf("Inserted amount: AED %.2f\n\n", amount_inserted);
        }

        else
        {
            printf("Please remove the invalid coin and insert AED 1 or AED 0.5\n");
        }
    }

    if (amount_inserted >= to_pay)                                              // Gives back change
    {
        change = amount_inserted - to_pay;
        printf("Payment completed. Returning change: AED %.2f\n", change);
        sleep(2);
        printf("\033[H\033[J");
        return 1;
    }

    return 0;
}
