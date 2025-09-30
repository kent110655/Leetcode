class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string cur = "";
        path += '/';
        for(int i = 0; i < path.size(); i++)
        {
            switch(path[i])
            {
                case '/':
                    if(cur == "..")
                    {
                        if(!v.empty())
                            v.pop_back();
                    }
                    else if(cur == "." || cur == "")
                    {
                        // do nothing
                    }
                    else
                    {
                        v.push_back(cur);
                    }
                    cur = "";
                    break;
                default:
                    cur += path[i];
                    break;
            }
        }
        string result = "";
        if(v.empty())
            return "/";
        for(int j = 0; j < v.size(); j++)
        {
            result += "/" + v[j];
        }
        return result;
    }
};

/*
Comment:
We use a vector to store the string which is from separated string by '/'. If we meet a char which is not '/', we can push into current string. When we meet '/', we could process the current string with situation.
Time Complexity:Ｏ(n)
Space Complexity:Ｏ(n)
*/
