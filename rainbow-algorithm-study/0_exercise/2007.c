#include <stdio.h>

int main (){
    int dayz[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    char YO[31]="MONTUEWEDTHUFRISATSUN";
    int mon, day, today, yoil, i;
    
    scanf("%d %d",&mon,&day);
    
    today=0;
    for (i=0;i<mon-1;i++){
        today+=dayz[i];
    }
    today+=day;
    yoil = today % 7;
    
    printf("%c%c%c",YO[3*yoil],YO[3*yoil+1],YO[3*yoil+2]);
    
    return 0;
}