arr = input()
bomb = input()
stack = []
length = len(bomb)
last = bomb[-1]
for a in arr:
    stack.append(a)
    if a == last and "".join(stack[-length:]) == bomb:
        del stack[-length:]
answer = "".join(stack)
if answer:
    print(answer)
else:
    print("FRULA")