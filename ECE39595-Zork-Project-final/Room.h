#pragma once
#include <iostream>
#include <string>
#include "Item.h"
#include "Container.h"
#include "Trigger.h"
#include "Border.h"
#include "Creature.h"

class Room {
private:
    std::string name;
    std::string status;
    std::string type;
    std::string description;
    std::vector<Item*> items;
    std::vector<Container*> containers;
    std::vector<Creature*> creatures;
    std::vector<Trigger*> triggers;
    std::vector<Border*> borders;

public:
    virtual ~Room();
    Room();
    void setName(std::string name);
	void setStatus(std::string status);
	void setType(std::string type);
    void setDescription(std::string description);
    void addItem(Item* item);
    void addContainer(Container* container);
    void addCreature(Creature* creature);
    void addTrigger(Trigger* trigger);
    void addBorder(Border* border);
    void removeItem(Item* item);
    void removeCreature(Creature* creature);

    std::string getName();
	std::string getStatus();
	std::string getType();
    std::string getDescription();
    std::vector<Item*> getItems();
    std::vector<Container*> getContainers();
    std::vector<Creature*> getCreatures();
    std::vector<Trigger*> getTriggers();
    std::vector<Border*> getBorders();
};