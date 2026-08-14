class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> hash(26, 0);
        int i = 0, j = 0;
        int result = 0;

        while(j < n){
            hash[s[j] - 'a']++;
            while(i < j && hash[s[j] - 'a'] > 2){
                hash[s[i]-'a']--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};