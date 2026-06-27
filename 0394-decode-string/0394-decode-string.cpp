class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> num;

        int cnt = 0;
        string s1 = "";

        for(int i=0; i<s.length(); i++){
            char c = s[i];

            if(c >= '0' && c <= '9'){
                cnt = cnt * 10 + (c - '0');
            }
            else if(c == '['){
                st.push(s1);
                num.push(cnt);
                s1 = "";
                cnt = 0;
            }
            else if( c == ']'){
                int n = num.top(); num.pop();
                string s2 = st.top(); st.pop();
                string res;
                res += s2;
                while(n--) res += s1;
                s1 = res;
            }
            else{
                s1 += c;
            }
        }
        return s1;
    }
};