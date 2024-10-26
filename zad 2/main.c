#include <stdio.h>

void clear() {
    printf("\n\n\n\n\n\n\n\n");
}

int chooseOperation(int intA, int intB, float floatA, float floatB, int isFloat) {
    clear();
    printf("Wybierz operacje\n");

    printf("1: Dodawanie\n");
    printf("2: Odejmowanie\n");
    printf("3: Mnozenie\n");
    //ponizej prosto z zadan na labach :)
    printf("%s\n", ((intB != 0 && !isFloat) || (floatB != 0 && isFloat)) ? "4: Dzielenie":"4: Niedostepne - nie mozna dzielic przez zero");
    if (!isFloat) {printf("5: %s\n",(intB!=0 ? "Dzielenie" : "Niedostepne - nie mozna dzielic przez 0"));} else {printf("5: Niedostepne - nie istnieje modulo dla liczb zmiennoprzecinkowych\n");}

    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("Niepoprawny wybor\n");
        while (getchar() != '\n') {}
        return 1;
    }
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
                    printf("Nie mozna dzielic przez 0");
                    return 1;
                } else {
                    printf("Wynik dzielenia tych liczb to: %.2f\n",floatA / floatB);
                }
            break;
            default:
                printf("Niepoprawny wybor\n");
            return 1;
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
                if (intB==0) {
                    printf("Nie mozna dzielic przez 0\n");
                    return 1;
                } else {
                    printf("Wynik dzielenia tych liczb to: %.2f\n",(float)intA / (float)intB);
                }
            break;
            case 5:
                if (intB==0) {
                    printf("Nie mozna dzielic przez 0\n");
                    return 1;
                } else {
                    printf("Wynik modulo tych liczb to: %d\n",intA%intB);
                }
            break;
            default:
                printf("Niepoprawny wybor\n");
            return 1;
        }
    }
    return 2;
}

int chooseNumbers(int *intA,int *intB, float *floatA, float *floatB, int *isFloat) {
    clear();
    printf("Wybierz rodzaj liczb\n");

    printf("1: Liczby calkowite\n");
    printf("2: Liczby zmiennoprzecinkowe\n");
    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("Niepoprawny wybor\n");
        while (getchar() != '\n') {}
        return 0;
    }

    switch (choice) {
        case 1:
            printf("Podaj dwie liczby calkowite oddzielone spacja\n");
            if (scanf("%d %d", intA, intB) != 2) {
                printf("Niepoprawne liczby\n");
                while (getchar() != '\n') {}
                return 0;
            }
            while (getchar() != '\n') {}
            *isFloat=0;
            return 1;
        case 2:
            printf("Podaj dwie liczby zmiennoprzecinkowe oddzielone spacja\n");
            if (scanf("%f %f", floatA, floatB) != 2) {
                printf("Niepoprawne liczby\n");
                while (getchar() != '\n') {}
                return 0;
            }
            while (getchar() != '\n') {}
            *isFloat=1;
            return 1;
        default:
            printf("Niepoprawny wybor\n");
        return 0;
    }
}

int main(){
    int intA=0, intB=0, c=0, isFloat=0;
    float floatA=0.0f, floatB=0.0f;
    while (c!=1) {
        c=chooseNumbers(&intA,&intB,&floatA,&floatB,&isFloat);
    }
    while (c!=2) {
        c=chooseOperation(intA,intB,floatA,floatB,isFloat);
    }

    printf("Dziekuje za skorzystanie z programu!\n");
    return 0;
}
