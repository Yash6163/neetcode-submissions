class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()) return false;

        unordered_map<char,int> mpp;
        vector<int> hash(26,0);

        for(char it : s1){
            mpp[it]++;
            hash[it-'a']++;
        }

        unordered_map<char,int> mpp2;
        vector<int> hash2(26,0);

        int l = 0, r = s1.size()-1;

        // First window
        for(int i = 0; i <= r; i++){
            hash2[s2[i]-'a']++;
            mpp2[s2[i]]++;
        }

        // Check first window
        if(mpp2.size() == mpp.size()){
            int flag = 0;
            for(auto it : mpp){
                if(hash2[it.first-'a'] != hash[it.first-'a']){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) return true;
        }

        // Sliding window
        while(r + 1 < s2.size()){

            // Remove left character
            hash2[s2[l]-'a']--;
            mpp2[s2[l]]--;
            if(mpp2[s2[l]] == 0)
                mpp2.erase(s2[l]);

            l++;
            r++;

            // Add right character
            hash2[s2[r]-'a']++;
            mpp2[s2[r]]++;

            // Check current window
            if(mpp2.size() == mpp.size()){
                int flag = 0;
                for(auto it : mpp){
                    if(hash2[it.first-'a'] != hash[it.first-'a']){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) return true;
            }
        }

        return false;
    }
};