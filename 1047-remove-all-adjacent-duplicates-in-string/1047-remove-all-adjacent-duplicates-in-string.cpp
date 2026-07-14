class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n = s.length();
        string result;

        for(int i=n-1; i>=0; i--){
            if(!st.empty() && st.top() == s[i]) st.pop();
            else st.push(s[i]);
        }

        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};