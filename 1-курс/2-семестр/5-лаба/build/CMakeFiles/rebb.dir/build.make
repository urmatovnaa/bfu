# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /snap/cmake/1378/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1378/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба/build

# Include any dependencies generated for this target.
include CMakeFiles/rebb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rebb.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rebb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rebb.dir/flags.make

CMakeFiles/rebb.dir/main.cpp.o: CMakeFiles/rebb.dir/flags.make
CMakeFiles/rebb.dir/main.cpp.o: /home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба/main.cpp
CMakeFiles/rebb.dir/main.cpp.o: CMakeFiles/rebb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rebb.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rebb.dir/main.cpp.o -MF CMakeFiles/rebb.dir/main.cpp.o.d -o CMakeFiles/rebb.dir/main.cpp.o -c /home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба/main.cpp

CMakeFiles/rebb.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/rebb.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба/main.cpp > CMakeFiles/rebb.dir/main.cpp.i

CMakeFiles/rebb.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/rebb.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба/main.cpp -o CMakeFiles/rebb.dir/main.cpp.s

# Object files for target rebb
rebb_OBJECTS = \
"CMakeFiles/rebb.dir/main.cpp.o"

# External object files for target rebb
rebb_EXTERNAL_OBJECTS =

rebb: CMakeFiles/rebb.dir/main.cpp.o
rebb: CMakeFiles/rebb.dir/build.make
rebb: CMakeFiles/rebb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rebb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rebb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rebb.dir/build: rebb
.PHONY : CMakeFiles/rebb.dir/build

CMakeFiles/rebb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rebb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rebb.dir/clean

CMakeFiles/rebb.dir/depend:
	cd /home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба /home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба /home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба/build /home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба/build /home/killua/Desktop/bfu_1/лабы_программирование/1-курс/2-семестр/5-лаба/build/CMakeFiles/rebb.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/rebb.dir/depend

