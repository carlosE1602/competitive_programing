while True:
    n = int(input())
    if n == 0: break;
    cont = 1
    aux = 0
    #numero da catalan * n!, pois para cada arvóre temos n rotulos
    for i in range(n+2,(2*n)+1):
        cont*=i

    print(cont)