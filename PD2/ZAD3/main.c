//Napisz program na bazie zadania 1, który dokona modyfikacji tablicy w taki sposób, iż przesunie wszystkie jej
//elementy „w prawo” o jeden, tzn. pierwszy element stanie się drugim, drugi – trzecim, itd. Ostatni element
//przesuwamy na początek tablicy. Na koniec wypisujemy zmodyfikowaną tablicę.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand(time(0));
    int n,a,b;
    printf("podaj rozmiar tablicy: ");
    scanf("%d",&n);
    printf("podaj zakres losowania <a,b>: ");
    scanf("%d %d",&a,&b);
    if (a>b) {int tmp=a; a=b; b=tmp;}
    int tab[n];
    int i=0;
    for (;i<n;i++) {
        tab[i]=rand()%(b-a+1)+a;
        printf("%d ",tab[i]);
    }
    printf("\n");
    int lastElement=tab[n-1];
    for (i=n-1;i>0;i--) {
        tab[i]=tab[i-1];
    }
    tab[0]=lastElement;
    for (i=0;i<n;i++) {
        printf("%d ", tab[i]);
    }
    return 0;
}
