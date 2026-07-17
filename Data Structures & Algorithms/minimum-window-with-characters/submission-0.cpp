class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>hash(256,0);int count=0;
        for(auto it : t)hash[it]++;

        int index=-1;
        int min_len =INT_MAX;
        int l=0,r=0;

        while(r<s.size()){
            if(hash[s[r]]>0)count++;
            hash[s[r]]--;

            while(count==t.size()){
                if((r-l+1)<min_len){
                    min_len=r-l+1;
                    index=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0)count--;
                
                l++;
            }
            r++;
        }
        if(index==-1)return "";
        return s.substr(index,min_len);
    }
};
