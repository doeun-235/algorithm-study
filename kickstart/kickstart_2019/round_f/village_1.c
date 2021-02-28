#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int casenum;
    int i,j,k,l;
    int vnum;
    int B[100000];
    int a,b;
    int V[100000];
    int A[100000];
    int Bi[100000];
    int maxsum;

//    FILE*finput;
//    finput=fopen("village_input.txt","r");

//    fscanf(finput,"%d",&casenum);
    scanf("%d",&casenum);
     // 표준 입력을 받아서 변수에 저장


    for (i=1;i<=casenum;i++) {
        scanf("%d", &vnum);
        //fscanf(finput,"%d", &vnum);       
        
        for (j=0;j<vnum;j++) {
//            fscanf(finput,"%d", &B[j]);
            scanf("%d", &B[j]);
        }


        int *d_Array =malloc(sizeof(int*)*vnum*vnum);
        int *db_Array =malloc(sizeof(int*)*vnum*vnum);
        
        for (j=0;j<vnum;j++){
            for (k=0;k<vnum;k++){
                d_Array[j*vnum+k]=0;
                db_Array[j*vnum+k]=0;
            }
        }

        for (j=0;j<vnum-1;j++){
            scanf("%d %d",&a,&b);
            //fscanf(finput,"%d %d",&a,&b);
            d_Array[(a-1)*vnum+b-1]=B[b-1];
            d_Array[(b-1)*vnum+a-1]=B[a-1];
            db_Array[(a-1)*vnum+b-1]=1;
            db_Array[(b-1)*vnum+a-1]=1;
            d_Array[j*vnum+j]=B[j];
            V[j]=0;
            A[j]=0;
        }
        V[vnum-1]=0;
        A[vnum-1]=0;
        
        maxsum =0;

        Bi[0]=1;
        for (j=1;j<=vnum;j++) {
            Bi[j]=2*Bi[j-1];
        }

        int *Bi_Arrary =malloc(sizeof(int*)*vnum*(Bi[vnum]-1));

        for (j=0;j<Bi[vnum];j++){
            b=0;
            for (k=0;k<vnum;k++){
                A[k]=0;
            }
            for (k=0;k<vnum;k++){
                a = j%Bi[k+1];
                Bi_Arrary[j*vnum+k]=a/Bi[k];
                if (Bi_Arrary[j*vnum+k]==1){
                    for (l=0;l<vnum;l++){
                        if (db_Array[k*vnum+l]==1){
                            A[l]=1;
                        }

                    }
                    A[k]=1;
                }
            }
            for (k=0;k<vnum;k++){
                b=b+A[k]*B[k];
            }
            if (maxsum<b){
                maxsum=b;
            }            
        }





        // for (j=0;j<vnum;j++){
        //     for(k=0;k<vnum;k++){
        //         printf("%d ",db_Array[j*(vnum)+k]);
        //     }
        //     printf("\n");
        // }


        /*
        int cnt=0;

        for (j=0;j<vnum;j++){
            a=0;
            for (k=0;k<vnum;k++){
                a=a+d_Array[j*vnum+k]*(1-A[k]);
            }
            if (a>0){
                V[j]=1;
                A[j]=1;
                printf("%d %d\n",j+1,a);
                maxsum=maxsum+a;
                for (k=0;k<vnum;k++){
                    if (db_Array[j*vnum+k]==1){
                        A[k]=1;
                    }
                }
            }
        }

        for (j=0;j<vnum;j++){
            printf("%d %d %d\n", j+1,V[j],A[j]);
        }
        */



        printf("Case #%d: %d", i,maxsum);
        if (i<casenum) {
            printf("\n");
        }
//        fclose(finput);

    }


    // printf("%d\n", casenum);    // 변수의 내용을 출력
    

    return 0;
}

// 이걸 어떻게 n^2 2^n아니라 n 2^n이 나오나 싶었는데 그낭 vertex별로 보는게 아니라 edge별로 보면 됐구나.