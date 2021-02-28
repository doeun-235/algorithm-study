#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    int casenum;
    int i,j,k,l;
    
    int N[101];
    int A[100000];
    int num[100001];


//    FILE*finput;
//    finput=fopen("village_input.txt","r");

//    fscanf(finput,"%d",&casenum);
    scanf("%d",&casenum);
     // 표준 입력을 받아서 변수에 저장


    for (i=1;i<=casenum;i++) {
        scanf("%d", &N[i]);
        //fscanf(finput,"%d", &vnum);       
        int H=1;
        int ind,cnt;
        memset(num,0,sizeof(num));
        printf("Case #%d:",i);
        for (j=0;j<N[i];j++) {
//            fscanf(finput,"%d", &B[j]);
            scanf("%d", &A[j]);
            if (A[j]>N[i]){
                ind = N[i];
            }else {
                ind = A[j];
            }
            num[ind]+=1;
            if (ind>H){
                cnt=0;
                for (k=1;k<H+1;k++){
                    cnt+=num[k];
                }
                if (cnt<=j-H){
                    H++;
                }
            }
            printf(" %d",H);
        }

        printf("\n");

// //        fclose(finput);

    }


    // printf("%d\n", casenum);    // 변수의 내용을 출력
    

    return 0;
}
