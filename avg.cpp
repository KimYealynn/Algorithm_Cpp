#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int test_cases, nums, num, sum;
    int scores[1001];
    
    cin>>test_cases;
    while(test_cases--){
        cin>>nums;
        sum=0;
        int i=0;
        while(i<nums){
            cin>>num;
            sum+=num;
            scores[i++]=num;
        }
        float avg = (float)sum/(float)nums;
        i=0; sum =0;
        while(i<nums){
            if(scores[i++]>avg) sum++; 
        }
        float result = (float)sum*100.0/(float)nums;
        printf("%.3f%% \n", result);
    }
    
    return 0;
}
