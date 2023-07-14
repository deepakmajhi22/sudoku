#include <bits/stdc++.h>
using namespace std;

bool issafe(int i, int j, vector<vector<int> > &board, int val)
{
    int n = board.size();
    // row check
    for (int k = 0; k < n; k++)
    {
        if (val == board[i][k])
            return false;
    }

    // col check
    for (int k = 0; k < n; k++)
    {
        if (val == board[k][j])
            return false;
    }

    // 3*3 check
    for (int k = 0; k < n; k++)
    {
        int a = (3 * (i / 3)) + (k / 3);
        int b = (3 * (j / 3)) + (k % 3);
        if (val == board[a][b])
            return false;
    }

    return true;
}

bool Solve(vector<vector<int> > &board)
{
    int n = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                for (int k = 1; k <= n; k++)
                {

                    if (issafe(i, j, board,k))
                    {
                        board[i][j] =k;
                        bool issolutionpossible = Solve(board);
                        if (issolutionpossible)
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] =0;
                        }
                    }
                }

                return false;
            }
        }
    }

    return true;
}
int main()
{   int n=9;
     int temp;
     vector<vector<int> > sudoku;
    cout<<"please give the inputs of the sudoku(9*9)\n";
    for(int i=0; i<n; i++){ 
    
         vector<int> row;
         
         for(int j=0; j<n; j++){
              cin>>temp;
              row.push_back(temp);
           }
              sudoku.push_back(row);

      }
     

     // solveSudoku(sudoku);
       bool ch = Solve(sudoku);
    if(!ch) {
        cout<<"\n this can not be solved please recheck your input\n ";
        return 0;
    }

    cout<<endl<<"the answer is :\n";
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
          cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
     }

    return 0;
}
