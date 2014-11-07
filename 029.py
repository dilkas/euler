listas = []
for a in range(2, 101):
  for b in range(2, 101):
    listas.append(a**b)
listas = list(set(listas))
print len(listas)
