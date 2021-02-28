#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int casenum;
    int i,j,k;

    scanf("%d",&casenum);
     // 표준 입력을 받아서 변수에 저장


    for (i=1;i<=casenum;i++) {
        scanf("%d %d %d %d %d", &n,&r,&c,&sr,&sc);       
        s[0]=sr;
        s[1]=sc;

        scanf("%s", inslist);
        
        int *d_Array =malloc(sizeof(int*)*r*c);
        
        for (j=0;j<r*c;j++){
            d_Array[j]=0;
        }
        
        
        
        
        printf("Case #%d: %d %d", i,x+1,y+1);
        if (i<casenum) {
            printf("\n");
        }

    }


    // printf("%d\n", casenum);    // 변수의 내용을 출력
    

    return 0;
}