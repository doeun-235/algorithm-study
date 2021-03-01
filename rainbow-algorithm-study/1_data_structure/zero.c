#include <stdio.h>

int N, sum, temp, input;

int stack[100000];

int main(){

    int i,top;

    top=0;
    sum=0;

    scanf("%d",&N);
    for (i=0;i<N;i++){
        scanf("%d",&input);
        if (input!=0){
            stack[top]=input;
            sum+=input;
            top++;
//            printf ("top : %d, size : %d, sum : %d\n",stack[top-1],top,sum);
        } else {
            sum-=stack[top-1];
            top--;
 //           printf ("top : %d, size : %d, sum : %d\n",stack[top-1],top,sum);

        }
    }
    printf("%d",sum);
    return 0;
}