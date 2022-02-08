#ifndef ATTACK_H_
#define ATTACK_H_

#pragma once
#include <string>
#include <vector>
#include "Condition.h"

class Attack {   
private:
	Condition* condition;
	std::string print;
    std::vector<std::string> actions;

public:
	virtual ~Attack();
    Attack();
	void setCondition(Condition* name);
	void setPrint(std::string print);
    void addAction(std::string action);
	Condition* getCondition();
	std::string getPrint();
    std::vector<std::string> getActions();
};

#endif