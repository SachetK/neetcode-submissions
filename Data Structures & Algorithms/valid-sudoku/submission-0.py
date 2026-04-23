class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_seen = [set() for i in range(9)]
        col_seen = [set() for i in range(9)]
        box_seen = [set() for i in range(9)]

        for i in range(9):
            for j in range(9):
                val = board[i][j]
                
                if val == '.':
                    continue
                
                box_idx = i // 3 * 3 + j // 3

                if val in row_seen[i] or val in col_seen[j] or val in box_seen[box_idx]:
                    return False
    
                row_seen[i].add(val)
                col_seen[j].add(val)
                box_seen[box_idx].add(val)

        return True
