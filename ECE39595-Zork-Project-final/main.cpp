#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "XMLParser.h"
#include "Commands.h"

//g++ -std=c++11 *.cpp -o out -DTIXML_USE_STL

int main(int argc, char** args) {
	// prompt for XML file to parse
	std::string filename;
	bool shouldPause = true;

	// if given a second argument, use that as the XML file
	// means calling "XMLParseDemo mapActivity.xml" will parse the file "mapActivity.xml". The Makefile is set up to supply this argument when using on command line
	if (argc >= 2) {
		filename = args[1];
		shouldPause = false;
	}
	else {
		// if no argument, prompt for filename. This is the form used in running in Visual Studio
		std::cout << "Enter filename: ";
		std::cin >> filename;
		// remove the extra newline character from cin
		std::cin.get();
	}

	// call the parser to parse the XML
	XMLParser parser;
	Map* map = parser.parseXML(filename);

	// maps.clear(); // not strictly required, I just like to remove references to pointers after deleting them
	std::vector<Room*> rooms = map->getRooms();
	std::vector<Item*> items = map->getItems();
	std::vector<Creature*> creatures = map->getCreatures();
	std::vector<Container*> containers = map->getContainers();
	Room* entrance;
	for (Room* room : rooms) {
		if (room->getName() == "Entrance") {
			entrance = room;
		}
	}

	Commands* commands = new Commands(map, entrance);
	// commands->rooms = rooms;
	// commands->items = items;
	// commands->creatures = creatures;
	// commands->containers = containers;
	std::string command;
	std::cout << entrance->getDescription() << std::endl;
	while (command != "quit") {
		command = commands->getInput();
		if (commands->checkTrigger(command)) {
			NULL;
		}
		else if (command == "n" | command == "s" | command == "e" | command == "w") {
			commands->checkTrigger(command);
			commands->move(command);
		}
		else if (command == "i") {
			commands->displayInventory();
		}
		else if (command == "open exit") {
			std::cout << commands->openExit() << std::endl;
		}
		else if (command.substr(0,5) == "take ") {
			std::vector<std::string> words = commands->parseCommand(command);
			if (words.size() != 2) {continue;}
			bool found = false;
			for (Item* item : commands->currentRoom->getItems()) {
				if (item->getName() == words[1]) {
					commands->takeItem(item);
					found = true;
					break;
				}
			}
			for (Container* container : commands->currentRoom->getContainers()) {
				for (Item* item : container->getItems()) {
					if (item->getName() == words[1]) {
						commands->takeItem(item);
						found = true;
						break;
					}
				}
			}
			if (!found) {std::cout << words[1] << " not in room" << std::endl;}
			commands->checkTrigger(command);;
		}
		else if (command.substr(0,5) == "drop ") {
			std::vector<std::string> words = commands->parseCommand(command);
			if (words.size() != 2) {continue;}
			bool found = false;
			for (Item* item : commands->inventory) {
				if (item->getName() == words[1]) {
					commands->dropItem(item);
					found = true;
					break;
				}
			}
			if (!found) {std::cout << words[1] << " not in inventory" << std::endl;}
			commands->checkTrigger(command);
		}
		else if (command.substr(0,5) == "read ") {
			std::vector<std::string> words = commands->parseCommand(command);
			if (words.size() != 2) {continue;}
			commands->readItem(words[1]);
		}
		else if (command.substr(0,4) == "put ") {
			std::vector<std::string> words = commands->parseCommand(command);
			if (words.size() != 4) {continue;}
			commands->putItemInContainer(words[1],words[3]);
			commands->checkTrigger(command);
		}
		else if (command.substr(0,8) == "turn on ") {
			std::vector<std::string> words = commands->parseCommand(command);
			if (words.size() != 3) {continue;}
			commands->turnOnItem(words[2]);
			commands->checkTrigger(command);
		}
		else if (command.substr(0,7) == "attack ") {
			std::vector<std::string> words = commands->parseCommand(command);
			if (words.size() != 4) {continue;}
			commands->attackCreatureWithItem(words[1], words[3]);
			commands->checkTrigger(command);
		}
		else if (command.substr(0,5) == "open ") {
			std::vector<std::string> words = commands->parseCommand(command);
			if (words.size() != 2) {continue;}
			commands->openContainer(words[1]);
			commands->checkTrigger(command);
		}
		else {
			std::cout << "Bad command" << std::endl;
		}
	}

	// wait for key press to exit, added for the sake of visual studio as the command window closes after the program finishes
	// skipped when a filename is given via command line, that is what the makefile is set up to use
	// worth pointing out that this is not strictly related to XML parsing, it is just done to make testing the program easier
	// if (shouldPause) std::cin.get();

	return 0;
}