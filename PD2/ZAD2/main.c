//Napisz program na bazie zadania 1, który wypisze długość najdłuższego ciągu rosnącego. 
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
    int maxLength=0, currentLength=1; 
    for (i=1; i<n; i++) { 
        if (tab[i]>tab[i-1]) {currentLength++;} else { 
            if (currentLength>maxLength) {maxLength=currentLength;} 
            currentLength=1; 
        } 
    } 
    if (currentLength>maxLength) {maxLength=currentLength;} 
    printf("Dlugosc najdluzszego ciagu rosnacego to: %d",maxLength); 
    return 0; 
} 
