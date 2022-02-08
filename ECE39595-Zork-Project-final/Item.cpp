#include "Item.h"
#include <iostream>

Item::Item() {
	// std::cout << "Item has been created" << std::endl;

}

Item::~Item() {
    for(Trigger * trigger : triggers){
        delete trigger;
    }

    triggers.clear();

}

void Item::setName(std::string name) {
	// std::cout << "Set item name: " << name << std::endl;
	this->name = name;
}

void Item::setDescription(std::string description) {
	// std::cout << "Set item description: " << description << std::endl;
	this->description = description;
}

void Item::setWriting(std::string writing) {
	// std::cout << "Set item writing: " << writing << std::endl;
	this->writing = writing;
}

void Item::setTurnon(Turnon* turnon) {
	// std::cout << "Set item turnon: " << turnon->getAction() << std::endl;
	this->turnon = turnon;
}

void Item::setStatus(std::string status) {
	// std::cout << "Set item status: " << status << std::endl;
	this->status = status;
}

void Item::addTrigger(Trigger* trigger){
	// std::cout << "Added item trigger" << std::endl;
    triggers.push_back(trigger);
}

std::string Item::getName() {
	return name;
}

std::string Item::getDescription() {
	return description;
}

std::string Item::getWriting() {
	return writing;
}

Turnon* Item::getTurnon() {
	return turnon;
}

std::string Item::getStatus() {
	return status;
}

std::vector<Trigger*> Item::getTriggers(){
    return triggers;
}