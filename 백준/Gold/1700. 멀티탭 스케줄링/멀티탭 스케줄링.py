n, k = map(int, input().split())
arr = list(map(int, input().split()))
tap = [0 for i in range(n)]
count = 0
temp = 0
stop = 0
for i in range(k):
    if temp == n:
        stop = i
        break
    if arr[i] not in tap:
        tap[temp] = arr[i]
        temp += 1
for i in range(stop, k):
    if arr[i] in tap:
        continue
    pos = [0 for i in range(k+1)]
    for j in range(n):
        for t in range(i, len(arr)):
            if (tap[j] == arr[t]):
                pos[tap[j]] = t
                break
        if pos[tap[j]] == 0:
            pos[tap[j]] = 100
    m = pos.index(max(pos))
    tap[tap.index(m)] = arr[i]
    count += 1
        
print(count)