#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n, m;
map<string, int> name;
int main(int argc, char** argv)
{
    vector<string> ans;
    cin >> n >> m;
    for (int i = 0 ; i < n + m ; i++){
        string s;
        cin >> s;
        name[s]++;
        if(name[s] > 1)
            ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}