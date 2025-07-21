#include <stdio.h>
#include <stdlib.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(file);
}

void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    fprintf(file, "This is a sample text written to the file.\n");
    fprintf(file, "This line is also part of the file.\n");

    printf("Data written to '%s' successfully.\n", filename);
    fclose(file);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    char ch;
    printf("Reading contents of '%s':\n", filename);
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void appendFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file for appending!\n");
        return;
    }

    fprintf(file, "This line is appended to the file.\n");
    printf("Data appended to '%s' successfully.\n", filename);
    fclose(file);
}

int main() {
    const char *filename = "sample.txt";

    createFile(filename);
    writeFile(filename);
    readFile(filename);
    appendFile(filename);
    readFile(filename);

    return 0;
}
