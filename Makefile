CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -pedantic
TARGET = myrobot
SOURCES = main.cpp House.cpp VacuumCleaner.cpp Algorithm.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJECTS)
