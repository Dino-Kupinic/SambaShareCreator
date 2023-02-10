#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 300

typedef struct {
    char name[MAX_LENGTH];
    char comment[MAX_LENGTH];
    char folder[MAX_LENGTH];
    bool readOnly;
    bool inheritACL;
} Share;

void fixFilePath(char *filePath);
void promptRowSkip();

int main() {
    char filePath[MAX_LENGTH];

    printf("Samba Share Creator by Dino Kupinic\n");
    printf("Input the path to the .csv file:\n");

    fgets(filePath, MAX_LENGTH, stdin);
    FILE *csvFile;

    fixFilePath(filePath);

    csvFile = fopen(filePath, "r");

    if (csvFile == NULL) {
        perror("Invalid file or file path");
        return EXIT_FAILURE;
    }

    promptRowSkip();

    char currentLine[MAX_LENGTH];
    while (fgets(currentLine, MAX_LENGTH, csvFile)) {
        for (int i = 0; i < strlen(currentLine); i++) {
            if (currentLine[i] == ';') {

            }
        }
        printf("%s", currentLine);
    }

    fclose(csvFile);

    return EXIT_SUCCESS;
}

//  C:\Users\Dino\Desktop\SambaShares.csv

void fixFilePath(char *filePath) {
    unsigned int size = strlen(filePath);
    filePath[size] = '\0';
    filePath[size - 1] = '\0';
}

void promptRowSkip() {
    printf("Skip first row? [y/n]");
    int decision = getchar();
    if (decision == 'y' || decision == 'Y') {
        // TODO: skip first line
    } else if (decision == 'n' || decision == 'N'){
        // TODO: read all
    } else {
        printf("Invalid Input... default: skip enabled");
        // TODO: skip first line
    }
}
