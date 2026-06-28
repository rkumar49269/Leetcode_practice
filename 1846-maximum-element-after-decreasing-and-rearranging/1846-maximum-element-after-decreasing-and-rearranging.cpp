class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int maxi = 1;
        arr[0] = 1;

        for(int i=1;i<arr.size();i++){
            if(arr[i] == maxi) continue;
            if(arr[i] > maxi){
                arr[i] = maxi + 1;
            }
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
};