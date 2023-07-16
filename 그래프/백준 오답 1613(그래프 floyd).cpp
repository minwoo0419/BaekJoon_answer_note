#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int n, k, s;
vector < vector <int> > map(401, vector <int>(401, 0));
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    int start, end;
    for (int i = 0 ; i < k ; i++)
    {
        cin >> start >> end;
        if (start <= 0 || start > n || end <= 0 || end > n)
            return 0;
        map[start][end] = -1;
        map[end][start] = 1;

    }
    cin >> s;
    for (int i = 1 ; i <= n ; i++){ //모든 노드 저장 후 거기서 찾기(그래프 floyd 알고리즘)
        for (int j = 1 ; j <= n ; j++){
            for (int v = 1 ; v <= n ; v++){
                if (map[j][v] == 0){
                    if (map[j][i] ==  map[i][v])
                        map[j][v] = map[j][i];
                }
            }
        }
    }
    for (int i = 0 ; i < s ; i++) {
        cin >> start >> end;
        cout << map[start][end] << "\n";
    }
    return 0;
}
