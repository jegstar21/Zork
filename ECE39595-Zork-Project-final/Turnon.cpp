#include "Turnon.h"
#include <iostream>

Turnon::Turnon(){
	// std::cout << "Turnon has been created" << std::endl;
}

Turnon::~Turnon(){
	
}

void Turnon::setPrint(std::string print) {
	this->print = print;
	// std::cout << "set print to " << print << std::endl;
}

void Turnon::setAction(std::string action) {
	this->action = action;
}

std::string Turnon::getPrint() {
	return print;
}

std::string Turnon::getAction() {
	return action;
}