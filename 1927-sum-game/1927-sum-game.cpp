class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int leftSum = 0;
        int rightSum = 0;
        int leftQnmark = 0;
        int rightQnmark = 0;

        for(int i = 0; i < n; i++){
            if(num[i] == '?'){
                if(i < n/2) leftQnmark++;
                else rightQnmark++;
            }
            else{
                if(i < n/2) leftSum += num[i] - '0';
                else rightSum += num[i] - '0';
            }
        }

        int totalQnmark = leftQnmark + rightQnmark;
        if(totalQnmark % 2 == 1) return true;

        int left = 2 * leftSum + 9 * leftQnmark;
        int right = 2 * rightSum + 9 * rightQnmark;

        if(left == right) return false;
        return true;
    }
};