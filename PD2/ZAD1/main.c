//Napisz program na bazie zadania 1, który wypisze informację czy tablica jest uporządkowana niemalejąco.
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
    i=1;
    int flag=0, lastNumber=tab[0];
    while (i<n && !flag) {
        if (tab[i]<lastNumber) {flag=1;printf("\nTablica nie jest uporzadkowana niemalejaco\n");}
        lastNumber=tab[i];
        i++;
    }
    if (!flag) {printf("\nTablica jest uporzadkowana niemalejaco\n");}
    return 0;
}
