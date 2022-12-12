#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include <map>


using namespace std;

int main(){
  char input[80];
  char output[80];

  char* north = (char*)("North");
  char* east = (char*)("East");
  char* south = (char*)("South");
  char* west = (char*)("West");

  Room* cafeteria = new Room();
  cafeteria->setName((char*)("cafeteria "));
  Room* n_hall = new Room();
  n_hall->setName((char*)("n_hall"));
  Room* up_engine = new Room();
  up_engine->setName((char*)("up_engine"));
  Room* w_hall = new Room();
  w_hall->setName((char*)("w_hall "));
  Room* reactor = new Room();
  reactor->setName((char*)("reactor "));
  Room* cams = new Room();
  cams->setName((char*)("cams "));
  Room* low_engine = new Room();
  low_engine->setName((char*)("low_engine "));
  Room* electrical = new Room();
  electrical->setName((char*)("electrical "));
  Room* storage = new Room();
  storage->setName((char*)("storage "));
  Room* main_hall = new Room();
  main_hall->setName((char*)("main_hall "));
  Room* admin = new Room();
  admin->setName((char*)("admin "));
  Room* comms = new Room();
  comms->setName((char*)("comms "));
  Room* shields = new Room();
  shields->setName((char*)("shields "));
  Room* o2 = new Room();
  o2->setName((char*)("o2 "));
  Room* weapons = new Room();
  weapons->setName((char*)("weapons "));
  Room* e_hall = new Room();
  e_hall->setName((char*)("e_hall "));
  
  //cafeteria
  cafeteria->setExit(east, e_hall);
  cafeteria->setExit(south, main_hall);
  cafeteria->setExit(west, n_hall);
  //n_hall
  n_hall->setExit(east, cafeteria);
  n_hall->setExit(west, up_engine);
  //up_engine
  up_engine->setExit(east , up_engine);
  up_engine->setExit(south , w_hall);
  //w_hall
  w_hall->setExit(north, up_engine);
  w_hall->setExit(east, cams);
  w_hall->setExit(south, low_engine);
  w_hall->setExit(west, reactor);
  //reactor
  reactor->setExit(east, w_hall);
  //cams
  cams->setExit(west, w_hall);
  //low_engine
  low_engine->setExit(north, w_hall);
  low_engine->setExit(east, electrical);
  //electrical
  electrical->setExit(west, low_engine);
  electrical->setExit(east, storage);
  //storage
  storage->setExit(west, electrical);
  storage->setExit(east, main_hall);
  //main_hall
  main_hall->setExit(west, storage);
  main_hall->setExit(north, cafeteria);
  main_hall->setExit(east, admin);
  //admin
  admin->setExit(west, main_hall);
  admin->setExit(east, comms);
  //comms
  comms->setExit(west, admin);
  comms->setExit(north, o2);
  comms->setExit(east, shields);
  //shields
  shields->setExit(west, comms);
  //o2
  o2->setExit(south, comms);
  o2->setExit(north, weapons);
  //weapons
  weapons->setExit(south, o2);
  weapons->setExit(north, e_hall);
  //e_hall
  e_hall->setExit(south, weapons);
  e_hall->setExit(west, cafeteria);

  //actual gameplay time
  
  return 0;
}


