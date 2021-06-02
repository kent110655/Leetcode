class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        while(true)
        {
            if(n == 1)
                break;
            if(n % 3 == 0)
                n /= 3;
            else
                return false;
            
        }
        return true;
    }
};
/*
Comment:
判斷是否為三的次方數
*/
