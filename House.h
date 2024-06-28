#ifndef HOUSE_H
#define HOUSE_H

#include <vector>
#include <string>
#include <utility>

class House {
public:
    House(const std::string &filename);
    void displayHouse() const;
    int getDirtLevel(int x, int y) const;
    void cleanDirt(int x, int y);
    bool isWall(int x, int y) const;
    bool isDockingStation(int x, int y) const;
    int getTotalDirt() const;
    std::pair<int, int> getDimensions() const;
    int getDockX() const;
    int getDockY() const;

private:
    void loadHouse(const std::string &filename);
    std::vector<std::vector<int>> layout;
    int dockX, dockY;
};

#endif // HOUSE_H
