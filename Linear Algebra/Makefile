
CXX = g++

CXXFLAGS = -std=c++17 -Wall -I./include

SRC_DIR = ./src
BUILD_DIR = ./build

EXEC = matrixFunzzies

SOURCES = $(SRC_DIR)/matrix.cpp $(SRC_DIR)/main.cpp

OBJECTS = $(BUILD_DIR)/matrix.o $(BUILD_DIR)/main.o

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC)

.PHONY: all clean