#include <bits/stdc++.h>
using namespace std;

int cnt=0;

void printBoard(vector<vector<char>>&board){
    cout<<"----------- Chess Board "<<cnt<<" ----------"<<endl;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(vector<vector<char>> &board, int row, int col){
    // vertical up
    for(int i=row-1;i>=0;i--){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    // diagonally left up
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // diagonally right up
    for(int i=row-1,j=col+1;i>=0 && j<board.size();i--,j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

void nQueens(vector<vector<char>> &board, int row){

    if(board.size() == row){
        cnt++;
        printBoard(board);
        return;
    }

    for(int j=0;j<board.size();j++){
        if(isSafe(board,row,j)){
            board[row][j] = 'Q';
            nQueens(board, row+1);
            board[row][j] = 'X';
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of queens ";
    cin>>n;

    vector<vector<char>> board(n, vector<char>(n, 'X'));
    nQueens(board,0);
}