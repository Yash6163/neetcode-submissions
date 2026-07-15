class Solution {
public:
    bool isPalindrome(string s) {
        string copy="";

        for(auto it : s){
            if(isalnum(it))copy+=tolower(it);
        }

        int n=copy.size();
        int l=0,r=n-1;

        while(l<r){
            if(copy[l]==copy[r]){
                l++;r--;
            }
            else return false;
        }
        return true;
    }
};
