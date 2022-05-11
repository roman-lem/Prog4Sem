#include<iostream>
using namespace std;

class GasHolder
{
  double V = 0;
  double R = 8.31;
  double T = 273;
  double P = 0;

public:

  GasHolder(float v){
    V = v;
  }

  ~GasHolder(){
    V = 0;
    P = 0;
  }

  void inject(float m, float M){
    P += m*R*T/(M*V);
  }

  void heat(float dT){
    P = P*(T+dT)/T;
    T += dT;
  }
  void cool(float dT){
    double T2 = (T-dT < 0) ? 0 : T-dT;
    P = P*T2/T;
    T = T2;
  }
  float getPressure(){
    return (float)P;
  }
};

int main(){

  GasHolder h(1.0);
  h.inject(29, 29);
  cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
  h.inject(29, 29);
  cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
  h.heat(273);
  cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
  h.cool(373);
  cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;
  h.cool(373);
  cout << "Pressure after operation: " << h.getPressure() << " Pa" << endl;

}