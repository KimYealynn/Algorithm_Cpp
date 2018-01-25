#define H(a,b) (a<b)?a:b
#define MAX(a,b) (a>b)?a:b

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int He = H(height[i],height[j]);
        int size = (j-i) * He;

        while( j-i > 1){
            if(height[i]>height[j]) j--;
            else i++;

            He=H(height[i],height[j]);
            size = MAX(size, (j-i)*He);
        }
        return size;
    }
}; 