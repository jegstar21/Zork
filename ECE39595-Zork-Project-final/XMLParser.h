#ifndef _XMLPARSER_H_
#define _XMLPARSER_H_

#pragma once
#include <vector>
#include <string>
#include "Attack.h"
#include "Border.h"
#include "Condition.h"
#include "Container.h"
#include "Creature.h"
#include "Item.h"
#include "Room.h"
#include "Trigger.h"
#include "Turnon.h"
#include "Map.h"
#include "tinyxml.h"

class XMLParser {
private:
	TiXmlElement* root;
	Map* parseMap(TiXmlElement* element);
	Attack* parseAttack(TiXmlElement* element);
	Border* parseBorder(TiXmlElement* element);
	Condition* parseCondition(TiXmlElement* element);
	Container* parseContainer(TiXmlElement* element);
	Creature* parseCreature(TiXmlElement* element);
	Item* parseItem(TiXmlElement* element);
	Room* parseRoom(TiXmlElement* element);
	Trigger* parseTrigger(TiXmlElement* element);
	Turnon* parseTurnon(TiXmlElement* element);
	Item* parseMapForItem(std::string item);
	Creature* parseMapForCreature(std::string creature);
	Container* parseMapForContainer(std::string container);

public:

	Map* parseXML(std::string filename);
};

#endif