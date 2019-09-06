#include <iostream>
#include <list>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;
    while(testcases--){
        string str;
        list<char> password;
        list<char>::iterator itr,x;
        
        cin>>str;    
        
        int i = 0, index=0;
        char c = str[i++];
        password.push_back('\n');
        itr=password.begin();
        while(c!='\0'){
            if(isalpha(c)){
                password.insert(itr, c);
                ++index;
            }
            else if(c == '>'&&index<password.size()-1){
                    ++itr; ++index;
            }
            else if(password.size()>1&&index>0){
                if(c == '-'){
                    --index;
                    itr = password.erase(--itr);
                }
                else if(c == '<'){
                    --itr; --index;
                 }  
            }
            c = str[i++];
        }

        for(itr=password.begin(); itr != password.end(); itr++){
            cout<<*itr;
        }
    }
    return 0;
}  

