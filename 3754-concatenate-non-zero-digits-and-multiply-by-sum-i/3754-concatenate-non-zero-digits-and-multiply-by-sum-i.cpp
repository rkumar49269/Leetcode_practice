class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string r;

        for(int i=0; i<s.size();i++){
            if(s[i] != '0') r.push_back(s[i]);
        }

        if(r.empty()) return 0;

        int cnt = 0;
        for(int i=0; i<r.size(); i++){
            cnt += (r[i]-'0');
        }
        return (long long)stoi(r) * cnt;
    }
};