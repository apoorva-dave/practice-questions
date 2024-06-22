class Solution {

    List<List<String>> result = new ArrayList<List<String>>();

    public List<List<String>> solveNQueens(int n) {
        
        List<String> board = new ArrayList<String>();
        for(int i=0; i<n; i++) {
            StringBuilder row = new StringBuilder("");
            for(int j=0; j<n; j++)
                row.append(".");
            board.add(row.toString());
        }
        solve(0, board);

        return result;
    }

    public void solve(int row, List<String> board) {
        if(row == board.size()) {
            result.add(new ArrayList<>(board));
            return;
        }

        for(int j=0; j< board.size(); j++) {
            if(isSafe(row,j,board)) {
                StringBuilder newRow = new StringBuilder(board.get(row));
                newRow.setCharAt(j, 'Q');
                board.set(row, newRow.toString());
                solve(row+1, board);
                newRow.setCharAt(j, '.');
                board.set(row, newRow.toString());
            }
        }
    }

    public boolean isSafe(int row, int col, List<String> board) {
        // row-1, col
        // row-1, col-1
        // row-1, col+1
        for(int i=row-1; i>=0; i--) {
            if(board.get(i).charAt(col) == 'Q') return false;
        }
        for(int i=row-1, j=col-1; i>=0 && j>=0;) {
            if(board.get(i).charAt(j) == 'Q') return false;
            i--;
            j--;
        }
        for(int i=row-1, j=col+1; i>=0 && j<board.size();) {
            if(board.get(i).charAt(j) == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }
}
