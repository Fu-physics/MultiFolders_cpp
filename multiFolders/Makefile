## makefile for cases that 
##	makefile is upper directory of all source files, such as
##  .
##	makefile
##	./src -------> '*.cpp'
##	./obj -------> '*.o'
##	./include ---> '*.h'

##	run command: './a' or 'make run'
##	for an explanation of ‘:=’, which is a variant of ‘=’.

CXX := g++
CFLAGS := -Wall -g
TARGET := a

SRC_DIR = src
OBJ_DIR = obj

# $(wildcard $(SRC_DIR)/*.cpp /xxx/xxx/*.cpp): get all .cpp files from the '$(SRC_DIR)' directory and dir "/xxx/xxx/"
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
# Change the list of Cpp source files into a list of object files by replacing the ‘.cpp’ 
# suffix with ‘.o’ in the result, like this:
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o,$(SRCS))

## the include path
INC = -Iinclude
VPATH = ./:include


all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

## for each using '%', not '*'
## '${INC}' is used to add the '*.h' file
$(OBJS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $(CFLAGS) ${INC} $< -o $@

run: 
	./a


## this command is for windows termianl
## It does not work for wsl
plot:
	gnuplot ./gnuplot/plot.gp
	
.PHONY: all clean

clean:
	rm -rf $(OBJ_DIR)/*.o 

# $^
# The names of all the prerequisites, with spaces between them.

# $@
# The file name of the target of the rule. If the target is an archive member, then ‘$@’ is the name of the archive file. In a pattern rule that has multiple targets (see Introduction to Pattern Rules), 
# ‘$@’ is the name of whichever target caused the rule’s recipe to be run.

# $%
# The target member name, when the target is an archive member. See Archives. For example, if the target is foo.a(bar.o) then ‘$%’ is bar.o and ‘$@’ is foo.a. 
# ‘$%’ is empty when the target is not an archive member.

# $<
# The name of the first prerequisite. If the target got its recipe from an implicit rule, 
# this will be the first prerequisite added by the implicit rule (see Implicit Rules).

# $*
# The stem with which an implicit rule matches (see How Patterns Match). If the target is dir/a.foo.b and the target pattern is a.%.b then the stem is dir/foo. The stem is useful for constructing names of related files.

# In a static pattern rule, the stem is part of the file name that matched the ‘%’ in the target pattern.