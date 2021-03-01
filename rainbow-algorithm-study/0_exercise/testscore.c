#include <stdio.h>

int main (){
    int score,a;
    char grade;
    
    scanf("%d",&score);
    if(score<60){
        grade="F";
    }else if (score==100){
        grade="A";
    }else {
        score=score-60;
        a=score/10;
        grade=68-a;
    }
    printf("%c",grade);
    return 0;
}