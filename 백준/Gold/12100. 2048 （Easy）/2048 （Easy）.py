from copy import deepcopy


dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

def input_arr(count):
    graph = []
    for i in range(count):
        graph.append(list(map(int, input().split())))

    return graph
    

def move(arr, x, y, count):
    if (x == 0 and y == 1):
        for i in range(count):
            top = count - 1
            for j in range(count-2, -1, -1):
                if (arr[i][j] != 0):
                    tmp = arr[i][j]
                    arr[i][j] = 0
                    if arr[i][top] == 0:
                        arr[i][top] = tmp
                    elif arr[i][top] == tmp:
                        arr[i][top] = tmp * 2
                        top -= 1
                    else:
                        top -= 1
                        arr[i][top] = tmp
                        
                
    elif (x == 0 and y == -1):
        for i in range(count):
            top = 0
            for j in range(1, count):
                if (arr[i][j] != 0):
                    tmp = arr[i][j]
                    arr[i][j] = 0
                    if arr[i][top] == 0:
                        arr[i][top] = tmp
                    elif arr[i][top] == tmp:
                        arr[i][top] = tmp * 2
                        top += 1
                    else:
                        top += 1
                        arr[i][top] = tmp
    elif (x == 1 and y == 0):
        for j in range(count):
            top = count - 1
            for i in range(count-2, -1, -1):
                if (arr[i][j] != 0):
                    tmp = arr[i][j]
                    arr[i][j] = 0
                    if arr[top][j] == 0:
                        arr[top][j] = tmp
                    elif arr[top][j] == tmp:
                        arr[top][j] = tmp * 2
                        top -= 1
                    else:
                        top -= 1
                        arr[top][j] = tmp
    else:
        for j in range(count):
            top = 0
            for i in range(1, count):
                if (arr[i][j] != 0):
                    tmp = arr[i][j]
                    arr[i][j] = 0
                    if arr[top][j] == 0:
                        arr[top][j] = tmp
                    elif arr[top][j] == tmp:
                        arr[top][j] = tmp * 2
                        top += 1
                    else:
                        top += 1
                        arr[top][j] = tmp
    return arr

def get_max(arr, count):
    max = 0
    for i in range(count):
        for j in range(count):
            if (max < arr[i][j]):
                max = arr[i][j]
    return max

global max
max = 0

def simulation(arr, tmp, count):
    global max
    if (tmp == 5):
        if (max < get_max(arr, count)):
            max = get_max(arr, count)
        return
    for i in range(4):
        tmp_arr = move(deepcopy(arr), dx[i], dy[i], count)
        simulation(tmp_arr, tmp + 1, count)

def main():
    count = int(input())
    arr = input_arr(count)
    simulation(arr, 0, count)
    print(max)

if __name__ == "__main__":
    main()