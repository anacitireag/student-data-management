#include <stdio.h>
#include <string.h>
struct Studenti {
    char nume[20];
    char prenume[20];
    char CNP[15];
    unsigned int varsta;
    float medie;
};
struct Medii {
    char CNP[15];
    float medie;
};
int main(void) {
    unsigned int n;
    scanf("%u", &n);
    struct Studenti student[n];
    for (int i = 0; i < n; i++) {
         scanf("%s", student[i].nume);
         scanf("%s", student[i].prenume);
         scanf("%s", student[i].CNP);
         scanf("%u", &student[i].varsta);
    }
    struct Medii medie[n];
    for (int i = 0; i < n; i++) {
         scanf ("%s", medie[i].CNP);
         scanf ("%f", &medie[i].medie);
    }

    //a
    struct Studenti aux;
    for (int i = 0; i < n; i++) {
         for (int j = i+1; j < n; j++) {
              if (student[i].varsta > student[j].varsta) {
                  aux = student[i];
                  student[i] = student[j];
                  student[j] = aux;
              }
         }
    }
    for (int i = 0; i < n; i++) {
        student[i].medie = 0.0;
        for (int j = 0; j < n; j++) {
            if (strcmp(student[i].CNP, medie[j].CNP) == 0) {
                student[i].medie = medie[j].medie;
            }
        }
    }
    for (int i = 0; i < n; i++) {
         printf("%s ", student[i].nume);
         printf("%s ", student[i].prenume);
         printf("%s ", student[i].CNP);
         printf("%u ", student[i].varsta);
         printf("%.2f\n", student[i].medie);
    }

    //b
    float medie_varste = 0.0;
    for (int i = 0; i < n; i++) {
         medie_varste += student[i].varsta;
    }
    medie_varste = medie_varste / n;
    printf("%.2f\n", medie_varste);

    //c
    float medie_max = 0.0;
    for (int i = 0; i < n; i++) {
        if (student[i].medie > medie_max) {
            medie_max = student[i].medie;
        }
    }
    for (int i = 0; i < n; i++) {
         if (student[i].medie == medie_max) {
             printf("%s ", student[i].nume);
             printf("%s ", student[i].prenume);
             printf("%.2f\n", student[i].medie);
             break;
         }
    }
    return 0;
}

