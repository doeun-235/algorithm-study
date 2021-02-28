#include <stdio.h>
#include <string.h>

int N, A[100][100], par;
int B[100][100];
int cnt[2][2][199]; //cnt [방향][0:0개수/1:최대값][]
int cnta[2][2][199];
int list[2][199];

/*
어떻게 하면 되는지는 좀 알겟음.
"짝수"대각선 / "홀수"대각선 나눠서 하면 됨
각각에 대해서 가장 긴 대각선 중 하나가 켜져 있을 때 필요한 개수 구하기
그리고 전체 "짝수" 대각선 / "홀수" 대각선 개수에서 켜져있는거 뺐을 때(=가장 큰 대각선이 꺼져있을때 필요한 개수)와 비교해서 더 작은 값 return
    -> 짝수 홀수 기준 : / 방향- r+c=even or odd -> 이거 기준. 그러면 \ 방향 -c-r+N-1 = (even or odd)+ (parity of N-1)
    -> 각각의 개수 : 총 대각선 개수 각 방향별로 2N-1개. / : 0=<r+c<=2N-2 이므로 짝수는 N개, 홀수는 N-1개
                                                       \ : 0=<-c+r+N-1<=2N-2 이므로 이 값이 짝수인 것은 N개, 홀수인 것은 N-1개
    따라서 N이 홀수 : 짝수 대각선 개수 : 2N / N이 짝수 : 짝수 대각선 개수 : 2N-1 => 2N-1+par(parity of N) / 홀수 대각서 개수 2N-1-par
그리고 그 둘의 값 더하면 됨.
*/

int printA(){
    int i,j;
    int a=0;
    for (i=0;i<N;i++){
        for (j=0;j<N;j++){
            printf("%d",A[i][j]);
        }
        printf("\n");
    }
    if (a==0){
        return 0;
    }
}

int checkcnt(){
    int i;
    for (i=0;i<2*N-1;i++){
        if (cnt[0][0][i]==1 || cnt[1][0][i]==1){
            return 1;
        }
    }
    return 0;
}

int flip_list(int dir, int ind){
    int s,j,k,a;

//    printf ("flip %d,%d\n",dir,ind);
    list[dir][ind]=1;    
    a=cnt[dir][1][ind];
    cnt [dir][0][ind]=cnt[dir][1][ind]-cnt[dir][0][ind];
           
    //대각선 따라 가면서 뒤집기
    // [0][m] : r+c=m 임, [1][m] = c-r+N-1 = m임
            
    if (ind>=N){
        s=ind-N+1;
    }else {
        s=0;
    }

    if (dir==0){
        for (j=s;j<a+s;j++){
            cnt[1][0][j-ind+j+N-1]+=2*A[ind-j][j]-1;
//            list[1][j-ind+j+N-1]+=cnt[1][0][j-ind+j+N-1];
            A[ind-j][j]=1-A[ind-j][j];
        }
    }else {
        for (j=s;j<a+s;j++){
            cnt[0][0][2*j+N-1-ind]+=2*A[j+N-1-ind][j]-1;
//            list[0][2*j+N-1-ind]+=cnt[0][0][2*j+N-1-ind];
            A[j+N-1-ind][j]=1-A[j+N-1-ind][j];
        }
    }

    // 만약 에러 있으면 난리나라고.        
    for(j=0;j<2*N-1;j++){
        if (cnt[0][0][j]<0 || cnt[1][0][j]<0){
            while (a>0){
                s=0;
            }
        }
    }
    return 0;
}



int main(){
    int casenum,turn_f,turn[2];
    int i,j,k,done,max,maxind[2];
    int a,b,s;
    char c;
    
    FILE*finput;
    
    finput=fopen("prob2.txt","r");

    // printf("START\n");

    fscanf(finput,"%d",&casenum);

    // printf("%d\n",casenum);

//    scanf("%d",&casenum);
    
    for (i=0;i<casenum;i++){
    
        fscanf(finput,"%d",&N);

    //    scanf("%d",&N);
        
//        printf("%d\n",N);
        
        par = N % 2;

        memset(cnt,0,sizeof(cnt));
        
        //[0][] : 45도 , [1][] : -45도. 순서는 둘다 좌->우
        
        for (j=0;j<N;j++){
            for (k=0;k<N;k++){

                fscanf(finput,"%c",&c);

            //    scanf("%c",&c);
                if (c=='\n'){
                    fscanf(finput,"%c",&c);

                //    scanf("%c",&c);
                }
                if (c=='.'){
                    A[j][k]=0;
                    B[j][k]=0;
                    cnt[0][0][j+k]++;
                    cnt[1][0][k-j+N-1]++;
                } else {
                    A[j][k]=1;
                    B[j][k]=1;
                }
//               printf("%d",A[j][k]);
            }
//           printf("\n");
        }
        
        memset(list,0,sizeof(list));
        
        // 각각 대각선 별로 숫자 개수 구하기
        
        for (j=0;j<2*N-1;j++){
//            printf ("%d %d\n",cnt[0][0][j],cnt[1][0][j]);          
            if (j<N){
                cnt[0][1][j]=j+1;
                cnt[1][1][j]=j+1;
            }else {
                cnt[0][1][j]=2*N-1-j;
                cnt[1][1][j]=2*N-1-j;
            }

            /*
            cnta[0][1][j]=cnt[0][1][j];
            cnta[0][0][j]=cnt[0][0][j];
            cnta[1][0][j]=cnt[1][0][j];
            cnta[1][1][j]=cnt[1][1][j];
            */
        }

         
        done=0;   
        
        // printf("HELLO\n");

        // 짝수 대각선 부터 -> 짝수 대각선에서 \방향에서 가장 긴 것을 키고, 거기에 대해서 수직인 짝수 대각선에 대해서 킬지 말지를 결정하고, 나머지 \방향에 대해서 전부 확인
        
        // 0: r+c , 1: -r+c+N-1

//        printf("even\n");
        turn[0]=1;
        flip_list(1,N-1);

        // \ 방향에서 큰 대각선에 수직인 것 (/) 확인하면서 뒤집음
        for (j=0;j<N;j++){
            if (A[j][j]==0){
                flip_list(0,2*j);
                turn[0]++;
            }
        }
        
        // \방향으로 가면서 뒤집어야하는거 뒤집음;
        for (j=1-par;j<2*N-1;j+=2){
            if (cnt[1][0][j]!=0){
                flip_list(1,j);
                turn[0]++;
            }
        }
        
//        printf("odd\n");
        turn[1]=1;
        flip_list(1,N-2);
//        printA();
        for (j=1;j<=N-1;j++){
            if (A[j][j-1]==0){
                flip_list(0,2*j-1);
                turn[1]++;
            }
        }

        for (j=par;j<2*N-1;j+=2){
            if(cnt[1][0][j]!=0){
                flip_list(1,j);
                turn[1]++;
            }
        }
        
        turn_f=0;

//        printf("%d, %d\n",turn[0],turn[1]);

        // 짝수 대각선, 홀수 대각선, 각각 대응되는 쌍별로 더 작은 쪽으로 
        if (2* turn [0] < 2*N -1 + par){
            turn_f+=turn[0];
        }else {
            turn_f+=2*N-1+par-turn[0];
        }
        if (2*turn [1] < 2*N-1 - par){
            turn_f+=turn[1];
        }else {
            turn_f+=2*N-1-par-turn[1];
        }

        printf("Case #%d: %d\n",i+1,turn_f);
    }
    
    // fclose(finput);
    
    return 0;
}