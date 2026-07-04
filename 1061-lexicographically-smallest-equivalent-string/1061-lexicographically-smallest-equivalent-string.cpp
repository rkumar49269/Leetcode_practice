class Solution {
public:
    char dfs_find_min_char(unordered_map<char, vector<char>>& adj, char ch, vector<bool>& visited){
        visited[ch - 'a'] = true;
        char min_char = ch;

        for(auto& c : adj[ch]){
            if(!visited[c - 'a']){
                char x = dfs_find_min_char(adj, c, visited);
                if(min_char > x){
                    min_char = x;
                }
            }
        }
        return min_char;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> adj;
        for(int i=0; i<s1.length();i++){
            char u = s1[i];
            char v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string result;

        for(int i=0; i<baseStr.length(); i++){
            char ch = baseStr[i];
            vector<bool> visited(26, false);

            char min_char = dfs_find_min_char(adj, ch, visited);

            result.push_back(min_char);
        }
        return result;
    }
};