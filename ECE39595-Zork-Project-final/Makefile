# Name of the output EXE file
EXECUTABLE=out

# Compiler to use
CC=g++
# Additional C flags, note that defining TIXML_USE_STL lets us use std::string instead of char* for interacting with TinyXML
CFLAGS=-g -std=c++11 -Wall -Werror -DTIXML_USE_STL

# Any source files with a same named header file
CLASSES=*.cpp
#  Source files that have no header file are just included here
SOURCES=main.cpp $(CLASSES) tinyxmlerror.cpp tinyxmlparser.cpp
# All cpp files produce a o file
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=$(CLASSES:.cpp=.h)

# This variable can be overridden to run the program with a different XML file
XML_FILE=sample.xml

# Create a zip file with all relevant files to build the project
ZIPNAME=$(EXECUTABLE).zip
# Create a zip file with all relevant files to build the project
ZIPFILES=$(SOURCES) $(HEADERS) $(PROJECT_FILES) $(XML_FILE)

# Builds then runs the program
run: $(EXECUTABLE)
	./$(EXECUTABLE) $(XML_FILE)


# cleans existing build files then builds
rebuild: clean $(EXECUTABLE)

# Compiles the EXE using all source files
$(EXECUTABLE):
	g++ -std=c++11 *.cpp -g -o out -DTIXML_USE_STL

# general .cpp to .o rule
.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# Cleans all build files
clean:
	$(RM) *.o
	$(RM) $(EXECUTABLE)
	$(RM) $(EXECUTABLE).exe
	$(RM) $(ZIPNAME)

# Creates a zip file for submission
zip: $(ZIPFILES)
	$(ZIP) $(ZIPNAME) $(ZIPFILES)

.PHONY: run clean