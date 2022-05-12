#include<iostream>

namespace namespaceA {
  class Engine {
  public:
    void run() {
      std::cout << "EngineA run" << std::endl;
    }
  };
}
namespace namespaceB {
  class Engine {
  public:
    void run() {
      std::cout << "EngineB run" << std::endl;
    }
  };
}
namespace namespaceC {
  class Engine {
  public:
    void run() {
      std::cout << "EngineC run" << std::endl;
    }
  };
}

class MyEngine {
public:
  void run(unsigned int number){
    switch(number){
      case 1:
        namespaceA::Engine objA;
        objA.run();
        break;
      case 2:
        namespaceB::Engine objB;
        objB.run();
        break;
      case 3:
        namespaceC::Engine objC;
        objC.run();
        break;
      default:
        break;
    }
  }
};


int main(){
  MyEngine e;
 e.run(1); // вызов run из Engine-а из библиотеки A
 e.run(2); // вызов run из Engine-а из библиотеки B
 e.run(3); // вызов run из Engine-а из библиотеки C
 e.run(10); // ничего не происходит
}