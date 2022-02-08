#pragma once
#include <string>
#include <vector>
#include "Trigger.h"
#include "Item.h"

class Container {   
private:
	std::string name;
	std::string status;
	std::string description;
  	std::vector<std::string> accepts;
	std::vector<Item*> items;
	std::vector<Trigger*> triggers;

public:
	virtual ~Container();
  	Container();

	void setName(std::string name);
	void setStatus(std::string status);
	void setDescription(std::string description);
	void addAccept(std::string accept);
	void addItem(Item* item);
	void addTrigger(Trigger* trigger);
	void removeItem(Item* item);
	std::string getName();
	std::string getStatus();
	std::string getDescription();
	std::vector<std::string> getAccepts();
	std::vector<Item*> getItems();
	std::vector<Trigger*> getTriggers();
};

