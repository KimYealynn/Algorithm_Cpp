#include <iostream>
#include <list>
#include <utility>

using namespace std;

int main(){
    int testcases, N, M, M_num, max, num, index, cnt;

    cin >> testcases;
    while(testcases--){
        list<pair<int,int>> arr, front;
        list<pair<int,int>>::iterator itr, itr_max;
            
        index = 0;
        cin >> N >> M;
        
        while(N--){
            cin >> num;
            if(index==M) M_num = num;
            arr.push_back(make_pair(num, index++)); 
        }

        cnt = 0;
        while(++cnt){
            for(itr=arr.begin(), itr_max=arr.begin();itr!=arr.end();itr++){
                if(itr->first > itr_max->first) {
                    itr_max = itr;
                }
            }
            if( M == itr_max->second ) break;

            front.splice(front.begin(), arr, arr.begin(), itr_max);
            arr.splice(arr.end(), front);
            arr.pop_front();
        }
        printf("%d\n", cnt);
    }
    return 0;
}  

