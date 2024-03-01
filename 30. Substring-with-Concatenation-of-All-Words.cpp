class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordLen = words[0].length();
        int wordCnt = words.size();
        int wordsLen = wordLen * wordCnt;
        unordered_map<string, int> hashSample;
        for(auto w:words)
        {
            hashSample[w] += 1;
        }
        int wordsType = hashSample.size();
        for(int start = 0; start < wordLen; start++)
        {
            int left = start;
            int right = left;
            int count = 0;
            unordered_map<string, int> current;

            while(right < s.size() && left <= right)
            {
                string nextWord = s.substr(right, wordLen);
                if(hashSample.find(nextWord) == hashSample.end())
                {
                    left += wordLen;
                    right = left;
                    count = 0;
                    current.clear();
                }
                else if(current[nextWord] < hashSample[nextWord])
                {
                    right += wordLen;
                    current[nextWord] += 1;
                    if(current[nextWord] == hashSample[nextWord])
                    {
                        count += 1;
                    }
                    if(count == wordsType)
                    {
                        result.push_back(left);
                        string removeWord = s.substr(left, wordLen);
                        current[removeWord] -= 1;
                        count -= 1;
                        left += wordLen;
                    }
                }
                else //Word過多，left往前一個wordLen
                {
                    string removeWord = s.substr(left, wordLen);
                    current[removeWord] -= 1;
                    if(current[removeWord] == hashSample[removeWord] -1)
                    {
                        count -= 1;
                    }
                    left += wordLen;
                }
            }
        }
        return result;
    }
};


/*
Algo3:
Comment:
利用hash table sample紀錄每個word應出現的次數(key=word, value=times)
先以初始位置start來做分組處理，比如word長度為4，則第一組0,4,8,... ，第二組1,5,9...
兩個pointer left,right來呈現一個字串的頭尾位置
一個count紀錄目前滿足數量的word type(以此來判斷是否有滿足result條件)
一個hash table current紀錄目前各word的數量

一開始left與right同處於第一個位置(start)
先分析要新增的word(right~right+wordLen):
1. 如果下一個word不屬於sample，則代表此left開頭的str不合規
    -> 直接讓left移動到下一個wordLen，且right也回到left，重新開始(count,current 設回default)
2. 如果下一個word屬於sample，且此word type還未滿(current<sample)
    -> 則讓right移動到下一個wordLen，並更新current, count
    -> 並且判斷count是否已達到所有wordtype皆滿足的數量，若滿足則紀錄此時的left為result
3. 如果下一個word屬於sample，但此word type數量已超過所需(current>=sample)
    -> 則讓left移動到下一個wordLen(移除第一個word)，並更新current, count
    (下一個loop會讓這次的word再判斷一次是否有滿，直到left把此相同的word移除為止)

Time Complexity：O(k*m)
Space Complexity：O(n*k)
n = word數量
k = word長度
m = s字串長度
-> 此方法目前最優解
*/


/*
Algo2:

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordLen = words[0].length();
        int wordCnt = words.size();
        int wordsLen = wordLen * wordCnt;
        unordered_map<string, int> hashSample;
        unordered_map<string, int> hashEmpty;
        for(auto w:words)
        {
            hashEmpty[w] = 0;
        }
        for(auto w:words)
        {
            hashSample[w] += 1;
        }

        for(int t = 0; t < wordLen; t++)
        {
            unordered_map<string, int> hashmap = hashEmpty;
            int left = t;
            int right = t + wordLen * wordCnt;

            for(int i = 0; i < wordCnt; i++)
            {
                string word = s.substr(left + i * wordLen , wordLen);
                if(hashmap.find(word) != hashmap.end())
                {
                    hashmap[word] += 1;
                }
            }
            if(checkSuccess(hashSample, hashmap))
            {
                result.push_back(left);
            }

            while(s.size() >= right)
            {
                string removeWord = s.substr(left , wordLen);
                string addWord = s.substr(right , wordLen);
                left += wordLen;
                right += wordLen;

                if(hashmap.find(removeWord) != hashmap.end())
                {
                    hashmap[removeWord] -= 1;
                }
                if(hashmap.find(addWord) != hashmap.end())
                {
                    hashmap[addWord] += 1;
                }

                if(checkSuccess(hashSample, hashmap))
                {
                    result.push_back(left);
                }
            }
        }
        return result;
    }

private:
    bool checkSuccess(unordered_map<string, int> sample, unordered_map<string, int> test)
    {
        for (const auto& pair : sample)
        {
            if(pair.second != test[pair.first])
            {
                return false;
            }
        }
        return true;
    }
};

Comment:
利用hash table紀錄每個word應出現的次數(key=word, value=times)
先以初始位置來做分組處理，比如word長度為4，則第一組0,4,8,... ，第二組1,5,9...
當同一組內切換不同起始點時，在hash table中去除第一個word，再加入新增的一個word
-> 如此可省調每次起始點不同就要從頭判斷是否合法的步驟(只需更新頭尾各一個word)

Time Complexity：k(n+n+m/k*n) = 2kn + mn = n(2k+m) -> O(n(2k+m))
Space Complexity：O(n*k)
n = word數量
k = word長度
m = s字串長度
-> 此方法會過
*/










/*
Algo1:

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wordLen = words[0].length();
        int wordCnt = words.size();
        int wordsLen = wordLen * wordCnt;
        unordered_map<string, int> hashmap;
        for(auto w:words)
        {
            hashmap[w] = 0;
        }
        int p = 0;
        int right = wordCnt * wordLen;

        while(p < s.size())
        {
            auto subStr = s.substr(p, wordsLen);
            for(int i = 0; i < wordCnt; i++)
            {
                auto word = subStr.substr(i * wordLen , wordLen);
                if(hashmap.find(word) != hashmap.end() && hashmap[word] == 0)
                {
                    hashmap[word] += 1;
                }
                else
                {
                    break;
                }
                if(i == wordCnt-1)
                {
                    result.push_back(p);
                }
            }
            p += 1;
        }
        return result;
    }
};

Comment:
利用hash table紀錄每個word應出現的次數(key=word, value=times)
從s第一個char開始往後取整個需要的長度，並且調整hash table紀錄的數量
-> word出現一次，就減掉hash table內對應的次數，hash table內次數皆為0時即成功符合

Time Complexity：n + m*n -> O(m*n)
Space Complexity：O(n*k)
n = word數量
k = word長度
m = s字串長度
--> 此方法TLE沒過
*/
