#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>


int pin();
int withdraw();
int deposit();
int check();
int transfer();

    // Variable Assignment
    int option, balance = 500, account, amount, pincode, enteredPin, pinCheck = 0, wrongPinCheck = 2, transferamount;
    const int MAX = 2000;
    struct termios tp, save;

int main()
{
    printf("Please enter your new PIN: ");

    // Hide Input for PIN
    tcgetattr( STDIN_FILENO, &tp);              
    save = tp;                                  
    tp.c_lflag &= ~ECHO;                        
    tcsetattr( STDIN_FILENO, TCSAFLUSH, &tp );  
    scanf("%d", &pincode);
    tcsetattr( STDIN_FILENO, TCSANOW, &save);
    pin();

    // Main Menu
    printf("\t\t\t\t\t----- Banking System -----\n\n");
    printf("\t\t\t\t\t\t1. Withdraw\n\n");
    printf("\t\t\t\t\t\t2. Deposit\n\n");
    printf("\t\t\t\t\t\t3. Check Balance\n\n");
    printf("\t\t\t\t\t\t4. Transfer\n\n");
    printf("\t\t\t\t\t\t9. Quit\n\n");

    // Take menu input
    printf("Option: ");
    scanf("%d", &option);

    if (option == 1)
    {
        withdraw();
    }

    else if(option == 2)
    {
        deposit();
    }

    else if (option == 3)
    {
        check();
    }

    else if (option == 4)
    {
        transfer();
    }

        else if (option == 9)
    {
        exit(0);
    }

    else
    {
        printf("Wrong choice\n");
    }
}

int pin()
{
    while (pinCheck == 0)
    {

        printf("\nPlease enter PIN: ");
        
        // Hide Input for PIN //
        tcgetattr( STDIN_FILENO, &tp);              
        save = tp;                                  
        tp.c_lflag &= ~ECHO;                        
        tcsetattr( STDIN_FILENO, TCSAFLUSH, &tp );  
        scanf("%d", &enteredPin);
        tcsetattr( STDIN_FILENO, TCSANOW, &save);

        if (pincode != enteredPin && wrongPinCheck > 0)
        {
            printf("\nIncorrect PIN\n");
            printf("Number of tries: %d\n", wrongPinCheck);
            wrongPinCheck--;
        }
        else if (wrongPinCheck == 0)
        {
            printf("\nIncorrect PIN.\n");
            printf("Revoking the card\n");
            exit(0);
            return 1;
        }
        else if (pincode == enteredPin)
        {
            printf("\nCorrect PIN\n");
            pinCheck++;
        }
    }
    return 0;
}

int withdraw()
{
        printf("\t\t\t\t\t----- Withdraw -----\n\n");
        if (balance > 1)
        {
            printf("Balance: %d€\n", balance);
            printf("Please select the amount to withdraw: "); 
            scanf("%d", &amount);
            if (amount > balance)
            {
                printf("Insufficient funds to perform withdrawal\n");
                withdraw();
                return 0;
            }
            else if (amount < 0)
            {
                printf("Amount cannot be negative\n");
                withdraw();
                return 0;
            }
            else
            {
                balance -= amount;
                printf("Successfully withdrawn %d€\n", amount);
                printf("Balance: %d€\n", balance);
                pin();
                main();
                return 0;
            }
        }
        else
        {
            printf("Insufficient balance to perform withdrawal\n");
            main();
            return 1;
        }
}
int deposit()
{

    printf("\t\t\t\t\t----- Deposit -----\n\n");
    printf("Balance: %d€\n", balance);
    printf("Max Allowed: %d€\n", MAX);
    printf("Please select the amount to deposit: ");
    scanf("%d", &amount);
    if (amount <= MAX && amount > 0)
    {
        balance += amount;
        printf("Successfully deposited %d€\n", amount);
        printf("Balance: %d€\n", balance);
        pin();
        main();
        return 0;
    }
    else
    {
        printf("Amount not allowed\n");
        deposit();
        return 1;
    }
}

int check()
{ 
        printf("\t\t\t\t\t----- Balance -----\n\n");
        printf("Balance: %d€\n", balance);
        pin();
        main();
        return 0;
}  

int transfer()
{
        printf("\t\t\t\t\t----- Transfer -----\n\n");
        printf("Balance: %d€\n", balance);
        printf("Select amount to transfer: ");
        scanf("%d", &transferamount);
        if (transferamount > balance || transferamount < 0)
        {
            printf("Amount not available\n");
            transfer();
        }
        else
        {
            printf("Select account (9 digits): ");
            scanf("%d", &account);

            if (account > 000000000 && account < 999999999)
            {
                printf("Successfully transfered\n");
                pin();
                main();
                return 0;
            }
            else
            {
                printf("Incorrect account");
                transfer();
            }
        }
        return 0;
}
