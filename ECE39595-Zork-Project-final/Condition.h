#ifndef CONDITION_H_
#define CONDITION_H_

#pragma once
#include <string>
#include <vector>
#include "Item.h"
class Item;

class Condition {   
private:
	std::string has;
	std::string object;
	std::string owner;
	std::string status;

public:
	virtual ~Condition();
	Condition();
	void setHas(std::string has);
	void setObject(std::string object);
	void setOwner(std::string owner);
	void setStatus(std::string status);
	std::string getHas();
	std::string getObject();
	std::string getOwner();
	std::string getStatus();
};

#endif