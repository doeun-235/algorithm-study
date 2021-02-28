import numpy as np

casenum=int(input())

for i in range(casenum) :
    infoo =input()
    info=infoo.split(' ')
    n = int(info[0])
    r = int(info[1])
    c = int(info[2])
    s_r = int(info[3])
    s_c = int(info[4])
    
    s=[s_r,s_c]
    
    ins=input()
    ins_list=[]
       
    direc={"N" : [-1,0], "S" : [1,0], "E" : [0,1], "W" : [0,-1]}
    
    for j in range(n) :
        a = ins[j]
        ins_list.append(a)
    
    mapp=np.zeros((r,c)).tolist()
    
    x = s_r-1
    y = s_c-1
    
    for j in range(n) :
        
        mapp[x][y] = 1
        go_direc = direc[ins_list[j]]
        
#        print (go_direc)
        
        done=False 
        while done == False :
            x += go_direc[0]
            y += go_direc[1]
#            print (j, x, y)
            if mapp[x][y]==0 :
                done = True
               
    print ("Case #",end='')
    print (i+1,end='')
    print(":",x+1,y+1) 