valores = [44, 66, -35, 30, -45, 46, -32]
contador = 0

def sorpresa(valor):
    global contador
    if contador < len(valores):
        valor += valores[contador]
        contador+=1
        return chr(valor) + sorpresa(valor)
    else:
        return ""

print("https://amzn.to/" + sorpresa(7))