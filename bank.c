#include <stdio.h>
#include "bank.h"

struct UserAccount client_list[MAX_RECORDS];
int total_clients = 0;

void create_records() {
    printf("Enter total number of accounts to manage: ");
    scanf("%d", &total_clients);

    for (int i = 0; i < total_clients; i++) {
        printf("\n--- Account Registration %d ---\n", i + 1);
        printf("Enter Account Number: ");
        scanf("%d", &client_list[i].id);
        
        printf("Enter Holder Name: ");
        scanf("%s", client_list[i].name);
        
        printf("Enter Account Type (savings/current): ");
        scanf("%s", client_list[i].type);
        
        printf("Enter Opening Balance: ₹");
        scanf("%lf", &client_list[i].funds);
    }
    printf("\nSuccess: Saved %d account records.\n", total_clients);
}

void show_records() {
    if (total_clients == 0) {
        printf("\nNo database records found.\n");
        return;
    }
    printf("\n=== BANKING CLIENT DATABASE ===\n");
    for (int i = 0; i < total_clients; i++) {
        printf("ID: %d | Holder: %s | Type: %s | Balance: ₹%.2f\n",
               client_list[i].id, client_list[i].name, client_list[i].type, client_list[i].funds);
    }
}
