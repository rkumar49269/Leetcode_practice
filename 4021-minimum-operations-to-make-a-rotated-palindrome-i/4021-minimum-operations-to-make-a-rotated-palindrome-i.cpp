class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int ops = 1e9;
        for(int i = 0; i < n; i++){
            int curr = i;
            string t = s;
            rotate(t.begin(), t.begin()+i, t.end());

            for(int j = 0; j < n/2; j++){
                int d = abs(t[j]-t[n-j-1]);
                curr += min(d, 26-d);
            }
            ops = min(ops, curr);
        }
        return ops;
    }
};