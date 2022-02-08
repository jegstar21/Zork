#ifndef CREATURE_H_
#define CREATURE_H_

#pragma once
#include <string>
#include <vector>
#include "Attack.h"
#include "Trigger.h"

class Creature {   
private:
	std::string name;
	std::string status;
	std::vector<std::string> vulnerabilities;
  Attack* attack;
	std::vector<Trigger*> triggers;

public:
	virtual ~Creature();
    Creature();
	void setName(std::string name);
	void setStatus(std::string status);
	void addVulnerability(std::string vulnerability);
  	void setAttack(Attack* attack);
	void addTrigger(Trigger* trigger);
	std::string getName();
	std::string getStatus();
	std::vector<std::string> getVulnerabilities();
  	Attack* getAttack();
	std::vector<Trigger*> getTriggers();
};

#endif