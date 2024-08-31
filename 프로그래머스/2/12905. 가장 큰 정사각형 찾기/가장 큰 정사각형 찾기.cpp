#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int solution(vector<vector<int>> boards)
{
    int answer = 0;
    vector<vector<int>> board(boards.size() + 1, vector<int>(boards[0].size() + 1, 0));
    for (int i = 0 ; i < boards.size() ; i++){
        for (int j = 0 ; j < boards[0].size() ; j++){
            board[i+1][j+1] = boards[i][j];
        }
    }
    for (int i = 1 ; i < board.size() ; i++){
        for (int j = 1 ; j < board[i].size() ; j++){
            if(!board[i][j])
                continue;
            board[i][j] = min(board[i][j-1], min(board[i-1][j], board[i-1][j-1])) + 1;
            answer = max(answer, board[i][j]);
        }
    }
    return pow(answer, 2);
}