class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0) return "";
        
        sort(strs.begin(), strs.end());
        string lcp;
        int smallest_len = strs[0].size();
        
        for(int i=0; i<smallest_len; i++) {
            if(strs[0][i] == strs[n-1][i]) 
                lcp += strs[0][i];
            else
                break;
        }
        
        return lcp;
    }
};