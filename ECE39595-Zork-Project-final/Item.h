#ifndef ITEM_H_
#define ITEM_H_

#pragma once
#include <string>
#include <vector>
#include "Trigger.h"
#include "Turnon.h"
class Trigger;

class Item {   
private:
	std::string name;
	std::string description;
    std::string writing;
    std::string status;
    Turnon* turnon;
	std::vector<Trigger*> triggers;

public:
	virtual ~Item();
	Item();
	void setName(std::string name);
	void setDescription(std::string description);
	void setWriting(std::string writing);
	void setStatus(std::string status);
	void setTurnon(Turnon* turnon);
	void addTrigger(Trigger* trigger);
	std::string getName();
	std::string getDescription();
	std::string getWriting();
	std::string getStatus();
	Turnon* getTurnon();
	std::vector<Trigger*> getTriggers();
};

#endif