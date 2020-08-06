class Solution {
public:
    bool isPalindrome(int x) {
        if(x <= 0)
            return x==0 ? true : false;
        
        long long num = x, revNum = 0;
        while(x) {
            revNum = revNum*10 + x%10;
            x = x/10;
        }
        
        return (num == revNum);
    }
};