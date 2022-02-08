#include "Condition.h"
#include <iostream>

Condition::Condition(){
	// std::cout << "Condition has been created" << std::endl;
	setHas("");
	setObject("");
	setOwner("");
	setStatus("");
}

Condition::~Condition(){

}

void Condition::setHas(std::string has) {
    // std::cout << "Set condition has: " << has << std::endl;
	this->has = has;
}

void Condition::setObject(std::string object) {
    // std::cout << "Set condition object: " << object << std::endl;
	this->object = object;
}

void Condition::setOwner(std::string owner) {
    // std::cout << "Set condition owner: " << owner << std::endl;
	this->owner = owner;
}

void Condition::setStatus(std::string status) {
    // std::cout << "Set condition status: " << status << std::endl;
	this->status = status;
}

std::string Condition::getHas() {
	return has;
}

std::string Condition::getObject() {
	return object;
}

std::string Condition::getOwner() {
	return owner;
}

std::string Condition::getStatus() {
	return status;
}