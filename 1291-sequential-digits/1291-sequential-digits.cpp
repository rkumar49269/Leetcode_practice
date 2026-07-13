class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        queue<int> que;
        for(int i=1; i<=9;i++){
            que.push(i);
        }

        while(!que.empty()){
            int curr = que.front();
            que.pop();

            if(curr >= low && curr <= high){
                result.push_back(curr);
            }

            int last_digit = curr % 10;
            if(last_digit < 9){
                long long next_num = (long long)curr * 10 + (last_digit + 1);
                if(next_num <= high){
                    que.push(next_num);
                }
            }
        }
        return result;
    }
};