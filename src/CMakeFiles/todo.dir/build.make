# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

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

#Suppress display of executed commands.
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
CMAKE_SOURCE_DIR = /home/salted/repos/todo-cli

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/salted/repos/todo-cli/src

# Include any dependencies generated for this target.
include CMakeFiles/todo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/todo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/todo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/todo.dir/flags.make

CMakeFiles/todo.dir/codegen:
.PHONY : CMakeFiles/todo.dir/codegen

CMakeFiles/todo.dir/main.cpp.o: CMakeFiles/todo.dir/flags.make
CMakeFiles/todo.dir/main.cpp.o: main.cpp
CMakeFiles/todo.dir/main.cpp.o: CMakeFiles/todo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/salted/repos/todo-cli/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/todo.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/todo.dir/main.cpp.o -MF CMakeFiles/todo.dir/main.cpp.o.d -o CMakeFiles/todo.dir/main.cpp.o -c /home/salted/repos/todo-cli/src/main.cpp

CMakeFiles/todo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/todo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/salted/repos/todo-cli/src/main.cpp > CMakeFiles/todo.dir/main.cpp.i

CMakeFiles/todo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/todo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/salted/repos/todo-cli/src/main.cpp -o CMakeFiles/todo.dir/main.cpp.s

# Object files for target todo
todo_OBJECTS = \
"CMakeFiles/todo.dir/main.cpp.o"

# External object files for target todo
todo_EXTERNAL_OBJECTS =

todo: CMakeFiles/todo.dir/main.cpp.o
todo: CMakeFiles/todo.dir/build.make
todo: CMakeFiles/todo.dir/compiler_depend.ts
todo: CMakeFiles/todo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/salted/repos/todo-cli/src/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable todo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/todo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/todo.dir/build: todo
.PHONY : CMakeFiles/todo.dir/build

CMakeFiles/todo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/todo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/todo.dir/clean

CMakeFiles/todo.dir/depend:
	cd /home/salted/repos/todo-cli/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/salted/repos/todo-cli /home/salted/repos/todo-cli /home/salted/repos/todo-cli/src /home/salted/repos/todo-cli/src /home/salted/repos/todo-cli/src/CMakeFiles/todo.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/todo.dir/depend

