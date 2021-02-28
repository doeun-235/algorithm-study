#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ind,sum,lim,cnt;
int A[9][3];

int choose(int num, int dep){
    if (dep==0){
        return 1;
    }else {
        return num*choose(num-1,dep-1)/dep;
    }

}

int make(int dep, int a, int remsum){
    int i,b,count;
    A[dep][2]+=a;
    count=remsum-a; // count-=a; //이게 되려나 모르겠네;
    // printf("make(%d,%d,%d)\n",dep,a,remsum);
    // for (i=0;i<ind;i++){
    //     printf("%d",A[i][2]);
    // }
    // printf("\n");

    if ((A[dep][2]>A[dep][0]) || (count<0)){
        if (dep!=0){
            make(dep-1,1,count+A[dep][2]);
        }else {
            printf("end\n");
            return 0;
            printf("why not end?\n");
        }
    } else if (dep==ind-1){ //이거를 else if 로 안하고 두개의 if로 분리하면 이상하게 되던데 이유를 모르겟음
        printf("*");
        for (i=0;i<ind;i++){
            printf("%d",A[i][2]);
        }
        printf("\n");
        cnt++;
        if (dep==0){
            return 0;
        }
        make(dep-1,1,count+A[dep][2]);
    }else {
        if (A[dep][1]<count){
            printf("dep,a,remsum,count : %d,%d,%d,%d\n",dep,a,remsum,count);
            for (i=0;i<ind;i++){
                printf("%d",A[i][2]);
            }
            printf("\nerror\n");
            return 0;
        }else if (A[dep+1][1]>count){
            b=0;
        }else {
            b=count-A[dep+1][1];
        }
        A[dep+1][2]=b;
        make(dep+1,0,count-A[dep+1][2]);
    }
    return 0;
}


int main(void){
    int i,pred,a;
    scanf("%d %d",&ind,&lim);

    sum=0;
    memset(A,0,sizeof(A));

    for (i=0;i<ind;i++){
        scanf ("%d",&A[i][0]);
        sum+=A[i][0];
    }

    A[0][1]=sum-A[0][0];
    for (i=1;i<ind-1;i++){
        A[i][1]=A[i-1][1]-A[i][0];
    }

    // for (i=0;i<ind;i++){
    //     printf("%d",A[i][0]);
    // }
    // printf("\n");
    for (i=0;i<ind;i++){
        printf("%d",A[i][1]);
    }
    printf("\n");

    // ind 개 만큼의 수를 입력 받고서, 각각 A[i][0] 만큼 최대가ㅄ 가지고, 총 합이 lim이 되어야 할때 모든 경우의 수 출력해주는 프로그램

    cnt=0;
    if (ind!=0){
        if (0<=lim-A[0][1]){
            A[0][2]=lim-A[0][1];
            make (0,0,A[0][1]);
        } else {
            make (0,0,lim);
        }
    }
    printf("total : %d\n",cnt);

    //pred != lim + ind-1 choose ind-1 -> 왜냐면 각 a_i 별로 상한이 있기 때문. 따라서 중복조합 X
    // 이거 개수 구하는 방법은 물어보자!
    
    // if (lim<ind-1){
    //     a=lim;
    // }else {
    //     a=ind-1;
    // }

    // pred=choose(lim+ind-1,a);
    
    // printf("predict : %d\n",pred);
    return 0;
}

// * size_t라는 자료형이 있음 - unsigned int