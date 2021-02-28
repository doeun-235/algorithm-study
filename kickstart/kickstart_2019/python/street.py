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
    nums[0]=0
    nums[1]=0
    for i in range(2,a+1):
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

    sieve(max_r+3)

    # for i in range(36) :
    #     print (i," ",nums[i])

    for i in range(casenum) :    
        cnt = 0
        
        # 범위에 있는 수 중에서, 소수, 2*홀수(4k+2), 4*소수 꼴만 가능 / 2는 소수이면서도 4k+2꼴이기 때문에 처리해줘야

        L=divmod(l[i],4)
        R=divmod(r[i],4)
        
        # 4k+2 꼴의 개수 : 몫의 차이로 계산
        cnt += (R[0]-L[0]+1)
        
        #끝가ㅄ 처리 아니 값이 안쳐져 코드에서만. 이유를 모르겠네
        if L[1] > 2 :
            cnt -= 1
        if R[1] < 2 :
            cnt -= 1

        # print(cnt)
            
        
        # 홀수인 소수 개수 세기 : 2도 제외할 겸 짝수까지 포문 다 돌릴 필요 없으니깐
        for j in range(L[0]*2+L[1]//2,R[0]*2+R[1]//2+1) :
            cnt += nums[2*j+1]
        
        if (R[1] == 0 or R[1]== 2) : #예제에서 11 이나 103같은게 들어가는 케이스 제외
            cnt -= nums[r[i]+1]

        # print(cnt)

        # 4p꼴 세기
        for j in range(L[0]+1,R[0]+1) :
            cnt += nums[j]
                
        if L[1] ==0 :
            cnt+= nums[L[0]]

        cnt=int(cnt)
        cnum=str(i+1)
        pnt = "Case #"+cnum+":"
        print (pnt,cnt)
    
        
        
            
        
        
        
        
        
            
    
    
