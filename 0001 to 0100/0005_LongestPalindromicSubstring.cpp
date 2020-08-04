class Solution {
private:
    // function to return maxlen of palindrome having l & r as centers
    int expandAroundCenter(string& s, int& n, int l, int r) {
        while(l >= 0 && r < n && s[l] == s[r]) {
            l--; r++;
        }        
        return r-l-1;
    }
    
public:
    string longestPalindrome(string s) { 
        int n = s.size();
        if(n<2) return s;
        
        int maxlen = 0, start = 0;
        for(int i = 0; i< n; i++) {
            int len1 = expandAroundCenter(s, n, i, i);   // checking for odd length palindrome
            int len2 = expandAroundCenter(s, n, i, i+1); // checking for even length palindrome

            if(max(len1,len2) > maxlen) {                
                maxlen = max(len1,len2);
                start = i - (maxlen-1)/2;
            }
        }

        return s.substr(start, maxlen);
    }
};

// DP-SOLUTION
// string longestPalindrome(string s) {
//     int n = s.size();
//     if(n < 2) return s;

//     bool dp[n][n]; // to keep track of whether a substring is palindrome or not
//     int maxlen = 1, start = 0;

//     for(int i=0; i<n; i++)
//         dp[i][i] = true;
//     for(int i=0; i<n-1; i++) {
//         if(s[i] == s[i+1]) {
//             dp[i][i+1] = true;
//             maxlen = 2; start = i;
//         }
//         else
//             dp[i][i+1] = false;
//     }
//     for(int repeat=0, gap=2; repeat<n-2; repeat++, gap++) {
//         for(int i=0; i<n-2-repeat; i++) {
//             if(dp[i+1][i+gap-1] && s[i]==s[i+gap]) {
//                 dp[i][i+gap] = true;
//                 maxlen = gap+1; start = i;
//             }
//             else
//                 dp[i][i+gap] = false;
//         }
//     } 

//     return s.substr(start, maxlen);
// }