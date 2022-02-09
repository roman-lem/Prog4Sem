#include <iostream>
#include <vector>
using namespace std;

void VectorPlus(vector<int> &v){
  cout << "Size = " << v.size() << endl;

  for(int i = 0; i < v.size(); i++){
    cout << v[i] << ' ';
    v[i] *= 2;
  }
  cout << endl;
}

int main(){

  vector<int> v = {1, 2, 3, 4};

  VectorPlus(v);
  VectorPlus(v);
  VectorPlus(v);
}