#include <stdio.h>

/* Experimentieren Sie mit dem Stream stdin. Versuchen Sie Funktionen und
Prozeduren zu schreiben, mit denen Sie eine zuverlässigere
Benutzereingabe ermöglichen als mit scanf(). */





int getintinput() {

    char buffer[50];
    int num;
    while(1) {
        printf("Enter a number: ");
        fgets(buffer, sizeof(buffer), stdin); //Read the stdin

        //is input valid?

        if(sscanf(buffer, "%d", &num) != 1) {
            printf("Invalid input, try again!\n");

        }
        else {
            return num;
        }
    }

}


int main(void) {

    int number = getintinput();
    printf("Your Number is: %d\n", number);
    return 0;
}
