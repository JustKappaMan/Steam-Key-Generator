#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
#include <string.h>


const char ALL_CHARS[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const uint_fast8_t ALL_CHARS_LENGTH = 36;

const uint_fast8_t NUMERIC_CHARS_LENGTH = 10;


// Checks if string is a natural number from 1 to 999999
bool isValidString(const char* s);

// Generates a key that matches pattern XXXXX-XXXXX-XXXXX
void generateKeyOne(char* const emptyString);

// Generates a key that matches pattern XXXXX-XXXXX-XXXXX-XXXXX-XXXXX
void generateKeyTwo(char* const emptyString);

// Generates a key that matches pattern XXXXXXXXXXXXXXX XX
void generateKeyThree(char* const emptyString);


int main(int argc, char const* argv[]) {
    if (argc != 3) {
        printf("Invalid number of arguments! Check README for details.\n");
        return 1;
    }

    const char* rawType = argv[1];
    uint_fast8_t type;

    if (isValidString(rawType)) {
        type = atoi(rawType);
    } else {
        printf("%s isn't a valid type! Check README for details.\n", rawType);
        return 2;
    }

    const char* rawNumber = argv[2];
    uint_fast32_t number;

    if (isValidString(rawNumber)) {
        number = atoi(rawNumber);
    } else {
        printf("%s isn't a valid number! Check README for details.\n", rawNumber);
        return 3;
    }

    srand((uint_fast32_t)time(NULL));

    switch (type) {
        case 1: {
            char emptyString[18];
            for (;number; --number) {
                generateKeyOne(emptyString);
                printf("%s\n", emptyString);
            }
            break;
        }

        case 2: {
            char emptyString[30];
            for (;number; --number) {
                generateKeyTwo(emptyString);
                printf("%s\n", emptyString);
            }
            break;
        }

        case 3: {
            char emptyString[19];
            for (;number; --number) {
                generateKeyThree(emptyString);
                printf("%s\n", emptyString);
            }
            break;
        }

        default: {
            printf("%s isn't a valid type! Check README for details.\n", rawType);
            return 2;
        }
    }

    return 0;
}


bool isValidString(const char* s) {
    if (strlen(s) > 6 || !strcmp(s, "0")) {
        return false;
    }

    for (uint_fast8_t i = 0; s[i] != '\0'; ++i) {
        if (!isdigit(s[i])) {
            return false;
        }
    }

    return true;
}

void generateKeyOne(char* const emptyString) {
    for (uint_fast8_t i = 0; i < 18; ++i) {
        emptyString[i] = ALL_CHARS[rand() % ALL_CHARS_LENGTH];
    }

    emptyString[5] = '-';
    emptyString[11] = '-';
    emptyString[17] = '\0';
}

void generateKeyTwo(char* const emptyString) {
    for (uint_fast8_t i = 0; i < 30; ++i) {
        emptyString[i] = ALL_CHARS[rand() % ALL_CHARS_LENGTH];
    }

    emptyString[5] = '-';
    emptyString[11] = '-';
    emptyString[17] = '-';
    emptyString[23] = '-';
    emptyString[29] = '\0';
}

void generateKeyThree(char* const emptyString) {
    emptyString[0] = ALL_CHARS[rand() % NUMERIC_CHARS_LENGTH];
    emptyString[1] = ALL_CHARS[rand() % NUMERIC_CHARS_LENGTH];
    emptyString[2] = ALL_CHARS[rand() % NUMERIC_CHARS_LENGTH];

    for (uint_fast8_t i = 3; i < 15; ++i) {
        emptyString[i] = ALL_CHARS[rand() % ALL_CHARS_LENGTH];
    }

    emptyString[15] = ' ';
    emptyString[16] = ALL_CHARS[rand() % NUMERIC_CHARS_LENGTH];
    emptyString[17] = ALL_CHARS[rand() % NUMERIC_CHARS_LENGTH];
    emptyString[18] = '\0';
}