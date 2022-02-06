#include <iostream>
using namespace std;

int main(){

  int n = 0, m = 0;
  int arr[2][1000];
  int temp[2] = {0};

  cin >> n;

  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 1000; j++){
      arr[i][j] = 0;
    }
  }

  for(int i = 0; i < n; i++){
    cin >> arr[0][i];
    arr[1][i] = i;
  }

  cin >> m;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[0][j] > arr[0][j + 1]) {
        temp[0] = arr[0][j];
        temp[1] = arr[1][j];
        arr[0][j] = arr[0][j + 1];
        arr[1][j] = arr[1][j + 1];
        arr[0][j + 1] = temp[0];
        arr[1][j + 1] = temp[1];
      }
    }
  }

  for (int i = n - m; i < n - 1; i++) {
    for (int j = n - m; j < n - 1; j++) {
      if (arr[1][j] > arr[1][j + 1]) {
        temp[0] = arr[0][j];
        temp[1] = arr[1][j];
        arr[0][j] = arr[0][j + 1];
        arr[1][j] = arr[1][j + 1];
        arr[0][j + 1] = temp[0];
        arr[1][j + 1] = temp[1];
      }
    }
  }

  for(int i = n - m; i < n; i++){
    cout << arr[0][i] << ' ';
  }
  cout << endl;

  
}