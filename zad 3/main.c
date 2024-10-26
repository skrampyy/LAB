/*
Zadanie3 - 20 pkt.
    Napisz program, który obliczy ilość wszystkich liczb od 1 do n podzielnych bez reszty przez k
    (n oraz k – podaje użytkownik n>k). Zabezpiecz program w dowolny sposób przed podaniem
    niewłaściwych danych.
 */

#include <stdio.h>

void clear() { //funkcja pseudo-czyszczaca podgladowa konsole
    printf("\n\n\n\n\n\n\n\n");
}

int countDivisible(const int n, const int k) {//funkcja zliczajaca liczby z zakresu <1,n> podzielne przez k
    //int i,
    int counter=0;

    //for (i=1;i<=n;i++) {if (i%k==0) {counter++;}};
    counter=n/k;

    return counter;
}

int chooseNumbers(int *n, int *k) {//funkcja wybierania wartosci n i k
    clear();
    static int fistAttempt=1;

    if (fistAttempt==0) {printf("Wprowadziles niewlasciwe dane. Upewnij sie, ze n>1 i n>k\n");}//komunikat informujacy o blednym wprowadzeniu danych
    fistAttempt=0;//zmiana zmiennej okreslajacej pierwsza probe

    printf("podaj n i k oddzielone spacjami:\n");
    if (scanf("%d %d",n,k)!=2) { //sprawdzanie inputu uzytkownika i czyszczenie bufforu
        while (getchar()!='\n') {}
        return 1;
    }

    while (getchar()!='\n') {}//czyszczenie bufforu

    if (*n<1 || *k<=0 || *n<*k) {return 1;} //sprawdzanie czy uzytkownik podal odpowiednie wartosci n i k

    return 0;
}

int main(void) {
    int n=0, k=0;

    while (chooseNumbers(&n,&k)!=0) {}//petla wymuszajaca wprowadzenie poprawnych wartosci n i k przez uzytkownika

    printf("ilosc liczb w przedziale <1,%d> dzielacych sie przez %d: %d",n,k,countDivisible(n,k));

    return 0;
}
