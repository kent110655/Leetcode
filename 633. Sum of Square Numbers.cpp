class Solution {
public:
    bool judgeSquareSum(int c) {
        long b = sqrt(c);
        long a = 0;
        while(a<=b)
        {
            long sum = a*a + b*b;
            if(sum==c)
                return true;
            else if(sum<c)
                a++;
            else
                b--;
        }
        return false;
    }
};

/*
利用兩個pointer a,b 來尋找0~c之間的兩個值（滿足a^2+b^2=c）
只需要遍尋一遍即可--> O(sqrt(c))
P.S. 需注意a*a + b*b的部分會overflow，所以使用long來預防。
*/