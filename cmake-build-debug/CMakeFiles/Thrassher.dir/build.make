# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Matheus\Documents\Code\7_C\Thrassher\Thrassher

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Matheus\Documents\Code\7_C\Thrassher\Thrassher\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Thrassher.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Thrassher.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Thrassher.dir/flags.make

CMakeFiles/Thrassher.dir/main.c.obj: CMakeFiles/Thrassher.dir/flags.make
CMakeFiles/Thrassher.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Matheus\Documents\Code\7_C\Thrassher\Thrassher\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Thrassher.dir/main.c.obj"
	C:\minGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Thrassher.dir\main.c.obj   -c C:\Users\Matheus\Documents\Code\7_C\Thrassher\Thrassher\main.c

CMakeFiles/Thrassher.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Thrassher.dir/main.c.i"
	C:\minGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Matheus\Documents\Code\7_C\Thrassher\Thrassher\main.c > CMakeFiles\Thrassher.dir\main.c.i

CMakeFiles/Thrassher.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Thrassher.dir/main.c.s"
	C:\minGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Matheus\Documents\Code\7_C\Thrassher\Thrassher\main.c -o CMakeFiles\Thrassher.dir\main.c.s

# Object files for target Thrassher
Thrassher_OBJECTS = \
"CMakeFiles/Thrassher.dir/main.c.obj"

# External object files for target Thrassher
Thrassher_EXTERNAL_OBJECTS =

Thrassher.exe: CMakeFiles/Thrassher.dir/main.c.obj
Thrassher.exe: CMakeFiles/Thrassher.dir/build.make
Thrassher.exe: CMakeFiles/Thrassher.dir/linklibs.rsp
Thrassher.exe: CMakeFiles/Thrassher.dir/objects1.rsp
Thrassher.exe: CMakeFiles/Thrassher.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Matheus\Documents\Code\7_C\Thrassher\Thrassher\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Thrassher.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Thrassher.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Thrassher.dir/build: Thrassher.exe

.PHONY : CMakeFiles/Thrassher.dir/build

CMakeFiles/Thrassher.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Thrassher.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Thrassher.dir/clean

CMakeFiles/Thrassher.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Matheus\Documents\Code\7_C\Thrassher\Thrassher C:\Users\Matheus\Documents\Code\7_C\Thrassher\Thrassher C:\Users\Matheus\Documents\Code\7_C\Thrassher\Thrassher\cmake-build-debug C:\Users\Matheus\Documents\Code\7_C\Thrassher\Thrassher\cmake-build-debug C:\Users\Matheus\Documents\Code\7_C\Thrassher\Thrassher\cmake-build-debug\CMakeFiles\Thrassher.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Thrassher.dir/depend
