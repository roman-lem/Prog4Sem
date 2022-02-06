#include <iostream>
using namespace std;

int main(){
  int array[1000] = {0};
  int n = 0;
  float average = 0;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> array[i];
    average += array[i];
  }
  average = average/n;

  for(int i = 0; i < n; i++){
    if(array[i] > average){
      cout << array[i] << ' ';
    }
  }
  cout << endl;

  return 0;
}