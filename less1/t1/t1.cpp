#include <iostream>
using namespace std;

int main(){
  int array[1000] = {0};
  int n = 0;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> array[i];
  }

  for(int i = 0; i < n; i++){
    cout << array[n - i - 1] << ' ';
  }
  cout << endl;

  return 0;
}