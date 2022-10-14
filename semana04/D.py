def power(base, exp):
    if exp < 0:
        return 1 / power(base, -exp)
    ans = 1
    while exp:
        if exp & 1:
            ans *= base
        exp >>= 1
        base *= base
    return ans

while(True):
    try:
        data = input().split(' ')
        print(data)
        t = int(data[0])
        a = int(data[1])
        b = int(data[2])

        print((power(t,a)-1)/(power(t,b)-1))
    except EOFError:
        break