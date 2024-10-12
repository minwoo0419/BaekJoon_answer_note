#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, l, r;
vector<vector<int>> maps;
vector<vector<int>> visits;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int bfs(int x, int y, int flag) {
    queue<Point> q;
    q.push(Point(x, y));
    visits[x][y] = flag;
    int cnt = 0, sum = 0;
    
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        cnt++;
        sum += maps[p.x][p.y];

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visits[nx][ny]) continue;

            int diff = abs(maps[p.x][p.y] - maps[nx][ny]);
            if (diff < l || diff > r) continue;

            visits[nx][ny] = flag;
            q.push(Point(nx, ny));
        }
    }

    if (cnt == 1) {
        visits[x][y] = 0;  // 연합이 형성되지 않은 경우 초기화
        return 0;
    }

    // 연합된 지역의 인구를 갱신
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visits[i][j] == flag) {
                maps[i][j] = sum / cnt;
            }
        }
    }

    return 1;
}

int main() {
    cin >> n >> l >> r;
    maps.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maps[i][j];
        }
    }

    int cnt = 0;
    while (true) {
        visits.assign(n, vector<int>(n, 0));
        int flag = 1;
        bool isUnionFormed = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visits[i][j]) continue;
                if (bfs(i, j, flag)) {
                    isUnionFormed = true;
                    flag++;
                }
            }
        }

        if (!isUnionFormed) break;
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}