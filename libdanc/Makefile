# /*
#  * ________________________________________________________________________________
#  * |  File: Makefile
#  * |  Project: patient
#  * |  File Created: Wednesday, 27th November 2024 06:41 pm
#  * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
#  */ 

# Define the target executable
TARGET := libdanc.a

# Define the compiler and flags
C_COMPILER			:= gcc
ARCHIVER			:= ar rcs
DEPENDENCY_TRACKING := -MMD -MP
FLAGS				:= -Wextra -Wall

# Define source and object directories
SRC_DIR		:= source/
OBJ_DIR		:= object/

# Find all .c files in the source directory
SOURCE := $(wildcard $(SRC_DIR)*.c)

# Convert source files to object files
OBJECTS := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SOURCE))

# Linking command
LINK := $(ARCHIVER) $(TARGET) $(OBJECTS)

# Default rule to build the target executable
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJ_DIR) $(OBJECTS)
	echo "CREATING STATIC LIBRARY $(TARGET)..."
	$(LINK)

# Rule to compile source files into object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	echo "COMPILING OBJECTS ($@)"
	$(C_COMPILER) $(FLAGS) $(ADDSAN) $(DEPENDENCY_TRACKING) -c $< -o $@

# Rule to create the object directory
$(OBJ_DIR):
	echo "CREATING OBJECT DIRECTORY..."
	mkdir -p $(OBJ_DIR)

# Include dependency files
-include $(OBJECTS:.o=.d)

test:
	$(C_COMPILER) test.c $(TARGET) -o output -fsanitize=address -g

# Rule to clean up compiled files
clean:
	echo "REMOVING OBJECT FILES..."
	rm -rf $(OBJ_DIR) $(TARGET)
	
# Phony targets
.PHONY: clean all
.SILENT: