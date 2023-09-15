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

#문제풀이 아이디어 : 남은 물건들 중에서 찾는 것이 아닌, 멀티탭에 꽃혀있는 물건들 중 가장 나중에 쓰이는 것을 뽑고 카운트하는 식으로 문제를 접근하면 된다!(처음 멀티탭 꼽을 때 중복제거 해야함)