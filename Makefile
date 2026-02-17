# /*
#  * ________________________________________________________________________________
#  * |  File: Makefile
#  * |  Project: patient
#  * |  File Created: Wednesday, 27th November 2024 06:41 pm
#  * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
#  */

# Define the target executable
TARGET := gush

# Define the compiler and flags
C_COMPILER			:= gcc
CFLAGS				:= -fsanitize=address -g
LDFLAGS 			:= -lreadline
DEPENDENCY_TRACKING := -MMD -MP
FLAGS				:= -Wall -Wextra 

# Define source and object directories
SRC_DIR		:= source/
OBJ_DIR		:= object/
DANC_DIR 	:= libdanc/
LIBDANC		:= $(DANC_DIR)libdanc.a

# Find all .c files in the source directory
SOURCE := $(wildcard $(SRC_DIR)*.c)

# Convert source files to object files
OBJECTS := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SOURCE))

# Linking command
LINK := $(C_COMPILER) -o $(TARGET) $(OBJECTS) $(LIBDANC) $(CFLAGS) $(LDFLAGS)

# Default rule to build the target executable
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJ_DIR) $(OBJECTS)
	echo "CREATING EXECUTABLE $(TARGET)..."
	$(LINK)

# Rule to compile source files into object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	echo "COMPILING OBJECTS ($@)"
	$(C_COMPILER) $(FLAGS) $(ADDSAN) $(DEPENDENCY_TRACKING) -c $< -o $@ $(CFLAGS)

# Rule to create the object directory
$(OBJ_DIR):
	echo "CREATING OBJECT DIRECTORY..."
	mkdir -p $(OBJ_DIR)

# Include dependency files
-include $(OBJECTS:.o=.d)

# Rule to clean up compiled files
clean:
	echo "REMOVING OBJECT FILES..."
	rm -rf $(OBJ_DIR) $(TARGET)

libs:
	make -C $(DANC_DIR)

# Phony targets
.PHONY: clean all
.SILENT: