#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0 ; i < t ; i++){
        int n, make;
        vector <int> coins;
        cin >> n;
        vector <int> how(10001, 0);
        for (int j = 0 ; j < n ; j++){
            int coin;
            cin >> coin;
            coins.push_back(coin);
        }
        how[0] = 1;
        cin >> make;
        for (int j = 0 ; j < coins.size() ; j++){
            int coin = coins[j];
            for (int k = coin ; k <= make ; k++){
                how[k] += how[k - coin];
            }
        }
        cout << how[make] << "\n";
    }
    return 0;
}
