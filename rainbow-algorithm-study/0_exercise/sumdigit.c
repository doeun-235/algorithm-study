#include <stdio.h>

int main (){
    char temp;
    int ans,n,i,a;
    ans=0;
    
    scanf("%d\n",&n);
    for (i=0;i<n;i++){
        scanf("%c",&temp);
        a=temp-48;
        ans+=a;
    }
    printf("%d",ans);
}