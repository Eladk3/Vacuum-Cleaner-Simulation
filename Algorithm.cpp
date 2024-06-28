#include "Algorithm.h"
#include <cstdlib>

Algorithm::Direction Algorithm::getNextMove() {
    return static_cast<Direction>(rand() % 5);
}
