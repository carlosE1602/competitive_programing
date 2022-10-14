def solve(n):
    horarios = []
    for i in range(n):
        aux = input().split(' ')
        horarios.append((aux[0],aux[1]))

    horarios.sort(key= lambda tup: (tup[0], tup[1]))

    if(n == 0): return('10:00',8,0)
    first = horarios[0][0]
    last = horarios[-1][1]

    # print(first, last)
    naps = []
    naps.insert(0,('10:00',first))
    naps.append((last,'18:00'))
    # print(horarios)

    for i in range(len(horarios)-1):
        incial = horarios[i][1]
        final = horarios[i+1][0]
        naps.append((incial,final))


    bestNap = [-1,-1]


    for ini,fin in naps:
        h1,m1 = ini.split(':')
        h2,m2 = fin.split(':')

        totalTime = (60*int(h2))+int(m2) - ((60*int(h1))+int(m1))
        
        if bestNap[0] == -1:
            bestNap = (ini, totalTime)
        elif bestNap[1] <= totalTime:
            # print(bestNap[0], bestNap[1], totalTime)
            if(bestNap[1] == totalTime):
                aux = bestNap[0].split(':') 
                auxValue = (int(h1)*60)+int(h2) < (int(aux[0])*60)+int(aux[1])
                if(auxValue):
                    bestNap = (ini, totalTime)
            else:
                    bestNap = (ini, totalTime)

    
    
    return(bestNap[0], bestNap[1]//60, bestNap[1]%60)
        
i = int(0)
while True:
    try:
        n = int(input())
        i+=1
        a,b,c = solve(n)
        print(f"Day #{i}: the longest nap starts at {a} and will last for",end="")
        if(b > 0):
            print(f" {b} hours and",end="")
        print(f" {c} minutes.")
    except EOFError:
        break