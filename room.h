#include <iostream>
#include <cstring>

using namespace std;

class Room{
 public:
  Room();
  Room(char*);
  char* getDesc();
  int getID();
 private:
  char* desc;
  int id;
};
