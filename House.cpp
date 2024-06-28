#include "House.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

House::House(const std::string &filename) {
    loadHouse(filename);
}

void House::loadHouse(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Unable to open house input file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        for (char c : line) {
            if (c == ' ') {
                row.push_back(0);
            } else if (c == 'D') {
                dockX = layout.size();
                dockY = row.size();
                row.push_back(0);
            } else if (c == '#') {
                row.push_back(-1);
            } else if (isdigit(c)) {
                row.push_back(c - '0');
            } else {
                throw std::runtime_error("Error: Invalid character in house input file.");
            }
        }
        layout.push_back(row);
    }

    if (layout.empty() || layout[0].empty()) {
        throw std::runtime_error("Error: Empty or invalid house layout.");
    }
}

void House::displayHouse() const {
    for (const auto &row : layout) {
        for (int cell : row) {
            if (cell == -1) {
                std::cout << '#';
            } else if (cell == 0) {
                std::cout << ' ';
            } else {
                std::cout << cell;
            }
        }
        std::cout << std::endl;
    }
}

int House::getDirtLevel(int x, int y) const {
    return layout[x][y];
}

void House::cleanDirt(int x, int y) {
    if (layout[x][y] > 0) layout[x][y]--;
}

bool House::isWall(int x, int y) const {
    return layout[x][y] == -1;
}

bool House::isDockingStation(int x, int y) const {
    return x == dockX && y == dockY;
}

int House::getTotalDirt() const {
    int totalDirt = 0;
    for (const auto& row : layout) {
        for (int cell : row) {
            if (cell > 0) totalDirt += cell;
        }
    }
    return totalDirt;
}

std::pair<int, int> House::getDimensions() const {
    return { layout.size(), layout[0].size() };
}

int House::getDockX() const {
    return dockX;
}

int House::getDockY() const {
    return dockY;
}
