class Solution {
public:
    int calculate(string s) {
        long long number = 0;
        int result = 0;
        int sign = 1;
        int n = s.length();
        stack<int> st;

        for(int i=0; i<n; i++){
            if(isdigit(s[i])){
                number = number*10 + (s[i] - '0');
            }
            else if(s[i] == '+'){
                result += (sign * number);
                number = 0;
                sign = 1;
            }
            else if(s[i] == '-'){
                result += (sign * number);
                number = 0;
                sign = -1;
            }
            else if(s[i] == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                result += (number * sign);
                number = 0;

                int lst_sign = st.top(); st.pop();
                int lst_num = st.top(); st.pop();

                result *= lst_sign;
                result += lst_num;
            }
        }
        result += (sign * number);
        return result;
    }
};