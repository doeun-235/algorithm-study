#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count;
int check[100000];
int vnum;
int B[100000];

typedef struct TreeNode{
    int data;
    int dep;
    int childnum;
    int ExpecB[2][2]; // [i][j] = 자신의 상태가 i이고 parent의 상태가 j일 때, 자신 이하의 subtree에서 나오는 Beauty value의 가ㅄ
    int done;
    struct TreeNode *leftchild;
    struct TreeNode *rightsibb;
    struct TreeNode *parent;
    struct TreeNode *older;
}Node;

Node *Addsibb(Node *sibb1, Node *new) {
    if ((*sibb1).rightsibb==NULL){
        (*sibb1).rightsibb=new;
    } else {
        Addsibb((*sibb1).rightsibb,new);
    }
    return sibb1;
}


Node *Addchild(Node *parent,int data){
    Node *New;
    New = (Node*)(malloc(sizeof(Node)));
    New->data=data;
    New->leftchild=NULL;
    New->rightsibb=NULL;
    New->childnum=0;
    New->done=0;
    memset((*New).ExpecB,0,(*New).ExpecB);
    if((*parent).leftchild==NULL){
        parent->leftchild=New;
        New->parent=parent;
        New->older=parent;
        New->dep=(*parent).dep+1;
        (*parent).childnum+=1;
    }else {
        Node *Temp;
        Temp = (Node*)(malloc(sizeof(Node)));
        /*        
        New->older=Addsibb((*parent).leftchild,New);
        New->parent=parent;
        New->dep=(*parent).dep+1;
        */
        
        Temp = (*parent).leftchild;
        for (int l=0;l<(*parent).childnum-1;l++){
            Temp = (*Temp).rightsibb;
        }
        (*Temp).rightsibb=New;
        New->older=Temp;
        New->parent=parent;
        New->dep=(*parent).dep+1;
        (*parent).childnum+=1;

        //여기서 free(Temp)하면 오류나는 이유를 모르겠음 
    }

    return New;
}

int *printnode (Node *loc) {
    if (check[loc->data]==0){
        for (int i=0;i<loc->dep;i++){
           printf(" ");
        }
        printf("%d\n",loc->data);
        check[loc->data]=1;
    }
    if ((loc->leftchild!=NULL)&&(check[(*(loc->leftchild)).data]==0)){
        printnode(loc->leftchild);
    } else if (loc->rightsibb!=NULL&&(check[(*(loc->rightsibb)).data]==0)){
        printnode(loc->rightsibb);
    } else if (loc->older!=NULL){
        printnode(loc->older);
    } else {
        return 0;
    }
}

int *freenode (Node *loc){
    Node *Temp;
    if ((loc->leftchild==NULL)&&(loc->rightsibb==NULL)){
        Temp = loc->older;
        if (Temp==NULL){
            free(loc);
            return 0;
        }
        if (Temp->leftchild==loc){
            Temp->leftchild=NULL;
        }else{
            Temp->rightsibb=NULL;
        }
        free (loc);
        freenode(Temp);
    }else if (loc->leftchild!=NULL){
        freenode(loc->leftchild);
    }else {
        freenode(loc->rightsibb);
    }
}

int *findresult(Node *loc){
    int k,a,b;
    if ((*loc).done==0){
        if ((*loc).leftchild==NULL){
            //loc이 leaf 일 때는 
            (*loc).ExpecB[0][0]=0;
            (*loc).ExpecB[0][1]=B[(*loc).data];
            (*loc).ExpecB[1][0]=B[(*loc).data];
            (*loc).ExpecB[1][1]=B[(*loc).data];
            (*loc).done=1;
        }else {
            Node *Temp;
            Temp=loc->leftchild;
            for (k=0;k<(*loc).childnum;k++){
                if ((*Temp).done==0){
                    findresult(Temp);
                }
                Temp=(*Temp).rightsibb;
            }
            Temp=loc->leftchild;
            a=0;
            b=0;
            for (k=0;k<(*loc).childnum;k++){
            
              if (k!=(*loc).childnum-1){
                    Temp=Temp->rightsibb;
                }
            }
            
                

        }
    }
    if ((*loc).rightsibb!=NULL){
        findresult((*loc).rightsibb);
    }else if ((*loc).parent!=NULL){
        findresult((*loc).parent);
    }else {
        return 0;
    }

}


int main(void) {
    
    int casenum;
    int i,j,k;
    int a,b;
    
    int V[100000];
    int A[100000];
    
    int checkEd[100000];
    Node *checkNd[100000];

    int Ed[100000][2];
    int Tr[100000][3];
    int Tem[100000];

    int maxsum;

    FILE*finput;
    finput=fopen("village_input.txt","r");

    fscanf(finput,"%d",&casenum);
     // 표준 입력을 받아서 변수에 저장


    for (i=1;i<=casenum;i++) {
        fscanf(finput,"%d", &vnum);       
        
        for (j=0;j<vnum;j++) {
            fscanf(finput,"%d", &B[j]);
        }


        for (j=0;j<vnum-1;j++){
            fscanf(finput,"%d %d",&a,&b);
            Ed[j][0]=a-1;
            Ed[j][1]=b-1;
            checkEd[j]=0;
            checkNd[j]=NULL;
        }
        checkNd[vnum-1]=NULL;
        checkEd[vnum-1]=0;
        
        int dep, ind, chdnum;
        int cnt;

//엣지 데이터를 트리로 변환

        Node *root;
        Node *Temp;

        root = (Node*)(malloc(sizeof(Node)));
        Temp = (Node*)(malloc(sizeof(Node)));

        (*root).data=Ed[0][0];
        root->childnum=0;
        root->leftchild=NULL;
        root->parent=NULL;
        root->older=NULL;
        root->dep=0;
        root->done=0;
        Addchild(root,Ed[0][1]);
        root->rightsibb=NULL;

        cnt=1;
        checkEd[0]=1;
        checkNd[Ed[0][0]]=root;
        checkNd[Ed[0][1]]=(*root).leftchild;

        i=1;
        while(cnt<vnum-1) {
            if (checkEd[i]==0){
                if(checkNd[Ed[i][0]]!=NULL){
                    Temp=checkNd[Ed[i][0]];
                    checkNd[Ed[i][1]]=Addchild(Temp,Ed[i][1]);
                    checkEd[i]=1;
                    cnt++;
                }else if (checkNd[Ed[i][1]]!=NULL){
                    Temp=checkNd[Ed[i][1]];
                    checkNd[Ed[i][0]]=Addchild(Temp,Ed[i][0]);
                    checkEd[i]=1;
                    cnt++;
                }
            }
            i++;
            if (i==vnum-1){
                i=1;
            }
        }

        count=0;

        // memset(check,0,sizeof(check)); //만들어진 트리 프린트하기
        // printnode(root);

        maxsum=0;


        printf("Case #%d: %d", i,maxsum);
        if (i<casenum) {
            printf("\n");
        }

      //free를 해준다고 그 주소에 있는 데이터가 지워거나, 그 주소로 접근이 불가능한 것은 아니다.
        freenode(root);
        free(Temp);

    }


    // printf("%d\n", casenum);    // 변수의 내용을 출력
    
    fclose(finput);

    return 0;
}