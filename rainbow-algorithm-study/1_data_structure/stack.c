#include <stdio.h>
#include <string.h>

int stack[100000];

int main (){
    int N, top, i, value;
    char order[10];

    top=0;

    scanf("%d",&N);

    for (i=0;i<N;i++){

        scanf("%s",order); //이렇게 쓰는 경우 공백 문자 이전까지만 받음.
        //scanf("%[^\n]s",blah) -> 이런식으로 해야 개행문자 나올때 까지의 문자열을 한번에 받음.
        //scanf("%5[123]s",blah) -> 이런식으로 하면 1) 123 같은 얘들만 나오는 곳까지만 받는다 2) 길이는 최대 5로

        if (strcmp(order,"push")==0){ //order== 이런식으로 하면 그건 문자열의 주소를 비교하는 것
            scanf("%d",&value);
            stack[top]=value;
            top++;
        }else if (strcmp(order,"pop")==0){
            if (top==0) {
                printf ("-1\n");
            }else {
                top--;
                printf("%d\n",stack[top]);
            }
        }else if (strcmp(order,"size")==0){
            printf ("%d\n",top);
        }else if (strcmp(order,"empty")==0){
            if (top==0){
                printf("1\n");
            }else {
                printf("0\n");
            }
        }else {
            if (top==0) {
                printf ("-1\n");
            }else {
                printf("%d\n",stack[top-1]);
            }
        }
    }



    return 0;
}