#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int customer_id;
    char name[50];
    char address[100];
} Customer;

typedef struct {
    int account_number;
    int customer_id;
    double balance;
} Account;

typedef struct {
    int transaction_id;
    int account_number;
    char type; // 'D' for deposit, 'W' for withdrawal
    double amount;
} Transaction;

#define MAX_CUSTOMERS 100
#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 100

Customer* customers[MAX_CUSTOMERS];
int num_customers = 0;
Account* accounts[MAX_ACCOUNTS];
int num_accounts = 0;
Transaction* transactions[MAX_TRANSACTIONS];
int num_transactions = 0;

// Create a new customer
Customer* createCustomer(int customer_id, const char* name, const char* address) {
    Customer* customer = (Customer*)malloc(sizeof(Customer));
    if (customer != NULL) {
        customer->customer_id = customer_id;
        strncpy(customer->name, name, sizeof(customer->name));
        strncpy(customer->address, address, sizeof(customer->address));
    }
    return customer;
}

// Create a new account
Account* createAccount(int account_number, int customer_id, double balance) {
    Account* account = (Account*)malloc(sizeof(Account));
    if (account != NULL) {
        account->account_number = account_number;
        account->customer_id = customer_id;
        account->balance = balance;
    }
    return account;
}

// Create a new transaction
Transaction* createTransaction(int transaction_id, int account_number, char type, double amount) {
    Transaction* transaction = (Transaction*)malloc(sizeof(Transaction));
    if (transaction != NULL) {
        transaction->transaction_id = transaction_id;
        transaction->account_number = account_number;
        transaction->type = type;
        transaction->amount = amount;
    }
    return transaction;
}

// Add customer to array
void addCustomer(Customer* customer) {
    if (num_customers < MAX_CUSTOMERS) {
        customers[num_customers++] = customer;
    } else {
        printf("Maximum number of customers reached.\n");
    }
}

// Add account to array
void createNewAccount(Account* account) {
    if (num_accounts < MAX_ACCOUNTS) {
        accounts[num_accounts++] = account;
    } else {
        printf("Maximum number of accounts reached.\n");
    }
}

// Perform transaction
void performTransaction(Transaction* transaction) {
    if (num_transactions < MAX_TRANSACTIONS) {
        transactions[num_transactions++] = transaction;

        for (int i = 0; i < num_accounts; i++) {
            if (accounts[i]->account_number == transaction->account_number) {
                if (transaction->type == 'D') {
                    accounts[i]->balance += transaction->amount;
                    return;
                } else if (transaction->type == 'W') {
                    if (accounts[i]->balance >= transaction->amount) {
                        accounts[i]->balance -= transaction->amount;
                    } else {
                        printf("Insufficient balance.\n");
                    }
                    return;
                } else {
                    printf("Invalid transaction type.\n");
                    return;
                }
            }
        }
        printf("Account %d not found.\n", transaction->account_number);
    } else {
        printf("Transaction limit reached.\n");
    }
}

// Display account info
void displayAccountInformation(int account_number) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i]->account_number == account_number) {
            printf("Account Number: %d\n", accounts[i]->account_number);
            printf("Customer ID: %d\n", accounts[i]->customer_id);
            printf("Balance: %.2lf\n", accounts[i]->balance);
            return;
        }
    }
    printf("Account %d not found.\n", account_number);
}

// Cleanup memory
void cleanupMemory() {
    for (int i = 0; i < num_customers; i++) {
        free(customers[i]);
    }
    for (int i = 0; i < num_accounts; i++) {
        free(accounts[i]);
    }
    for (int i = 0; i < num_transactions; i++) {
        free(transactions[i]);
    }
}

// Main function (for demonstration)
int main() {
    Customer* cust = createCustomer(1, "John Doe", "123 Main St");
    addCustomer(cust);

    Account* acc = createAccount(1001, 1, 500.0);
    createNewAccount(acc);

    Transaction* trans1 = createTransaction(1, 1001, 'D', 200.0);
    performTransaction(trans1);

    Transaction* trans2 = createTransaction(2, 1001, 'W', 100.0);
    performTransaction(trans2);

    displayAccountInformation(1001);

    cleanupMemory();
    return 0;
}
