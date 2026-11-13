#include <string>
#include <vector>
#include <iostream>

using namespace std;

void print(vector<vector<int>> board){
    for(int i=0; i<board.size(); ++i){
        for(int j=0; j<board[0].size(); ++j){
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> stack;
    
    for(auto v : moves){
       // cout << "move : " << v << endl;
        int row = 0, flag = 0;
        for(;row<board.size(); ++row){
            if(board[row][v-1]){
                flag = 1;
                break;
            }
        }
        if(flag == 0)   continue;
        

        int poped = board[row][v-1];
        board[row][v-1] = 0;
        
        //cout << "row : " << row << endl;
        //print(board);
        
        if(!stack.empty() && stack.back() == poped){
            stack.pop_back();
            answer += 2;
        }
        else    stack.push_back(poped);
        
    }
    
    return answer;
}