#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void) {
    
    int casenum;
    int l[100], r[100];
    int maxr=0;
    int i,j,k;
    int cnt;
    int max;
    int L[2],R[2];
    float root;

    scanf("%d",&casenum);

    for (i=0;i<casenum;i++){
        scanf("%d %d",&l[i],&r[i]);
        if (maxr<r[i]) {
            maxr=r[i];
        }
    }
   
    maxr=maxr+4;

    int *num = malloc(sizeof(int*)*maxr); //여기서 *개수가 포인터의 차원

    max=maxr;
    
    root = sqrt((float)maxr);
    
    maxr = (int)root+2;


    // sieve of eratostenes(?)

    num[0]=0;
    num[1]=1;
    for (i=2;i<=maxr;i++){
        num[i]=1;
    }
    for (i=2;i<=maxr;i++){
        if (num[i]==1) {
            for (j=i+1;j<=maxr;j++){
                if (j%i==0) {
                    num[j]=0;
                }
            }
        }
    }

    maxr=max;


    for (i=0;i<=maxr;i++){
        printf("%d %d\n",i,num[i]);
    }  


    for (i=0;i<casenum;i++){
        cnt = 0;
        L[0]=l[i]/4;
        L[1]=l[i]%4;
        R[0]=r[i]/4;
        R[1]=r[i]%4;

        //범위에 있는 수 중에서, 소수, 2*홀수(4k+2), 4*소수 꼴만 가능 / 2는 소수이면서도 4k+2꼴이기 때문에 처리해줘야
        //생각과 다르게 구글 답안 4가지 케이스가 맞음 -> 근데 얼떨결에 8이 가능하다는게 4p로 포함되어서 문제 없어짐
        //단 1을 빼먹음

        //4k+2 꼴의 개수 : 몫의 차이로 계산
        cnt = cnt + (R[0]-L[0]+1);

        //끝가ㅄ 처리 아니 값이 안쳐져 코드에서만. 이유를 모르겠네
        if (L[1]>2){
            cnt = cnt -1;
        }
        if (R[1]<2){
            cnt = cnt -1;
        }
        
        // printf("%d\n",&cnt);

        //홀수인 소수 개수 세기 : 2도 제외할 겸 짝수까지 포문 다 돌릴 필요 없으니깐
        for (j=L[0]*2+(L[1]/2);j<=R[0]*2+(R[1]/2);j++){
            cnt = cnt + num[2*j+1];
        }   

        if (R[1]==0 || R[1]==2){
            cnt = cnt - num[r[i]+1];
        }

        // printf("%d\n",&cnt);

        //4p꼴 세기

        for (j=L[0]+1;j<=R[0];j++){
            cnt = cnt+ num[j];
        }     

        if (L[1]==0){
            cnt = cnt + num[L[0]];
        }

        // if (l[i]==1){
        //     cnt = cnt+1;
        // }

        printf("Case #%d: %d\n",i+1,cnt);

    }
    return 0;
}
