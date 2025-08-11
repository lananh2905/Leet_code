from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        # Check columns and rows
        for i in range(9):
            
            check_cols = []
            check_rows = []
            
            for j in range(9):
                if(board[i][j] != "."):
                    if(check_cols.count(board[i][j]) > 0):
                        return False
                    
                    check_cols.append(board[i][j])
                    
                if(board[j][i] != "."):
                    if(check_rows.count(board[j][i]) > 0):
                        return False
                    
                    check_rows.append(board[j][i])
                    
        # Check 3x3 sub boxes
        for box_col in range(3):
            for box_row in range(3):
                
                check_subbox = []
                for i in range(3):
                    for j in range(3):
                        char = board[box_col*3 + i][box_row*3 + j]
                        if(char != "."):
                            if(check_subbox.count(char) > 0):
                                return False
                            
                            check_subbox.append(char)
                            
        return True

def main():
    sol = Solution()
    board = [["5","3",".",".","7",".",".",".","."],
             ["6",".",".","1","9","5",".",".","."],
             [".","9","8",".",".",".",".","6","."],
             ["8",".",".",".","6",".",".",".","3"],
             ["4",".",".","8",".","3",".",".","1"],
             ["7",".",".",".","2",".",".",".","6"],
             [".","6",".",".",".",".","2","8","."],
             [".",".",".","4","1","9",".",".","5"],
             [".",".",".",".","8",".",".","7","9"]]
    # Result should be True
    print(sol.isValidSudoku(board))

if __name__ == "__main__":
    main()
    
                            
                            