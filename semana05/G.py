def geraSub(c, k,  n): #{
	# //se nao for possivel podar: entrada proxima a 30 --> TLE
	if( False ): #{ //colocar algum teste aqui para podar, se possivel
		return
	#}
	if (k == n): #{ // se terminou de gerar um subconjunto
		# for(int i=0;i<n;i++) cout << c[i] << " ";
        
		# cout << "\n";
		return;
	# }
	c[k] = True; #// subconjuntos com o elemento k
	geraSub(c, k+1, n)
	c[k] = False; #// subconjuntos sem o elemento k
	geraSub(c, k+1, n)


def solve(entrada):
    
    print(entrada)
    pass


entrada = []
while True:
    try:
        line = input();
        # print(line)
        if line[0] == '.':
            solve(entrada)
            entrada = []
        else: entrada.append(line)
        
    except EOFError:
        break;