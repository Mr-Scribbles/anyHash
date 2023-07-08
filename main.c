#include <stdio.h>
#include <string.h>

char userName[100][50];
char passwordHash[100][65];
char clearText[100][50];
char md5[100][100];
char sha1[100][100];
char sha256[100][100];

void compareData() {
    for (int i = 1; i < 100; i++) {
        char *password = passwordHash[i];
        char *user = userName[i];

        // Compare with md5
        for (int n = 1; n < 100; n++) {
            if (strcmp(password, md5[n]) == 0) {
                printf("Password found for %s: %s, The password is hashed with Md5\n", user, clearText[n]);
                break;
            }
        }

        // Compare with sha1
        for (int n = 1; n < 100; n++) {
            if (strcmp(password, sha1[n]) == 0) {
                printf("Password found for %s: %s, The password is hashed with sha1\n", user, clearText[n]);
                break;
            }
        }

        // Compare with sha256
        for (int n = 1; n < 100; n++) {
            if (strcmp(password, sha256[n]) == 0) {
                printf("Password found for %s: %s, The password is hashed with sha256\n", user, clearText[n]);
                break;
            }
        }
    }
}

void prepareData() {
    FILE *commonFile;
    FILE *usersFile;

    // Check if users.csv file exists
    usersFile = fopen("C:\\Users\\E479860\\CLionProjects\\anyHash\\users.csv", "r");
    if (usersFile == NULL) {
        printf("Error: C:\\Users\\E479860\\CLionProjects\\anyHash\\users.csv file does not exist.\n");
        return;
    }

    // Save data from users.csv to arrays
    int totalUserFileRows = 0;
    char line[100];
    while (fgets(line, sizeof(line), usersFile) != NULL && totalUserFileRows < 100) {
        sscanf(line, "%[^,],%s", userName[totalUserFileRows], passwordHash[totalUserFileRows]);
        totalUserFileRows++;
    }

    fclose(usersFile);

    // Check if common.csv file exists and store data in arrays
    commonFile = fopen("C:\\Users\\E479860\\CLionProjects\\anyHash\\common.csv", "r");
    if (commonFile == NULL) {
        printf("Error: C:\\Users\\E479860\\CLionProjects\\anyHash\\common.csv file does not exist.\n");
        return;
    }

    // TODO: This is only test data located in the CSV - will need to be changed to hashed data using a hash function.
    int totalCommonFileRows = 0;
    while (fgets(line, sizeof(line), commonFile) != NULL && totalCommonFileRows < 100) {
        sscanf(line, "%[^,],%[^,],%[^,],%s", clearText[totalCommonFileRows], md5[totalCommonFileRows], sha1[totalCommonFileRows], sha256[totalCommonFileRows]);
        totalCommonFileRows++;
    }

    fclose(commonFile);
}

int main() {
    prepareData();
    int userChoice;
    printf("This app will hash common passwords in common.csv and cross-reference the hashes provided in users.csv\n\nPlease select from the following options:\n1. Hash the commonly used passwords in common.csv\n2. Cross-reference hashes provided in users.csv\n3. Do both options 1 and 2\n4. Provide more info\n");
    scanf("%d", &userChoice);

    if (userChoice == 1) {
        printf("You selected option 1: Hashing common passwords in common.csv\n\n");
    }
    else if (userChoice == 2) {
        printf("You selected option 2: Comparing hashed passwords from users.csv with common hashed passwords in common.csv\n\n");
        compareData();
    }
    else if (userChoice == 3) {
        printf("You selected option 3: Doing both option 1 and option 2\n\n");
        // Call the necessary functions here
        // For example: hashCommonPasswords() and compareData()
    }
    else if (userChoice == 4) {
        printf("You selected option 4:\nSelecting option 1 will hash common passwords provided in common.csv. The file will be saved with plain text password, password hashed with Md5, sha1, and sha256. Use this option if new passwords are added to common.csv.\nSelecting option 2 will cross-reference the hashed passwords in users.csv with the hashed passwords in common.csv. Use this option if no new passwords are added to common.csv.\nSelecting option 3 will perform both option 1 and 2 in that order.\nWhen the app finishes comparing hashes, the output will be printed and also saved in results.csv\n\n");
        // Call the necessary functions here
        // For example: hashCommonPasswords() and compareData()
    }
    else {
        printf("You have selected an invalid entry. Please try again.\n\n");
    }

    return 0;
}
