class Solution {
public:
    int n;
    int MOD = 1e9+7;
    vector<vector<pair<int, int>>> dp;

    bool isValid(int i, int j, vector<string>& board){
        return (i >= 0 && i < n && j >= 0 && j < n);
    }
    int getIntFromChar(char ch){
        return ch != 'S' ? ch - '0' : 0;
    }
    pair<int, int> solve(int i, int j, vector<string>& board){
        if(board[i][j] == 'E') return {0, 1};
        if(board[i][j] == 'X') return {0, 0};
        if(dp[i][j] != make_pair(-1, -1)) return dp[i][j];

        int upscore = 0, upPaths = 0;
        int leftscore = 0, leftPaths = 0;
        int diagscore = 0, diagPaths = 0;

        char ch = board[i][j];

        if(isValid(i-1, j, board)){
            auto [score, paths] = solve(i-1, j, board);
            upscore = score;
            upPaths = paths;

            if(upPaths > 0) upscore += getIntFromChar(ch);
        }

        if(isValid(i, j-1, board)){
            auto [score, paths] = solve(i, j-1, board);
            leftscore = score;
            leftPaths = paths;
            if(leftPaths > 0) leftscore += (ch != 'S' ? ch - '0' : 0);
        }

        if(isValid(i-1, j-1, board)){
            auto [score, paths] = solve(i-1, j-1, board);
            diagscore = score;
            diagPaths = paths;
            if(diagPaths > 0) diagscore += (ch != 'S' ? ch - '0' : 0);
        }

        int bestScore = 0, bestPaths = 0;
        if(upscore == leftscore && leftscore == diagscore){
            bestScore = leftscore;
            bestPaths = upPaths + leftPaths + diagPaths;
        }
        else if(upscore == leftscore){
            bestScore = leftscore;
            bestPaths = upPaths + leftPaths;
            if(diagscore > bestScore || (diagscore == bestScore && diagPaths > bestPaths)){
                bestScore = diagscore;
                bestPaths = diagPaths;
            }
        }
        else if(leftscore == diagscore){
            bestScore = leftscore;
            bestPaths = leftPaths + diagPaths;
            if(upscore > bestScore || (upscore == bestScore && upPaths > bestPaths)){
                bestScore = upscore;
                bestPaths = upPaths;
            }
        }
        else {
            bestScore = upscore;
            bestPaths = upPaths;
            if(leftscore > bestScore || (leftscore == bestScore && leftPaths > bestPaths)){
                bestScore = leftscore;
                bestPaths = leftPaths;
            }
            if(diagscore > bestScore || (diagscore == bestScore && diagPaths > bestPaths)){
                bestScore = diagscore;
                bestPaths = diagPaths;
            }
        }
        return dp[i][j] = {bestScore, bestPaths%MOD};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size();
        dp.assign(n, vector<pair<int, int>>(n, {-1, -1}));
        
        pair<int, int> result = solve(n-1, n-1, board);

        return {result.first, result.second};
    }
};