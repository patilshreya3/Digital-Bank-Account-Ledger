#include <stdio.h>
#include <string.h>
#include "bank.h"
#include "cash.h"

void process_deposit() {
    int search_id, found_flag = 0;
    double money;
    
    printf("\nEnter Account Number for Deposit: ");
    scanf("%d", &search_id);

    for (int i = 0; i < total_clients; i++) {
        if (client_list[i].id == search_id) {
            found_flag = 1;
            printf("Enter amount to add: ₹");
            scanf("%lf", &money);
            client_list[i].funds += money; 
            printf("Success! New Balance: ₹%.2f\n", client_list[i].funds);
            break;
        }
    }
    if (found_flag == 0) {
        printf("Alert: Account number does not exist!\n");
    }
}

void process_withdraw() {
    int search_id, found_flag = 0;
    double money;
    
    printf("\nEnter Account Number for Withdrawal: ");
    scanf("%d", &search_id);

    for (int i = 0; i < total_clients; i++) {
        if (client_list[i].id == search_id) {
            found_flag = 1;
            printf("Enter amount to remove: ₹");
            scanf("%lf", &money);
            
            if (money > client_list[i].funds) {
                printf("Transaction Denied! Insufficient balance. Available: ₹%.2f\n", client_list[i].funds);
            } else {
                client_list[i].funds -= money; 
                printf("Success! Remaining Balance: ₹%.2f\n", client_list[i].funds);
            }
            break;
        }
    }
    if (found_flag == 0) {
        printf("Alert: Account number does not exist!\n");
    }
}

void run_interest_loop() {
    for (int i = 0; i < total_clients; i++) {
        if (strcmp(client_list[i].type, "savings") == 0) {
            client_list[i].funds += client_list[i].funds * 0.04;
        } else if (strcmp(client_list[i].type, "current") == 0) {
            client_list[i].funds += client_list[i].funds * 0.02;
        }
    }
    printf("\nAnnual interest rates calculated and applied to all accounts loop updates.\n");
}
