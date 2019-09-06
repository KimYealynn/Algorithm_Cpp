class Solution {
public:
    string longestPalindrome(string s) {
        string long_s ="";
        int size = s.size();
        
        for(int i=0;i <= size*2-1; ++i){
            int left = i/2;
            int right = left + i%2;
            string tmp = "";
            while(left>=0&&right<size&&s[left]==s[right]){
                tmp = s.substr(left,right-left+1);

                long_s=long_s.size()>tmp.size()?long_s:tmp;

                left--;
                right++;
            }
        }
        return long_s;
    }
};