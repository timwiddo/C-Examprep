#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Entwickeln Sie ein Programm, dass die Lottozahlen zieht und die Ziehung plus
Datum in eine Textdatei protokolliert. */




void generateNumber(int* numbers, int count, int max) {

    int drawn, isDuplicate;
    for (int i = 0; i < count; i++) {
        do {
            drawn = rand() % max+1;
            isDuplicate = 0;

            for (int j = 0; j < i; j++) {
                if (numbers[j] == drawn) {
                    isDuplicate = 1;
                    break;
                }
            }
        } while (isDuplicate);

        numbers[i] = drawn;
    }

}


void writeLottoResultToFile(const char *filename, int *numbers, int count) {
    FILE *file = fopen(filename, "a"); // "a" für append
    if (file == NULL) {
        printf("Fehler beim Öffnen der Datei.\n");
        return;
    }
    // get the times
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    fprintf(file, "Ziehung am %02d.%02d.%04d um %02d:%02d:%02d ",
           t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,
           t->tm_hour, t->tm_min, t->tm_sec);


    for (int i = 0; i < count; i++) {
        fprintf(file, "%d ", numbers[i]);
    }
    fprintf(file, "\n");
    fclose(file);
}

int main(void) {

    const int Lotto_Count = 6;
    const int Lotto_Max = 49;
    int lottonumbers[Lotto_Count];
    const char *filepath = "C:/Coding/C/lotto_ziehung.txt"; // Absoluter Pfad

    srand((unsigned)time(NULL)); // Zufallsgenerator initialisieren


    generateNumber(lottonumbers, Lotto_Count, Lotto_Max);

    //Showing the numbers
    printf("Lottonumbers: ");
    for (int i = 0; i < Lotto_Count; i++) {
        printf("%d ", lottonumbers[i]);
    }
    printf("\n");

    writeLottoResultToFile(filepath, lottonumbers, Lotto_Count);
    printf("Done.\n");
    return 0;
}
