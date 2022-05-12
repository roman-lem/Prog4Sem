#include<iostream>
using namespace std;

class Animal {

public:
  virtual string getType() = 0;
  virtual bool isDangerous() = 0;
};

class Monkey : public Animal{
public:
  string getType(){
    return "Monkey";
  }

  bool isDangerous(){
    return false;
  }
};

class Lion : public Animal{
public:
  string getType(){
    return "Lion";
  }

  bool isDangerous(){
    return true;
  }
};

class ZooKeeper {
  int DanCount = 0;
public:
  ZooKeeper() {}

  void handleAnimal(Animal* a){
    DanCount += (a->isDangerous()) ? 1 : 0;
  }

  int getDangerousCount(){
    return DanCount;
  }
};

int main(){
  ZooKeeper z;
  Monkey *m = new Monkey();
  z.handleAnimal(m);
  delete m;
  m = new Monkey();
  z.handleAnimal(m);
  delete m;
  Lion *l = new Lion();
  z.handleAnimal(l);
  delete l;
  cout << z.getDangerousCount() << endl;
}