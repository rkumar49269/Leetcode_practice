class Solution {
public:
    int minAddToMakeValid(string s) {
        int size = 0;
        int open = 0;
        for(char &c : s){
            if(c == '(') size++;
            else if(c == ')' && size > 0) size--;
            else open++;
        }

        return open + size;
    }
};