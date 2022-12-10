#include <iostream>
#include <cstring>
#include "Room.h"

using namespace std;

Room::Room(){
  desc = new char[80];
  id = 0;
}

Room::Room(char* newDesc){
  desc = new char[80];
  strcpy(desc, newDesc);
  id = 0;
}

char* Room::getDesc(){
  return desc;
}

int Room::getID(){
  return id;
}
