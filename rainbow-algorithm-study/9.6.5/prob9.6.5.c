#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int num;
char letter[25000][16];
int len[25000];

int dep;


typedef struct TreeNode{
    int ind;
    int dep;
    int childnum;
    int done;
    struct TreeNode *leftchild;
    struct TreeNode *rightsibb;
    struct TreeNode *parent;
    struct TreeNode *older;

}Node;


/*
Node *Addsibb(Node *sibb1, Node *new) {
    if ((*sibb1).rightsibb==NULL){
        (*sibb1).rightsibb=new;
    } else {
        Addsibb((*sibb1).rightsibb,new);
    }
    return sibb1;
}
*/

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





int main() {

    int i;

    FILE*finput;
    finput=fopen("9.6.5_input.txt","r");

    fscanf(finput,"%d",&num);

    for (i=0;i<num;i++){
        fscanf(finput,"%s",letter[i]);
        len[i]=strlen(letter[i]);
    }




    return 0;
}