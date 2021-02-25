class Solution {
public: 
    string frequencySort(string s) {
        vector<int> counts(128);
        for(auto u:s)
        {
            counts[u]++;
        }
        vector<pair<int,char>> freq;
        for(int i=0;i<128;i++)
        {
            if(counts[i]>0)
                freq.push_back(make_pair(counts[i],i));
        }
        sort(freq.begin(),freq.end(),[&](pair<int,char> a,pair<int,char> b){return a.first>b.first;});
        string ans="";
        for(auto t:freq)
        {
            ans.append(t.first,t.second);
        }
        return ans;
    }
};


/*
algo 1: hash + sort string
    string frequencySort(string s) {
        unordered_map<char,int> counts;
        for(auto u:s)
        {
            counts[u]++;
        }
        sort(s.begin(),s.end(),[&](char& a,char& b)
             {
                 return counts[a]>counts[b] ||(counts[a]==counts[b]&&a>b);
             });
        return s;
    }
comment:
當key不多的時候，使用hash的unordered_map反而會很慢，不如用map、vector。
（因為hash基數很大）
Time complexity: Ｏ(nlogn)
*/

/*
algo 2: map + sort string
    string frequencySort(string s) {
        map<char,int> counts;
        for(auto u:s)
        {
            counts[u]++;
        }
        sort(s.begin(),s.end(),[&](char& a,char& b)
             {
                 return counts[a]>counts[b] ||(counts[a]==counts[b]&&a>b);
             });
        return s;
    }
comment:
Time complexity: Ｏ(nlogn*logk)
但因為key不多，所以速度反而比hash快。
*/

/*
algo 3:vector + sort string
    string frequencySort(string s) {
        vector<int> counts(128);
        for(auto u:s)
        {
            counts[u]++;
        }
        sort(s.begin(),s.end(),[&](char& a,char& b)
             {
                 return counts[a]>counts[b] ||(counts[a]==counts[b]&&a>b);
             });
        return s;
    }
comment:
事先創建大小128個element的vector(因為char範圍：0~127)
Time complexity: Ｏ(nlogn)
*/

/*
algo 4: vector + sort vector + string+=
    string frequencySort(string s) {
        vector<int> counts(128);
        for(auto u:s)
        {
            counts[u]++;
        }
        vector<pair<int,char>> freq;
        for(int i=0;i<128;i++)
        {
            if(counts[i]>0)
                freq.push_back(make_pair(counts[i],i));
        }
        sort(freq.begin(),freq.end(),[&](pair<int,char> a,pair<int,char> b){return a.first>b.first;});
        string ans="";
        for(auto t:freq)
        {
            ans.append(t.first,t.second);
        }
        return ans;
    }
    
comment:
1. 用vector來存frequence、char。
2. sort vector來找到排序
3. 用排序後的vector依序把string ans做出來。
前三個algo的string是sort出來的，而此algo的string是新創建出來的，所以比較快。
*/
