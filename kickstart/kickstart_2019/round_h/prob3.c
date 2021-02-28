#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[9][4]; // A[][3] 가ㅄ(1~9) / A[][0] 최대가ㅄ (쓸 수 있는 갯수) / A[i][1] sum_{j=i+1|^ind A[j][1] / A[][2] 카운트해서 구한 가ㅄ
int sum,done,ind;
int cnst;
int count;

int check(){
    int i,a=0;
    for (i=0;i<ind;i++){
        a+=A[i][3]*(A[i][0]-2*A[i][2]);
    }
    if (a%11==0) {
        // printf("\n");
        // for (i=0;i<ind;i++){
        //     printf ("%d %d\n",A[i][3],A[i][2]);
        // }
        return 1;
    }else {
        return 0;
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

    if (done==1) {
        return 0;
    }else if ((A[dep][2]>A[dep][0]) || (count<0)){
        if (dep!=0){
            make(dep-1,1,count+A[dep][2]);
        }else {
//            printf("end\n");
            return 0;
            printf("why not end?\n");
        }
    } else if (dep==ind-1){ //이거를 else if 로 안하고 두개의 if로 분리하면 이상하게 되던데 이유를 모르겟음
        // printf("*");
        // for (i=0;i<ind;i++){
        //     printf("%d",A[i][2]);
        // }
        // printf("\n");
        
        done = check();
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






int main(void) {
    
    int casenum;
    int i,j,k,l,chk[2];
    
//    int check [9]={1,2,3,4,5,-5,-4,-3,-2};


    FILE*finput;
    finput=fopen("prob3.txt","r");

    fscanf(finput,"%d",&casenum);
    // scanf("%d",&casenum);
     // 표준 입력을 받아서 변수에 저장


    for (i=1;i<=casenum;i++) {
        
        int a;
        int cnt;
        
        memset(A,0,sizeof(A));
        printf("Case #%d:",i);
        ind = 0;
        sum = 0;
        done = 0;
        for (j=0;j<9;j++) {
            fscanf(finput,"%d", &a);
            // scanf("%d", &a);
            if (a!=0){
                if (j>5){
                    A[ind][3]=j-10;
                }else {
                    A[ind][3]=j+1;
                }
                A[ind][0]=a;
                sum+=a;
                ind++;
            }
        }

        A[0][1]=sum-A[0][0];

        for (j=1;j<ind;j++){
            A[j][1]=A[j-1][1]-A[j][0];
        }
        
        // cnst=0;
        if (sum%2==0){
            sum=sum/2;
            

            // cnst=1; // sum이 짝수일 때는 계산량을 반으로 줄일 수 있음. 다만 이거는 나중에 처리
            // for (j=0;j<(A[0][1]+1)/2;j++){
            //     A[0][3]=A[0][1]-j;
            //     count=sum-A[0][3];
            //     make(0);                
            //     if (done==1){
            //         break;
            //     }
            // }
            
        }else {
            sum=(sum-1)/2;
        }
        
        chk[0]=0;
        chk[1]=0;
        
        for (j=0;j<ind;j++){
            if (A[i][0]>=10){
                chk[0]++;
                chk[1]++;
            }else if (A[j][0]>=6){
                chk[1]++;
            }
        }
        if ((chk[0]>=2)||(chk[1]>=3)){
            done=1;
        }
        
        if (ind!=0){
            if (done!=1){
                if (0<=sum-A[0][1]){
                    A[0][2]=sum-A[0][1];
                    make (0,0,A[0][1]);
                } else {
                    make (0,0,sum);
                }
            }
        }

        if (done==1){
            printf(" YES\n");
        }else {
            printf(" NO\n");
        }



    }

    fclose(finput);
    // printf("%d\n", casenum);    // 변수의 내용을 출력
    

    return 0;
}
