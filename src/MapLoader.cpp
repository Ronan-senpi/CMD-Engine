#include "MapLoader.h"
#include <fstream>
#include <iostream>
#include <map>
#include "GameObject.h"
#include "Transform.h"
#include "ASCIIRenderer.h"

enum MapDataType : int {None,Size,Labels,Map};
enum MapCellType : int {Empty,Wall,Enemy,Player,Gold};

MapLoader::MapLoader() {

}
void MapLoader::LoadMap(Scene& scene, std::string& fileName) {

	std::ifstream infile("resources/map1.txt");

	std::map<char,MapCellType> content;// key : the character, data : the type of cell

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
			switch (currentData) {
				case Map:
					std::cout << "Map " << line << '\n';
					for(char& cell : line){
						MapCellType cellType = content[cell];
						if(cellType != Empty){

							std::vector<std::shared_ptr<Component>> components;
							Transform t(3,5);
							components.push_back(std::make_shared<Transform>(3, 5));
							components.push_back(std::make_shared<ASCIIRenderer>());

							GameObject go(components);
							//scene.add go
							std::cout << " not empty " << std::endl;
							scene.
						}else{
							std::cout << " EMPTY " << std::endl;
						}
					}
					currentLine++;
					break;
				case Labels:
					std::cout << "Labels" << std::endl;
					substrings = Split(line,labelDelimiter);
					if(substrings.size() == 2){
						MapCellType cellType;
						if(substrings[0] == "wall") {
								cellType = Wall;
						}else if(substrings[0] == "player") {
							cellType = Player;
						}else if(substrings[0] == "enemy") {
							cellType = Enemy;
						}else if(substrings[0] == "gold") {
							cellType = Gold;
						}
						content[substrings[1].c_str()[0]] = cellType;
						std::cout << substrings[1] << " -> " << substrings[0] << std::endl;
					}
					break;
				case Size:
					std::cout << "Size" << std::endl;
					RemoveWordFromLine(line, firstSizeChar);
					RemoveWordFromLine(line, lastSizeChar);
					substrings = Split(line,sizeDelimiter);
					int width = atoi(substrings[0].c_str());
					int height = atoi(substrings[1].c_str());
					scene.SetSceneDimensions(width,height);
					std::cout << "Size : " << width << " " << height << std::endl;
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
