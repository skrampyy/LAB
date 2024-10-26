#include <stdio.h>

void clear() { //funkcja pseudo-czyszczaca podgladowa konsole
    printf("\n\n\n\n\n\n\n\n");
}

int chooseOperation(int intA, int intB, float floatA, float floatB, int isFloat, const int c) { //funkcja wyboru operacji na liczbach
    clear();
    if (c==3) {printf("Niepoprawny wybor\n");}
    printf("Wybierz operacje\n");

    printf("1: Dodawanie\n");
    printf("2: Odejmowanie\n");
    printf("3: Mnozenie\n"); //ponizej skomplikowanie kodu dla wlasnej satysfakcji
    printf("%s\n", ((intB != 0 && !isFloat) || (floatB != 0 && isFloat)) ? "4: Dzielenie":"4: Niedostepne - nie mozna dzielic przez zero");
    if (!isFloat) {printf("5: %s\n",(intB!=0 ? "Modulo" : "Niedostepne - nie mozna dzielic przez 0"));} else {printf("5: Niedostepne - nie istnieje modulo dla liczb zmiennoprzecinkowych\n");}

    int choice;
    if (scanf("%d", &choice) != 1) { //sprawdzanie inputu uzytkownika i czyszczenie buffora
        while (getchar() != '\n') {}
        return 3;
    }
    while (getchar() != '\n') {}
    clear();
    if (isFloat) {
        switch(choice) {
            case 1:
                printf("Suma dodawania tych liczb to: %.2f\n",floatA+floatB);
            break;
            case 2:
                printf("Suma odejmowania tych liczb to: %.2f\n",floatA-floatB);
            break;
            case 3:
                printf("Wynik mnozenia tych liczb to: %.2f\n",floatA*floatB);
            break;
            case 4:
                if (floatB==0.0) {
                    return 3;
                } else {
                    printf("Wynik dzielenia tych liczb to: %.2f\n",floatA / floatB);
                }
            break;
            default://niepoprawny wybor
            return 3;
        }
    } else {
        switch(choice) {
            case 1:
                printf("Suma dodawania tych liczb to: %d\n",intA+intB);
            break;
            case 2:
                printf("Suma odejmowania tych liczb to: %d\n",intA-intB);
            break;
            case 3:
                printf("Wynik mnozenia tych liczb to: %d\n",intA*intB);
            break;
            case 4:
                if (intB==0) { //nie mozna dzielic przez 0
                    return 3;
                } else {
                    printf("Wynik dzielenia tych liczb to: %.2f\n",(float)intA / (float)intB);
                }
            break;
            case 5:
                if (intB==0) {return 3;} else {
                    printf("Wynik modulo tych liczb to: %d\n",intA%intB);
                }
            break;
            default:
            return 3;
        }
    }
    return 2;
}

int chooseNumbers(int *intA,int *intB, float *floatA, float *floatB, int *isFloat, const int c) { //funkcja wybierania typow liczb i ich samych
    clear();
    if (c==3) {printf("Niepoprawny wybor\n");}
    printf("Wybierz rodzaj liczb\n");

    printf("1: Liczby calkowite\n");
    printf("2: Liczby zmiennoprzecinkowe\n");
    int choice;
    if (scanf("%d", &choice) != 1) { //sprawdzanie inputu uzytkownika, w razie zlego wyboru konczymy funkcje, wracamy do while ze 125 linijki i ponawiamy wywolanie funkcji
        printf("Niepoprawny wybor\n");
        while (getchar() != '\n') {} //czyszczenie buffora, np gdy uzytkownik poda "1 35g24tb25b25" to bufor zapamieta "35g24tb25b25" na nastepnego scanf
        return 3;//zwracanie wyniku funkcji, ktory napisze, ze nieprawidlowo wybralismy
    }

    switch (choice) {
        case 1:
            printf("Podaj dwie liczby calkowite oddzielone spacja\n");
            if (scanf("%d %d", intA, intB) != 2) { //to samo co wyzej, sprawdzanie inputu, czyszczenie buffora
                while (getchar() != '\n') {}
                return 3;
            }
            while (getchar() != '\n') {}
            *isFloat=0; //zmienna ktora przyda sie pozniej przy wyborze operacji
            return 1; //zakonczenie while ze 117 linijki
        case 2:
            printf("Podaj dwie liczby zmiennoprzecinkowe oddzielone spacja\n");
            if (scanf("%f %f", floatA, floatB) != 2) {
                while (getchar() != '\n') {}
                return 3;
            }
            while (getchar() != '\n') {}
            *isFloat=1;
            return 1; //zakonczenie while ze 117 linijki
        default:
        return 3;
    }
}

int main(){
    int intA=0, intB=0, c=0, isFloat=0;
    float floatA=0.0f, floatB=0.0f;
    while (c!=1) { //petla wymuszajaca na uzytkowniku podanie liczb odpowiedniego typu
        c=chooseNumbers(&intA,&intB,&floatA,&floatB,&isFloat,c);
    }
    while (c!=2) { //petla wymuszajaca na uzytkowniku wybranie poprawnej operacji dla danego typu liczb
        c=chooseOperation(intA,intB,floatA,floatB,isFloat,c);
    }

    printf("Dziekuje za skorzystanie z programu!\n");
    return 0;
}
