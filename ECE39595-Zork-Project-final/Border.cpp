#include "Border.h"
#include <iostream>

Border::Border(){
	// std::cout << "Border has been created" << std::endl;
}

Border::~Border(){
    
}

void Border::setDirection(std::string direction) {
//   std::cout << "Set border direction: " << direction << std::endl;
	this->direction = direction;
}

void Border::setName(std::string name) {
    // std::cout << "Set border  name: " << name << std::endl;
	this->name = name;
}

std::string Border::getDirection() {
	return direction;
}

std::string Border::getName() {
	return name;
}