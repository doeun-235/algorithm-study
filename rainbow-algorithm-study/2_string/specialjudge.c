#include <stdio.h>
#include <string.h>

char Str[2][200000], AnsIn[200000];
int len[2],lenAIn;
int Check[2],Ans;
int pi[200001]={0,};


int findpi(){
    int i,j=0;
    pi[0]=-1; //참고한 블로그와 다르게 pi[j]를 길이가 j인 부분문자열로 잡음.
    //pi[0]=-1인 이유는 checkin 함수에서 수식을 간단히 하기 위해

    //일단 이해는 잘 안되는데 코드 가져와봄.

    for (i=1;i<lenAIn;i++){
        while (j>0&&AnsIn[i]!=AnsIn[j]){
            j=pi[j];
        }
        if (AnsIn[i]==AnsIn[j]){
            j++;
            pi[i+1]=j;
        }
    }    

/*    for (i=2;i<lenAIn;i++){
        for (j=0;j<lenAIn-i;j++){
            if (AnsIn[i+j]!=AnsIn[j]){
                pi[i+j-1]=j;
            }
        }
    }
*/
    return 0;
}

int checkin (int index){
    int i=0, j=0, check=0;
    
    while (i<=len[index]-lenAIn){
        while (j<lenAIn){
            if (Str[index][i+j]!=AnsIn[j]){
                i+=j-pi[j];
                if (pi[j]<0){
                    j=0;
                }else {
                    j=pi[j];
                }
//                printf("%d %d\n",i,j);
                break;
            }
            j++;
        }
        if (j==lenAIn){
            check=1;
            break;
        }
//        printf("endofwhile %d %d\n",i,j);

        if(j<0 || i<0){
            break;
        }
    }

//    printf("%d %d\n",i,j);
    return check;
}

int main(){
    int i;
    
    scanf("%s",Str[0]); //근데 여기서 왜 이렇게 해도 되는지는 이해가 잘 안되김 함... 포인터가 뭐가 어케 된거야...?
    scanf("%s",Str[1]);
    scanf("%s",AnsIn);

    len[0]=strlen(Str[0]);
    len[1]=strlen(Str[1]);
    lenAIn=strlen(AnsIn);

    findpi();
/*    
    printf("finish pi\n");

    for (i=0;i<lenAIn+1;i++){
        printf("%d %d\n",i,pi[i]);
    }
*/
    Check[0]=checkin(0);
//    printf("finish check1 : %d\n",Check[0]);

    Check[1]=checkin(1);
//    printf("finish check2 : %d\n",Check[1]);

    //출력
    Ans=Check[0]*Check[1];
    if (Ans==0){
        printf("NO\n");
    }else {
        printf("YES");
    }

    return 0;
}