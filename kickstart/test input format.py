f= open("input.txt", 'r')
allthing = f.readlines()
print(allthing)
i=0
while True :
    print(i)
    line = f.readline()
    if not line : break
    print(line)
    i+=1
f.close

f=open("input.txt","r")
i=0
while True :
    print(i)
    line = f.readline()
    if not line : break
    print(line)
    i+=1
f.close
