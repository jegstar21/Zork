#include "Commands.h"
#include <vector>
#include <string>
#include <iostream>

Commands::Commands(Map* _map, Room* _entrance) : map(_map), currentRoom(_entrance) {
	// std::cout << "Commands has been created" << std::endl;
}

Commands::~Commands(){
    
}



std::string Commands::getInput() {
	std::string input;
	std::getline(std::cin, input);
	return input;
}

void Commands::move(std::string dir) {
	//std::cout << "Current room: " << currentRoom->getName() << std::endl;

	std::vector<Border*> borders = currentRoom->getBorders();
	std::string nextRoom = "none";
	for (Border* border : borders) {
		if (border->getDirection() == "north" && dir == "n") {
			nextRoom = border->getName();
			break;
		}
		else if (border->getDirection() == "south" && dir == "s") {
			nextRoom = border->getName();
			break;
		}
		else if (border->getDirection() == "east" && dir == "e") {
			nextRoom = border->getName();
			break;
		}
		else if (border->getDirection() == "west" && dir == "w") {
			nextRoom = border->getName();
			break;
		}
	}
	if (nextRoom == "none")
		std::cout << "cannot move that way" << std::endl;

	std::vector<Room*> rooms = map->getRooms();
	for (Room* room : rooms) {
		if (nextRoom == room->getName()) {
			currentRoom = room;
			// std::cout << "Moved to " << currentRoom->getName() << std::endl;
			std::cout << room->getDescription() << std::endl;
		}
	}
}

std::string Commands::openExit() {
	if (currentRoom->getType() == "exit") {
		std::cout << "Game over" << std::endl;
		exit(0);
	}
	return "Not in an exit";
}

void Commands::gameOver() {
	std::cout << "Victory!" << std::endl;
	exit(0);
}

void Commands::add(Room* room, Item* item) {
	// std::cout << "added " << item->getName() << " to " << currentRoom->getName() << std::endl;
	
	room->addItem(item);
}

void Commands::add(Container* container, Item* item) {
	container->addItem(item);
}

void Commands::remove(Item* name) {
	// std::cout << "removed " << name->getName() << " from " << currentRoom->getName() << std::endl;
	currentRoom->removeItem(name);
}

void Commands::remove(Creature* name) {
	// std::cout << "removed " << name->getName() << " from " << currentRoom->getName() << std::endl;
	currentRoom->removeCreature(name);
}

void Commands::takeItem(Item* item) {
	for (Item* roomItem : currentRoom->getItems()) {
		if (roomItem->getName() == item->getName()) {
			currentRoom->removeItem(item);
			inventory.push_back(item);
			std::cout << "Item " << item->getName() << " added to the inventory " << std::endl;
			return;
		}
	}
	for (Container* roomContainer : currentRoom->getContainers()) {
		// std::cout << "Container: " << roomContainer->getName() << std::endl;
		for (Item* containerItem : roomContainer->getItems()) {
			// std::cout << "      Item: " << containerItem->getName() << std::endl;
			if (containerItem->getName() == item->getName() && roomContainer->getStatus() == "open") {
				roomContainer->removeItem(item);
				inventory.push_back(item);
				std::cout << "Item " << item->getName() << " added to the inventory " << std::endl;
				return;
			}
		}
	}
	std::cout << "Item " << item->getName() << " not in room" << std::endl;
}

void Commands::dropItem(Item* item) {
	for (Item* invItem : inventory) {
		if (invItem->getName() == item->getName()) {
			currentRoom->addItem(item);
			int pos = 0;
			for (Item* findItem : inventory) {
				if (item->getName() == findItem->getName()) {
					inventory.erase(inventory.begin() + pos);
					std::cout << item->getName() << " dropped" << std::endl;
					return;
				}
				pos++;
			}
		}
	}
	std::cout << item->getName() << " not in inventory" << std::endl;
}

void Commands::displayInventory() {

	if(inventory.size() == 0){
		std::cout << "Inventory: Empty. Collect Items!" << std::endl;
	}

	else {
		std::cout << "Inventory: ";
		for (int i = 0; i < inventory.size(); ++i) {
			if (i == inventory.size() - 1) {
				std::cout << inventory[i]->getName() << std::endl;
			}
			else {
				std::cout << inventory[i]->getName() << ", ";
			}
		}
	}
}

std::vector<std::string> Commands::parseCommand(std::string input) {
	std::vector<std::string> output;
	int pos = 0;
	int end = input.find_first_of(" ");
	while (end <= input.length() + 1) {
		output.push_back(input.substr(pos,end-pos));
		pos = end + 1;
		end = input.find_first_of(" ", end + 1);
	}
	output.push_back(input.substr(pos));
	return output;
}

void Commands::readItem(std::string item) {
	for (Item* findItem : inventory) {
		if (findItem->getName() == item) {
			if (findItem->getWriting() != "\0")
			std::cout << findItem->getWriting() << std::endl;
			else
			std::cout << "Nothing written" << std::endl;
			return;
		}
	}
	std::cout << item << " not in inventory." << std::endl;
}

void Commands::putItemInContainer(std::string item, std::string container) {
	for (Item* findItem : inventory) {
		if (findItem->getName() == item) {
			for (Container* findContainer : currentRoom->getContainers()) {
				if (findContainer->getName() == container) {
					for (std::string acceptsItem : findContainer->getAccepts()) {
						if (item == acceptsItem) {
   							std::cout << "Added " << item << " to " << container << std::endl;
							findContainer->addItem(findItem);
							int pos = 0;
							for (Item* findItem2 : inventory) {
								if (item == findItem2->getName()) {
									inventory.erase(inventory.begin() + pos);
									return;
								}
								pos++;
							}
						}
					}
					if (findContainer->getStatus() == "open") {
    					std::cout << "Added " << item << " to " << container << std::endl;
						findContainer->addItem(findItem);

						int pos = 0;
						for (Item* findItem2 : inventory) {
							if (item == findItem2->getName()) {
								inventory.erase(inventory.begin() + pos);
								return;
							}
							pos++;
						}
					}
					std::cout << "Cannot add " << item << " to closed " << findContainer->getName() << std::endl;
					return;
				}
			}
		}
	}
	std::cout << item << " not in inventory." << std::endl;
}

void Commands::turnOnItem(std::string item) {
	for (Item* findItem : inventory) {
		if (findItem->getName() == item) {
			std::cout << "You activate the item" << std::endl;
			std::cout << findItem->getTurnon()->getPrint() << std::endl;
			this->doAction(findItem->getTurnon()->getAction());
			//findItem->setStatus(words[3]);
			return;
		}
	}
	std::cout << item << " not in inventory." << std::endl;
}

void Commands::openContainer(std::string container){
	bool empty = true;
	for(Container* findContainer : currentRoom->getContainers()){
		if (findContainer->getName() == container) {
			// std::cout << "Found container" <<std::endl;
			if (findContainer->getStatus() == "locked") {
				// std::cout << "Which is locked" <<std::endl;
				// for (Item* item : inventory) {
				// 	std::cout << item->getName();
				// 	for (std::string acceptsItem : findContainer->getAccepts()) {
				// 		std::cout << " compared to " << acceptsItem << std::endl;
				// 		if (item->getName() == acceptsItem) {
				// 			std::cout << "you have the key" <<std::endl;
				// 			findContainer->setStatus("unlocked");
				// 		}
				// 	}
				// }
				std::cout << container << " is locked!" << std::endl;
			} else {
				if (findContainer->getStatus() != "open") {findContainer->setStatus("open");}
				for(Item* item : findContainer->getItems()){
					std::cout << container << " contains " << item->getName() << std::endl;
					empty = false;
				}
				if (empty) {std::cout << findContainer->getName() << " is empty" << std::endl;}
			}
			return;
		}
	}
	std::cout << "No " << container << " in this room" << std::endl;
}

void Commands::attackCreatureWithItem(std::string creature, std::string item) {
	for (Item* findItem : inventory) {
		if (findItem->getName() == item) {
			for (Creature* findCreature : currentRoom->getCreatures()) {
				if (creature == findCreature->getName()) {
					for (std::string vuln : findCreature->getVulnerabilities()) {
						if (vuln == item) {
							if (findCreature->getAttack() != NULL) {
								if (findCreature->getAttack()->getCondition() != NULL) {
									for (Item* findItem : inventory) {
										if (findItem->getName() == findCreature->getAttack()->getCondition()->getObject()) {
											// std::cout << "has the thing" << std::endl << std::flush;
											// std::cout << "needs to be " << condition->getStatus() << " and is " << findItem->getStatus() << std::endl; 
											if (findCreature->getAttack()->getCondition()->getStatus() == findItem->getStatus()) {
												std::cout << "You assault the " << creature << " with the " << item <<std::endl;
												std::cout << findCreature->getAttack()->getPrint() << std::endl;
												for (std::string action : findCreature->getAttack()->getActions()) {
													this->doAction(action);
												}
												return;
											}
										}
									}
								} else {
									std::cout << "You assault the " << creature << " with the " << item <<std::endl;
									std::cout << findCreature->getAttack()->getPrint() << std::endl;
									for (std::string action : findCreature->getAttack()->getActions()) {
										this->doAction(action);
									}
									return;
								}
							} else {
								std::cout << "You assault the " << creature << " with the " << item <<std::endl;
								return;
							}
						}
					}
					std::cout << creature << " invulnerable to " << findItem->getStatus() << " " << item <<std::endl;
					return;
				}
			}
			std::cout << "creature " << creature << " not in room" << std::endl;
			return;
		}
	}
	std::cout << "item " << item << " not in inventory" << std::endl;
}

bool Commands::processTrigger(Trigger* trigger, std::string command) {
	if (trigger->getType() == "done") {
		// std::cout <<"trigger done\n";
		return false;
	}
	if (trigger->getCommand() == command || trigger->getCommand() == "") {
		// std::cout << "trigger found: " << trigger->getType() << std::endl << std::flush;

		for (Condition* condition : trigger->getConditions()) {
			if (condition->getStatus() != "") {
				// std::cout << "has status" << std::endl << std::flush;
				for (Item* findItem : inventory) {
					if (findItem->getName() == condition->getObject()) {
						// std::cout << "has the thing" << std::endl << std::flush;
						// std::cout << "needs to be " << condition->getStatus() << " and is " << findItem->getStatus() << std::endl; 
						if (condition->getStatus() == findItem->getStatus()) {
							// std::cout << "has t/he right status" << std::endl << std::flush;
							if (trigger->getType() == "single")
								trigger->setType("done");
							for (int i = 0; i < trigger->getPrints().size(); i++) {
								std::cout << trigger->getPrints()[i] << std::endl;
							}
							for (int i = 0; i < trigger->getActions().size(); i++) {
								this->doAction(trigger->getActions()[i]);
							}
							return true;
						}
					}
				}
				for (Item* findItem : currentRoom->getItems()) {
					if (findItem->getName() == condition->getObject()) {
						// std::cout << "has the thing" << std::endl << std::flush;
						// std::cout << "needs to be " << condition->getStatus() << " and is " << findItem->getStatus() << std::endl; 
						if (condition->getStatus() == findItem->getStatus()) {
							// std::cout << "has the right status" << std::endl << std::flush;
							if (trigger->getType() == "single")
								trigger->setType("done");
							for (int i = 0; i < trigger->getPrints().size(); i++) {
								std::cout << trigger->getPrints()[i] << std::endl;
							}
							for (int i = 0; i < trigger->getActions().size(); i++) {
								this->doAction(trigger->getActions()[i]);
							}
							return true;
						}
					}
				}
				for (Container* findContainer : currentRoom->getContainers()) {
					if (findContainer->getName() == condition->getObject()) {
						// std::cout << "has the thing" << std::endl << std::flush;
						// std::cout << "needs to be " << condition->getStatus() << " and is " << findContainer->getStatus() << std::endl; 
						if (condition->getStatus() == findContainer->getStatus()) {
							// std::cout << "has the right status" << std::endl << std::flush;
							if (trigger->getType() == "single")
								trigger->setType("done");
							for (int i = 0; i < trigger->getPrints().size(); i++) {
								std::cout << trigger->getPrints()[i] << std::endl;
							}
							for (int i = 0; i < trigger->getActions().size(); i++) {
								this->doAction(trigger->getActions()[i]);
							}
							return true;
						}
					}
				}
			}

			if (condition->getOwner() == "inventory") {
					// std::cout << "inventory trigger" << std::endl << std::flush;
				if (condition->getHas() == "yes") {
					// std::cout << "has yes" << std::endl << std::flush;
					for (Item* item : inventory) {
						if (item->getName() == condition->getObject()) {
							if (trigger->getType() == "single")
								trigger->setType("done");
							for (int i = 0; i < trigger->getPrints().size(); i++) {
								std::cout << trigger->getPrints()[i] << std::endl;
							}
							for (int i = 0; i < trigger->getActions().size(); i++) {
								this->doAction(trigger->getActions()[i]);
							}
							return true;
						}
					}
					return false;
				}
				else {
					for (Item* item : inventory) {
						if (item->getName() == condition->getObject()) {
							return false;
						}
					}
					if (trigger->getType() == "single")
						trigger->setType("done");
					for (int i = 0; i < trigger->getPrints().size(); i++) {
						std::cout << trigger->getPrints()[i] << std::endl;
					}
					for (int i = 0; i < trigger->getActions().size(); i++) {
						this->doAction(trigger->getActions()[i]);
					}
					return true;
				}
			}
			for (Container* container : currentRoom->getContainers()) {
				if (condition->getOwner() == container->getName()) {
					// std::cout << "container trigger" << std::endl << std::flush;
					if (condition->getHas() == "yes") {
						// std::cout << "has yes" << std::endl << std::flush;
						for (Item* item : container->getItems()) {
							if (item->getName() == condition->getObject()) {
								if (trigger->getType() == "single")
									trigger->setType("done");
								for (int i = 0; i < trigger->getPrints().size(); i++) {
									std::cout << trigger->getPrints()[i] << std::endl;
								}
								for (int i = 0; i < trigger->getActions().size(); i++) {
									this->doAction(trigger->getActions()[i]);
								}
								return true;
							}
						}
						return false;
					}
					else {
						for (Item* item : container->getItems()) {
							if (item->getName() == condition->getObject()) {
								return false;
							}
						}
						if (trigger->getType() == "single")
							trigger->setType("done");
						for (int i = 0; i < trigger->getPrints().size(); i++) {
							std::cout << trigger->getPrints()[i] << std::endl;
						}
						for (int i = 0; i < trigger->getActions().size(); i++) {
							this->doAction(trigger->getActions()[i]);
						}
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Commands::checkTrigger(std::string command) {
	bool found = false;
	for (Trigger* trigger : currentRoom->getTriggers()) {
		found |= processTrigger(trigger, command);
	}

	for (Creature* creature : currentRoom->getCreatures()) {
		for (Trigger* trigger : creature->getTriggers()) {
			// std::cout << "processing gnome trigger\n";
			found |= processTrigger(trigger, command);
		}
	}

	for (Container* container : currentRoom->getContainers()) {
		for (Trigger* trigger : container->getTriggers()) {

			found |= processTrigger(trigger, command);

		}
	}

	return found;
}

void Commands::doAction(std::string command) {
	if (command == "n" | command == "s" | command == "e" | command == "w") {
		this->move(command);
	}
	else if (command == "i") {
		this->displayInventory();
	}
	else if (command == "open exit") {
		std::cout << this->openExit() << std::endl;
	}
	else if (command.substr(0,3) == "Add") {
		std::vector<std::string> words = this->parseCommand(command);
		for (Room* room : map->getRooms()) {
			if (room->getName() == words[3]) {
				for (Item* item : map->getItems()) {
					if (item->getName() == words[1]) {
						this->add(room, item);
						break;
					}
				}
				for (Creature* creature : map->getCreatures()) {
					if (creature->getName() == words[1]) {
						room->addCreature(creature);
						break;
					}
				}
			}
		}
		for (Container* container : map->getContainers()) {
			if (container->getName() == words[3]) {
				for (Item* item : container->getItems()) {
					if (item->getName() == words[1]) {
						this->add(container, item);
					}
				}
			}
		}
	}
	else if (command.substr(0,9) == "Game Over") {
		this->gameOver();
	}
	else if (command.substr(0,6) == "Delete") {
		std::vector<std::string> words = this->parseCommand(command);
		// std::cout << command <<std::endl;
		for (Room* room : map->getRooms()) {
			for (Item* item : room->getItems()) {
				if (item->getName() == words[1]) {
					room->removeItem(item);
					break;
				}
			}
			for (Creature* creature : room->getCreatures()) {
				if (creature->getName() == words[1]) {
					// std::cout<<"removing " << words[1] << std::endl;
					room->removeCreature(creature);
					break;
				}
			}
		}
	}
	else if (command.substr(0,4) == "take") {
		std::vector<std::string> words = this->parseCommand(command);
		for (Item* item : currentRoom->getItems()) {
			if (item->getName() == words[1]) {
				this->takeItem(item);
			}
		}
	}
	else if (command.substr(0,4) == "drop") {
		std::vector<std::string> words = this->parseCommand(command);
		// std::cout << command <<std::endl;
		for (Item* item : inventory) {
			if (item->getName() == words[1]) {
				this->dropItem(item);
			}
		}
	}
	else if (command.substr(0,6) == "Update") {
		// std::cout << command <<std::endl;
		std::vector<std::string> words = this->parseCommand(command);
		for (Item* item : currentRoom->getItems()) {
			if (item->getName() == words[1]) {
				item->setStatus(words[3]);
			}
		}
		for (Item* item : inventory) {
			if (item->getName() == words[1]) {
				item->setStatus(words[3]);
			}
		}
		for (Container* container : currentRoom->getContainers()) {
			if (container->getName() == words[1]) {
				container->setStatus(words[3]);
			}
		}
		for (Creature* creature : currentRoom->getCreatures()) {
			if (creature->getName() == words[1]) {
				creature->setStatus(words[3]);
			}
		}
	}
	else if (command.substr(0,4) == "read") {
		std::vector<std::string> words = this->parseCommand(command);
		this->readItem(words[1]);
	}
	else if (command.substr(0,3) == "put") {
		std::vector<std::string> words = this->parseCommand(command);
		this->putItemInContainer(words[1],words[3]);
	}
	else if (command.substr(0,6) == "turnon") {
		std::vector<std::string> words = this->parseCommand(command);
		this->turnOnItem(words[1]);
	}
	else if (command.substr(0,6) == "attack") {
		std::vector<std::string> words = this->parseCommand(command);
		this->attackCreatureWithItem(words[1], words[3]);
	}
	else if (command.substr(0,5) == "open ") {
		std::vector<std::string> words = this->parseCommand(command);
		this->openContainer(words[1]);
	}
}