class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // array to keep track of last occurance of a character in the given string 
        // (ASCII chars, so size = 256)
        int index[256];  
        memset(index, -1, sizeof(index));

        // 'start' will point to the starting index of the current substring under consideration
        int start = 0, n = s.size();
        int maxLen = 0;  // to store answer
        
        // iterate through characters of the given string
        for(int i=0; i<n; i++) {
            int idx = s[i]; // ASCII number of the current character

            // if character already seen and last occurance was greater than or equals to the 
            // starting position then update 'start'
            if(index[idx] != -1 && index[idx] >= start)
                start = index[idx] + 1;
            
            // update last occurace of current character to current index
            index[idx] = i;

            // update maxLen
            maxLen = max(maxLen, i-start+1);
        }
        
        return maxLen;
    }
};