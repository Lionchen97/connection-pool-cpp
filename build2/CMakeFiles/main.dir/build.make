# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/project/gitpro3/connection-pool-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/project/gitpro3/connection-pool-cpp/build2

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/main.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/project/gitpro3/connection-pool-cpp/build2/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/src/main.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/main.o -c /root/project/gitpro3/connection-pool-cpp/src/main.cpp

CMakeFiles/main.dir/src/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/project/gitpro3/connection-pool-cpp/src/main.cpp > CMakeFiles/main.dir/src/main.i

CMakeFiles/main.dir/src/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/project/gitpro3/connection-pool-cpp/src/main.cpp -o CMakeFiles/main.dir/src/main.s

CMakeFiles/main.dir/src/main.o.requires:
.PHONY : CMakeFiles/main.dir/src/main.o.requires

CMakeFiles/main.dir/src/main.o.provides: CMakeFiles/main.dir/src/main.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.o.provides.build
.PHONY : CMakeFiles/main.dir/src/main.o.provides

CMakeFiles/main.dir/src/main.o.provides.build: CMakeFiles/main.dir/src/main.o

CMakeFiles/main.dir/src/Connection.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/Connection.o: ../src/Connection.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/project/gitpro3/connection-pool-cpp/build2/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/src/Connection.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/Connection.o -c /root/project/gitpro3/connection-pool-cpp/src/Connection.cpp

CMakeFiles/main.dir/src/Connection.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/Connection.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/project/gitpro3/connection-pool-cpp/src/Connection.cpp > CMakeFiles/main.dir/src/Connection.i

CMakeFiles/main.dir/src/Connection.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/Connection.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/project/gitpro3/connection-pool-cpp/src/Connection.cpp -o CMakeFiles/main.dir/src/Connection.s

CMakeFiles/main.dir/src/Connection.o.requires:
.PHONY : CMakeFiles/main.dir/src/Connection.o.requires

CMakeFiles/main.dir/src/Connection.o.provides: CMakeFiles/main.dir/src/Connection.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/Connection.o.provides.build
.PHONY : CMakeFiles/main.dir/src/Connection.o.provides

CMakeFiles/main.dir/src/Connection.o.provides.build: CMakeFiles/main.dir/src/Connection.o

CMakeFiles/main.dir/src/CommonConnectionPool.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/CommonConnectionPool.o: ../src/CommonConnectionPool.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/project/gitpro3/connection-pool-cpp/build2/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/main.dir/src/CommonConnectionPool.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/src/CommonConnectionPool.o -c /root/project/gitpro3/connection-pool-cpp/src/CommonConnectionPool.cpp

CMakeFiles/main.dir/src/CommonConnectionPool.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/src/CommonConnectionPool.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/project/gitpro3/connection-pool-cpp/src/CommonConnectionPool.cpp > CMakeFiles/main.dir/src/CommonConnectionPool.i

CMakeFiles/main.dir/src/CommonConnectionPool.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/CommonConnectionPool.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/project/gitpro3/connection-pool-cpp/src/CommonConnectionPool.cpp -o CMakeFiles/main.dir/src/CommonConnectionPool.s

CMakeFiles/main.dir/src/CommonConnectionPool.o.requires:
.PHONY : CMakeFiles/main.dir/src/CommonConnectionPool.o.requires

CMakeFiles/main.dir/src/CommonConnectionPool.o.provides: CMakeFiles/main.dir/src/CommonConnectionPool.o.requires
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/CommonConnectionPool.o.provides.build
.PHONY : CMakeFiles/main.dir/src/CommonConnectionPool.o.provides

CMakeFiles/main.dir/src/CommonConnectionPool.o.provides.build: CMakeFiles/main.dir/src/CommonConnectionPool.o

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/main.o" \
"CMakeFiles/main.dir/src/Connection.o" \
"CMakeFiles/main.dir/src/CommonConnectionPool.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/main.o
main: CMakeFiles/main.dir/src/Connection.o
main: CMakeFiles/main.dir/src/CommonConnectionPool.o
main: CMakeFiles/main.dir/build.make
main: /usr/lib64/mysql/libmysqlclient.so
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/main.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/Connection.o.requires
CMakeFiles/main.dir/requires: CMakeFiles/main.dir/src/CommonConnectionPool.o.requires
.PHONY : CMakeFiles/main.dir/requires

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /root/project/gitpro3/connection-pool-cpp/build2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/project/gitpro3/connection-pool-cpp /root/project/gitpro3/connection-pool-cpp /root/project/gitpro3/connection-pool-cpp/build2 /root/project/gitpro3/connection-pool-cpp/build2 /root/project/gitpro3/connection-pool-cpp/build2/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend
