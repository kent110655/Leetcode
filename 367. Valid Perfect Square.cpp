class Solution {
public:
    bool isPerfectSquare(int num) {
        int dec = 1;
        while(num >= 0)
        {
            num -= dec;
            dec += 2;
            if(num == 0)
                return true;
        }
        return false;
    }
};
/*
Comment:
利用平方數的性質：由1+3+5+7+...+(2n-1)組成
把num逐一減去1,3,5...即可驗證。(用加的可能會overflow)
*/
