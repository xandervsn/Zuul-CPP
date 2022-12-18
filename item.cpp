#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

void Item::setName(char* nameOut){
  strcpy(name, nameOut);
}

void Item::getName(char* nameOut){
  strcpy(nameOut, name);
}

void Item::printItem(){
  cout << name << endl;
}