#ifndef VACUUMCLEANER_H
#define VACUUMCLEANER_H

#include "House.h"
#include "Algorithm.h"
#include <vector>

class VacuumCleaner {
public:
    VacuumCleaner(House &house, int maxBatterySteps, int maxMissionSteps);
    void startCleaning();
    void displayStatus() const;

private:
    void makeMove(Algorithm::Direction direction);  // Declare the makeMove function here
    void chargeBattery();
    bool canMove(int x, int y) const;

    House &house;
    int battery;
    int maxBatterySteps;
    int maxMissionSteps;
    int steps;
    int posX, posY;
    std::vector<std::string> log;
};

#endif // VACUUMCLEANER_H
