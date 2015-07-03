class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if(s.size() != t.size())
            return false;
        int letters[52] = {0};
        int lettert[52] = {0};

        int len = s.size();
        for(int i = 0; i < len; i ++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                letters[s[i] - 'A'] ++;
            else if(s[i] >= 'a' && s[i] <= 'z')
                letters[s[i] - 'a' + 26] ++;

            if(t[i] >= 'A' && t[i] <= 'Z')
                lettert[t[i] - 'A'] ++;
            else if(t[i] >= 'a' && t[i] <= 'z')
                lettert[t[i] - 'a' + 26] ++;
        }

        for(int i = 0; i < 52; i++)
        {
            if(letters[i] != lettert[i])
                return false;
        }

        return true;
    }
};

