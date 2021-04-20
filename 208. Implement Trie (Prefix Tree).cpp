class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* p = this;
        for(auto c:word)
        {
            if(!p->Next[c - 'a'])
                p->Next[c - 'a'] = new Trie();
            p = p->Next[c - 'a'];
        }
        p->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* p = this;
        for(auto c:word)
        {
            if(!p->Next[c - 'a'])
                return false;
            p = p->Next[c - 'a'];
        }
        return p->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* p = this;
        for(auto c:prefix)
        {
            if(!p->Next[c - 'a'])
                return false;
            p = p->Next[c - 'a'];
        }
        return true;
    }
private:
    Trie* Next[26] = {};
    bool isLeaf = false;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


/*
Comment:
改進Algo 1:
不用在內部另外做struct node，直接用Trie來當Node即可。
並且把vector改成array來實作。
*/

/*
Algo 1:
class Trie {
public:
    
    struct TrieNode
    {
        TrieNode():isLeaf(false),Next(26,nullptr){};
        ~TrieNode()
        {
            for(auto n: Next)
            {
                if(n) delete n;
            }
        }
        vector<TrieNode*> Next;
        bool isLeaf;
    };
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for(auto c:word)
        {
            if(!p->Next[c - 'a'])
                p->Next[c - 'a'] = new TrieNode();
            p = p->Next[c - 'a'];
        }
        p->isLeaf = true;
    }

    bool search(string word) {
        TrieNode* p = root;
        for(auto c:word)
        {
            if(!p->Next[c - 'a'])
                return false;
            p = p->Next[c - 'a'];
        }
        return p->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(auto c:prefix)
        {
            if(!p->Next[c - 'a'])
                return false;
            p = p->Next[c - 'a'];
        }
        return true;
    }
private:
    TrieNode* root;
    
    
};
Comment:
實作Trie。
在class內部做出一個struct Node 去實作。
*/
