#include "Container.h"
#include <iostream>

Container::Container(){
	// std::cout << "Container has been created" << std::endl;
}

Container::~Container(){
    for(Item * item : items){
        delete item;
    }

    items.clear();

    for(Trigger * trigger : triggers){
        delete trigger;
    }

    triggers.clear();

    accepts.clear();
}

void Container::setName(std::string name) {
    // std::cout << "Set container name: " << name << std::endl;
    this->name = name;
}

void Container::setStatus(std::string status) {
    // std::cout << "Set container status: " << status << std::endl;
    this->status = status;
}

void Container::setDescription(std::string description) {
    // std::cout << "Set container description: " << description << std::endl;
    this->description = description;
}

void Container::addAccept(std::string accept) {
    // std::cout << "Added container accept: " << accept << std::endl;
    accepts.push_back(accept);
}

void Container::addItem(Item* item) {
    items.push_back(item);
}

void Container::addTrigger(Trigger* trigger) {
    // std::cout << "Added trigger to container" << std::endl;
    triggers.push_back(trigger);
}

void Container::removeItem(Item* item) {
    for (Item* containerItem : this->getItems()) {
        if (containerItem->getName() == item->getName()) {
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

std::string Container::getName() {
    return name;
}

std::string Container::getStatus() {
    return status;
}

std::string Container::getDescription() {
    return description;
}

std::vector<std::string> Container::getAccepts() {
    return accepts;
}

std::vector<Item*> Container::getItems() {
    return items;
}

std::vector<Trigger*> Container::getTriggers() {
    return triggers;
}
