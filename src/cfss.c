
//main.c
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "library.h"

int pin=123, id =123456, tid,tpin;
void user_reg() {
    struct User user;
    FILE *fg;
    long tmobile, tfmob;
    char tname[100], tcall_s_type[100], tservice_s[100];
    int spin;

    printf("\n................USER REGISTRATION PAGE...................\n");

    // Get user input
    printf("\n Enter the Source Number (Mobile Number) : ");
    scanf("%ld", &user.source);

    printf("\n Enter the Destination Number (Forwarded Number) : ");
    scanf("%ld", &user.desti);

    printf("\n Your name: ");
    scanf("%s", user.name);

    // Get PIN and validate
    bool valid_pin = false;
    while (!valid_pin) {
        printf("\n Your pin (8 digits only): ");
        scanf("%8s", user.pin);
        if (validate_pin(user.pin)) {
            valid_pin = true;
        } else {
            printf("\n Invalid PIN format. Please enter 8 digits.\n");
        }
    }

    // Enable or disable call forwarding
    char choice;
    printf("\n Enable call forwarding? (Y/N): ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        enable_call_forwarding(&user);
    } else {
        disable_call_forwarding(&user);
    }

    printf("\n------------------------------------------------\n");

    // Open the file for reading
    fg = fopen("user1.txt", "r");
    if (fg == NULL) {
        printf("Error opening the file for reading.\n");
        return;
    }

    // Check if the source number is already registered
    int alreadyRegistered = 0;
    while (fscanf(fg, "%ld|%ld|%99[^|]|%99[^|]|%99[^|]|%d%*[\n]", &tmobile, &tfmob, tname, tcall_s_type, tservice_s, &spin) == 6) {
        if (user.source == tmobile) {
            printf("\n This Source Number is Already Registered!!!\n");
            printf("\n Try with another Source Number.\n");
            alreadyRegistered = 1;
            break;
        }
    }
    fclose(fg);

    // If the source number is not registered, update user data
    if (!alreadyRegistered) {
        // Open the file for appending
        fg = fopen("user1.txt", "a+");
        if (fg == NULL) {
            printf("Could not open file.\n");
            exit(1);
        }

        char ed;
        if(user.call_forwarding_enabled==true){
                ed='E';
        }
        else{
                ed='D';
        }
        fprintf(fg, "%ld|%ld|%s|%s|%c\n", user.source, user.desti, user.name, ed);
        fclose(fg);
        printf("\n**********************************************\n");
        printf("\nYou Registered as a User Successfully...");
        printf("\n**********************************************\n");
    }
}


bool validate_pin(const char *pin) {
    // Check if the PIN is 8 digits long and contains only digits
    if (strlen(pin) != 8) {
        return false;
    }
    for (int i = 0; i < 8; i++) {
        if (!isdigit(pin[i])) {
            return false;
        }
    }
    return true;
}

void enable_call_forwarding(struct User *user) {
    user->call_forwarding_enabled = true;
    printf("\n Call forwarding enabled.\n");
}

void disable_call_forwarding(struct User *user) {
    user->call_forwarding_enabled = false;
    printf("\n Call forwarding disabled.\n");
}

void admin_login(){
        printf("\n................ADMIN LOGIN PAGE...................\n");
        printf("\n Enter Admin ID : ");
        scanf("%ld",&tid);
        printf(" Enter Admin Pin : ");
        scanf("%d",&tpin);

        if((tid==id)&&(tpin==pin))
        {
                printf("\n Login as Admin Successfully.....\n");
        }
        else
        {
                printf("\n Invalid  Admin ID or Pin Try Again....\n");

        }
}

void select_op() {
    int op;

    printf("\n*         SELECT AN OPTION         *");
    printf("\n************************************");
    printf("\n 1. Admin Login");
    printf("\n 2. User Registration");
    printf("\n 3. User Login");
    printf("\n************************************\n");
    printf("\nEnter your choice: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
            admin_login();
            break;
        case 2:
            user_reg();
            break;
        case 3:
           // user_login();
            break;
        default:
            printf("\nInvalid choice! Please enter a valid option.\n");
            break;
    }
}

int main() {
    printf("\n****** WELCOME TO CALL FORWARDING SYSTEM ****\n");
    printf("----------------------------------------------\n");
    select_op();
    return 0;
}




//library.h

#define CALL_FORWARDING_H

#include <stdbool.h>

struct User {
    long source;
    long desti;
    char name[30];
    char pin[9]; // Increased size to accommodate null terminator
    bool call_forwarding_enabled; // Flag to indicate whether call forwarding is enabled
};

void user_reg();
void select_op();
bool validate_pin(const char *pin);
void enable_call_forwarding(struct User *user);
void disable_call_forwarding(struct User *user);

