#include <stdio.h>
#include "bank.h"
#include "cash.h"
#include "summary.h"

int main() {
    int user_action;
    
    printf("============================================\n");
    printf("        BANK ACCOUNT MANAGEMENT SYSTEM      \n");
    printf("============================================\n");
    
    create_records();

    do {
        printf("\n--- OPERATION SERVICE PANEL ---\n");
        printf("1. Deposit Cash\n");
        printf("2. Withdraw Cash\n");
        printf("3. Execute Annual Interest\n");
        printf("4. Display High/Low Account Audits\n");
        printf("5. Scan for Minimum Balance Alerts\n");
        printf("6. View Entire System Database\n");
        printf("7. Shutdown App\n");
        printf("--------------------------------------------\n");
        printf("Select Option (1-7): ");
        scanf("%d", &user_action);

        switch(user_action) {
            case 1: process_deposit(); break;
            case 2: process_withdraw(); break;
            case 3: run_interest_loop(); break;
            case 4: check_extremes(); break;
            case 5: trigger_low_alerts(); break;
            case 6: show_records(); break;
            case 7: printf("\nClosing application services... Goodbye!\n"); break;
            default: printf("\nInvalid Selection! Please input numbers between 1 and 7.\n");
        }
    } while (user_action != 7);

    return 0;
}

