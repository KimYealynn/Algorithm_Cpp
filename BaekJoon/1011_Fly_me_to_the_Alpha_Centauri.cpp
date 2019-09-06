#include <iostream>

using namespace std;

int main(){
    int testcases;
    long long start, end, len, move;
    cin >> testcases;

    while(testcases--){
        long long cnt = 2;
        cin >> start >> end;
        len = end - start - 2;
        move = 1;
        if(len<=0) cnt = 1;
        while(len>0){
            if(len>(move+1)*2){
                len -= (move+1)*2;
                ++move;
                cnt +=2;
            }
            else if (len>move+1){
                cnt+=2; break;
            }
            else {cnt++; break;}
        }
        cout<<cnt<<endl;
    }
    return 0;
}  