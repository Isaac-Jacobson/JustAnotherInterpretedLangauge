# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /s/bach/j/under/isaac13/HW6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /s/bach/j/under/isaac13/HW6

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /s/bach/j/under/isaac13/HW6/CMakeFiles /s/bach/j/under/isaac13/HW6/CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /s/bach/j/under/isaac13/HW6/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named hw6.tar

# Build rule for target.
hw6.tar: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 hw6.tar
.PHONY : hw6.tar

# fast build rule for target.
hw6.tar/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw6.tar.dir/build.make CMakeFiles/hw6.tar.dir/build
.PHONY : hw6.tar/fast

#=============================================================================
# Target rules for targets named test

# Build rule for target.
test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test
.PHONY : test

# fast build rule for target.
test/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/build
.PHONY : test/fast

#=============================================================================
# Target rules for targets named hw6

# Build rule for target.
hw6: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 hw6
.PHONY : hw6

# fast build rule for target.
hw6/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw6.dir/build.make CMakeFiles/hw6.dir/build
.PHONY : hw6/fast

Board.o: Board.cc.o

.PHONY : Board.o

# target to build an object file
Board.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw6.dir/build.make CMakeFiles/hw6.dir/Board.cc.o
.PHONY : Board.cc.o

Board.i: Board.cc.i

.PHONY : Board.i

# target to preprocess a source file
Board.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw6.dir/build.make CMakeFiles/hw6.dir/Board.cc.i
.PHONY : Board.cc.i

Board.s: Board.cc.s

.PHONY : Board.s

# target to generate assembly for a file
Board.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw6.dir/build.make CMakeFiles/hw6.dir/Board.cc.s
.PHONY : Board.cc.s

Rule.o: Rule.cc.o

.PHONY : Rule.o

# target to build an object file
Rule.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw6.dir/build.make CMakeFiles/hw6.dir/Rule.cc.o
.PHONY : Rule.cc.o

Rule.i: Rule.cc.i

.PHONY : Rule.i

# target to preprocess a source file
Rule.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw6.dir/build.make CMakeFiles/hw6.dir/Rule.cc.i
.PHONY : Rule.cc.i

Rule.s: Rule.cc.s

.PHONY : Rule.s

# target to generate assembly for a file
Rule.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/hw6.dir/build.make CMakeFiles/hw6.dir/Rule.cc.s
.PHONY : Rule.cc.s

test.o: test.cc.o

.PHONY : test.o

# target to build an object file
test.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/test.cc.o
.PHONY : test.cc.o

test.i: test.cc.i

.PHONY : test.i

# target to preprocess a source file
test.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/test.cc.i
.PHONY : test.cc.i

test.s: test.cc.s

.PHONY : test.s

# target to generate assembly for a file
test.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/test.cc.s
.PHONY : test.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... hw6.tar"
	@echo "... hw6"
	@echo "... test"
	@echo "... Board.o"
	@echo "... Board.i"
	@echo "... Board.s"
	@echo "... Rule.o"
	@echo "... Rule.i"
	@echo "... Rule.s"
	@echo "... test.o"
	@echo "... test.i"
	@echo "... test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

