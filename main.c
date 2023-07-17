#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

struct AdminData
{
    char userName[20];
    char Password[20];
};

struct ClientData
{
    unsigned int accountNumber;
    char lastName[20];
    char firstName[20];
    double balance;
    int pinCode;
};

void welcomeScreen(FILE *cfPtr);
void mainMenu(FILE *cfPtr);
void adminPanle(FILE *cfPtr);
void checkAdminCredentials(FILE *cfPtr);
void adminRegister(FILE *cfPtr);
void updateAdminCredentials(FILE *cfPtr);
void deleteAdminCredentials(FILE *cfPtr);
void UserPanle(FILE *cfPtr);
void loginScreen(FILE *cfPtr);
bool checkCredentials(FILE *cfPtr);
void showMenu(FILE *cfPtr);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
int updatRecordMenu(FILE *cfPtr);
void amountWithdraw(FILE *fPtr);
void amountDeposit(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);
void viewAllRecord(FILE *fPtr);
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
    printf("\t\t#               |        The          |           #\n");
    printf("\t\t#               |        Bank         |           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t###################################################\n");
    sleep(3);
    loginScreen(cfPtr);
}

void mainMenu(FILE *cfPtr)
{
    clearScreen();
    printf("\t\t################################################################\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#               -----------------------                        #\n");
    printf("\t\t#               |      Main Menu      |                        #\n");
    printf("\t\t#               -----------------------                        #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                      Press                                   #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                 -->  1 For Customer                          #\n");
    printf("\t\t#                 -->  2 For Admin                             #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                 -->  0 To Exit                               #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t################################################################\n");

    char option;
    printf("\t\t\t\t--->: ");
    option = getch();
    option -= 48;
    printf("\n\n\n");
    if (option == 1)
        UserPanle(cfPtr);
    if (option == 2)
        adminPanle(cfPtr);
    mainMenu(cfPtr);
}



void adminPanle(FILE *cfPtr)
{
    FILE *adPtr;
    if ((adPtr = fopen("adminCredentials.dat", "rb+")) == NULL)
        puts("File could not Opened");
    else
    {
        clearScreen();
        printf("\t\t###################################################\n");
        printf("\t\t#                                                 #\n");
        printf("\t\t#               -----------------------           #\n");
        printf("\t\t#               |     Admin Panle     |           #\n");
        printf("\t\t#               -----------------------           #\n");
        printf("\t\t#                                                 #\n");
        printf("\t\t###################################################\n");
        sleep(1);
    }
}

void checkAdminCredentials(FILE *cfPtr)
{
    clearScreen();
    printf("\t\t###################################################\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               |     Admin Login      |           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t###################################################\n");
    sleep(1);
    printf("\n");
    FILE *adPtr;
    if ((adPtr = fopen("adminCredentials.dat", "rb+")) == NULL)
        puts("File could not Opened");
    else
    {
        char userName[20];
        char Password[20];
        printf("%s", "\t\tEnter User Name: ");
        scanf("%s", userName);
        printf("\n\t\tEnter Password: ");
        scanf("%s", Password);
        fseek(adPtr, 0, SEEK_SET);
        struct AdminData admin = {"", ""};
        fread(&admin, sizeof(struct AdminData), 1, adPtr);
        if (strcmp(admin.userName, userName) == 0 && strcmp(admin.Password, Password) == 0)
            adminPanle(cfPtr);
        else
        {
            printf("\n\n\n\t\t\tInvalid Credentials");
            printf("\n\n\t\tPress any key to back to meu");
            getch();
            checkAdminCredentials(cfPtr);
        }
    }
}

void adminRegister(FILE *cfPtr)
{
    clearScreen();
    printf("\t\t###################################################\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               |     Admin Register   |           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t###################################################\n");
    sleep(1);
    printf("\n");
    FILE *adPtr;
    if ((adPtr = fopen("adminCredentials.dat", "rb+")) == NULL)
        puts("File could not Opened");
    else
    {
        char userName[20];
        char Password[20];
        printf("%s", "\t\tEnter User Name: ");
        scanf("%s", userName);
        printf("\n\t\tEnter Password: ");
        scanf("%s", Password);
        fseek(adPtr, 0, SEEK_SET);
        struct AdminData admin = {"", ""};
        fread(&admin, sizeof(struct AdminData), 1, adPtr);
        if (strcmp(admin.userName, userName) == 0)
        {
            printf("\n\n\n\t\t\tUser Name Already Exist");
            printf("\n\n\t\tPress any key to back to meu");
            getch();
            adminRegister(cfPtr);
        }
        else
        {
            strcpy(admin.userName, userName);
            strcpy(admin.Password, Password);
            fseek(adPtr, 0, SEEK_SET);
            fwrite(&admin, sizeof(struct AdminData), 1, adPtr);
            printf("\n\n\n\t\t\tRegister Compelet");
            printf("\n\n\t\tPress any key to back to meu");
            getch();
        }
    }
}

void updateAdminCredentials(FILE *cfPtr)
{
    clearScreen();
    printf("\t\t###################################################\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               |     Update Admin     |           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t###################################################\n");
    sleep(1);
    printf("\n");
    FILE *adPtr;
    if ((adPtr = fopen("adminCredentials.dat", "rb+")) == NULL)
        puts("File could not Opened");
    else
    {
        char userName[20];
        char Password[20];
        printf("%s", "\t\tEnter User Name: ");
        scanf("%s", userName);
        printf("\n\t\tEnter Password: ");
        scanf("%s", Password);
        fseek(adPtr, 0, SEEK_SET);
        struct AdminData admin = {"", ""};
        fread(&admin, sizeof(struct AdminData), 1, adPtr);
        if (strcmp(admin.userName, userName) == 0 && strcmp(admin.Password, Password) == 0)
        {
            printf("\n\n\n\t\t\tUser Name Already Exist");
            printf("\n\n\t\tPress any key to back");
            getch();
            adminRegister(cfPtr);
        }
        else
        {
            strcpy(admin.userName, userName);
            strcpy(admin.Password, Password);
            fseek(adPtr, 0, SEEK_SET);
            fwrite(&admin, sizeof(struct AdminData), 1, adPtr);
            printf("\n\n\n\t\t\tUpdate Compelet");
            printf("\n\n\t\tPress any key to back to meu");
            getch();
        }
    }
}

void deleteAdminCredentials(FILE *cfPtr)
{

}

void UserPanle(FILE *cfPtr)
{
}

void loginScreen(FILE *cfPtr)
{
    clearScreen();
    printf("\t\t###################################################\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               |    Login Screen     |           #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t###################################################\n");
    sleep(1);
    printf("\n");
    if (checkCredentials(cfPtr))
        showMenu(cfPtr);
    else
    {
        printf("\n\n\n\t\t\tInvalid Credentials");
        printf("\n\n\t\tPress any key to back to meu");
        getch();
        loginScreen(cfPtr);
    }
}

bool checkCredentials(FILE *cfPtr)
{
    if ((cfPtr = fopen("account.dat", "rb+")) == NULL)
        puts("File could not Opened");
    else
    {
        unsigned int accountNumber;
        printf("%s", "\t\tEnter account number (1-100): ");
        scanf("%d", &accountNumber);
        printf("\n\t\tEnter Five(5) digit Pin Code: ");
        int pinCode;
        scanf("%d", &pinCode);
        fseek(cfPtr, (accountNumber - 1) * sizeof(struct ClientData), SEEK_SET);
        struct ClientData client = {0, "", "", 0.0, 0};
        fread(&client, sizeof(struct ClientData), 1, cfPtr);
        if (client.accountNumber != 0 && client.pinCode == pinCode)
            return true;
        else
            return false;
    }
}

void showMenu(FILE *cfPtr)
{
    clearScreen();
    printf("\t\t################################################################\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#               -----------------------                        #\n");
    printf("\t\t#               |      Bank Menu      |                        #\n");
    printf("\t\t#               -----------------------                        #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                      Press                                   #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                 -->  1 To Deposite Money                     #\n");
    printf("\t\t#                 -->  2 To withdraw Money                     #\n");
    printf("\t\t#                 -->  3 Add New Account                       #\n");
    printf("\t\t#                 -->  4 Update an Account                     #\n");
    printf("\t\t#                 -->  5 Delet and Acccount                    #\n");
    printf("\t\t#                 -->  6 view all Acccounts Record             #\n");
    printf("\t\t#                 -->  7 Store a Formatted Text                #\n");
    printf("\t\t#                        file of Account for Printing          #\n");
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
    if (option >= 1 && option <= 7)
    {
        if (option == 1)
            amountDeposit(cfPtr);
        else if (option == 2)
            amountWithdraw(cfPtr);
        else if (option == 3)
            newRecord(cfPtr);
        else if (option == 4)
            updateRecord(cfPtr);
        else if (option == 5)
            deleteRecord(cfPtr);
        else if (option == 6)
            viewAllRecord(cfPtr);
        else if (option == 7)
        {
            textFile(cfPtr);
            printf("\n\n\n\t\t\tUpload Compelet");
            printf("\n\n\t\tPress any key to back to meu");
            getch();
        }
    }
    else if (option == 0)
    {
        exitApp();
        fclose(cfPtr);
    }
    showMenu(cfPtr);
}

void viewAllRecord(FILE *fPtr)
{
    textFile(fPtr);
    FILE *viewPtr;
    if ((viewPtr = fopen("account.dat", "rb")) == NULL)
        puts("File could not Opened");
    else
    {
        printf("%-20s%-19s%-19s%10s\n", "Account Number", "Last Name", "First Name", "Balance");
        while (!feof(viewPtr))
        {
            struct ClientData clinet = {0, "", "", 0.0};
            int result = fread(&clinet, sizeof(struct ClientData), 1, viewPtr);
            if (result != 0 && clinet.accountNumber != 0)
                printf("%-20d%-19s%-19s%10.2f\n", clinet.accountNumber, clinet.lastName, clinet.firstName, clinet.balance);
        }
        fclose(viewPtr);
    }
    printf("\n\n\t\tPress any key to back to meu");
    getch();
}

void textFile(FILE *readPtr)
{
    FILE *writePtr;

    if ((writePtr = fopen("account.txt", "w")) == NULL)
        puts("File could not Opened");
    else
    {
        rewind(readPtr);
        fprintf(writePtr, "%-20s%-19s%-19s%-10s%-5s\n", "Account Number", "Last Name", "First Name", "Balance", "Pin Code");
        while (!feof(readPtr))
        {
            struct ClientData clinet = {0, "", "", 0.0, 0};
            int result = fread(&clinet, sizeof(struct ClientData), 1, readPtr);

            if (result != 0 && clinet.accountNumber != 0)
                fprintf(writePtr, "%-20d%-19s%-19s%10.2f%-5d\n", clinet.accountNumber, clinet.lastName, clinet.firstName, clinet.balance, clinet.pinCode);
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
    if (client.accountNumber == 0)
    {
        printf("\n\t\tAccount #%d has no information.\n", account);
        printf("\n\n\t\tPress any key to back to meu");
        getch();
        return;
    }
    else
    {
        int option = updatRecordMenu(fPtr);
        if (option == 1)
        {
            printf("%-10d%-19s%-19s%10.2f\n\n", client.accountNumber, client.lastName, client.firstName, client.balance);
            char name[20];
            printf("Please Enter the First Name again:  ");
            scanf("%s", name);
            // strcpy(client.firstName, name);
            strcpy(client.lastName, name);
            printf("%-10d%-19s%-19s%10.2f\n", client.accountNumber, client.lastName, client.firstName, client.balance);
            fseek(fPtr, (account - 1) * sizeof(struct ClientData), SEEK_SET);
            fwrite(&client, sizeof(struct ClientData), 1, fPtr);
        }
        else if (option == 2)
        {
            printf("%-10d%-19s%-19s%10.2f\n\n", client.accountNumber, client.lastName, client.firstName, client.balance);
            char name[20];
            printf("Please Enter the Last Name again:  ");
            scanf("%s", name);
            strcpy(client.firstName, name);
            // strcpy(client.lastName, name);
            printf("%-10d%-19s%-19s%10.2f\n", client.accountNumber, client.lastName, client.firstName, client.balance);
            fseek(fPtr, (account - 1) * sizeof(struct ClientData), SEEK_SET);
            fwrite(&client, sizeof(struct ClientData), 1, fPtr);
        }
        else if (option == 3)
        {
            printf("%-10d%-19s%-19s%10.2f\n\n", client.accountNumber, client.lastName, client.firstName, client.balance);
            double transaction;
            printf("%s", "Enter charge (+) or payment (-): ");
            scanf("%lf", &transaction);
            client.balance += transaction;
            printf("%-10d%-19s%-19s%10.2f\n", client.accountNumber, client.lastName, client.firstName, client.balance);
            fseek(fPtr, (account - 1) * sizeof(struct ClientData), SEEK_SET);
            fwrite(&client, sizeof(struct ClientData), 1, fPtr);
        }
    }
    printf("\n\n\n\t\t\tUpdate The Account successfully");
    printf("\n\n\t\tPress any key to back to meu");
    getch();
}

int updatRecordMenu(FILE *cfPtr)
{
    clearScreen();
    printf("\t\t################################################################\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#               -----------------------                        #\n");
    printf("\t\t#               |      Update Menu    |                        #\n");
    printf("\t\t#               -----------------------                        #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                      Press                                   #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                 -->  1 Update First Name                     #\n");
    printf("\t\t#                 -->  2 Update Last Name                      #\n");
    printf("\t\t#                 -->  3 Update Pin Code                       #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                 -->  4 view all Acccounts Record             #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                 -->  0 to Bank Menu                          #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t################################################################\n");
    char option;
    printf("\t\t\t\t--->: ");
    option = getch();
    option -= 48;
    printf("\n\n\n");
    if (option >= 1 && option <= 3)
        return (int)option;
    else if (option == 4)
        viewAllRecord(cfPtr);
    else if (option == 0)
        showMenu(cfPtr);
}

void deleteRecord(FILE *fPtr)
{
    // checkCredentials(fPtr);
    unsigned int accountNumber;
    printf("%s", "Enter account number to delete (1-100): ");
    scanf("%d", &accountNumber);
    fseek(fPtr, (accountNumber - 1) * sizeof(struct ClientData), SEEK_SET);
    struct ClientData client;
    fread(&client, sizeof(struct ClientData), 1, fPtr);
    if (client.accountNumber == 0)
        printf("Account #%d Does not Exist.\n", accountNumber);
    else
    {
        fseek(fPtr, (accountNumber - 1) * sizeof(struct ClientData), SEEK_SET);
        struct ClientData blankClient = {0, "", "", 0.0, 0};
        fwrite(&blankClient, sizeof(struct ClientData), 1, fPtr);
    }
    printf("\n\n\n\t\tDelete The Account successfully");
    printf("\n\n\t\tPress any key to back to meu");
    getch();
}

void newRecord(FILE *fPtr)
{
    printf("%s", "Enter new account number (1-100): ");
    int accountNumber;
    scanf("%d", &accountNumber);

    printf("\nEnter Five(5) digit Pin Code: ");
    int pinCode;
    scanf("%d", &pinCode);
    fseek(fPtr, (accountNumber - 1) * sizeof(struct ClientData), SEEK_SET);
    struct ClientData client = {0, "", "", 0.0, 0};
    fread(&client, sizeof(struct ClientData), 1, fPtr);
    if (client.accountNumber != 0)
        printf("Account #%d already contains information.\n", client.accountNumber);
    else
    {
        printf("%s", "Enter lastname: ");
        scanf("%s", client.lastName);
        printf("%s", "Enter firstname: ");
        scanf("%s", client.firstName);
        printf("%s", "Enter balance: ");
        scanf("%lf", &client.balance);
        client.pinCode = pinCode;
        client.accountNumber = accountNumber;
        fseek(fPtr, (client.accountNumber - 1) * sizeof(struct ClientData), SEEK_SET);
        fwrite(&client, sizeof(struct ClientData), 1, fPtr);
    }
    printf("\n\n\n\t\t\tNew Account added successfully");
    printf("\n\n\t\tPress any key to back to meu");
    getch();
}

void amountWithdraw(FILE *fPtr)
{
    unsigned int account;
    printf("%s", "Enter account to Withdraw (1-100): ");
    scanf("%d", &account);
    fseek(fPtr, (account - 1) * sizeof(struct ClientData), SEEK_SET);
    struct ClientData client = {0, "", "", 0.0};
    fread(&client, sizeof(struct ClientData), 1, fPtr);
    if (client.accountNumber == 0)
    {
        printf("\n\t\tAccount #%d has no information.\n", account);
        printf("\n\n\t\tPress any key to back to meu");
        getch();
        return;
    }
    else
    {
        printf("%-10d%-19s%-19s%10.2f\n\n", client.accountNumber, client.lastName, client.firstName, client.balance);
        double transaction;
        printf("%s", "Enter The Amount to Withdraw: ");
        scanf("%lf", &transaction);
        if (client.balance < transaction)
        {
            printf("\n\n\t\t\tInsufficient Balance");
            printf("\n\n\t\tPress any key to back to meu");
            getch();
            return;
        }
        client.balance += transaction;
        printf("%-10d%-19s%-19s%10.2f\n", client.accountNumber, client.lastName, client.firstName, client.balance);
        fseek(fPtr, (account - 1) * sizeof(struct ClientData), SEEK_SET);
        fwrite(&client, sizeof(struct ClientData), 1, fPtr);
    }
    printf("\n\n\n\t\t\tWithdraw The Account successfully");
    printf("\n\n\t\tPress any key to back to meu");
    getch();
}
void amountDeposit(FILE *fPtr)
{
    unsigned int account;
    printf("%s", "Enter account to Deposit (1-100): ");
    scanf("%d", &account);
    fseek(fPtr, (account - 1) * sizeof(struct ClientData), SEEK_SET);
    struct ClientData client = {0, "", "", 0.0};
    fread(&client, sizeof(struct ClientData), 1, fPtr);
    printf("%-10d%-19s%-19s%10.2f\n\n", client.accountNumber, client.lastName, client.firstName, client.balance);
    double transaction;
    printf("%s", "Enter charge (+) or payment (-): ");
    scanf("%lf", &transaction);
    client.balance += transaction;
    printf("%-10d%-19s%-19s%10.2f\n", client.accountNumber, client.lastName, client.firstName, client.balance);
    fseek(fPtr, (account - 1) * sizeof(struct ClientData), SEEK_SET);
    fwrite(&client, sizeof(struct ClientData), 1, fPtr);
    printf("\n\n\n\t\t\tDeposit The Account successfully");
    printf("\n\n\t\tPress any key to back to meu");
    getch();
}

void clearScreen()
{
    system("cls");
}

void exitApp()
{
    exit(0);
}
