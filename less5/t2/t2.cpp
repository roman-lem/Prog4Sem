#include<iostream>
using namespace std;

class Storage
{
  int ArrSize = 0;
private:
  int* Array;
public:

  Storage(unsigned int n){
    Array = new int[n];
    ArrSize = n;
  }

  virtual ~Storage(){
    delete[] Array;
    ArrSize = 0;
  }

  unsigned getSize(){
    return ArrSize;
  }

  int getValue(unsigned int i){
    return Array[i];
  }

  void setValue(unsigned int i, int value){
    Array[i] = value;
  }
};

class TestStorage : public Storage {
protected:
  // Унаследованная реализация зачем-то хочет выделить ещё памяти. Имеет право.
  int* more_data;
public:
  // В конструкторе память выделяется,
  TestStorage(unsigned int n) : Storage(n) {
    more_data = new int[n];
  }
  // ... а в деструкторе освобождается - всё честно.
  ~TestStorage() {
    delete[] more_data;
  }
};



int main() {
  Storage *ts = new TestStorage(42);
  delete ts;
  return 0;
}