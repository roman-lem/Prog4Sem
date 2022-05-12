#include<iostream>
using namespace std;

class Student
{
  string Name;
  int Score;
public:

 void setName(string name){
  this->Name = name;
 }

 void setScore(unsigned int score){
  this->Score = score;
 }

 string getName() const{
  return Name;
 }
 
 unsigned int getScore() const{
  return Score;
 }
};

ostream& operator << (ostream &os, const Student &s){
  return os << '\'' << s.getName() << "': " << s.getScore();
}

istream& operator >> (istream &is, Student &s){
  char name[1000];
  is.getline(name, 1000);
  s.setName(name);
  s.setScore(0);
  return is;
}

int main(){
  Student s;
  cin >> s;
  s.setScore(10);
  cout << s << endl;
}