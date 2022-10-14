def calcNaps(horarios):
    horarios.sort()
    results = []
    atual = None
    nxt = None
    if len(horarios) > 1:
        for i in range(len(horarios)-1):
            atual = horarios[i][1].split(':')
            nxt = horarios[i+1][0].split(':')
            
            # print(atual, nxt)

            tempo = (int(nxt[0])*60+int(nxt[1])) - (int(atual[0])*60+int(atual[1]))
            # print(tempo)

            results.append((horarios[i][1],tempo))

        aux1 = horarios[i+1][1].split(':')
        aux = 18*60 - (int(aux1[0])*60+int(aux1[1]))
        results.append((horarios[i+1][1],aux))
    elif len(horarios) == 0:
        return ("10:00",8,0)
    else:
        h,m = horarios[0][1].split(':')
        total = 18* 60 - (int(h)*60 + int(m))
        return (horarios[0][1], total//60, total%60)


    best = results[0]
    for horario in results:
        if horario[1] > best[1]:
            best = horario

    h = int(best[1])//60
    m = int(best[1])%60
    return (best[0],h,m)

def solve(n:int):
    horarios = []

    for i in range(n):
        a = input()
        horarios.append(a)
    
    new_horarios = []
    for h in horarios:
        aux = h.rstrip("\n").split(" ")
        new_horarios.append((aux[0],aux[1]))

    best = calcNaps(new_horarios)

    saida = f"the longest nap starts at {best[0]} and will last"

    if(best[1] != 0): saida+=f" will last for {best[1]} hours and"

    saida+=f" {best[2]} minutes."
    print(saida)
i = int(1)
while True:
    try:
        n = int(input())
        print(f"Day #{i}: ",end="")
        i+=1
        solve(n)
    except EOFError:
        break