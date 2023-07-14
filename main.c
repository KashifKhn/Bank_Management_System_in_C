#include <stdio.h>


struct ClientData
{
    unsigned int accountNumber;
    char lastName[20];
    char firstName[20];
    double balance;
};

unsigned int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);

int main()
{
    FILE *cfPtr;
    if ((cfPtr = fopen("account.dat", "rb+")) == NULL)
        puts("File could not Opened");
    else 
    {
        unsigned int choice;
        while ((choice = enterChoice()) != 5)
        {
            switch (choice)
            {
            case 1:
                textFile(cfPtr);
                break;
            case 2:
                updateRecord(cfPtr);
                break;
            case 3:
                newRecord(cfPtr);
                break;
            case 4:
                deleteRecord(cfPtr);
                break;
            default:
                puts("Incorrect Choice");
                break;
            }
        }
        fclose(cfPtr);
    }

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
unsigned int enterChoice(void)
{
    unsigned int menuChoice;
    printf("%s", "\nEnter your choice\n"
                "1 - store a formatted text file of accounts called\n"
                "    \"accounts.txt\" for printing\n"
                "2 - update an account\n"
                "3 - add a new account\n"
                "4 - delete an account\n"
                "5 - end program\n? ");
    scanf("%u", &menuChoice);
    return menuChoice;
}