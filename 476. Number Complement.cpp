class Solution {
public:
    int findComplement(int num) {
        int digits = 0;
        int mask = 0;
        while(num >> digits)
        {
            digits++;
            mask = (mask << 1) + 1;
        }
        return num ^ mask;
    }
};
/*
Comment:
利用digital來紀錄有幾位bit是有效位數
製作mask來把開頭的0遮蔽(mask = 00...0011...11)
最終所求為 num ^ mask
*/
