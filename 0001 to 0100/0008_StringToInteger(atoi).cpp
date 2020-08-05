class Solution {
public:
    int myAtoi(string str) {
        int i, n = str.size(), num = 0;
        bool isNegative = false;
        
        // skip all spaces and first sign character
        for(i=0; i<n; i++) {
            if(str[i] == ' ') continue;                
            else {
                if(str[i] == '+' || str[i] == '-') {
                    isNegative = (str[i] == '-') ? true : false;
                    i++;
                }
                break;
            }
        }
        
        // if any non digit number comes break out of the loop
        for(; i<n; i++) {
            if(str[i]<'0' || str[i]>'9')
                break;
            
            // check for overflow
            if((num > INT_MAX/10) || (num == INT_MAX/10 && str[i] > '7'))
               return isNegative ? INT_MIN : INT_MAX ;
            
            num = num*10 + (str[i]-'0');
        }
        
        // if negative return -num. else return +num
        return isNegative ? -num : num;
    }
};