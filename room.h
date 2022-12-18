#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "Item.h"

using namespace std;

class Room{
 public:
  char name[80];
  char charInput[80];
  map<char*, Room*> mymap;
  map<char*, Room*>::iterator it = mymap.begin();
  void setName(char* nameOut);
  void getName(char* charInput);
  void setExit(char* dir, Room* roomExit);
  void getExit(char* dir, Room*& roomCurrent);
  void printDesc(char* output);
  void addItem(char* nameOut);
  void giveItems(vector<Item*>& playerInv, char* nameOut);
  void takeItems(vector<Item*>& playerInv, char* nameOut);
  vector<Item*> roomItems;
};