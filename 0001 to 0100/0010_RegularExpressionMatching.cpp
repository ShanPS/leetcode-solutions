class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size(), p_size = p.size();
        bool dp[s_size+1][p_size+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        
        for(int j=2; j<=p_size; j++)
            if(p[j-1] == '*') dp[0][j] = dp[0][j-2];

        for(int i=1; i<=s_size; i++) {
            for(int j=1; j<=p_size; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') {
                    if(dp[i][j-2])
                        dp[i][j] = true;
                    else if(s[i-1] == p[j-2] || p[j-2] == '.')
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[s_size][p_size];
    }
};