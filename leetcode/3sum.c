

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    /*
    int **ans=malloc(sizeof(int*)*2);
    ans[0]=malloc(sizeof(int)*3);
    ans[1]=malloc(sizeof(int)*3);
    
    ans[1][0]=ans[1][1]=ans[0][0]=-1;
    ans[1][2]=2;
    ans[0][1]=1;
    ans[0][2]=0;
    
    *returnSize=2;
    
    
    *returnColumnSizes=malloc(sizeof(int)*2);
    (*returnColumnSizes)[0]=3;
    (*returnColumnSizes)[1]=3;
    //returnColumnSizes=malloc(sizeof(int*)*2);
    
    
    //returnColumnSizes[0]=3;
    //returnColumnSizes[1]=3;
    
    return ans;
    */
    ///*
    
    //sol 1 : 3중 포문. 근데 44ms인데 시간초과라하는거 에바 아님?
    /*
    
    if (numsSize<3){
        *returnSize=0;
        *returnColumnSizes=NULL;
        return NULL;
    }
    
    int i,j,k,a,count,b,c,cnt,ind1,ind2,ind3;
    a=(numsSize*(numsSize-1)*(numsSize-2)/6);
    int **list=malloc(sizeof(int*)*a);
    
    for (i=0;i<a;i++){
        list[i]=malloc(sizeof(int)*3);
    }
    count=0;
    
    for(i=0;i<numsSize;i++){
        b=0-nums[i];
        for(j=i+1;j<numsSize;j++){
            c=b-nums[j];
            for (k=j+1;k<numsSize;k++){
                if (c==nums[k]){
                    if (nums[i]<nums[j]){
                        if (nums[j]<nums[k]){
                            //i<j<k
                            ind1=i;
                            ind2=j;
                            ind3=k;
                        }else {
                            if(nums[i]<nums[k]){
                            //i<k<j
                                ind1=i;
                                ind2=k;
                                ind3=j;
                            }else {
                            //k<i<j
                                ind1=k;
                                ind2=i;
                                ind3=j;
                                    
                            }                            
                        }
                    }else {
                        if (nums[j]<nums[k]){
                            if (nums[k]<nums[i]){
                                //j<k<i
                                ind1=j;
                                ind2=k;
                                ind3=i;
                            }else {
                                //j<i<k
                                ind1=j;
                                ind2=i;
                                ind3=k;
                            }
                        }else {
                            //k<j<i
                            ind1=k;
                            ind2=j;
                            ind3=i;
                        }
                        
                    }
                    list[count][0]=nums[ind1];
                    list[count][1]=nums[ind2];
                    list[count][2]=nums[ind3];
                    count++;
                }
            }
        }
    }
    

    cnt=0;
    if (count==0){
        *returnSize=0;
        *returnColumnSizes=NULL;
        return NULL;
    }

    if (count!=1){        
    
        int *check=malloc(sizeof(int)*count); //아니 count는 4인데 왜 check를 int*3만큼 초기화하려고만 해도 에러 나고, size만큼 하라 하면 2만되는 이유를 모르겠음.
        memset(check,0,sizeof(check));
     
        for (i=0;i<count;i++){
            if (check[i]!=1){
                for (j=i+1;j<count;j++){
                    if (list[i][0]==list[j][0]&&list[i][1]==list[j][1]&&list[i][2]==list[j][2]){
                        check[j]=1;
                        cnt++;
                    }
                }
            }
        }
    
    
    c=count-cnt;
    

    
  
    
    *returnSize=c;
    
    
    *returnColumnSizes=malloc(sizeof(int)*c);
    
    b=0;
  //  if (c!=1){
        
        int **ans=malloc(sizeof(int*)*c);

        for (i=0;i<count;i++){
            if (check[i]!=1){
                ans[b]=malloc(sizeof(int)*3);
                ans[b][0]=list[i][0];
                ans[b][1]=list[i][1];
                ans[b][2]=list[i][2];
     //           ans[b][3]=check[i];
       //         ans[b][4]=i;
                (*returnColumnSizes)[b]=3;
                b++;
            }
        }

        return ans;
    }else {
        *returnSize=1;
        *returnColumnSizes=malloc(sizeof(int)*1);

        int **answ=malloc(sizeof(int*)*1);
        answ[0]=malloc(sizeof(int)*3);
        answ[0][0]=list[0][0];
        answ[0][1]=list[0][1];
        answ[0][2]=list[0][2];
        (*returnColumnSizes)[0]=3;
        
        
        return answ;
    }
    
    
    */
    
    //sol2 분포를 파악하기 - 근데 이것도 32ms 나오는데 시간초과라고? 에바다 진짜
    
    int min,max,i,j;
    
    
    if (numsSize<3){
        *returnSize=0;
        *returnColumnSizes=NULL;
        return NULL;
    }
    
    min=nums[0];
    max=nums[0];
    
    
    for (i=1;i<numsSize;i++){
        if (min>nums[i]){
            min=nums[i];
        }  
        if (max<nums[i]){
            max=nums[i];
        }
    }
    
    if (min>=1 || max<=-1){
        *returnSize=0;
        *returnColumnSizes=NULL;
        return NULL;
    }
    
    
    int *dist=malloc(sizeof(int)*(max-min+1));
    for (i=0;i<max-min+1;i++){
        dist[i]=0;
    }
    
    int a;
   
    
    for (i=0;i<numsSize;i++){
        a=nums[i];
        dist[a-min]+=1;
    }
    
     
  
    int b,c,cnt,amount;
    
      
    
    
    amount=(numsSize*(numsSize-1)*(numsSize-2))/6;
    
 
    
    
    int **list=malloc(sizeof(int*)*amount);
    for (i=0;i<amount;i++){
        list[i]=malloc(sizeof(int)*3);
    }

     
    
    
    
    a=0;
    cnt=0;
       
    
    for (i=0;i<0-min+1;i++){
        if (dist[i]>0){
            dist[i]-=1;
            b=0-(i+min);
            for (j=i;2*j<=b-2*min;j++){
                
                if (b-(j+min)-min>=0 &&b-(j+min)-min<max-min+1 && j< max-min+1){
                    if (dist[j]>0){
                    if (j+min!=b-(j+min) && dist[b-(j+min)-min]>0){
                        list[cnt][0]=i+min;
                        list[cnt][1]=j+min;
                        list[cnt][2]=b-(j+min);
                        cnt++;
                    }else if (j+min==b-(j+min) && dist[j]>1){
                        list[cnt][0]=i+min;
                        list[cnt][1]=j+min;
                        list[cnt][2]=j+min;
                        cnt++;
                    }              
                    }
                }
            }
            dist[i]+=1;
        }
    }
/*    
    *returnSize=0;
        *returnColumnSizes=NULL;
        return NULL;        
    
  */
    
    if (cnt==0){
        *returnSize=0;
        *returnColumnSizes=NULL;
        return NULL;        
    }
    free(dist);
    *returnColumnSizes=malloc(sizeof(int)*cnt);
    *returnSize=cnt;
    int **ans=malloc(sizeof(int*)*cnt);
    for (i=0;i<cnt;i++){
        ans[i]=malloc(sizeof(int)*3);
        ans[i][0]=list[i][0];
        ans[i][1]=list[i][1];
        ans[i][2]=list[i][2];
        (*returnColumnSizes)[i]=3;
    }
    
    return ans;
    
}

