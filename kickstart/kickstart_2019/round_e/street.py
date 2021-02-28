import numpy as np


# def prime_check(a) :
#     b = int (a ** 0.5) + 1
#     check = True
#     for i in range(1,b) :
#         if a % (i+1) == 0 :
#             check = False
#             break
    
#     return check

def sieve (a) :
    
    for i in range(i,a+1):
        if nums[i]==1 :
            for j in range(i+1,a+1) :
                if j % i == 0 :
                    nums[j] = 0



if __name__ == '__main__':
    casenum=int(input())
    
    l=[]
    r=[]
    max_r = 0

    for i in range(casenum) :
        infoo = input()
        info = infoo.split(' ')
        l.append (int(info[0]))
        r.append (int(info[1]))
        if r[i]>=max_r :
            max_r = r[i]

    

    nums = np.ones(max_r+4)

    sieve(35)

    for i in range(36) :
        print (i," ",nums[i])

    # for i in range(casenum) :    
    #     cnt = 0
        
    #     L=divmod(l[i],4)
    #     R=divmod(r[i],4)
        
    #     cnt += (R[0]-L[0]+1)
        
    #     if L[1] > 2 :
    #         cnt -= 1
    #     if R[1] < 2 :
    #         cnt -= 1
            
        
    #     for j in range(L[0]*2+L[1]//2,R[0]*2+R[1]//2+1) :
    #         cnt += nums[2*j+1]
        
    #     if R[1] == 3 :
    #         cnt += nums[r[i]]
            
    
    #     for j in range(L[0]+1,R[0]+1) :
    #         cnt += nums[j]
                
    #     if L[1] ==0 :
    #         cnt+= nums[L[0]]
                
    #     print ("Case #",i+1,": ",cnt)
    
        
        
            
        
        
        
        
        
            
    
    
