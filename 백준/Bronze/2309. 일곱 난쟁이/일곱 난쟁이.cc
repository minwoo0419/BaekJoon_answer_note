#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> nine(9, 0);
int main() {
    vector<int> seven(0);
    int sum = 0;
    for (int i = 0 ; i < 9 ; i++){
        cin >> nine[i];
        sum += nine[i];
    }
    sort(nine.begin(), nine.end());
    for (int i = 0 ; i < 9 ; i++){
        for (int j = i + 1 ; j < 9 ; j++){
            if (sum - nine[i] - nine[j] == 100){
                for (int k = 0 ; k < 9 ; k++){
                     if (k != i && k != j)
                        cout << nine[k] << "\n";
                }
                return 0;
            }

        }
    }
    return 0;
}