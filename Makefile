# <PROJECT> makefile.
# 

default: all

# Pick one of:
#   linux
#   macos
#   windows

UNAME=$(shell uname)
ifeq ($(UNAME),Darwin)
  OS=macos
else ifeq ($(UNAME),Linux)
  OS=linux
else ifneq (,$(findstring MINGW32_NT,$(UNAME)))
  OS=win
else
  $(error unknown os $(UNAME))
endif

# Build directory
#

BUILD_DIR=build
INCLUDE_DIR=src

# Commands
#

RM=rm -f
CXX=g++

# Libraries
#

SFML_GRAPHICS=sfml-graphics
SFML_WINDOW=sfml-window
SFML_SYSTEM=sfml-system
SFML_AUDIO=sfml-audio
SFML_INCLUDE_DIR=/usr/include/

# Compiler flags
#

CXXFLAGS=-std=c++14 \
         -I$(INCLUDE_DIR) \
	 -I$(SFML_INCLUDE_DIR)

CXXWFLAGS=-Wall \
          -Wextra \
          -Werror

# Misc
#

TAGS=.tags \
     .etags

# Source code files
#

DEMO_OFILES=src/Graphics/RoundedRectangleShape.o \
	    src/Graphics/UI/SelectionMenu.o \
	    src/Main.o

# Make targets
#

all: demo

demo: $(BUILD_DIR)/demo

$(BUILD_DIR)/demo: $(DEMO_OFILES)
	@echo "    BUILD  $(BUILD_DIR)/demo"
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -o $(BUILD_DIR)/demo \
	        $(DEMO_OFILES) \
	        -l$(SFML_WINDOW) -l$(SFML_SYSTEM) -l$(SFML_GRAPHICS) \
	        -l$(SFML_AUDIO) \

%.o: %.cpp
	@echo "    CXX    $@"
	@$(CXX) -c $(CXXWFLAGS) $(CXXFLAGS) -o $@ $<

# Tag files
#

tags: etags

etags:
	etags -f .etags $$(find ./src -name '*.cpp' -or -name '*.hpp') || true

# Cleaning
#

clean:
	@echo "    CLEAN"
	@$(RM) $(DEMO_OFILES) \
	       $(BUILD_DIR)/demo \
	       $(TAGS) \
	       **/*~

.PHONY: clean
