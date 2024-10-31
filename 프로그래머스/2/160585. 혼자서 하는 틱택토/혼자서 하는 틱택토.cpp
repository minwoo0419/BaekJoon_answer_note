#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

bool isWin(vector<string> &board, char c){
    int cnt = 0, rcnt = 0;
    for (int i = 0 ; i < 3 ; i++){
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c) 
            return true;
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
            return true;
        if (board[i][i] == c) cnt++;
        if (board[i][2 - i] == c) rcnt++;
    }
    return cnt == 3 || rcnt == 3;
}

int solution(vector<string> board) {
    int ocnt = 0, xcnt = 0;
    for (int i = 0 ; i < board.size() ; i++){
        for (auto c : board[i]){
            if (c == 'O') ocnt++;
            else if (c == 'X') xcnt++;
        }
    }
    bool oWin = isWin(board, 'O'), xWin = isWin(board, 'X');
    if (ocnt > xcnt + 1 || ocnt < xcnt) return 0;
    if (oWin && ocnt == xcnt) return 0;
    if (xWin && ocnt > xcnt) return 0;
    return 1;
}