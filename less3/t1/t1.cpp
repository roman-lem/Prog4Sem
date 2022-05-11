#include<iostream>
using namespace std;

class Train{
  double mass = 1;
  double velocity = 0;
  double x = 0;

public:
  Train(double m){
    mass = m;
  }

  void move(double dt){
    x += velocity * dt;
  }

  void accelerate(double dp){
    velocity += dp/mass;
  }

  double getX(){
    return x;
  }

};

int main(){

  Train t(10);
 t.accelerate(1); // Скорость стала 0.1
 t.move(1);
 cout << "Current X: " << t.getX() << endl;
 t.move(1);
 cout << "Current X: " << t.getX() << endl;
 t.accelerate(-2); // Скорость стала -0.1
 t.move(3);
 cout << "Current X: " << t.getX() << endl;

}