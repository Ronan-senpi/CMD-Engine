#include "MapLoader.h"
#include <fstream>
#include <iostream>
#include <map>
#include "../Objects/GameObject.h"
#include "../Components/Transform.h"
#include "../Components/ASCIIRenderer.h"
#include "TagManager.h"

enum MapDataType : int {None,Size,Labels,Map};

MapLoader::MapLoader() {
}

void MapLoader::LoadMap(Factory* fac, Scene* scene, std::string& fileName) {
	std::ifstream infile("resources/map1.txt");

	std::map<char,int> content;// key : the character, data : the type of cell

	MapDataType currentData = None;
	int currentLine = 0;
	for (std::string line; std::getline(infile, line, '\n'); ) {

		if(line[0] == '>'){//reading a change in data type
			if (line == ">size"){
				currentData = Size;
			}else if (line == ">labels"){
				currentData = Labels;
			}else if (line == ">map"){
				currentData = Map;
			}
		}else{//reading data
			std::vector<std::string> substrings;
			int currentChar = 0;
			switch (currentData) {
				case Map:
					currentChar = 0;
					for(char& cell : line){

						auto cellType = content.find(cell);
						if(cellType != content.end()){
							//std::vector<Component*> components;
							//components.push_back(new Transform(currentChar, currentLine));
							//components.push_back(new ASCIIRenderer(cell,0));
							//GameObject go(std::move(components));
							Position pos = Position(currentChar,currentLine);
							GameObject* go = fac->createObject(cellType->second, pos,cell);
							scene->Instantiate(go);
						}
						currentChar++;
					}
					currentLine++;
					break;
				case Labels:
					substrings = Split(line,labelDelimiter);
					if(substrings.size() == 2){
						content[substrings[1].c_str()[0]] = TagManager::getInstance()->m_TagManager[substrings[0]];
					}
					break;
				case Size:
					RemoveWordFromLine(line, firstSizeChar);
					RemoveWordFromLine(line, lastSizeChar);
					substrings = Split(line,sizeDelimiter);
					int width = atoi(substrings[0].c_str());
					int height = atoi(substrings[1].c_str());
					scene->SetSceneDimensions(width,height);
					break;
			}
		}
	}
}
void MapLoader::RemoveWordFromLine(std::string &line, const std::string &word)
{
	auto n = line.find(word);
	if (n != std::string::npos)
	{
		line.erase(n, word.length());
	}
}
// for string delimiter
std::vector<std::string> MapLoader::Split(const std::string& s, const std::string& delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	std::string token;
	std::vector<std::string> res;

	while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
		token = s.substr (pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back (token);
	}

	res.push_back (s.substr (pos_start));
	return res;
}
