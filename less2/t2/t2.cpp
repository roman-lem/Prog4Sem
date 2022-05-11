#include <iostream>
#include <vector>
using namespace std;

int main(){

  vector<int> queue;
  int n, k, q;
  string s;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> s;
    if(s == "WORRY"){
      cin >> k;
      queue[k] = 1;
    }

    if(s == "QUIET"){
      cin >> k;
      queue[k] = 1;
    }

    if(s == "COME"){
      cin >> k;
      if(k > 0){
        for(int j = 0; j < k; j++){
          queue.push_back(0);
        }
      }

      if(k <0){
        for(int j = 0; j < -k; j++){
          queue.pop_back();
        }
      }

    }

    if(s == "WORRY_COUNT"){
      q = 0;
      for(int j = 0; j < queue.size(); j++){
        q += (queue[j] == 1) ? 1 : 0;
      }
      cout << q << endl;
    } 
  }
}