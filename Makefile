CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
TARGET = hello_world
SOURCE = hello_world.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run