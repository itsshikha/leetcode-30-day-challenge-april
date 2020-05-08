/*
  Given an array of strings, group anagrams together.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        multimap<string, string> hash_map;
        int size = strs.size();
        for(int i=0; i<size; i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            hash_map.insert(pair<string, string> (temp,strs[i]));
        }
        vector<vector<string>> res;
        string prev = hash_map.begin()->first;
        string curr = hash_map.begin()->second;
        res.push_back({curr});
        int i = 0;
        multimap <string, string> :: iterator itr;
        for(itr = ++hash_map.begin(); itr!=hash_map.end(); itr++){
            if(itr->first == prev){
                res[i].push_back(itr->second);
            }
            else{
                res.push_back({itr->second});
                prev = itr->first;
                i++;
            }
        }
        return res;
    }
};
