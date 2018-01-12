#include <iostream>

using namespace std;

int main(){
    int cnt, sum=0, i=0;
    string nums;
    cin>>cnt;
    cin.ignore();
    getline(cin, nums);
    while(cnt--){
        char c =nums[i++];
        sum += c -'0';
        cout<< cnt<<" "<<c<<" "<<sum<<endl; 
    }
    cout<<sum<<endl;
    return 0;
}  