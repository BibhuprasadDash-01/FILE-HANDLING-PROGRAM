#include <stdio.h>

void createFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file.\n");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(fp);
}

void writeFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error writing to file.\n");
        return;
    }

    char data[100];
    printf("Enter text to write to file: ");
    getchar(); // consume newline left by previous input
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    printf("Data written successfully.\n");
    fclose(fp);
}

void appendFile(const char *filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }

    char data[100];
    printf("Enter text to append to file: ");
    getchar(); // consume newline left by previous input
    fgets(data, sizeof(data), stdin);

    fputs(data, fp);
    printf("Data appended successfully.\n");
    fclose(fp);
}

void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error reading file or file does not exist.\n");
        return;
    }

    char ch;
    printf("File contents:\n");
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

int main() {
    int choice;
    char filename[50];

    printf("Enter filename: ");
    scanf("%s", filename);

    do {
        printf("\n--- File Operations Menu ---\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Append to File\n");
        printf("4. Read File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createFile(filename); break;
            case 2: writeFile(filename); break;
            case 3: appendFile(filename); break;
            case 4: readFile(filename); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
