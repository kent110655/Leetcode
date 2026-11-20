class Node:
    def __init__(self):
        self.next = {}

class WordDictionary:

    def __init__(self):
        self.root = Node()

    def addWord(self, word: str) -> None:
        cur = self.root
        word = word + '#'
        for c in word:
            if c in cur.next:
                cur = cur.next[c]
                matchCh = True
            else:
                node = Node()
                cur.next[c] = node
                cur = node
        

    def search(self, word: str) -> bool:
        st = []
        st.append((self.root, 0))
        word = word + '#'
        
        while st:
            cur, wordIndex = st.pop()
            c = word[wordIndex]
            if c in cur.next:
                if c == '#':
                    return True
                st.append((cur.next[c], wordIndex+1))
            elif c == '.':
                for v in cur.next.values():
                    st.append((v, wordIndex+1))
        return False

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)

"""
Comment:
I use a Trie to represent the structure. In the Trie class, I use a dictionary to store the char and the next Node. Then in the addWord function, I just go through the path that match the new word. If the path already existed, I just pass through it. If it doesn't existed, I would add the Node to the path. Otherwise, I use a end char '#' to represent the end of a word. Then, in the Search function, I use a DFS trversal to go through all the path which is match the word. If the char which I go through is '.', I just let all the chars in this stage get into stack. If I go through the end char '#', that means it is matched. After going through all the path, if I didn't find the matched word, I would return False.
Time Complexity:Ｏ(L), L: len(word)
Space Complexity:Ｏ(Σ L*d), d: cnt of word
"""
