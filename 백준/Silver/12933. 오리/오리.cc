#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> ducks;

bool Solution(char word, char key, int num){

    if(word == key){
        for(int i = 0; i < ducks.size(); i++){
            if(ducks[i].length()%5 == num){
                ducks[i].push_back(word);
                return false;
            }
        }
    }
    if(word == 'q' && key =='q'){
        ducks.push_back("q");
        return false;
    }

    return true;
}
int main(){

    bool fail;
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        fail = true;
        char word = str[i];
        if(ducks.empty()){
            if(word == 'q') {
                ducks.push_back("q");
                fail = false;
            }
        }
        else{
            fail &= Solution(word,'q',0);
            fail &= Solution(word,'u',1);
            fail &= Solution(word,'a',2);
            fail &= Solution(word,'c',3);
            fail &= Solution(word,'k',4);
        }
        
        if(fail) break;
    }
    for(int i = 0; i < ducks.size(); i++){
        if(ducks[i].length() % 5 != 0){
            cout << "-1";
            return 0;
        }
    }
    if(fail) cout << "-1";
    else cout << ducks.size();
}