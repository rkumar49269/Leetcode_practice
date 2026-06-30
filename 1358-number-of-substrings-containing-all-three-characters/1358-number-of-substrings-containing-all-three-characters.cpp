class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0;
        int cnt_a = 0, cnt_b = 0, cnt_c = 0;
        int cnt = 0;
        int n = s.length();

        while(j < n){
            if(s[j] == 'a') cnt_a++;
            else if(s[j] == 'b') cnt_b++;
            else if(s[j] == 'c') cnt_c++;

            while(cnt_a > 0 && cnt_b > 0 && cnt_c > 0){
                cnt += (n - j);

                if(s[i] == 'a') cnt_a--;
                else if(s[i] == 'b') cnt_b--;
                else if(s[i] == 'c') cnt_c--;

                i++;
            }
            
            j++;
        }
        return cnt;   
    }
};