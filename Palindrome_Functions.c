#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palindrome.h"

// Funktion zum Umkehren eines Strings
char *reverse(char *str) {
    int len = strlen(str);
    char *reversed = (char *)malloc(sizeof(char) * (len + 1)); // +1 für das Null-Terminator-Zeichen

    for(int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0'; // Null-Terminator
    return reversed;
}

// Funktion zur Palindrom-Erkennung (mit String-Vergleich)
void ispalindrome(char *str) {
    char *reversed = reverse(str); // String umkehren
    if(strcmp(reversed, str) == 0) { // Vergleich der umgekehrten Strings
        printf("%s is a palindrome.\n", str);
    }
    else {
        printf("%s is not a palindrome.\n", str);
    }
    free(reversed); // Speicherfreigabe nach Verwendung
}

// Funktion zur Palindrom-Erkennung (mit Pointer-Technik)
void pointer_ispalindrome(char *str) {
    int left = 0, right = strlen(str) - 1;
    while(left <= right) {
        if(str[left] != str[right]) {
            printf("%s is not a palindrome.\n", str);
            return;
        }
        left++;
        right--;
    }
    printf("%s is a palindrome.\n", str);
}
