# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /tmp/tmp.BeA75e79jF

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.BeA75e79jF/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/semkaServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/semkaServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/semkaServer.dir/flags.make

CMakeFiles/semkaServer.dir/main.c.o: CMakeFiles/semkaServer.dir/flags.make
CMakeFiles/semkaServer.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.BeA75e79jF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/semkaServer.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/semkaServer.dir/main.c.o -c /tmp/tmp.BeA75e79jF/main.c

CMakeFiles/semkaServer.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/semkaServer.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.BeA75e79jF/main.c > CMakeFiles/semkaServer.dir/main.c.i

CMakeFiles/semkaServer.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/semkaServer.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.BeA75e79jF/main.c -o CMakeFiles/semkaServer.dir/main.c.s

CMakeFiles/semkaServer.dir/pos_sockets/passive_socket.c.o: CMakeFiles/semkaServer.dir/flags.make
CMakeFiles/semkaServer.dir/pos_sockets/passive_socket.c.o: ../pos_sockets/passive_socket.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.BeA75e79jF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/semkaServer.dir/pos_sockets/passive_socket.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/semkaServer.dir/pos_sockets/passive_socket.c.o -c /tmp/tmp.BeA75e79jF/pos_sockets/passive_socket.c

CMakeFiles/semkaServer.dir/pos_sockets/passive_socket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/semkaServer.dir/pos_sockets/passive_socket.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.BeA75e79jF/pos_sockets/passive_socket.c > CMakeFiles/semkaServer.dir/pos_sockets/passive_socket.c.i

CMakeFiles/semkaServer.dir/pos_sockets/passive_socket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/semkaServer.dir/pos_sockets/passive_socket.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.BeA75e79jF/pos_sockets/passive_socket.c -o CMakeFiles/semkaServer.dir/pos_sockets/passive_socket.c.s

CMakeFiles/semkaServer.dir/pos_sockets/char_buffer.c.o: CMakeFiles/semkaServer.dir/flags.make
CMakeFiles/semkaServer.dir/pos_sockets/char_buffer.c.o: ../pos_sockets/char_buffer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.BeA75e79jF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/semkaServer.dir/pos_sockets/char_buffer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/semkaServer.dir/pos_sockets/char_buffer.c.o -c /tmp/tmp.BeA75e79jF/pos_sockets/char_buffer.c

CMakeFiles/semkaServer.dir/pos_sockets/char_buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/semkaServer.dir/pos_sockets/char_buffer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.BeA75e79jF/pos_sockets/char_buffer.c > CMakeFiles/semkaServer.dir/pos_sockets/char_buffer.c.i

CMakeFiles/semkaServer.dir/pos_sockets/char_buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/semkaServer.dir/pos_sockets/char_buffer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.BeA75e79jF/pos_sockets/char_buffer.c -o CMakeFiles/semkaServer.dir/pos_sockets/char_buffer.c.s

CMakeFiles/semkaServer.dir/pos_sockets/active_socket.c.o: CMakeFiles/semkaServer.dir/flags.make
CMakeFiles/semkaServer.dir/pos_sockets/active_socket.c.o: ../pos_sockets/active_socket.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.BeA75e79jF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/semkaServer.dir/pos_sockets/active_socket.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/semkaServer.dir/pos_sockets/active_socket.c.o -c /tmp/tmp.BeA75e79jF/pos_sockets/active_socket.c

CMakeFiles/semkaServer.dir/pos_sockets/active_socket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/semkaServer.dir/pos_sockets/active_socket.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/tmp.BeA75e79jF/pos_sockets/active_socket.c > CMakeFiles/semkaServer.dir/pos_sockets/active_socket.c.i

CMakeFiles/semkaServer.dir/pos_sockets/active_socket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/semkaServer.dir/pos_sockets/active_socket.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/tmp.BeA75e79jF/pos_sockets/active_socket.c -o CMakeFiles/semkaServer.dir/pos_sockets/active_socket.c.s

# Object files for target semkaServer
semkaServer_OBJECTS = \
"CMakeFiles/semkaServer.dir/main.c.o" \
"CMakeFiles/semkaServer.dir/pos_sockets/passive_socket.c.o" \
"CMakeFiles/semkaServer.dir/pos_sockets/char_buffer.c.o" \
"CMakeFiles/semkaServer.dir/pos_sockets/active_socket.c.o"

# External object files for target semkaServer
semkaServer_EXTERNAL_OBJECTS =

semkaServer: CMakeFiles/semkaServer.dir/main.c.o
semkaServer: CMakeFiles/semkaServer.dir/pos_sockets/passive_socket.c.o
semkaServer: CMakeFiles/semkaServer.dir/pos_sockets/char_buffer.c.o
semkaServer: CMakeFiles/semkaServer.dir/pos_sockets/active_socket.c.o
semkaServer: CMakeFiles/semkaServer.dir/build.make
semkaServer: CMakeFiles/semkaServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.BeA75e79jF/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable semkaServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/semkaServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/semkaServer.dir/build: semkaServer

.PHONY : CMakeFiles/semkaServer.dir/build

CMakeFiles/semkaServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/semkaServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/semkaServer.dir/clean

CMakeFiles/semkaServer.dir/depend:
	cd /tmp/tmp.BeA75e79jF/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.BeA75e79jF /tmp/tmp.BeA75e79jF /tmp/tmp.BeA75e79jF/cmake-build-debug /tmp/tmp.BeA75e79jF/cmake-build-debug /tmp/tmp.BeA75e79jF/cmake-build-debug/CMakeFiles/semkaServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/semkaServer.dir/depend

