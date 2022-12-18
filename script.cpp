/* Xander Siruno-Nebel
   C++/Data Structs, Galbraith
   12/17/22
   Zuul: plays the console game 'Zuul'
*/

#include <iostream>
#include <cstring>
#include <vector>
#include "Room.h"
#include "Item.h"
#include <map>


using namespace std;

int main(){
  char input[80];
  char output[80];
  char item1[80];
  char item2[80];
  vector<Item*> Inventory;

  //directions
  char* north = (char*)("North");
  char* east = (char*)("East");
  char* south = (char*)("South");
  char* west = (char*)("West");

  //room init
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
  up_engine->setExit(east , n_hall);
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

  reactor->addItem((char*)("Mask"));
  cams->addItem((char*)("Tapes"));
  weapons->addItem((char*)("Body"));
  shields->addItem((char*)("Knife"));
  comms->addItem((char*)("Footprints"));
  cafeteria->addItem((char*)("Button"));

  //actual gameplay time
  Room* roomCurrent = cafeteria;
  cout << "Welcome to Zuul! Input 'help' for commands" << endl;

  while(true){
    roomCurrent->printDesc(output); //prints current room
    cout << "What do you want to do?" << endl;
    cin >> input;
    cout << endl;
    if(strcmp(input, "inv") == 0){ //INVENTORY ======================
      cout << "Inventory: " << endl;
      if(Inventory.size() > 0){
        for(int i = 0; i < Inventory.size(); i++){
          Inventory[i]->getName(output);
          cout << output << endl;
        }
      }
    }else if(strcmp(input, "take") == 0){//TAKE ======================
      cout << "Which item?" << endl;
      cin >> input;
      if(strcmp(input, "Button") == 0 && roomCurrent == cafeteria){
        cout << "The button is bolted to the ground. You call an emergency meeting: " << endl;
        if(Inventory.size() > 4){//win condition
          cout << "Red was the impostor. Congratulations -- you win!" << endl;
          return 0;
        }else{
          cout << "Insufficient evidence. Nobody believes you" << endl;
        }
      }else{
        roomCurrent->giveItems(Inventory, input);
      }
    }else if(strcmp(input, "drop") == 0){ //DROP ======================
      cout << "Which item?" << endl;
      cin>> input;
      roomCurrent->takeItems(Inventory, input);
    }else if(strcmp(input, "move") == 0){ //MOVE ======================
      cout << "'North', 'East', 'South', or 'West'?" << endl;
      cin >> input;
      cout << endl;
      roomCurrent->getExit(input, roomCurrent);
    }else if(strcmp(input, "help") == 0){ //HELP ======================
      cout << "Possible commands: 'move', 'help', 'quit', 'inv', take, drop" << endl;
    }else if(strcmp(input, "quit") == 0){ //QUIT ======================
      cout << "Thank you for playing Zuul :3";
      return 0;
    }else{
      cout << "Sorry, you can't do that. Input 'help' for help" << endl;
    }
  }
  return 0;
}