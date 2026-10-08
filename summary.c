#include <stdio.h>
#include "bank.h"
#include "summary.h"

void check_extremes() {
    if (total_clients == 0) {
        printf("\nDatabase is empty.\n");
        return;
    }
    
    int top_idx = 0;
    int bottom_idx = 0;

    for (int i = 1; i < total_clients; i++) {
        if (client_list[i].funds > client_list[top_idx].funds) {
            top_idx = i;
        }
        if (client_list[i].funds < client_list[bottom_idx].funds) {
            bottom_idx = i;
        }
    }
    
    printf("\n=== ACCOUNT METRICS REPORT ===\n");
    printf("Highest Balance Account -> No: %d | Name: %s | Balance: ₹%.2f\n", 
           client_list[top_idx].id, client_list[top_idx].name, client_list[top_idx].funds);
    printf("Lowest Balance Account  -> No: %d | Name: %s | Balance: ₹%.2f\n", 
           client_list[bottom_idx].id, client_list[bottom_idx].name, client_list[bottom_idx].funds);
}

void trigger_low_alerts() {
    int alert_counter = 0;
    
    printf("\n=== MINIMUM BASELINE WARNINGS (< ₹1000) ===\n");
    for (int i = 0; i < total_clients; i++) {
        if (client_list[i].funds < 1000.0) {
            printf("Warning Notice! Acc ID: %d (%s) drops below standard: ₹%.2f\n", 
                   client_list[i].id, client_list[i].name, client_list[i].funds);
            alert_counter++;
        }
    }
    printf("Total registered accounts breaking threshold limits: %d\n", alert_counter);
}

