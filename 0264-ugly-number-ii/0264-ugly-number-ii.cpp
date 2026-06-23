class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> t(n+1);
        int i2=1,i3=1,i5=1;
        t[1] = 1;

        for(int i=2; i<=n ;i++){
            int i2u = t[i2]*2;
            int i3u = t[i3]*3;
            int i5u = t[i5]*5;

            int minu = min({i2u, i3u, i5u});
            t[i] = minu;
            
            if(minu == i2u) i2++;
            if(minu == i3u) i3++;
            if(minu == i5u) i5++;
        }
        return t[n];
    }
};