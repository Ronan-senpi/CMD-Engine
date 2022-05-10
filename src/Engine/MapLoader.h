#pragma once
#include <string>
#include <vector>
#include "Scene.h"

class MapLoader{
public:
	MapLoader();
	void LoadMap(Scene* scene, std::string& fileName);
private:
	void RemoveWordFromLine(std::string &line, const std::string &word);
	std::vector<std::string> Split(const std::string& s, const std::string& delimiter);


	std::string firstSizeChar = "[";
	std::string lastSizeChar = "]";
	std::string sizeDelimiter = ",";
	std::string labelDelimiter = " ";
};