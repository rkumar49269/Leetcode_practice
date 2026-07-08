class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        int ans;
        long long sum = 0;
        for(const int& x : chalk){
            sum += x;
        }

        int rem = k % sum;

        for(int i=0; i<n; i++){
            if(rem < chalk[i]) return i;
            rem -= chalk[i];
        }
        return ans;
    }
};