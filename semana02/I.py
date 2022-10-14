class time:
    def __init__(self, name = None, golM = 0, golS = 0, partidas = 0, vit = 0, emp = 0, der = 0, points = 0):
        self.pontos = points
        self.vit = vit
        self.dif= 0
        self.golM = golM
        self.partidas = partidas
        self.name = name

        self.emp= emp
        self.der= der
        self.golS = golS

    def print(self):
        print("nome",self.name)
        print('pontos',self.pontos)
        # print("golsMarcados",self.golM)
        # print("sofridos",self.golS)
        # print("partidas",self.partidas)
        # print("v",self.vit)
        # print("e",self.emp)
        # print("d",self.der)

from operator import itemgetter    
# def compare(time1):

    
def solve(n:int):
    nomeCampeonato = input()

    z = int(input())

    dicionario = {}
    times = {}
    for i in range(z):
        nome = input()
        dicionario[nome] = i
        times[nome] = time(nome)

    z = int(input())

    for i in range(z):
        jogo = input().split('#')
        # print(jogo)
        time1 = jogo[0]
        time2 = jogo[2]

        gol1,gol2 = jogo[1].split('@')
        gol1 = int(gol1)
        gol2 = int(gol2)
        time1 = times[time1]
        time2 = times[time2]

        time1.partidas+=1
        time2.partidas+=1


        # print(time1.golM, time2.golM)

        time1.golM += gol1
        time2.golM += gol2

        time1.dif = time1.dif + gol1-gol2
        time2.dif = time2.dif - gol1+gol2

        
        # print(time1.golM, time2.golM)

        time2.golS += gol1
        time1.golS += gol2

        if gol1 > gol2:
            time1.vit += 1
            time2.der += 1
            time1.pontos +=3
            

        elif gol2 > gol1:
            time2.vit += 1
            time1.der += 1
            time2.pontos +=3

        else:
            time1.emp += 1
            time2.emp += 1
            time1.pontos+=1
            time2.pontos+=1


    result = list(times.values())
    import functools

    # for auto in result:
    #     auto.print()

    
    result.sort(key=lambda time: time.name.lower(), reverse=False)
    result.sort(key=lambda time: time.partidas, reverse=False)
    result.sort(key=lambda time: time.golM, reverse=True)
    result.sort(key=lambda time: time.dif, reverse=True)
    result.sort(key=lambda time: time.vit, reverse=True)
    result.sort(key=lambda time: time.pontos, reverse=True)




    print(nomeCampeonato)
    for i,auto in enumerate(result):
        print(f"{i+1}) ",end = "")
        print(f"{auto.name} {auto.pontos}p, {auto.partidas}g ({auto.vit}-{auto.emp}-{auto.der})",end=", ")
        print(f"{auto.dif}gd ({auto.golM}-{auto.golS})")
    if n!= 1:
        print()

n = int(input())

while True:
    if(n==0): break;
    solve(n)
    n-=1