#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
        vector<vector<string>>ans;
      
    bool isSafe(int row,int col,vector<string>board,int n){

            //check for left upper diagonals
            int dupRow=row,dupCol=col;
            while(row>=0 && col>=0){
                if(board[row][col]=='Q')return false;
                row--;
                col--;
            }
            row=dupRow;
            col=dupCol;
            //check for same row elemtns on left side 
                while(col>=0){
                    if(board[row][col]=='Q')return false;
                    col--;
                }
                row=dupRow;
                col=dupCol;
            //check for left lower diagonals

            while(row<n&&col>=0){
                if(board[row][col]=='Q')return false;
                row++;
                col--;
            }

            //No need to check right upper diagonal ,lower diagonal and side elemtns since we didnt even insert at there and all they are marked default '-'
            return true; 

    }

    void solve(int col,vector<string>board,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,n);
                board[row][col]='.';//after iteration of that particular column we need to remove the queens placed if it return by failure
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
     vector<string>board(n);    
        string sr(n,'.');
        for(int i=0;i<n;i++){
            board[i]=sr; 
        }
     solve(0,board,n); 
     return ans;
    }
};