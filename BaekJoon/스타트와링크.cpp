#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

int N;
int members[20][20];

int get_score(vector<int> T){
    int score = 0;
    for(int i = 0; i < T.size()-1; i++){
        for(int j = i+1; j < T.size(); j++){
            score += (members[T[i]][T[j]] + members[T[j]][T[i]]);
        }
    }
    return score;
}

int main()
{   
    cin >> N;
    int min_gap = 50000;
    vector<int> tmp;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> members[i][j];
            
            
    for(int i = 0; i < N/2; i++) tmp.push_back(0);
    for(int i = 0; i < N/2; i++) tmp.push_back(1);
    
    do{
        vector<int> team1;
        vector<int> team2;
        for(int i = 0; i < tmp.size(); i++){
            if(tmp[i]==0) team1.push_back(i);
            else team2.push_back(i);
        }
       
        int gap = abs(get_score(team1) - get_score(team2));
        min_gap = min_gap > gap ? gap : min_gap;
        
    }while(next_permutation(tmp.begin(), tmp.end()));

    cout << min_gap << endl;
    return 0;
}