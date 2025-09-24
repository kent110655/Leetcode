class TextEditor {
public:
    list<char> List;
    list<char>::iterator iter;
    TextEditor() {
        iter = List.begin();
    }
    
    void addText(string text) {
        for(auto t:text)
            List.insert(iter, t);
    }
    
    int deleteText(int k) {
        int cnt = 0;
        while(k > 0 && iter != List.begin())
        {
            auto iter2 = iter;
            List.erase(--iter2);
            cnt++;
            k--;
        }
        return cnt;
    }
    
    string cursorLeft(int k) {
        while(k > 0 && iter != List.begin())
        {
            iter--;
            k--;
        }
        auto iter2 = iter;
        string output;
        int leftCnt = 0;
        while(iter2 != List.begin() && leftCnt < 10)
        {
            leftCnt++;
            iter2--;
        }
        for(int i = 0; i < leftCnt; i++)
        {
            output.push_back(*iter2);
            iter2++;
        }
        return output;
    }
    
    string cursorRight(int k) {
        while(k > 0 && iter != List.end())
        {
            iter++;
            k--;
        }
        auto iter2 = iter;
        string output;
        int leftCnt = 0;
        while(iter2 != List.begin() && leftCnt < 10)
        {
            leftCnt++;
            iter2--;
        }
        for(int i = 0; i < leftCnt; i++)
        {
            output.push_back(*iter2);
            iter2++;
        }
        return output;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

 /*
 Comment:
 - Use a doubly linked list (std::list<char>) to represent the text.
 - Maintain an iterator (`iter`) to represent the cursor position.
 - addText: insert each character before the cursor (O(m)).
 - deleteText: erase up to k characters to the left of the cursor (O(k)).
 - cursorLeft / cursorRight: move the cursor k steps left/right,
   then collect up to 10 characters to the left of the cursor for output.
 Time Complexity:
 - addText: O(m), where m = length of inserted text
 - deleteText: O(k), where k = number of deletions
 - cursorLeft / cursorRight: O(k + 10)
 Space Complexity: O(n), where n = total number of characters in the editor
 */
