#ifndef MAP_H_
#define MAP_H_

#include "Container.h"
#include "Creature.h"
#include "Room.h"
#include "Item.h"
#include <vector>
#include <string>
#include <iostream>

class Map {
private:
    Map* map;
    std::vector<Room*> rooms;
    std::vector<Item*> items;
    std::vector<Creature*> creatures;
    std::vector<Container*> containers;

public:

    Map();
    std::vector<Creature*> getCreatures();
    std::vector<Container*> getContainers();
    std::vector<Room*> getRooms();
    std::vector<Item*> getItems();
    virtual ~Map();

    void addCreature(Creature* creature);
    void addContainer(Container* container);
    void addRoom(Room* room);
    void addItem(Item* item);
    void removeItem(Item* item);
};

#endif