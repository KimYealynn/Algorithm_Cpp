#include <iostream>

using namespace std;

int main(){
    string str;
    char c;
    int cnt=0,i=0;
    bool isFirst=true;
   
    getline(cin, str);
    cout<<str;

   while(true){
       c=str[i++];
       cout<<c<<endl;
       if(c=='\n'|| c=='\0') break;
       else if(c == ' '){
           isFirst=true;
       }
       else if(isFirst) {
           isFirst=false;
           cnt++;
       }
   }
   cout<<cnt<<endl;
    return 0;
}  