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
CMAKE_SOURCE_DIR = /work/workspace/test/cpp/boost/study/asio-master/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /work/workspace/test/cpp/boost/study/asio-master/src

# Include any dependencies generated for this target.
include conn_pair/CMakeFiles/pair.dir/depend.make

# Include the progress variables for this target.
include conn_pair/CMakeFiles/pair.dir/progress.make

# Include the compile flags for this target's objects.
include conn_pair/CMakeFiles/pair.dir/flags.make

conn_pair/CMakeFiles/pair.dir/pair.cc.o: conn_pair/CMakeFiles/pair.dir/flags.make
conn_pair/CMakeFiles/pair.dir/pair.cc.o: conn_pair/pair.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /work/workspace/test/cpp/boost/study/asio-master/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object conn_pair/CMakeFiles/pair.dir/pair.cc.o"
	cd /work/workspace/test/cpp/boost/study/asio-master/src/conn_pair && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pair.dir/pair.cc.o -c /work/workspace/test/cpp/boost/study/asio-master/src/conn_pair/pair.cc

conn_pair/CMakeFiles/pair.dir/pair.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pair.dir/pair.cc.i"
	cd /work/workspace/test/cpp/boost/study/asio-master/src/conn_pair && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /work/workspace/test/cpp/boost/study/asio-master/src/conn_pair/pair.cc > CMakeFiles/pair.dir/pair.cc.i

conn_pair/CMakeFiles/pair.dir/pair.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pair.dir/pair.cc.s"
	cd /work/workspace/test/cpp/boost/study/asio-master/src/conn_pair && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /work/workspace/test/cpp/boost/study/asio-master/src/conn_pair/pair.cc -o CMakeFiles/pair.dir/pair.cc.s

conn_pair/CMakeFiles/pair.dir/pair.cc.o.requires:
.PHONY : conn_pair/CMakeFiles/pair.dir/pair.cc.o.requires

conn_pair/CMakeFiles/pair.dir/pair.cc.o.provides: conn_pair/CMakeFiles/pair.dir/pair.cc.o.requires
	$(MAKE) -f conn_pair/CMakeFiles/pair.dir/build.make conn_pair/CMakeFiles/pair.dir/pair.cc.o.provides.build
.PHONY : conn_pair/CMakeFiles/pair.dir/pair.cc.o.provides

conn_pair/CMakeFiles/pair.dir/pair.cc.o.provides.build: conn_pair/CMakeFiles/pair.dir/pair.cc.o

# Object files for target pair
pair_OBJECTS = \
"CMakeFiles/pair.dir/pair.cc.o"

# External object files for target pair
pair_EXTERNAL_OBJECTS =

conn_pair/pair: conn_pair/CMakeFiles/pair.dir/pair.cc.o
conn_pair/pair: conn_pair/CMakeFiles/pair.dir/build.make
conn_pair/pair: /usr/lib64/libboost_thread-mt.so
conn_pair/pair: /usr/lib64/libboost_system-mt.so
conn_pair/pair: /usr/lib64/libboost_chrono-mt.so
conn_pair/pair: conn_pair/CMakeFiles/pair.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable pair"
	cd /work/workspace/test/cpp/boost/study/asio-master/src/conn_pair && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pair.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
conn_pair/CMakeFiles/pair.dir/build: conn_pair/pair
.PHONY : conn_pair/CMakeFiles/pair.dir/build

conn_pair/CMakeFiles/pair.dir/requires: conn_pair/CMakeFiles/pair.dir/pair.cc.o.requires
.PHONY : conn_pair/CMakeFiles/pair.dir/requires

conn_pair/CMakeFiles/pair.dir/clean:
	cd /work/workspace/test/cpp/boost/study/asio-master/src/conn_pair && $(CMAKE_COMMAND) -P CMakeFiles/pair.dir/cmake_clean.cmake
.PHONY : conn_pair/CMakeFiles/pair.dir/clean

conn_pair/CMakeFiles/pair.dir/depend:
	cd /work/workspace/test/cpp/boost/study/asio-master/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /work/workspace/test/cpp/boost/study/asio-master/src /work/workspace/test/cpp/boost/study/asio-master/src/conn_pair /work/workspace/test/cpp/boost/study/asio-master/src /work/workspace/test/cpp/boost/study/asio-master/src/conn_pair /work/workspace/test/cpp/boost/study/asio-master/src/conn_pair/CMakeFiles/pair.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : conn_pair/CMakeFiles/pair.dir/depend

