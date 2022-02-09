#include <iostream>
#include <vector>
using namespace std;

int main(){

  vector<int> tempr;
  int n, temp;
  int k = 0;
  int avg =0;

  cin >> n;
  tempr.resize(n);

  for(int i = 0; i < n; i++){
    cin >> tempr[i];
  }

  for(int i: tempr){
    avg += i;
  }

  avg = avg / tempr.size();

  for(int i = 0; i < tempr.size(); i++){
    if(tempr[i] > avg){
      k++;
    }
  }

  cout << k <<endl;

  for(int i = 0; i < tempr.size(); i++){
    if(tempr[i] > avg){
      cout << i << ' ';
    }
  }
  cout << endl;
}