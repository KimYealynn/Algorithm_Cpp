#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> nums;
vector<int> operators;

void solve(){
    int max = -1123456789;
    int min = 1123456789;
    
    queue<vector<int>> Q;
    Q.push(operators);
    
    while(!Q.empty()){
        vector<int> V = Q.front(); // 0:+ 1:- 2:* 3:/ 4:idx 5:num
        Q.pop();
        
        if(V[4] == N){
            max = max < V[5] ? V[5] : max;
            min = min > V[5] ? V[5] : min;
            continue;    
        }
        
        for(int i = 0; i < 4; i++){
            if(V[i] == 0) continue;
            vector<int> tmpV(V.begin(), V.end());
            tmpV[i]--;
            if(i == 0) tmpV[5] += nums[tmpV[4]];
            else if(i == 1) tmpV[5] -= nums[tmpV[4]];
            else if(i == 2) tmpV[5] *= nums[tmpV[4]];
            else tmpV[5] /= nums[tmpV[4]];
            tmpV[4]++;
            
            Q.push(tmpV);
        }
    }
    cout << max << endl << min << endl;
}

int main(){
    int x;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> x;
        nums.push_back(x);
    } 
    
    for(int i = 0; i < 4; i++){
        cin >> x;
        operators.push_back(x);
    }
    
    operators.push_back(1);
    operators.push_back(nums[0]);
    
    solve();
    
    return 0;
}