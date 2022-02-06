#include <iostream>
using namespace std;

int main(){
  int array[10][10];
  int n = 0;

  cin >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> array[j][i];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << array[i][j] << ' ';
    }
    cout << endl;
  }


  return 0;
}