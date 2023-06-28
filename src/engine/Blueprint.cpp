//
// Created by m4tex on 2023-06-15.
//

#include "engine/Blueprint.h"
#include <fstream>
#include <iostream>

#define BP_HEADER "m4xbp v1\n";

//Blueprint::Blueprint(std::string name, std::string path) : children(nullptr) {
//    std::ofstream file(path + "/" + name + ".m4x");
//
//    if (file.fail()) std::cout << "[Error]: Failed to create blueprint file" << std::endl;
//
//    file << BP_HEADER;
//    file << "n " + name;
//}
//
//Blueprint::Blueprint() : children(nullptr) {}
//
//template<typename T> Blueprint::Instantiate() {
//
//}

//Blueprint Blueprint::ReadFromPath(std::string path) {
//    Blueprint bp;
//
//    std::string name;
//
//    std::ifstream file;
//    file.open(_filepath);
//
//    if (file.fail()) std::cout << "[Error]: Failed to open blueprint file" << std::endl;
//
//    std::string line;
//    while(file.is_open()) {
//        while (std::getline(file, line)) {
//            if (line[0] == 'n') {
//
//            }
//        }
//    }
//
//    return
//}