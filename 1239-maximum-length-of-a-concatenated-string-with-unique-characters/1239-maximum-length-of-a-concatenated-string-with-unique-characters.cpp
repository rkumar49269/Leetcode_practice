class Solution {
public:
    bool hasDup(string s1, string s2){
        int t[26]={0};
        for(char &ch: s1){
            if(t[ch-'a']>0) return true;
            t[ch-'a']++;
        }
        for(char &ch: s2){
            if(t[ch-'a']>0) return true;
        }
        return false;
    }
    int solve(int i, vector<string>& arr, string temp, int n){
        if(i >= n){
            return temp.length();
        }
        int include = 0;
        int exclude = 0;

        if(hasDup(arr[i], temp)){
            exclude = solve(i+1, arr, temp, n);
        }
        else{
            exclude = solve(i+1, arr, temp, n);
            include = solve(i+1, arr, temp+arr[i], n);
        }
        return max(include, exclude);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        return solve(0, arr, "", n);
    }
};