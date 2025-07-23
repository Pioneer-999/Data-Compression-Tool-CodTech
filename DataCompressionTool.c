#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input file using RLE
void compressFile(const char *inputFile, const char *outputFile) {
    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");

    if (fin == NULL || fout == NULL) {
        perror("Error opening file");
        return;
    }

    char currentChar, prevChar;
    int count = 1;

    prevChar = fgetc(fin); // Read first character
    if (prevChar == EOF) {
        printf("Input file is empty.\n");
        fclose(fin);
        fclose(fout);
        return;
    }

    while ((currentChar = fgetc(fin)) != EOF) {
        if (currentChar == prevChar) {
            count++;
        } else {
            fprintf(fout, "%c%d", prevChar, count);  // Write encoded form
            prevChar = currentChar;
            count = 1;
        }
    }
    // Write last character and count
    fprintf(fout, "%c%d", prevChar, count);

    printf("File compressed successfully to '%s'\n", outputFile);

    fclose(fin);
    fclose(fout);
}

// Function to decompress the RLE-encoded file
void decompressFile(const char *inputFile, const char *outputFile) {
    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");

    if (fin == NULL || fout == NULL) {
        perror("Error opening file");
        return;
    }

    char ch;
    int count;

    while ((ch = fgetc(fin)) != EOF) {
        if (fscanf(fin, "%d", &count) != 1) {
            printf("Invalid format in compressed file.\n");
            fclose(fin);
            fclose(fout);
            return;
        }

        for (int i = 0; i < count; i++) {
            fputc(ch, fout);
        }
    }

    printf("File decompressed successfully to '%s'\n", outputFile);

    fclose(fin);
    fclose(fout);
}

// Main menu
int main() {
    int choice;
    char inputFile[100], outputFile[100];

    while (1) {
        printf("\n--- Run-Length Encoding Tool ---\n");
        printf("1. Compress File\n");
        printf("2. Decompress File\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline

        switch (choice) {
            case 1:
                printf("Enter input file name (to compress): ");
                scanf("%s", inputFile);
                printf("Enter output file name (compressed): ");
                scanf("%s", outputFile);
                compressFile(inputFile, outputFile);
                break;

            case 2:
                printf("Enter input file name (compressed): ");
                scanf("%s", inputFile);
                printf("Enter output file name (decompressed): ");
                scanf("%s", outputFile);
                decompressFile(inputFile, outputFile);
                break;

            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
