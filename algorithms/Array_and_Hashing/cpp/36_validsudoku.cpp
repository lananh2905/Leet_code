#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>> &board) {
            

            // Check columns, rows
            for (int i = 0 ; i < 9; i++)
            {
                unordered_set<char> check_col;
                unordered_set<char> check_row;

                for(int j = 0; j < 9; j++)
                {
                    if(board[i][j] != '.'){
                        if((check_col.find(board[i][j]) != check_col.end()))
                        {
                            return false;
                        }
                        check_col.insert(board[i][j]);
                    }

                    if(board[j][i] != '.'){
                        if((check_row.find(board[j][i]) != check_row.end()))
                        {
                            return false;
                        }
                        check_row.insert(board[j][i]);
                    }
                }
            }

            // Check 3x3 sub-boxes
            for (int box_row = 0; box_row < 3; box_row++)
            {
                for (int box_col = 0; box_col < 3; box_col++)
                {
                    unordered_set<char> check_box;

                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            char current = board[box_row * 3 + i][box_col * 3 + j];
                            if (current != '.')
                            {
                                if (check_box.find(current) != check_box.end())
                                {
                                    return false;
                                }
                                check_box.insert(current);
                            }
                        }
                    }
                }
            }
            return true;

        }
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '5', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '6', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '2', '4', '1', '9', '.', '.', '.'},
        {'.', '8', '7', '3', '.', '2', '.', '5', '.'}
    };
    cout << (sol.isValidSudoku(board) ? "Valid Sudoku" : "Invalid Sudoku") << endl;
    return 0;
}