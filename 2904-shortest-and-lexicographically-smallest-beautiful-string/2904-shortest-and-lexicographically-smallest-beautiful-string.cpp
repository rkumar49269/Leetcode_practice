class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans; 
        int left = 0, right = 0, count = 0;

        while (right < n) {
            if (s[right] == '1') {
                count++;
            }
            while (left < n && count == k) {
                string sub = s.substr(left, right - left + 1);
                if (ans.empty() || sub.size() < ans.size()) {
                    ans = sub;
                } else if (sub.size() == ans.size()) {
                    ans = min(ans, sub);
                }
                if (s[left] == '1') {
                    count--;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};