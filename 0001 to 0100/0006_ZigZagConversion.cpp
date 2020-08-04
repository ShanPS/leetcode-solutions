class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        // traverse the string from start till end but insert elements row by row
        // for that we need a vector of string. One string for each row.
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = true;

        for(char c : s) {
            rows[curRow] += c;
            curRow += goingDown ? 1 : -1;

            // if we reach top row or bottom row then toggle the direction
            if(curRow == 0 || curRow == numRows-1)
                goingDown = !goingDown;
        }

        string ans;
        for(string row : rows) ans += row; // concatenate strings row by row
        return ans;
    }
};