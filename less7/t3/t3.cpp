#include<iostream>
using namespace std;

class VectorN
{
  int N = 0;
  int* coord;
public:
  // Конструктор вектора размерности n
  VectorN(unsigned int n){
    N = n;
    coord = new int[n];
  }
  // Деструктор
  ~VectorN(){
    delete[] coord;
  }

  unsigned getSize() const{
    return N;
  }

  int getValue(unsigned int i) const{
    return coord[i];
  }

  void setValue(unsigned int i, int value){
    coord[i] = value;
  }

  bool operator == (const VectorN& v2){
    for(int i = 0; i < this->N; i++){
      if(this->coord[i] != v2.coord[i]){
        return false;
      }
    }
    return true;
  }

  bool operator != (const VectorN& v2){
    return !(*this == v2);
  }
  // Оператор + складывает два вектора покоординатно,
  // возвращает результат как новый экземпляр вектора
  VectorN operator + (const VectorN& v2){
    VectorN res(this->N);
    for(int i = 0; i < this->N; i++){
      res.setValue(i, this->coord[i] + v2.getValue(i));
    }
    return res;
  }
  // Оператор * умножает вектор на скаляр типа int покоординатно,
  // возвращает результат как новый экземпляр вектора.
  VectorN operator * (const int a){
    VectorN res(this->N);
    for(int i = 0; i < this->N; i++){
      res.setValue(i, this->coord[i] * a);
    }
    return res;
  }
  // Умножение должно работать при любом порядке операндов.
};

VectorN operator * (const int a, const VectorN& v){
    VectorN res(v.getSize());
    for(int i = 0; i < v.getSize(); i++){
      res.setValue(i, v.getValue(i) * a);
    }
    return res;
}

int main(){

  VectorN a(4);
  a.setValue(0, 0);
  a.setValue(1, 1);
  a.setValue(2, 2);
  a.setValue(3, 3);
  VectorN b(4);
  b.setValue(0, 0);
  b.setValue(1, -1);
  b.setValue(2, -2);
  b.setValue(3, -3);
  cout << (a == b) << endl;
  cout << (a != b) << endl;
  VectorN c = a + b;
  VectorN d = 5 * c;
  for(unsigned int i = 0; i < a.getSize(); ++i)
  cout << d.getValue(i) << endl;
}