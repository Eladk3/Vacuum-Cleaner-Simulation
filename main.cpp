#include <iostream>
#include <fstream>
#include "House.h"
#include "VacuumCleaner.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <house_input_file>" << std::endl;
        return 1;
    }

    try {
        std::string houseFile = argv[1];
        House house(houseFile);
        house.displayHouse();

        int maxBatterySteps = 100; // Example value
        int maxMissionSteps = 1000; // Example value
        VacuumCleaner vc(house, maxBatterySteps, maxMissionSteps);
        vc.startCleaning();

        std::string outputFileName = "output_" + houseFile;
        std::ofstream outputFile(outputFileName);
        if (!outputFile) {
            std::cerr << "Error: Unable to open output file." << std::endl;
            return 1;
        }
        std::streambuf *coutbuf = std::cout.rdbuf(); // Save old buffer
        std::cout.rdbuf(outputFile.rdbuf()); // Redirect std::cout to output file

        vc.displayStatus();

        std::cout.rdbuf(coutbuf); // Reset to standard output
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
