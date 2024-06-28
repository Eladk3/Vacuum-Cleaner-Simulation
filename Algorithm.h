#ifndef ALGORITHM_H
#define ALGORITHM_H

class Algorithm {
public:
    enum Direction { NORTH, EAST, SOUTH, WEST, STAY };
    Direction getNextMove();
};

#endif // ALGORITHM_H
