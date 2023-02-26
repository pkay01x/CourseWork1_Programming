



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
// ANSI escape codes for colors and formatting
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_CYN     "\e[0;36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_BOLD_ON       "\x1b[1m"
#define ANSI_BOLD_OFF      "\x1b[22m"





// Function to encrypt the message
void encrypt(char *message, int key) {
    char ch;
    int i;

    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        // Encrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
        // Encrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
    }
}

// Function to decrypt the message
void decrypt(char *message, int key) {
    char ch;
    int i;

    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        // Decrypt uppercase letters
        if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if(ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
            message[i] = ch;
        }
        // Decrypt lowercase letters
        else if(ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if(ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
            message[i] = ch;
        }
    }
}




int main() {
    char message[MAX_SIZE];
    int key;
    int choice;

    // Clearing the screen
    printf("\033[2J\033[1;1H");

    // Header
    printf(ANSI_COLOR_YELLOW ANSI_BOLD_ON);
    printf("====================================================\n");
    printf("        WELCOME TO THE STRING ENCRYPTION TOOL       \n");
    printf("====================================================\n");
    printf(ANSI_COLOR_RESET);

    // Ask the user whether they want to encrypt or decrypt the message
    printf(ANSI_COLOR_GREEN ANSI_BOLD_ON);
    printf("\n");
    printf("============== Please select an option =============\n");
    printf("=               1. Encrypt A Message               =\n");
    printf("=               2. Decrypt A Message               =\n");
    printf("                > ");
    scanf("%d", &choice);
    printf("=                                                  =");
    printf("\n====================================================\n");
    

    // Input the message and the key
    printf("\n");
    printf("====================================================\n");
    printf("=                                                  =\n");
    printf("=        Please Enter The Message To %s       =\n         >  ", choice == 1 ? "Encrypt" : "Decrypt");
    getchar(); 
    
    fgets(message, MAX_SIZE, stdin);
    printf("\n=                                                  =\n");
    printf("=        Enter The Encryption/Decryption Key       =\n         >  ");
    scanf("%d", &key);  
    printf("=                                                  =\n");
    printf("====================================================\n");



    // Encrypt or decrypt the message based on the user's choice
    if (choice == 1) {
        encrypt(message, key);
        printf("\n");
        printf("====================================================\n");
        printf("=                 Encrypted Message                =\n");
        printf("\n");
        printf("  %s", message);
        printf("\n");
        printf("=                                                  =\n");
        printf("====================================================\n");
    } else if (choice == 2) {
        decrypt(message, key);
        printf("\n");
        printf("====================================================\n");
        printf("=                 Decrypted Message                =\n");
        printf("\n");
        printf("  %s", message);
        printf("\n");
        printf("=                                                  =\n");
        printf("====================================================\n");
    } else {
        printf(ANSI_COLOR_RED ANSI_BOLD_ON);
         printf("\n");
        printf("====================================================\n");
        printf("                  Invalid choice.\n");
         printf("\n");
        printf("====================================================\n");
        printf(ANSI_COLOR_RESET);
    }
    printf(ANSI_COLOR_RESET);


    // Footer 
    printf(ANSI_COLOR_YELLOW ANSI_BOLD_ON);
    printf("\n");
    printf("====================================================\n");
    printf("          THANK YOU FOR USING OUR TOOL!              \n");
    printf("====================================================\n");
    printf(ANSI_COLOR_RESET);

    printf(ANSI_COLOR_CYN ANSI_BOLD_ON);
    printf("\n");
    printf("====================================================\n");
    printf("          Developed For Demonstration !             \n");
    printf("          Developed By Prabesh P. Kafle             \n");
    printf("====================================================\n");
    printf(ANSI_COLOR_RESET);


    return 0;
} 