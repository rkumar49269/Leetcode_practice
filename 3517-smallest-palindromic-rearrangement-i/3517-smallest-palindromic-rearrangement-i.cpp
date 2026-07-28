class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        vector<int> hash(26, 0);
        for(char& ch : s){
            hash[ch - 'a']++;
        }

        char odd = '0';
        string result = "";

        for(int i = 0; i < 26; i++){
            if(hash[i]%2 == 1) odd = 'a' + i;
            int temp = hash[i]/2;
            while(temp--) result.push_back('a' + i);
        }
        string res = result;
        if(odd != '0') result.push_back(odd);

        reverse(begin(res), end(res));

        return result + res;
    }
};