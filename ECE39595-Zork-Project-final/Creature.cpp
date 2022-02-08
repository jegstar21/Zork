#include "Creature.h"
#include <iostream>

Creature::Creature(){
	// std::cout << "Creature has been created" << std::endl;
    this->attack = NULL;
}

Creature::~Creature() {
    for(std::string vulnerability : vulnerabilities){
        delete &vulnerability;
    }

    vulnerabilities.clear();

    for(Trigger * trigger : triggers){
        delete trigger;
    }

    triggers.clear();

}

void Creature::setName(std::string name) {
	// std::cout << "Set creature name: " << name << std::endl;
    this->name = name;
}

void Creature::setStatus(std::string status) {
	// std::cout << "Set creature status: " << status << std::endl;
    this->status = status;
}

void Creature::addVulnerability(std::string vulnerability) {
	// std::cout << "Added creature vunerability: " << vulnerability << std::endl;
    vulnerabilities.push_back(vulnerability);
    // std::cout << vulnerabilities[0] << std::endl;
}

void Creature::setAttack(Attack* attack) {
	// std::cout << "Added creature attack: " << attack->getPrint() << std::endl;
    this->attack = attack;
}

void Creature::addTrigger(Trigger* trigger) {
	// std::cout << "Added creature trigger" << std::endl;
    triggers.push_back(trigger);
}

std::string Creature::getName() {
    return name;
}

std::string Creature::getStatus() {
    return status;
}

std::vector<std::string> Creature::getVulnerabilities() {
    return vulnerabilities;
}

Attack* Creature::getAttack() {
    return attack;
}

std::vector<Trigger*> Creature::getTriggers() {
    return triggers;
}
