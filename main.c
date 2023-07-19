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
void updateAdminCredentials(FILE *cfPtr);
void viewAllAdminCredentials(FILE *cfPtr);
void UserPanle(FILE *cfPtr);
void checkUserCredentials(FILE *cfPtr);
void showMenu(FILE *cfPtr);
void textFile(FILE *readPtr);
void updateUserCredentials(FILE *fPtr);
int updatRecordMenu(FILE *cfPtr);
void amountWithdraw(FILE *fPtr);
void amountDeposit(FILE *fPtr);
void addNewUserAccount(FILE *fPtr);
void deleteUserAccount(FILE *fPtr);
void viewAllUserRecords(FILE *fPtr);
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
    mainMenu(cfPtr);
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
        checkAdminCredentials(cfPtr);
    mainMenu(cfPtr);
}

void adminPanle(FILE *cfPtr)
{
    clearScreen();
    FILE *adPtr;
    if ((adPtr = fopen("adminCredentials.dat", "rb+")) == NULL)
        puts("File could not Opened");
    else
    {
        clearScreen();
        printf("\t\t################################################################\n");
        printf("\t\t#                                                              #\n");
        printf("\t\t#               -------------------------                      #\n");
        printf("\t\t#               |     Admin Panle Menu  |                      #\n");
        printf("\t\t#               -------------------------                      #\n");
        printf("\t\t#                                                              #\n");
        printf("\t\t#                      Press                                   #\n");
        printf("\t\t#                                                              #\n");
        printf("\t\t#                 -->  1 To Update Admin detail                #\n");
        printf("\t\t#                 -->  2 To View Admin                         #\n");
        printf("\t\t#                                                              #\n");
        printf("\t\t#                 -->  3 To Add New User Account               #\n");
        printf("\t\t#                 -->  4 To Delete User Account                #\n");
        printf("\t\t#                 -->  5 To View All User Account              #\n");
        printf("\t\t#                 -->  6 To Upload User Detail For Print       #\n");
        printf("\t\t#                                                              #\n");
        printf("\t\t#                 -->  9 To MainMenu                           #\n");
        printf("\t\t#                 -->  0 To Exit                               #\n");
        printf("\t\t#                                                              #\n");
        printf("\t\t#                                                              #\n");
        printf("\t\t#                                                              #\n");
        printf("\t\t################################################################\n");
        sleep(1);
        printf("\n");
        printf("\t\t\t\t--->: ");
        char option;
        option = getch();
        option -= 48;
        printf("\n\n\n");
        if (option >= 1 && option <= 7)
        {
            if (option == 1)
                updateAdminCredentials(cfPtr);
            else if (option == 2)
                viewAllAdminCredentials(cfPtr);
            else if (option == 3)
                addNewUserAccount(cfPtr);
            else if (option == 4)
                deleteUserAccount(cfPtr);
            else if (option == 5)
                viewAllUserRecords(cfPtr);
            else if (option == 6)
            {
                textFile(cfPtr);
                printf("\n\n\n\t\t\tUpload Compelet");
                printf("\n\n\t\tPress any key to back to meu");
                getch();
            }
        }
        else if (option == 9)
            mainMenu(cfPtr);
        else if (option == 0)
        {
            exitApp();
            fclose(cfPtr);
        }
        adminPanle(cfPtr);
    }
}

void checkAdminCredentials(FILE *cfPtr)
{
    clearScreen();
    printf("\t\t###################################################\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               |     Admin Login     |           #\n");
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
            mainMenu(cfPtr);
        }
    }
}

void viewAllAdminCredentials(FILE *cfPtr)
{
    printf("\n\n");
    FILE *viewPtr;
    if ((viewPtr = fopen("adminCredentials.dat", "rb")) == NULL)
        puts("File could not Opened");
    else
    {
        printf("%-20s%-20s\n", "AdminUser_Name", "Admin_Password");
        while (!feof(viewPtr))
        {
            struct AdminData admin = {"", ""};
            int result = fread(&admin, sizeof(struct AdminData), 1, viewPtr);
            if (result != 0)
                printf("%-20s%-20s\n", admin.userName, admin.Password);
        }
        fclose(viewPtr);
    }
    printf("\n\n\t\tPress any key to back to meu");
    getch();
}

void updateAdminCredentials(FILE *cfPtr)
{
    clearScreen();
    printf("\t\t###################################################\n");
    printf("\t\t#                                                 #\n");
    printf("\t\t#               -----------------------           #\n");
    printf("\t\t#               |     Admin Update    |           #\n");
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
        printf("\n\t\tEnter New Password: ");
        scanf("%s", Password);
        char temp[20];
        strcpy(temp, Password);
        printf("\n\t\tEnter  Password Again: ");
        scanf("%s", Password);
        if (strcmp(temp, Password) != 0)
        {
            printf("\n\n\n\t\t\tInvalid Password");
            printf("\n\n\t\tPress any key to back to meu");
            getch();
            updateAdminCredentials(cfPtr);
        }
        fseek(adPtr, 0, SEEK_SET);
        struct AdminData admin = {"", ""};
        fread(&admin, sizeof(struct AdminData), 1, adPtr);
        if (strcmp(admin.Password, Password) == 0)
        {
            printf("\n\n\n\t\t\tEnter New Password");
            printf("\n\n\t\tPress any key to back to meu");
            getch();
            updateAdminCredentials(cfPtr);
        }
        else
        {
            strcpy(admin.userName, userName);
            strcpy(admin.Password, Password);
            fseek(adPtr, 0, SEEK_SET);
            fwrite(&admin, sizeof(struct AdminData), 1, adPtr);
            fclose(adPtr);
            printf("\n\n\n\t\tUpdate Compelet");
            printf("\n\n\t\tPress any key to back to meu");
            getch();
        }
    }
}

void UserPanle(FILE *cfPtr)
{
    clearScreen();
    printf("\t\t################################################################\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#               -------------------------                      #\n");
    printf("\t\t#               |     User Panle Menu   |                      #\n");
    printf("\t\t#               -------------------------                      #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                      Press                                   #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                 -->  1 To Deposite Money                     #\n");
    printf("\t\t#                 -->  2 To withdraw Money                     #\n");
    printf("\t\t#                 -->  3 Update an Account                     #\n");
    printf("\t\t#                 -->  4 To Delete an Account                  #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                 -->  9 To MainMenu                           #\n");
    printf("\t\t#                 -->  0 To Exit                               #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t################################################################\n");
    sleep(1);
    printf("\n");
    printf("\t\t\t\t--->: ");
    char option;
    option = getch();
    option -= 48;
    printf("\n\n\n");
    if (option >= 1 && option <= 4)
    {
        if (option == 1)
            amountDeposit(cfPtr);
        else if (option == 2)
            amountWithdraw(cfPtr);
        else if (option == 3)
            updateUserCredentials(cfPtr);
        else if (option == 4)
            deleteUserAccount(cfPtr);
    }
    else if (option == 9)
        mainMenu(cfPtr);
    else if (option == 0)
    {
        exitApp();
        fclose(cfPtr);
    }
    UserPanle(cfPtr);
}

void checkUserCredentials(FILE *cfPtr)
{
    clearScreen();
    printf("\t\t#####################################################\n");
    printf("\t\t#                                                   #\n");
    printf("\t\t#               ---------------------               #\n");
    printf("\t\t#               |   User Login      |               #\n");
    printf("\t\t#               ---------------------               #\n");
    printf("\t\t#                                                   #\n");
    printf("\t\t#####################################################\n");
    sleep(1);
    printf("\n");
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
            showMenu(cfPtr);
        else
        {
            printf("\n\n\n\t\t\tInvalid Credentials");
            printf("\n\n\t\tPress any key to back to meu");
            getch();
            mainMenu(cfPtr);
        }
    }
}

void showMenu(FILE *cfPtr)
{
    clearScreen();
    printf("\t\t################################################################\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#               -----------------------                        #\n");
    printf("\t\t#               |      User Menu      |                        #\n");
    printf("\t\t#               -----------------------                        #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                      Press                                   #\n");
    printf("\t\t#                                                              #\n");
    printf("\t\t#                 -->  1 To Deposite Money                     #\n");
    printf("\t\t#                 -->  2 To withdraw Money                     #\n");
    printf("\t\t#                 -->  3 Update an Account                     #\n");
    printf("\t\t#                 -->  4 To Delete an Account                  #\n");
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
            updateUserCredentials(cfPtr);
        else if (option == 4)
            deleteUserAccount(cfPtr);
    }
    else if (option == 0)
    {
        exitApp();
        fclose(cfPtr);
    }
    showMenu(cfPtr);
}

void viewAllUserRecords(FILE *fPtr)
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

void updateUserCredentials(FILE *fPtr)
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
        viewAllUserRecords(cfPtr);
    else if (option == 0)
        showMenu(cfPtr);
}

void deleteUserAccount(FILE *fPtr)
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

void addNewUserAccount(FILE *fPtr)
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
