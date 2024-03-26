import sys
sys.setrecursionlimit(10**6)
n = int(input())
def func(str, s, e):
    while s < e:
        if str[s] != str[e]:
            return False
        s += 1
        e -= 1
    return True
for i in range(n):
    str = input()
    s, e = 0, len(str) - 1
    if str == str[::-1]:
        print(0)
    else:
        while s < e:
            if str[s] != str[e]:
                check1 = func(str, s+1, e)
                check2 = func(str, s, e-1)
                if check1 or check2:
                    print(1)
                    break
                else:
                    print(2)
                    break
            else:
                s += 1
                e -= 1