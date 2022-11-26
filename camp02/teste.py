def menor_string_maior(name):
    rname = sorted(name,reverse = True)
    if name == rname: return -1

print(menor_string_maior('bca'))