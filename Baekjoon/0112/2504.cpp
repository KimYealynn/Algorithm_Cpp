#include <iostream>
#include <stack>
#include <utility>

using namespace std;

bool isPair(char a, char b){
    return a+1 == b || a+2 == b;
}


int main(){
    stack<pair<char,int>> stk;
    string str;
    char c='a', c_pop;
    int i = 0, num_pop, result=1;

    getline(cin, str);
    c = str[i++];
    if(c=='\0') result=0;
    while(c!='\0'){
        if(!result) break;

        if( c == ']' || c == ')'){
            if(!stk.empty() ){
                c_pop = stk.top().first;
                num_pop = stk.top().second;
                stk.pop();
                if( isPair(c_pop,c) ){
                    if(c==']') stk.push( make_pair('N',3));
                    else stk.push( make_pair('N',2));
                }
                else if(c_pop == 'N'){
                    int num = num_pop;
                    while(true) {
                        if(stk.empty()) {result=0; break;}

                        c_pop = stk.top().first;
                        num_pop = stk.top().second;
                        stk.pop();
                        if(c_pop!='N') {
                            if( isPair(c_pop,c) ){
                                if(c_pop =='[') stk.push( make_pair('N',3*num));
                                else stk.push( make_pair('N',2*num));
                            }
                            else result=0;
                            break;
                        }
                        else {
                            num += num_pop;
                        }
                    }
                }
                else {result=0;break;}
            }
            else {result=0; break;}
        }
        else stk.push( make_pair(c,0) );
        c = str[i++];        
    }

    if(!result) printf("%d\n",result);
    else{
        result = 0;
        while(!stk.empty()){
            c_pop = stk.top().first;
            num_pop = stk.top().second;
            stk.pop();
            
            if(c_pop != 'N') {result =0; break;}
            else{
                result += num_pop;
            }
        }
        printf("%d\n", result);
    }
    return 0;
}  

