#include<iostream>
using namespace std;

class Animal
{
protected:
  double mass;
  double speed;
public:
  Animal() {}
  virtual ~Animal() {}
  // Создаём зверушку с заданной массой и скоростью
  Animal(double mass, double speed) {
  this->mass = mass;
  this->speed = speed;
  }
  // Получить массу зверя
  virtual double getMass() const {
  return mass;
  }
  // Получить скорость зверя
  virtual double getSpeed() const {
  return speed;
  }
  // Может ли зверушка нападать на других зверей
  // (не может, зверь мирный)
  virtual bool canAtack() const {
  return false;
  }
  // Съесть другого зверя, не делает ничего, мы же мирные
  virtual void eat(const Animal& a) {
  }
};

class Predator : public Animal{

public:

  Predator(double mass, double speed) {
  this->mass = mass;
  this->speed = speed;
  }

  bool canAtack() const {
    return true;
  }

  void eat(const Animal& a) {
    if(a.getMass() <= this->getMass() && a.getSpeed() <= this-> getSpeed()){
      this->mass += a.getMass();
    }
  }
};

int main(){

  Animal* predator = new Predator(1, 10);
  cout << "Current mass: " << predator->getMass() << endl;
  if(predator->canAtack()) {

    predator->eat(Animal(2, 1)); // Этого не съедим - слишком большой
    cout << "Current mass: " << predator->getMass() << endl;

    predator->eat(Animal(1, 1)); // А вот этого вполне
    cout << "Current mass: " << predator->getMass() << endl;

    predator->eat(Animal(1, 20)); // Этого не выйдет - слишком быстрый
    cout << "Current mass: " << predator->getMass() << endl;

    predator->eat(Animal(2, 2)); // А вот этого догоним
    cout << "Current mass: " << predator->getMass() << endl;
  }
  delete predator;
}