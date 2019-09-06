class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        string prefix = "";
        for(int i=0; i < strs[0].size(); i++){
            char str = strs[0][i];
            for(int s=1; s<strs.size(); s++){
                if(i>strs[s].size()-1) return prefix;   
                if(str != strs[s][i]) return prefix;
            }
            prefix += str;
        }
        return prefix;
    }
};