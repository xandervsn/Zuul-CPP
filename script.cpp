#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"

using namespace std;

const int SIZE = 2;

void printArrayDesc(Room**, int);
void printVectorDesc(vector<Room*> &);

int main(){
  Room* list[SIZE];
  vector<Room*> vect;
  char* desc1 = new char[80];
  strcpy(desc1, "1st Room");
  list[0] = new Room(desc1);
  char* desc2 = new char[80];
  strcpy(desc2, "2nd Room");
  list[1] = new Room(desc2);
  printArrayDesc(list, SIZE);
  vect.push_back(list[0]);
  vect.push_back(list[1]);
  printVectorDesc(vect);
  
  return 0;
}

void printArrayDesc(Room** newlist, int size){
  for(int i = 0; i < size; i++){
    cout << newlist[i]->getDesc() << endl;
  }
}

void printVectorDesc(vector<Room*> &newvect){
  for(vector<Room*>::iterator it = newvect.begin(); it != newvect.end(); it++){
    cout << (*it)->getDesc() << endl;
  }
}
