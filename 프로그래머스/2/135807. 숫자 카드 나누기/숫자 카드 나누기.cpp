#include <string>
#include <vector>

using namespace std;

int uclid(int a, int b){
    while(a % b > 0){
        int temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int a = arrayA[0], b = arrayB[0];
    for (int i = 1 ; i < arrayA.size() ; i++){
        a = uclid(a, arrayA[i]);
        b = uclid(b, arrayB[i]);
    }
    int aflag = 1, bflag = 1;
    for (int i = 0 ; i < arrayA.size() ; i++){
        if (arrayA[i] % b == 0){
            aflag = 0;
        } 
        if (arrayB[i] % a == 0){
            bflag = 0;
        }
    }
    if (aflag && bflag)
        return max(a, b);
    if (aflag)
        return b;
    if (bflag)
        return a;
    return 0;
}