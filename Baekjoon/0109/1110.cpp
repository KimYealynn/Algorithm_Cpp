#include <iostream>

using namespace std;

int main(){
    int start_num, new_num, cnt=0, x, y, sum;
    cin >> start_num;
    new_num = start_num;

    while(true){
        x = new_num/10;
        y = new_num%10;
        sum = x+y;
        new_num = sum%10 + y*10;
        cout<<new_num
        ++cnt;
        if(start_num==new_num) break;
    }
    printf("%d\n",cnt);

    return 0;
}  