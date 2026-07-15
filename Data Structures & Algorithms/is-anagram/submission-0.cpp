class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        vector<int>hash(26,0);
        for(auto it : s)hash[it-'a']++;
        for(auto it : t)hash[it-'a']--;
        for(auto it : hash){
            if(it!=0)return false;
        }
        return true;
    }
};
