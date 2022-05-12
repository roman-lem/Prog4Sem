#include<iostream>
using namespace std;

class Material
{
public:

  virtual float getStress(float strain) = 0;
};

class ElasticMaterial : public Material{

  float EMod = 0;
public:
  ElasticMaterial(float elasticModulus){
    EMod = elasticModulus;
  }

  float getStress(float strain){
    return EMod*strain;
  }
};

class PlasticMaterial : public Material{

  float EMod = 0;
  float Lim = 0;

public:
  PlasticMaterial(float elasticModulus, float strainLimit): EMod(elasticModulus), Lim(strainLimit) {};

  float getStress(float strain){
    strain = (strain > Lim) ? Lim : strain;
    return EMod*strain;
  }
};



int main(){

  Material* m;
  m = new ElasticMaterial(100);
  cout << "Material stress is: " << m->getStress(0.1) << endl;
  delete m;
  m = new PlasticMaterial(100, 0.01);
  cout << "Material stress is: " << m->getStress(0.1) << endl;
  delete m;
}