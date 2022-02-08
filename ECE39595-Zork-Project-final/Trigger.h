#ifndef TRIGGER_H_
#define TRIGGER_H_

#pragma once
#include <string>
#include <vector>
#include "Condition.h"
class Condition;

class Trigger {
private:
	std::string type;
	std::string command;
	std::vector<Condition*> conditions;
	std::vector<std::string> prints;
	std::vector<std::string> actions;
public:
	virtual ~Trigger();
	Trigger();
	void setType(std::string type);
	void setCommand(std::string command);
	void addCondition(Condition* condition);
	void addPrint(std::string print);
	void addAction(std::string action);
	std::string getType();
	std::string getCommand();
	std::vector<Condition*> getConditions();
	std::vector<std::string> getPrints();
	std::vector<std::string> getActions();
};

#endif