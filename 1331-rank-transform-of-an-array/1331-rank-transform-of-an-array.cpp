class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> valueToRank;
        int rank = 1;

        for(int num : nums){
            if(valueToRank.find(num) == valueToRank.end()){
                valueToRank[num] = rank;
                rank++;
            }
        }

        vector<int> ans;

        for(int num : arr){
            ans.push_back(valueToRank[num]);
        }

        return ans;
    }
};