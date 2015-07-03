class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string, vector<string> >group;
        for(int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            group[key].push_back(strs[i]);
        }

        vector<string> result;
        unordered_map<string, vector<string> >::const_iterator iter = group.begin();
        for(; iter != group.end(); iter ++)
        {
            if(iter->second.size() > 1)
                result.insert(result.end(), iter->second.begin(), iter->second.end());
        }

        return result;
    }

};


