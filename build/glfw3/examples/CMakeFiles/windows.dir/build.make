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
CMAKE_SOURCE_DIR = /home/prithivi/Projects/opengl-learning/lib_srcs/glfw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/prithivi/Projects/opengl-learning/build/glfw3

# Include any dependencies generated for this target.
include examples/CMakeFiles/windows.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/windows.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/windows.dir/flags.make

examples/CMakeFiles/windows.dir/windows.c.o: examples/CMakeFiles/windows.dir/flags.make
examples/CMakeFiles/windows.dir/windows.c.o: /home/prithivi/Projects/opengl-learning/lib_srcs/glfw/examples/windows.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/prithivi/Projects/opengl-learning/build/glfw3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/windows.dir/windows.c.o"
	cd /home/prithivi/Projects/opengl-learning/build/glfw3/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/windows.dir/windows.c.o   -c /home/prithivi/Projects/opengl-learning/lib_srcs/glfw/examples/windows.c

examples/CMakeFiles/windows.dir/windows.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/windows.c.i"
	cd /home/prithivi/Projects/opengl-learning/build/glfw3/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/prithivi/Projects/opengl-learning/lib_srcs/glfw/examples/windows.c > CMakeFiles/windows.dir/windows.c.i

examples/CMakeFiles/windows.dir/windows.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/windows.c.s"
	cd /home/prithivi/Projects/opengl-learning/build/glfw3/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/prithivi/Projects/opengl-learning/lib_srcs/glfw/examples/windows.c -o CMakeFiles/windows.dir/windows.c.s

# Object files for target windows
windows_OBJECTS = \
"CMakeFiles/windows.dir/windows.c.o"

# External object files for target windows
windows_EXTERNAL_OBJECTS =

examples/windows: examples/CMakeFiles/windows.dir/windows.c.o
examples/windows: examples/CMakeFiles/windows.dir/build.make
examples/windows: src/libglfw3.a
examples/windows: /usr/lib/x86_64-linux-gnu/libm.so
examples/windows: /usr/lib/x86_64-linux-gnu/librt.so
examples/windows: /usr/lib/x86_64-linux-gnu/libm.so
examples/windows: examples/CMakeFiles/windows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/prithivi/Projects/opengl-learning/build/glfw3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable windows"
	cd /home/prithivi/Projects/opengl-learning/build/glfw3/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/windows.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/windows.dir/build: examples/windows

.PHONY : examples/CMakeFiles/windows.dir/build

examples/CMakeFiles/windows.dir/clean:
	cd /home/prithivi/Projects/opengl-learning/build/glfw3/examples && $(CMAKE_COMMAND) -P CMakeFiles/windows.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/windows.dir/clean

examples/CMakeFiles/windows.dir/depend:
	cd /home/prithivi/Projects/opengl-learning/build/glfw3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/prithivi/Projects/opengl-learning/lib_srcs/glfw /home/prithivi/Projects/opengl-learning/lib_srcs/glfw/examples /home/prithivi/Projects/opengl-learning/build/glfw3 /home/prithivi/Projects/opengl-learning/build/glfw3/examples /home/prithivi/Projects/opengl-learning/build/glfw3/examples/CMakeFiles/windows.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/windows.dir/depend

