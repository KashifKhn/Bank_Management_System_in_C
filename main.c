#include <stdio.h>
#include <conio.h>
#include <unistd.h>

struct ClientData
{
    unsigned int accountNumber;
    char lastName[20];
    char firstName[20];
    double balance;
};

void welcomeScreen(FILE *cfPtr);
void showMenu(FILE *cfPtr);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
void clearScreen();
void exitApp();

int main()
{
    FILE *cfPtr;
    if ((cfPtr = fopen("account.dat", "rb+")) == NULL)
        puts("File could not Opened");
    else 
        welcomeScreen(cfPtr);
}

void welcomeScreen(FILE *cfPtr)
{
    clearScreen();
    printf("\t\t###################################################\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               |      Welcome To     |           #\n");
    printf("\t\t#               |         The         |           #\n");
    printf("\t\t#               |         Bank        |           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t###################################################\n");
    showMenu(cfPtr);
}

void showMenu(FILE *cfPtr)
{
    sleep(3);
    clearScreen();
    printf("\t\t################################################################\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#               -----------------------                        #\n");
    printf("\t\t#               |      Bank Menu      |                        #\n");
    printf("\t\t#               -----------------------                        #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                      Press                                   #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                 -->  1 Store a Formatted Text                #\n");
    printf("\t\t#                        file of Account for Printing          #\n");
    printf("\t\t#                 -->  2 Add New Account                       #\n");
    printf("\t\t#                 -->  3 Update an Account                     #\n");
    printf("\t\t#                 -->  4 Delet and Acccount                    #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                 -->  0 to exit the Program                   #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t################################################################\n");

    char option;
    printf("\t\t\t\t--->: ");
    option = getch();
    option -= 48;
    printf("\n\n\n");
    if (option == 1)
        textFile(cfPtr);
    else if (option == 2)
        newRecord(cfPtr);
    else if (option == 3)
        updateRecord(cfPtr);
    else if (option == 4)
        deleteRecord(cfPtr);
    else if (option == 0)
        exitApp();
    else
        showMenu(cfPtr);
    showMenu(cfPtr);
}

void textFile(FILE *readPtr)
{
    FILE *writePtr;

    if((writePtr = fopen("account.txt", "w")) == NULL)
        puts("File could not Opened");
    else 
    {
        rewind(readPtr);
        fprintf(writePtr, "%-6s%-16s%-11s%10s\n", "Acct", "Last Name", "First Name", "Balance");
        while(!feof(readPtr))
        {
            struct ClientData clinet = {0, "", "", 0.0};
            int result = fread(&clinet, sizeof(struct ClientData), 1, readPtr);

            if(result !=0 && clinet.accountNumber !=0)
                fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n", clinet.accountNumber, clinet.lastName, clinet.firstName, clinet.balance);
        }
        fclose(writePtr);
    }
}

void updateRecord(FILE *fPtr)
{
    unsigned int account;
    printf("%s", "Enter account to update (1-100): ");
    scanf("%d", &account);

    fseek(fPtr, (account - 1) * sizeof(struct ClientData), SEEK_SET);

    struct ClientData client = {0, "", "", 0.0};

    fread(&client, sizeof(struct ClientData), 1, fPtr);

    if(client.accountNumber == 0)
        printf("Account #%d has no information.\n", account);
    else 
    {
        printf("%-6d%-16s%-11s%10.2f\n\n", client.accountNumber, client.lastName, client.firstName, client.balance);

        double transaction;
        printf("%s", "Enter charge (+) or payment (-): ");
        scanf("%lf", &transaction);
        client.balance += transaction;

        printf("%-6d%-16s%-11s%10.2f\n", client.accountNumber, client.lastName, client.firstName, client.balance);

        fseek(fPtr, (account - 1) * sizeof(struct ClientData), SEEK_SET);

        fwrite(&client, sizeof(struct ClientData), 1, fPtr);
    }
}

void deleteRecord(FILE *fPtr)
{
    unsigned int accountNumber;
    printf("%s", "Enter account number to delete (1-100): ");
    scanf("%d", &accountNumber);

    fseek(fPtr, (accountNumber - 1) * sizeof(struct ClientData), SEEK_SET);

    struct ClientData client ;

    fread(&client, sizeof(struct ClientData), 1, fPtr);

    if(client.accountNumber == 0)
        printf("Account #%d Does not Exist.\n", accountNumber);
    else 
    {
        fseek(fPtr, (accountNumber - 1) * sizeof(struct ClientData), SEEK_SET);

        struct ClientData blankClient = {0, "", "", 0.0};

        fwrite(&blankClient, sizeof(struct ClientData), 1, fPtr);
    }
}

void newRecord(FILE *fPtr)
{
    printf("%s", "Enter new account number (1-100): ");
    unsigned int accountNumber;
    scanf("%d", &accountNumber);

    fseek(fPtr, (accountNumber - 1) * sizeof(struct ClientData), SEEK_SET);

    struct ClientData client = {0, "", "", 0.0};

    fread(&client, sizeof(struct ClientData), 1, fPtr);

    if(client.accountNumber != 0)
        printf("Account #%d already contains information.\n", client.accountNumber);
    else 
    {
        printf("%s", "Enter lastname, firstname, balance\n? ");
        scanf("%s%s%lf", client.lastName, client.firstName, &client.balance);

        client.accountNumber = accountNumber;

        fseek(fPtr, (client.accountNumber - 1) * sizeof(struct ClientData), SEEK_SET);

        fwrite(&client, sizeof(struct ClientData), 1, fPtr);
    }
    
}

void clearScreen()
{
    system("cls");
}

void exitApp()
{
    exit(0);
}
