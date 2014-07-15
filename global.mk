################################################################################
# BUILD FLAGS
################################################################################

# Be silent by default, but 'make V=1' will show all compiler calls
ifneq ($(V),1)
MAKEFLAGS += --no-print-directory
MAKEFLAGS += -s
endif

# Debugging flags are off by default; 'make D=1' will enable them
ifeq ($(D),1)
CFLAGS += -g -O0
LDFLAGS += -g -O0
else
CFLAGS += -O2
LDFLAGS += -O2
endif

# Turn on maximum warnings for fine tuning
ifeq ($(W),1)
CFLAGS += -Wall -Werror
endif


################################################################################
# DIRECTORIES
################################################################################

# Top level directory structure common to every project
BASE_DIR := $(CURDIR)
INC      := $(BASE_DIR)/include
SRC      := $(BASE_DIR)/src
OBJ      := $(BASE_DIR)/obj
BIN      := $(BASE_DIR)/bin

# Includes common to every project
INCLUDES := -I$(INC)


################################################################################
# FILES
################################################################################

# Files structure to every project
SOURCE          := $(wildcard $(SRC)/*.cpp)
OBJECTS         := $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SOURCE))

# Dependency files
-include $(OBJECTS:.o=.d)


################################################################################
# TOOLS
################################################################################

# Tools common to all projects
MAKE   := make
CPP    := g++

# Compiler flags common to all projects -- Note the use of '=' rather than ':='
CFLAGS  += $(INCLUDES) -Wfatal-errors -g
LDFLAGS += -Wfatal-errors -g
