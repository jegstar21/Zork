#include <iostream>
#include "Room.h"

Room::Room(){
    // std::cout << "Room has been created" << std::endl;
    type = "regular";
}

void Room::setName(std::string name){
    // std::cout << "Set room name: " << name << std::endl;
    this->name = name;
}

void Room::setStatus(std::string status) {
    // std::cout << "Set room status: " << status << std::endl;
	this->status = status;
}

void Room::setType(std::string type) {
    // std::cout << "Set room type: " << type << std::endl;
    this->type = type;
}

void Room::setDescription(std::string description){
    // std::cout << "Set room description: " << description << std::endl;
    this->description = description;
}

void Room::addItem(Item* item){
    // std::cout << "Added room item: " << item->getName() << " to " << this->getName() << std::endl;
    items.push_back(item);
}

void Room::addContainer(Container* container){
    // std::cout << "Added room container: " << container->getName() << " to " << this->getName() << std::endl;
    containers.push_back(container);
}

void Room::addCreature(Creature* creature){
    // std::cout << "Added room creature: " << creature->getName() << " to " << this->getName() << std::endl;
    creatures.push_back(creature);
}

void Room::addTrigger(Trigger* trigger){
    // std::cout << "Added room trigger" << std::endl;
    triggers.push_back(trigger);
}

void Room::addBorder(Border* border){
    // std::cout << "Set room " << this->getName() << " " << border->getDirection() << " border to " << border->getName() << std::endl;
    borders.push_back(border);
}

void Room::removeItem(Item* item) {
    for (Item* roomItem : this->getItems()) {
        if (roomItem->getName() == item->getName()) {
            int pos = 0;
			for (Item* findItem : this->items) {
				if (item->getName() == findItem->getName()) {
					this->items.erase(this->items.begin() + pos);
					return;
				}
				pos++;
			}
        }
    }
}

void Room::removeCreature(Creature* creature) {
    for (Creature* roomCreature : this->getCreatures()) {
        if (roomCreature->getName() == creature->getName()) {
            int pos = 0;
			for (Creature* findCreature : this->creatures) {
				if (creature->getName() == findCreature->getName()) {
					this->creatures.erase(this->creatures.begin() + pos);
					return;
				}
				pos++;
			}
        }
    }
}

Room::~Room(){
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

    for(Trigger * trigger : triggers){
        delete trigger;
    }

    triggers.clear();

    for(Border * border : borders){
        delete border;
    }

    borders.clear();
}

std::string Room::getName(){
    return name;
}

std::string Room::getStatus() {
	return status;
}

std::string Room::getType() {
	return type;
}

std::string Room::getDescription() {
    return description;
}

std::vector<Item*> Room::getItems(){
    return items;
}

std::vector<Container*> Room::getContainers(){
    return containers;
}

std::vector<Creature*> Room::getCreatures(){
    return creatures;
}

std::vector<Trigger*> Room::getTriggers(){
    return triggers;
}

std::vector<Border*> Room::getBorders(){
    return borders;
}