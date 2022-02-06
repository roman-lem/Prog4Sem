#include <iostream>
using namespace std;

int main(){
  int n = 0, m = 0;
  int arr[1000] = {0};
  int temp;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  cin >> m;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  for(int i = n - m; i < n; i++){
    cout << arr[i] << ' ';
  }
  cout << endl;
}