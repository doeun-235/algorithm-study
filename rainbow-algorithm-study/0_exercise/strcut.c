#include <stdio.h>
#include <string.h>

int main (){
    FILE *fl;
    char a[150],temp[15];
    int len, i, done=0;
    
    fl=fopen("strcut.txt","w");

    scanf("%s",a);

    memset(temp,0,sizeof(temp));

    len=strlen(a);

    for (i=0;i<len;i++){
        temp[done]=a[i];
        done++;
        if (done==10){
            done=0;
            fprintf(fl,"%s\n",temp);
            memset(temp,0,sizeof(temp));
        }
    }
    if (done!=0){
        fprintf(fl,"%s\n",temp);
    }

    fclose(fl);
    return 0;
    
}