# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nick/esprog

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nick/esprog

# Include any dependencies generated for this target.
include CMakeFiles/SIR_Simulation.out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SIR_Simulation.out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SIR_Simulation.out.dir/flags.make

CMakeFiles/SIR_Simulation.out.dir/main.cpp.o: CMakeFiles/SIR_Simulation.out.dir/flags.make
CMakeFiles/SIR_Simulation.out.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nick/esprog/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SIR_Simulation.out.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SIR_Simulation.out.dir/main.cpp.o -c /home/nick/esprog/main.cpp

CMakeFiles/SIR_Simulation.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SIR_Simulation.out.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nick/esprog/main.cpp > CMakeFiles/SIR_Simulation.out.dir/main.cpp.i

CMakeFiles/SIR_Simulation.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SIR_Simulation.out.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nick/esprog/main.cpp -o CMakeFiles/SIR_Simulation.out.dir/main.cpp.s

# Object files for target SIR_Simulation.out
SIR_Simulation_out_OBJECTS = \
"CMakeFiles/SIR_Simulation.out.dir/main.cpp.o"

# External object files for target SIR_Simulation.out
SIR_Simulation_out_EXTERNAL_OBJECTS =

SIR_Simulation.out: CMakeFiles/SIR_Simulation.out.dir/main.cpp.o
SIR_Simulation.out: CMakeFiles/SIR_Simulation.out.dir/build.make
SIR_Simulation.out: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
SIR_Simulation.out: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
SIR_Simulation.out: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
SIR_Simulation.out: CMakeFiles/SIR_Simulation.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nick/esprog/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SIR_Simulation.out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SIR_Simulation.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SIR_Simulation.out.dir/build: SIR_Simulation.out

.PHONY : CMakeFiles/SIR_Simulation.out.dir/build

CMakeFiles/SIR_Simulation.out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SIR_Simulation.out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SIR_Simulation.out.dir/clean

CMakeFiles/SIR_Simulation.out.dir/depend:
	cd /home/nick/esprog && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nick/esprog /home/nick/esprog /home/nick/esprog /home/nick/esprog /home/nick/esprog/CMakeFiles/SIR_Simulation.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SIR_Simulation.out.dir/depend

