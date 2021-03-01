#include <stdio.h>

int main (){
    int n,k,kl,ku,ans;
    scanf("%d",n);
    if (n<15){
        kl=3*n;
        ku=2*n;
        if (kl/5<ku/3){
            k=ku/3;
            ans=2*k-n;
        }else if (kl%5==0 || ku%3==0){
            k=kl/5;
            ans=2*k-n;
        }else {
            ans=-1;
        }
    }else {
        kl=3*n;
        if (kl%5==0){
            k=kl/5;
        }else {
            k=kl/5+1;
        }
        ans=2*k-n;
    }
    printf("%d",ans);
}