class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int>hash(256,0);
        int l=0;
        int len=0,curr=0;
        for(int r=0;r<n;r++){
            curr++;
            hash[s[r]]++;
            while(hash[s[r]]>1 &&l<r){
                hash[s[l]]--;
                l++;
                curr--;
            }
            len=max(len,curr);
        }
        return len;
    }
};
