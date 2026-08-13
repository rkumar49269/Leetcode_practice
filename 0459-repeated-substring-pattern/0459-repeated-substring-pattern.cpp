class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for(int l = n/2; l >= 1; l--){
            if(n % l == 0){
                int time = n/l;
                string pattern = "";
                string sub = s.substr(0, l);

                while(time--){
                    pattern += sub;
                }

                if(pattern == s) return true;
            }
        }
        return false;
    }
};