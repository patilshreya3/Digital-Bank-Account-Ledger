#ifndef BANK_H
#define BANK_H

#define MAX_RECORDS 500

struct UserAccount {
    int id;
    char name[50];
    char type[20]; 
    double funds;
};

extern struct UserAccount client_list[MAX_RECORDS];
extern int total_clients;

void create_records();
void show_records();

#endif
