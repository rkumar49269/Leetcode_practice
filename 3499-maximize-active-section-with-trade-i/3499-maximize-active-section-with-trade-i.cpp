class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int ones_cnt = count(begin(s), end(s), '1');
        
        vector<int> zero_cnt;
        int i = 0;

        while(i < n){
            if(s[i] == '0'){
                int start = i;
                while(i < n && s[i] == '0') i++;

                zero_cnt.push_back(i - start);
            }
            else i++;
        }

        int max_pairsum = 0;
        for(int i = 1; i < zero_cnt.size(); i++){
            max_pairsum = max(max_pairsum, zero_cnt[i-1] + zero_cnt[i]);
        }

        return max_pairsum + ones_cnt;
    }
};