#include <iostream>
#include <cstring>
#include "Room.h"
#include <map>

using namespace std;

void Room::setName(char* nameOut){
  strcpy(name, nameOut);
}

void Room::getName(char* charIn){
  strcpy(charIn, name);
}

void Room::setExit(char* dir, Room* roomExit){
  mymap.insert(pair<char*, Room*>(dir, roomExit));
}

void Room::getExit(char* dir, Room*& roomCurrent){
  for(it = mymap.begin(); it != mymap.end(); ++it){
    if(strcmp(dir, it->first) == 0){
      roomCurrent = it->second;
    }
  }
}

void Room::printDesc(char* output){
  cout << "You are in " << name << endl;
  cout << "Exits: " << endl;
  for(it = mymap.begin(); it!= mymap.end(); ++it){
    if(strcmp("North", it->first) == 0){
      cout << "North";
    }
    if (strcmp("East", it->first) == 0){
      cout << "East";
    }
    if(strcmp("South", it->first) == 0){
      cout << "South";
    }
    if(strcmp("West", it->first) == 0){
      cout << "West";
    }
  }
  cout << endl;
}
