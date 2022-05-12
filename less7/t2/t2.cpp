#include<iostream>
using namespace std;

class Vector2D
{
  int x = 0;
  int y = 0;
public:

 Vector2D() = default;

 Vector2D(int x, int y){
  this->x = x;
  this->y = y;
 }

 ~Vector2D() = default;

 int getX() const{
  return x;
 }
 int getY() const{
  return y;
 }

 void setX(int x){
  this->x = x;
 }
 void setY(int y){
  this->y = y;
 }

 bool operator== (const Vector2D& v2) const{
  return (this->x == v2.x && this->y == v2.y);
 }
 bool operator!= (const Vector2D& v2) const{
  return !(*this == v2);
 }

 Vector2D operator+ (const Vector2D& v2) const{
  Vector2D res;
  res.setX(this->x + v2.x);
  res.setY(this->y + v2.y);
  return res;
 }

 Vector2D operator- (const Vector2D& v2) const{
  Vector2D res;
  res.setX(this->x - v2.x);
  res.setY(this->y - v2.y);
  return res;
 }

 Vector2D operator* (const int a) const{
  Vector2D res;
  res.setX(this->x*a);
  res.setY(this->y*a);
  return res;
 }
};

Vector2D operator* (int a, const Vector2D& v){
  Vector2D res;
  res.setX(v.getX() * a);
  res.setY(v.getY() * a);
  return res;
}

std::ostream& operator<<(std::ostream& os, const Vector2D& v){
  return os << '(' << v.getX() << "; " << v.getY() << ')';
}

std::istream& operator>>(std::istream &is, Vector2D &v){
  int x, y;
  is >> x >> y;
  v.setX(x);
  v.setY(y);
  return is;
}

int main(){
  Vector2D v1;
  cin >> v1;
  cout << v1 << endl;
  Vector2D v2;
  cin >> v2;
  cout << v2 << endl;
  cout << boolalpha << (v1 == v2) << endl;
  cout << boolalpha << (v1 != v2) << endl;
  Vector2D v3 = v1 - v2;
  cout << v3 << endl;
  cout << v3 * 42 << endl;
  cout << 42 * v3 << endl;
}