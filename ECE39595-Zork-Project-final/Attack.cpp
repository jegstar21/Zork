#include "Attack.h"
#include <iostream>

Attack::Attack(){
	// std::cout << "Attack has been created" << std::endl;
    this->condition = NULL;
}

Attack::~Attack(){
    for(std::string action : actions){
        delete &action;
    }

    actions.clear();
}

void Attack::setCondition(Condition* condition) {
    // std::cout << "Set attack condition: " << condition->getObject() << std::endl;
    this->condition = condition;
}

void Attack::setPrint(std::string print) {
    // std::cout << "Set attack print: " << print << std::endl;
    this->print = print;
}

void Attack::addAction(std::string action) {
    // std::cout << "Added attack action: " << action << std::endl;
    actions.push_back(action);
}

Condition* Attack::getCondition() {
    return condition;
}

std::string Attack::getPrint() {
    return print;
}

std::vector<std::string> Attack::getActions() {
    return actions;
}
