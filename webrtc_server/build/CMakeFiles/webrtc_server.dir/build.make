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
CMAKE_SOURCE_DIR = /home/abhinav/video_audio_encoding/webrtc_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abhinav/video_audio_encoding/webrtc_server/build

# Include any dependencies generated for this target.
include CMakeFiles/webrtc_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/webrtc_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/webrtc_server.dir/flags.make

CMakeFiles/webrtc_server.dir/main.cpp.o: CMakeFiles/webrtc_server.dir/flags.make
CMakeFiles/webrtc_server.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abhinav/video_audio_encoding/webrtc_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/webrtc_server.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webrtc_server.dir/main.cpp.o -c /home/abhinav/video_audio_encoding/webrtc_server/main.cpp

CMakeFiles/webrtc_server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webrtc_server.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abhinav/video_audio_encoding/webrtc_server/main.cpp > CMakeFiles/webrtc_server.dir/main.cpp.i

CMakeFiles/webrtc_server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webrtc_server.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abhinav/video_audio_encoding/webrtc_server/main.cpp -o CMakeFiles/webrtc_server.dir/main.cpp.s

CMakeFiles/webrtc_server.dir/utility/websocket_server.cpp.o: CMakeFiles/webrtc_server.dir/flags.make
CMakeFiles/webrtc_server.dir/utility/websocket_server.cpp.o: ../utility/websocket_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/abhinav/video_audio_encoding/webrtc_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/webrtc_server.dir/utility/websocket_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webrtc_server.dir/utility/websocket_server.cpp.o -c /home/abhinav/video_audio_encoding/webrtc_server/utility/websocket_server.cpp

CMakeFiles/webrtc_server.dir/utility/websocket_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webrtc_server.dir/utility/websocket_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/abhinav/video_audio_encoding/webrtc_server/utility/websocket_server.cpp > CMakeFiles/webrtc_server.dir/utility/websocket_server.cpp.i

CMakeFiles/webrtc_server.dir/utility/websocket_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webrtc_server.dir/utility/websocket_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/abhinav/video_audio_encoding/webrtc_server/utility/websocket_server.cpp -o CMakeFiles/webrtc_server.dir/utility/websocket_server.cpp.s

# Object files for target webrtc_server
webrtc_server_OBJECTS = \
"CMakeFiles/webrtc_server.dir/main.cpp.o" \
"CMakeFiles/webrtc_server.dir/utility/websocket_server.cpp.o"

# External object files for target webrtc_server
webrtc_server_EXTERNAL_OBJECTS =

webrtc_server: CMakeFiles/webrtc_server.dir/main.cpp.o
webrtc_server: CMakeFiles/webrtc_server.dir/utility/websocket_server.cpp.o
webrtc_server: CMakeFiles/webrtc_server.dir/build.make
webrtc_server: CMakeFiles/webrtc_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/abhinav/video_audio_encoding/webrtc_server/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable webrtc_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/webrtc_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/webrtc_server.dir/build: webrtc_server

.PHONY : CMakeFiles/webrtc_server.dir/build

CMakeFiles/webrtc_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/webrtc_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/webrtc_server.dir/clean

CMakeFiles/webrtc_server.dir/depend:
	cd /home/abhinav/video_audio_encoding/webrtc_server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abhinav/video_audio_encoding/webrtc_server /home/abhinav/video_audio_encoding/webrtc_server /home/abhinav/video_audio_encoding/webrtc_server/build /home/abhinav/video_audio_encoding/webrtc_server/build /home/abhinav/video_audio_encoding/webrtc_server/build/CMakeFiles/webrtc_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/webrtc_server.dir/depend
