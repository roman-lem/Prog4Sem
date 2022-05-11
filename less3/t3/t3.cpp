#include<iostream>
#include<vector>
using namespace std;

class SpacePort
{
  vector<int> docks;
public:
  
  SpacePort(unsigned int size){
    docks.resize(size);
  }

  bool requestLanding(unsigned int dockNumber){
    if(dockNumber < docks.size() && docks[dockNumber] == 0){
      docks[dockNumber] = 1;
      return true;
    }
    else{
      return false;
    }
  }

  bool requestTakeoff(unsigned int dockNumber){
    if(dockNumber < docks.size() && docks[dockNumber] == 1){
      docks[dockNumber] = 0;
      return true;
    }
    else{
      return false;
    }
  }
};

int main(){

  SpacePort s(5);
  cout << boolalpha << s.requestLanding(0) << endl;
  cout << boolalpha << s.requestLanding(4) << endl;
  cout << boolalpha << s.requestLanding(5) << endl;
  cout << boolalpha << s.requestTakeoff(0) << endl;
  cout << boolalpha << s.requestTakeoff(4) << endl;
  cout << boolalpha << s.requestTakeoff(5) << endl;

}