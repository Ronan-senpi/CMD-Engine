#pragma once
#include <string>
#include <vector>

class MapLoader{
public:
	MapLoader();
	void LoadMap(std::string& fileName);
private:
	void RemoveWordFromLine(std::string &line, const std::string &word);
	std::vector<std::string> Split(const std::string& s, const std::string& delimiter);


	std::string firstSizeChar = "[";
	std::string lastSizeChar = "]";
	std::string sizeDelimiter = ",";
	std::string labelDelimiter = " ";
};