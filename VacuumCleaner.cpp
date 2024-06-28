#include "VacuumCleaner.h"
#include <iostream>

VacuumCleaner::VacuumCleaner(House &house, int maxBatterySteps, int maxMissionSteps)
    : house(house), maxBatterySteps(maxBatterySteps), maxMissionSteps(maxMissionSteps), steps(0), posX(house.getDockX()), posY(house.getDockY()) {
    battery = maxBatterySteps;
}

void VacuumCleaner::startCleaning() {
    Algorithm algo;
    while (steps < maxMissionSteps && battery > 0) {
        Algorithm::Direction direction = algo.getNextMove();
        makeMove(direction);
        if (house.isDockingStation(posX, posY)) {
            chargeBattery();
        }
        steps++;
    }
}

void VacuumCleaner::displayStatus() const {
    for (const std::string &entry : log) {
        std::cout << entry << std::endl;
    }
    std::cout << "Total steps: " << steps << std::endl;
    std::cout << "Dirt left: " << house.getTotalDirt() << std::endl;
    std::cout << "Battery exhausted: " << (battery <= 0) << std::endl;
    std::cout << "Mission succeeded: " << (house.getTotalDirt() == 0 && house.isDockingStation(posX, posY)) << std::endl;
}

void VacuumCleaner::makeMove(Algorithm::Direction direction) {
    int newX = posX, newY = posY;
    switch (direction) {
        case Algorithm::NORTH: newX--; break;
        case Algorithm::EAST: newY++; break;
        case Algorithm::SOUTH: newX++; break;
        case Algorithm::WEST: newY--; break;
        case Algorithm::STAY: break;
    }
    if (canMove(newX, newY)) {
        posX = newX;
        posY = newY;
        battery--;
        if (house.getDirtLevel(posX, posY) > 0) {
            house.cleanDirt(posX, posY);
            log.push_back("Cleaned dirt at (" + std::to_string(posX) + "," + std::to_string(posY) + ")");
        } else {
            log.push_back("Moved to (" + std::to_string(posX) + "," + std::to_string(posY) + ")");
        }
    }
}

void VacuumCleaner::chargeBattery() {
    battery = maxBatterySteps;
    log.push_back("Battery charged at docking station");
}

bool VacuumCleaner::canMove(int x, int y) const {
    std::pair<int, int> dimensions = house.getDimensions();
    int maxX = dimensions.first;
    int maxY = dimensions.second;
    return x >= 0 && x < maxX && y >= 0 && y < maxY && !house.isWall(x, y);
}
