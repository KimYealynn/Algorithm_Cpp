#include <iostream>

using namespace std;

char chk_equal[3] = {'c', 's', 'z'};
char chk_minus[2] = {'c', 'd'};
char chk_j[2] = {'l', 'n'};

bool check_chroatia(char arr[], char x, int size){
    for(int i=0; i<size; i++){
        if(arr[i]==x){ 
            return true;}
    }
    return false;
}

int main(){
    string str;
    int i=1, cnt=1;
    getline(cin,str);

    char c = str[i++];

    while(c!='\0'){
        cnt++;
        if(c =='=' && check_chroatia(chk_equal, str[i-2], sizeof(chk_equal)/sizeof(char))) {
            --cnt;
            if(i>2 && str[i-2]=='z' && str[i-3]=='d') --cnt;
        }
        else if(c =='-' && check_chroatia(chk_minus, str[i-2], sizeof(chk_minus)/sizeof(char))) 
            --cnt;
        else if(c == 'j' && check_chroatia(chk_j, str[i-2], sizeof(chk_j)/sizeof(char))) 
            --cnt;

        c=str[i++];
    }
    cout<< cnt<<endl;
    return 0;
}  

