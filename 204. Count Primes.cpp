class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        vector<bool> record(n+1, false);
        for(int i = 3; i * i <= n; i += 2)
        {
            for(int k = i * i; k < n; k += i * 2)
            {
                record[k] = true;
            }
        }
        int count = 1;
        for(int t = 3; t < n; t += 2)
        {
            if(record[t] == false)
                count++;
        }
        return count;
    }
};
/*
Algo 2:
Comment:
類似Algo 1，但跳過2的倍數，使loop不用跑過偶數部分以加快速度
*/

/*
Algo 1:
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1 || n == 2)
            return 0;
        vector<bool> record(n+1, false);
        int count = 0;
        for(int i = 2; i < n; i++)
        {
            if(record[i] == true)
                continue;
            count++;
            for(long k = long(i) * i; k < n; k += i)
            {
                record[k] = true;
            }
        }
        return count;
    }
};
Comment:
利用埃拉托斯特尼篩法
從小的往大的找，並同時把找過的數的倍數標記不再找它
時間複雜度：Ｏ(n)
空間複雜度：Ｏ(n)
*/
