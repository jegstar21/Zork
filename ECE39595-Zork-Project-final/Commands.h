#pragma once
#include <string>
#include <vector>
#include "Map.h"
#include "Room.h"
#include "Container.h"
#include "Item.h"
#include "Creature.h"
#include "Trigger.h"

class Commands {   
private:
	Map* map;
  bool processTrigger(Trigger* trigger, std::string command);

public:
  Room* currentRoom;

  std::vector<Item*> inventory;
	virtual ~Commands();
  Commands(Map* _map, Room* _entrance);
  std::string getInput();
  void move(std::string dir);
  std::string openExit();
  void displayInventory();
  void takeItem(Item* item);
  void dropItem(Item* item);
  void add(Room* room, Item* item);
  void add(Room* room, Creature* creature);
  void add(Container* container, Item* item);
  void remove(Item* item);
  void remove(Creature* creature);
  void gameOver();
  std::vector<std::string> parseCommand(std::string);
  
  void openContainer(std::string container);
  void readItem(std::string item);
  void putItemInContainer(std::string item, std::string container);
  void turnOnItem(std::string item);
  void attackCreatureWithItem(std::string creature, std::string item);
  void updateItemToStatus(Item* item, std::string status);

  bool checkTrigger(std::string command);
  void doAction(std::string command);
};
