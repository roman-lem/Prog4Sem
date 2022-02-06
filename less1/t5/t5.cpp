#include <iostream>
using namespace std;

int main(){
  char array[10][10];
  int n = 0, m = 0;
  char c;

  cin >> n >> m;

  for(int y = 0; y < n; y++){
    for(int x = 0; x < m; x++){
      cin.get(c);
      if(c != '\n'){
        array[m-x-1][y] = c;
      }
      else
        x--;
    }
  }

  for(int y = 0; y < m; y++){
    for(int x = 0; x < n; x++){
      cout << array[y][x];
    }
    cout << endl;
  }


  return 0;
}