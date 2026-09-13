class Solution {
    public int countOverlaps(int [][] A, int [][] B, int r, int c){
        int n = A.length;
        int cnt = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(row + r < 0 || row + r >= n || col + c < 0 || col + c >= n){
                    continue;
                }

                cnt += A[row][col] * B[row + r][col + c];
            }
        }
        return cnt;
    }
    public int largestOverlap(int[][] A, int[][] B) {
        int n = A.length;
        int maxCnt = 0;

        for(int row = -n + 1; row < n; row++){
            for(int col = -n + 1; col < n; col++){
                int cnt = countOverlaps(A, B, row, col);
                maxCnt = Math.max(maxCnt, cnt);
            }
        }

        return maxCnt;
    }
}