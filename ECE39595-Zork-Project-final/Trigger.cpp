#include <iostream>
#include "Trigger.h"

Trigger::Trigger(){
	// std::cout << "Trigger has been created" << std::endl;
	this->setType("single");
}

Trigger::~Trigger(){
    for(Condition * condition : conditions){
        delete condition;
    }

    conditions.clear();

    for(std::string print : prints){
        delete &print;
    }

    prints.clear();

    for(std::string action : actions){
        delete &action;
    }

		actions.clear();
}

void Trigger::setType(std::string type) {
	// std::cout << "Set trigger type: " << type << std::endl;
	this->type = type;
}

void Trigger::setCommand(std::string command) {
	// std::cout << "Set trigger command: " << command << std::endl;
	this->command = command;
}

void Trigger::addCondition(Condition* condition) {
	// std::cout << "Added trigger condition: " << condition->getObject() << std::endl;
	conditions.push_back(condition);
}

void Trigger::addPrint(std::string print) {
	// std::cout << "Added trigger print: " << print << std::endl;
	prints.push_back(print);
}

void Trigger::addAction(std::string action) {
	// std::cout << "Added trigger action: " << action << std::endl;
	actions.push_back(action);
}

std::string Trigger::getType() {
	return type;
}

std::string Trigger::getCommand() {
	return command;
}

std::vector<Condition*> Trigger::getConditions() {
	return conditions;
}

std::vector<std::string> Trigger::getPrints() {
	return prints;
}

std::vector<std::string> Trigger::getActions() {
	return actions;
}