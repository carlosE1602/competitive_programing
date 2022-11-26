L = int(input('Entre com um número ímpar (>=5): '))
while L < 5 or L%2 == 0 :
    L = int(input('Entre com com um número ímpar (>=5): '))

pos = 0
while L-2*pos >=0  :
    for i in range(L):
        if i < pos or i >= (L-pos):
            print(' ', end = '')
            
        else:
            print('*', end = '')
    print()
    pos += 1