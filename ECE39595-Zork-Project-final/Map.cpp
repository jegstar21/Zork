#include <iostream>
#include <vector>
#include <string>
#include "Map.h"

Map::Map(){
    // std::cout << "Map Built" << std::endl;
}

Map::~Map(){
    for(Item * item : items){
        delete item;
    }

    items.clear();

    for(Container * container : containers){
        delete container;
    }

    containers.clear();

    for(Creature * creature : creatures){
        delete creature;
    }

    creatures.clear();

    for(Room* room : rooms){
        delete room;
    }

    rooms.clear();
}

std::vector<Room*> Map::getRooms(){
    return rooms;
}

std::vector<Item*> Map::getItems(){
    return items;
}

std::vector<Creature*> Map::getCreatures(){
    return creatures;
}

std::vector<Container*> Map::getContainers(){
    return containers;
}

void Map::addRoom(Room* room){
    // std::cout << "Added room " << room->getName() << " to map" << std::endl;
    rooms.push_back(room);
}

void Map::addItem(Item* item){
    // std::cout << "Added item " << item->getName() << " to map" << std::endl;
    items.push_back(item);
}

void Map::addCreature(Creature* creature){
    // std::cout << "Added creature " << creature->getName() << " to map" << std::endl;
    creatures.push_back(creature);
}

void Map::addContainer(Container* container){
    // std::cout << "Added container " << container->getName() << " to map" << std::endl;
    containers.push_back(container);
}

void Map::removeItem(Item* name) {
    int pos = 0;
    for (Item* item : items) {
		if (item->getName() == name->getName()) {
			items.erase(items.begin() + pos);
            // std::cout << "Removed item " << item->getName() << std::endl;
		}
        pos++;
	}
}

// void Map::removeCreature(Item* name) {
//     int pos = 0;
//     for (Creature* creature : creatures) {
// 		if (creature->getName() == name->getName()) {
// 			creatures.erase(creatures.begin() + pos);
//             std::cout << "Removed item " << creature->getName() << std::endl;
// 		}
//         pos++;
// 	}
// }