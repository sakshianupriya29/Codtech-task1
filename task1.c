#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char data[100];

    // 1. Create and write to a file
    file = fopen("sample.txt", "w"); // "w" creates the file or truncates if it exists
    if (file == NULL) {
        printf("Error creating file!\n");
        return 1;
    }
    fprintf(file, "Hello! This is the first line.\n");
    fclose(file);
    printf("File created and written successfully.\n");

    // 2. Append data to the file
    file = fopen("sample.txt", "a"); // "a" opens file to append
    if (file == NULL) {
        printf("Error opening file for appending!\n");
        return 1;
    }
    fprintf(file, "This line is appended to the file.\n");
    fclose(file);
    printf("Data appended successfully.\n");

    // 3. Read data from the file
    file = fopen("sample.txt", "r"); // "r" opens file for reading
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("\nReading contents of the file:\n");
    while (fgets(data, sizeof(data), file) != NULL) {
        printf("%s", data);
    }
    fclose(file);

    return 0;
}
