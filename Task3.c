#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

// List of keywords
char* keywords[] = {"int", "float", "if", "else", "while", "return"};
int num_keywords = 6;

// List of operators
char* operators[] = {"+", "-", "*", "/", "=", ">", "<", "=="};
int num_operators = 8;

// Function to check if a string is a keyword
int is_keyword(char* str) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a string is an operator
int is_operator(char* str) {
    for (int i = 0; i < num_operators; i++) {
        if (strcmp(str, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a string is an identifier
int is_identifier(char* str) {
    if (isdigit(str[0])) {
        return 0;  // Identifiers should not start with a digit
    }
    for (int i = 0; i < strlen(str); i++) {
        if (!isalnum(str[i])) {
            return 0;  // Identifiers should contain only letters and digits
        }
    }
    return 1;
}

// Function to perform lexical analysis
void lexical_analysis(FILE* file) {
    char ch;
    char buffer[MAX_LEN];
    int index = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch)) {
            continue;  // Skip whitespaces
        }

        if (isalpha(ch)) {  // Start of keyword or identifier
            buffer[index++] = ch;
            while (isalnum(ch = fgetc(file))) {
                buffer[index++] = ch;
            }
            buffer[index] = '\0';
            ungetc(ch, file);  // Put the last non-alphanumeric character back into the file
            index = 0;

            // Check if it's a keyword or identifier
            if (is_keyword(buffer)) {
                printf("Keyword: %s\n", buffer);
            } else if (is_identifier(buffer)) {
                printf("Identifier: %s\n", buffer);
            }
        } 
        else if (isdigit(ch)) {  // Start of a number (optional)
            buffer[index++] = ch;
            while (isdigit(ch = fgetc(file))) {
                buffer[index++] = ch;
            }
            buffer[index] = '\0';
            ungetc(ch, file);
            index = 0;
            printf("Number: %s\n", buffer);
        } 
        else if (ispunct(ch)) {  // Operator or punctuation
            buffer[index++] = ch;
            buffer[index] = '\0';
            index = 0;
            // Check if it's an operator
            if (is_operator(buffer)) {
                printf("Operator: %s\n", buffer);
            }
        }
    }
}

// Function to write content to the file
void write_to_file(char* filename) {
    FILE* file = fopen(filename, "w");  // Open for writing (creates the file if it doesn't exist)
    if (file == NULL) {
        printf("Error creating the file!\n");
        exit(1);
    }

    printf("Enter content for the file (Type 'exit' to stop):\n");

    char line[MAX_LEN];
    while (1) {
        printf("Enter line: ");
        fgets(line, MAX_LEN, stdin);
        // Remove newline character
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, "exit") == 0) {
            break;
        }
        fprintf(file, "%s\n", line);  // Write the content to the file
    }

    fclose(file);  // Close the file after writing
}

int main() {
    char filename[100];
    printf("Enter the input file name: ");
    scanf("%s", filename);  // Take the filename as input from the user

    getchar();  // Consume the newline left by scanf

    // Write content to the file
    write_to_file(filename);
    printf("Content has been written to %s\n", filename);

    // Open the file for reading (lexical analysis)
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s!\n", filename);
        return 1;
    }

    lexical_analysis(file);  // Perform lexical analysis

    fclose(file);  // Close the file
    return 0;
}
