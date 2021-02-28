#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    char inslist[100];
    int casenum;
    int n,r,c,sr,sc;
    int s[2];
    int dir;
    int i,j,k;
    int x,y;
    int go_direc[2];
    int done;
    int direc[4][2] ={
        {-1,0},
        {1,0},
        {0,1},
        {0,-1}
    };
//    int d_Array[100][100];

    scanf("%d",&casenum);
     // 표준 입력을 받아서 변수에 저장


    for (i=1;i<=casenum;i++) {
        scanf("%d %d %d %d %d", &n,&r,&c,&sr,&sc);       
        s[0]=sr;
        s[1]=sc;

        scanf("%s", inslist);
        
        // int **d_Array = malloc(sizeof(int*)*r);

        // for (j = 0; j<r; j++) {
        //     d_Array[j] = malloc(sizeof(int*)*c);
        //     for (k=0;k<c;k++) {
        //         d_Array[j][k]=0;
        //     }
        // }

        int *d_Array =malloc(sizeof(int*)*r*c);
        for (j=0;j<r*c;j++){
            d_Array[j]=0;
        }
        
        
        x=sr-1;
        y=sc-1;
        
        //printf("%c\n",inslist[0]);

        for (j=0;j<n;j++){
            d_Array[c*x+y]=1;

            if (inslist[j]=='N') {
                dir=0;
            }
            else if (inslist[j]=='S') {
                dir=1;
            }
            else if (inslist[j]=='E') {
                dir=2;
            }
            else {
                dir=3;
            } 
            go_direc[0]=direc[dir][0];
            go_direc[1]=direc[dir][1];

            done =0;
            while (done==0) {
                x=x+go_direc[0];
                y=y+go_direc[1];

                if (d_Array[x*c+y]==0) {
                    done = 1;
                }
            }


        }
    //    d_Array[x][y]=j+1;
        
        printf("Case #%d: %d %d", i,x+1,y+1);
        if (i<casenum) {
            printf("\n");
        }
        
    //    for (j=0;j<r;j++){
    //        for (k=0;k<c;k++){
    //            printf("\t%d",d_Array[j][k]);
    //        }
    //        printf("\n");
    //    }


    }


    // printf("%d\n", casenum);    // 변수의 내용을 출력
    

    return 0;
}