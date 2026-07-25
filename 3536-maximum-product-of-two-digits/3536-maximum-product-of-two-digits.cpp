class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int sz = s.length();
        int maxi = INT_MIN;
        int second_maxi = INT_MIN;

        for(int i = 0; i < sz; i++){
            int num = s[i] - '0';
            if (num > maxi) {
                second_maxi = maxi;
                maxi = num;
            } else if (num >= second_maxi){
                second_maxi = num;
            }
        }
        return (maxi * second_maxi);
    }
};