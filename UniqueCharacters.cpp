class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        if(str.empty())
            return true;

        set<char> characters;

        for(int i = 0; i < str.size(); i++)
        {
            if(characters.count(str[i]))
                return false;
            else
                characters.insert(str[i]);
        }

        return true;
    }
};

