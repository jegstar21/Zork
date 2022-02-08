#include <string>
#include <vector>
#include <iostream>
#include "XMLParser.h"
#include "tinyxml.h"

Trigger* XMLParser::parseTrigger(TiXmlElement* element) {

Trigger* trigger = new Trigger();

	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
	TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {

		std::string name = childElement->ValueStr();

			if (name == "type") {
				std::string value = childElement->GetText();
				trigger->setType(value);
			}
			else if (name == "command") {
				std::string value = childElement->GetText();
				trigger->setCommand(value);
			}
			else if (name == "condition") {
				trigger->addCondition(parseCondition(childElement));
			}
			else if (name == "print") {
				std::string value = childElement->GetText();
				trigger->addPrint(value);
			}
			else if(name == "action") {
				std::string value = childElement->GetText();
				trigger->addAction(value);
			}
		}
	}

	return trigger;
}


Attack* XMLParser::parseAttack(TiXmlElement* element) {
	Attack* attack = new Attack();

	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {

			std::string name = childElement->ValueStr();
			

			if (name == "condition") {
				attack->setCondition(parseCondition(childElement));
			}
			else if (name == "print") {
				std::string value = childElement->GetText();
				attack->setPrint(value);
			}
			else if (name == "action") {
				std::string value = childElement->GetText();
				attack->addAction(value);
			}
		}
	}

	return attack;
}

Creature* XMLParser::parseCreature(TiXmlElement* element) {
	Creature* creature = new Creature();

	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {

			std::string name = childElement->ValueStr();			

			if (name == "name") {
				creature->setName(childElement->GetText());
			}
			else if (name == "status") {
				creature->setStatus(childElement->GetText());
			}
			else if (name == "vulnerability") {
				creature->addVulnerability(childElement->GetText());
			}
			else if (name == "attack") {
				creature->setAttack(parseAttack(childElement));
			}
			else if(name == "trigger") {
				creature->addTrigger(parseTrigger(childElement));
			}
		}
	}

	return creature;
}



Border* XMLParser::parseBorder(TiXmlElement* element) {
	Border* border = new Border();

	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
 
			std::string name = childElement->ValueStr();

			if(name == "name")
			{
				std::string value = childElement->GetText();
				border->setName(value);
			}

			else if(name == "direction")
			{
				std::string value = childElement->GetText();
				border->setDirection(value);
			}
		}
	}

	return border;
}

Turnon* XMLParser::parseTurnon(TiXmlElement* element) {
	Turnon* turnon = new Turnon();

	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
 
			std::string name = childElement->ValueStr();
			std::string value = childElement->GetText();

			if(name == "print")
			{
				turnon->setPrint(value);
			}

			else if(name == "action")
			{
				turnon->setAction(value);
			}
		}
	}

	return turnon;
}

Item* XMLParser::parseItem(TiXmlElement* element) {
	Item* item = new Item();

	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {
 
			std::string name = childElement->ValueStr();

			if(name == "name")
			{
			std::string value = childElement->GetText();
				item->setName(value);
			}

			else if(name == "description")
			{
			std::string value = childElement->GetText();
				item->setDescription(value);
			}

			else if(name == "writing")
			{
			std::string value = childElement->GetText();
				item->setWriting(value);
			}

			else if(name == "status")
			{
			std::string value = childElement->GetText();
				item->setStatus(value);
			}

			else if(name == "turnon")
			{
				item->setTurnon(parseTurnon(childElement));
			}

			else if(name == "trigger")
			{
				item->addTrigger(parseTrigger(childElement));
			}
		}
	}

	return item;
}

Condition* XMLParser::parseCondition(TiXmlElement* element) {

Condition* condition = new Condition();

for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
	TiXmlElement* childElement = node->ToElement();
	if (childElement != NULL) {

		std::string name = childElement->ValueStr();
		std::string value = childElement->GetText();

		if (name == "has") {
			std::string value = childElement->GetText();
			condition->setHas(value);
		}
		else if (name == "object") {
			std::string value = childElement->GetText();
			condition->setObject(value);
		}
		else if(name == "owner") {
			std::string value = childElement->GetText();
			condition->setOwner(value);
		}
		else if(name == "status") {
			std::string value = childElement->GetText();
			condition->setStatus(value);
		}
	}
}
	return condition;
}

Container* XMLParser::parseContainer(TiXmlElement* element) {
	Container* container = new Container();

	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {

			std::string name = childElement->ValueStr();

			if(name == "name")
			{
			std::string value = childElement->GetText();
				container->setName(value);
			}

			else if(name == "status")
			{
			std::string value = childElement->GetText();
				container->setStatus(value);
			}

			else if(name == "description")
			{
			std::string value = childElement->GetText();
				container->setDescription(value);
			}

			else if(name == "item")
			{
				container->addItem(this->parseMapForItem(childElement->GetText()));
			}

			else if(name == "accept")
			{
				container->addAccept(childElement->GetText());
			}

			else if(name == "trigger")
			{
				container->addTrigger(parseTrigger(childElement));
			}
		}
	}

	return container;
}

Room* XMLParser::parseRoom(TiXmlElement* element) {
	Room* room = new Room();

	for (TiXmlNode* node = element->IterateChildren(NULL); node != NULL; node = element->IterateChildren(node)) {
		TiXmlElement* childElement = node->ToElement();
		if (childElement != NULL) {

			std::string name = childElement->ValueStr();

		if (name == "name") {
			std::string value = childElement->GetText();
			room->setName(value);
		}

		else if (name == "status") {
			std::string value = childElement->GetText();
			room->setStatus(value);
		}

		else if (name == "type") {
			std::string value = childElement->GetText();
			room->setType(value);
		}

		else if (name == "description") {
			std::string value = childElement->GetText();
			room->setDescription(value);
		}

		else if(name == "item") {
			room->addItem(this->parseMapForItem(childElement->GetText()));
		}

		else if (name == "container") {
			room->addContainer(this->parseMapForContainer(childElement->GetText()));
		}

		else if (name == "creature") {
			room->addCreature(this->parseMapForCreature(childElement->GetText()));
		}

		else if (name == "trigger") {
			room->addTrigger(parseTrigger(childElement));
		}

		else if (name == "border") {
			room->addBorder(parseBorder(childElement));
		}

	}
	}
	return room;
}

Map* XMLParser::parseMap(TiXmlElement* element) {
	Map* map = new Map();
	map = map;

	TiXmlNode* node = NULL;
	while ((node = element->IterateChildren(node)) != NULL) {

		TiXmlElement* childElement = node->ToElement();

		if (childElement->ValueStr() == "room") {
			map->addRoom(parseRoom(childElement));
		}

		else if(childElement->ValueStr() == "container") {
			map->addContainer(parseContainer(childElement));
		}

		else if(childElement->ValueStr() == "item") {
			map->addItem(parseItem(childElement));
		}

		else if(childElement->ValueStr() == "creature") {
			map->addCreature(parseCreature(childElement));
		}
	}

	return map;
}

Map* XMLParser::parseXML(std::string filename) {

	TiXmlDocument doc(filename);
	doc.LoadFile();

	TiXmlElement* rootElement = doc.RootElement();

	if (rootElement == NULL) {
		std::cerr << "Invalid XML file, contains no data" << std::endl;

	}
	if (rootElement->ValueStr() != "map") {
		std::cerr << "Invalid XML file, should start with Map array" << std::endl;
	}
	this->root = rootElement;
	return parseMap(rootElement);
}

Item* XMLParser::parseMapForItem(std::string item) {
	TiXmlElement* root = this->root;
	Item* newItem;

	TiXmlNode* node = NULL;
	while ((node = root->IterateChildren(node)) != NULL) {

		TiXmlElement* childElement = node->ToElement();
		if(childElement->ValueStr() == "item") {

			TiXmlNode* nodeer = NULL;
			while ((nodeer = childElement->IterateChildren(nodeer)) != NULL) {

				TiXmlElement* childerElement = nodeer->ToElement();
				if (childerElement->ValueStr() != "name") {
					continue;
				}
				else if (childerElement->GetText() == item) {
					newItem = parseItem(childElement);
					return newItem;
				}
				else {
					break;
				}
			}
		}
	}
	return newItem;
}

Creature* XMLParser::parseMapForCreature(std::string creature) {
	TiXmlElement* root = this->root;
	Creature* newCreature;

	TiXmlNode* node = NULL;
	while ((node = root->IterateChildren(node)) != NULL) {

		TiXmlElement* childElement = node->ToElement();
		if(childElement->ValueStr() == "creature") {

			TiXmlNode* nodeer = NULL;
			while ((nodeer = childElement->IterateChildren(nodeer)) != NULL) {

				TiXmlElement* childerElement = nodeer->ToElement();

				if (childerElement->ValueStr() == "name" && childerElement->GetText() == creature) {
					newCreature = parseCreature(childElement);
					return newCreature;
				}
			}
		}
	}

	return newCreature;
}

Container* XMLParser::parseMapForContainer(std::string container) {
	TiXmlElement* root = this->root;
	Container* newContainer;

	TiXmlNode* node = NULL;
	while ((node = root->IterateChildren(node)) != NULL) {

		TiXmlElement* childElement = node->ToElement();
		if(childElement->ValueStr() == "container") {

			TiXmlNode* nodeer = NULL;
			while ((nodeer = childElement->IterateChildren(nodeer)) != NULL) {

				TiXmlElement* childerElement = nodeer->ToElement();

				if (childerElement->GetText() == container) {
					newContainer = parseContainer(childElement);
					return newContainer;
				}
			}
		}
	}

	return newContainer;
}
