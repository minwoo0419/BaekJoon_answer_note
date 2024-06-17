#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<sstream>
#include<cmath>
#include<regex>
#include<algorithm>
#include<deque>
using namespace std;
int r, c, t;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
vector<int> clean;
vector< vector<int> > maps(50, vector<int>(50, 0));
void wind(int idx){
    int x = clean[idx];
    int y = 1;
    int tmp = 0, pre = 0;
    int k = 0;
    while(x != clean[idx] || y != 0){
        tmp = maps[x][y];
        maps[x][y] = pre;
        pre = tmp;
        if ((x == clean[idx] || x == 0 || x == r - 1) && (y == 0 || y == c - 1)){
            idx == 0 ? k = (k + 1) % 4 : k = (k + 3) % 4;
        }
        x += dx[k];
        y += dy[k];
    }
}
void flood(){
    vector< vector<int> > temp_maps(50, vector<int>(50, 0));
    for (int i = 0 ; i < r ; i++){
        for (int j = 0 ; j < c ; j++){
            if (maps[i][j] == -1)
                temp_maps[i][j] = -1;
            if (maps[i][j] <= 0)
                continue;
            int cnt = 0;
            for (int k = 0 ; k < 4 ; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c || maps[nx][ny] == -1)
                    continue;
                temp_maps[nx][ny] += maps[i][j] / 5;
                cnt++;
            }
            temp_maps[i][j] += maps[i][j] - maps[i][j] / 5 * cnt;
        }
    }
    maps = temp_maps;
}

int main(int argc, char** argv)
{
    cin >> r >> c >> t;
    for (int i = 0 ; i < r ; i++){
        for (int j = 0 ; j < c ; j++){
            cin >> maps[i][j];
            if (maps[i][j] == -1)
                clean.push_back(i);
        }
    }
    for (int i = 0 ; i < t ; i++){
        flood();
        for (int j = 0 ; j < 2 ; j++){
            wind(j);
        }
    }
    int sum = 0;
    for (int i = 0 ; i < r ; i++){
        for (int j = 0 ; j < c ; j++){
            if (maps[i][j] > 0)
                sum += maps[i][j];
        }
    }
    cout << sum;
    return 0;
}