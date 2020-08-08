class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int ans = 0;
        int curVal = m[s[0]];
        for(int i=1; i<n; i++) {
            int nextVal = m[s[i]];
            
            if(curVal < nextVal) ans -= curVal;
            else ans += curVal;
            
            curVal = nextVal;
        }
        ans += curVal;
        
        return ans;
    }
};