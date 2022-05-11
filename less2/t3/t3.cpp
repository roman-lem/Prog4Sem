#include <iostream>
#include <vector>
using namespace std;

int main(){
  int dayQ[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  vector<vector<string>> todo;
  todo.resize(dayQ[0]);

  string s;
  int k, n, q, size;
  q = 0;

  cin >> n;

  for(int i = 0; i < n; i++){

    cin >> s;

    if(s == "ADD"){
      cin >> k >> s;
      todo[k-1].push_back(s);
    }

    else if(s == "DUMP"){
      cin >> k;
      size = todo[k-1].size();
      cout << size;

      for(int j = 0; j < size; j++){
        cout << ' ' << todo[k-1][j];
      }
      cout << endl;
    }

    else if(s == "NEXT"){

      q++;
      q = q%12;
      size = todo.size();
      if(dayQ[q] > size){
        todo.resize(dayQ[q]);
      }
      if(dayQ[q] < size){
        for(int j = 0; j < size - dayQ[q]; j++){
          todo[size - j - 2].insert(todo[size - j - 2].end(), todo[size - j - 1].begin(), todo[size - j - 1].end());
        }
        todo.resize(dayQ[q]);
      }
    }
  }
}