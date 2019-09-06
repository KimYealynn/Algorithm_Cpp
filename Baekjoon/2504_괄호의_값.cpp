#include<iostream>
#include<vector>
using namespace std;
/**
  0 1 2 3 4 5
1 1 1 1 1 1 1
2 1 - 1 1 2 2
5 1 - - - - 1
**/
long change(int total, vector<int> coin)
{
  
  int num = total;
  int len = coin.size();
  vector<long> DP;
	vector<vector<long>> X;
  long answer=0;
  
  for(int j=0;j<len;j++)
    DP.push_back(1);
  
  X.push_back(DP);
  	  
  for(int i = 1; i<=num;++i){
    DP.clear();
    long sum = 0;

    for(int j= 0; j<len;++j){
    	if(i>=coin[j]){
        sum += X[i-coin[j]][j];
      	DP.push_back(sum);
        answer =sum;
      }
      else{
        DP.push_back(sum);
        answer =sum;
      }
    }
    X.push_back(DP);
  }   
    
  return answer;
}

int main()
{
    int test_case;
    cin >>test_case;
    while(test_case--){
	    int total, coin;
	    vector<int > test;
        cin >>coin;
        while(coin--){
            cin >> total;
            test.push_back(total);
        }
        cin >>total;
	    cout<<change(total, test)<<endl;
    }
}
