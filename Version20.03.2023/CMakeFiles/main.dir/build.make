# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = "/home/sergh/MAI/Architecture Program/DeliveryBotCode"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/sergh/MAI/Architecture Program/DeliveryBotCode"

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: main.cpp
CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sergh/MAI/Architecture Program/DeliveryBotCode/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c "/home/sergh/MAI/Architecture Program/DeliveryBotCode/main.cpp"

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sergh/MAI/Architecture Program/DeliveryBotCode/main.cpp" > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sergh/MAI/Architecture Program/DeliveryBotCode/main.cpp" -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/Camera.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Camera.cpp.o: Camera.cpp
CMakeFiles/main.dir/Camera.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sergh/MAI/Architecture Program/DeliveryBotCode/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/Camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/Camera.cpp.o -MF CMakeFiles/main.dir/Camera.cpp.o.d -o CMakeFiles/main.dir/Camera.cpp.o -c "/home/sergh/MAI/Architecture Program/DeliveryBotCode/Camera.cpp"

CMakeFiles/main.dir/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sergh/MAI/Architecture Program/DeliveryBotCode/Camera.cpp" > CMakeFiles/main.dir/Camera.cpp.i

CMakeFiles/main.dir/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sergh/MAI/Architecture Program/DeliveryBotCode/Camera.cpp" -o CMakeFiles/main.dir/Camera.cpp.s

CMakeFiles/main.dir/Robot.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Robot.cpp.o: Robot.cpp
CMakeFiles/main.dir/Robot.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sergh/MAI/Architecture Program/DeliveryBotCode/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/Robot.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/Robot.cpp.o -MF CMakeFiles/main.dir/Robot.cpp.o.d -o CMakeFiles/main.dir/Robot.cpp.o -c "/home/sergh/MAI/Architecture Program/DeliveryBotCode/Robot.cpp"

CMakeFiles/main.dir/Robot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Robot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sergh/MAI/Architecture Program/DeliveryBotCode/Robot.cpp" > CMakeFiles/main.dir/Robot.cpp.i

CMakeFiles/main.dir/Robot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Robot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sergh/MAI/Architecture Program/DeliveryBotCode/Robot.cpp" -o CMakeFiles/main.dir/Robot.cpp.s

CMakeFiles/main.dir/Robot_control.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Robot_control.cpp.o: Robot_control.cpp
CMakeFiles/main.dir/Robot_control.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sergh/MAI/Architecture Program/DeliveryBotCode/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/Robot_control.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/Robot_control.cpp.o -MF CMakeFiles/main.dir/Robot_control.cpp.o.d -o CMakeFiles/main.dir/Robot_control.cpp.o -c "/home/sergh/MAI/Architecture Program/DeliveryBotCode/Robot_control.cpp"

CMakeFiles/main.dir/Robot_control.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Robot_control.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sergh/MAI/Architecture Program/DeliveryBotCode/Robot_control.cpp" > CMakeFiles/main.dir/Robot_control.cpp.i

CMakeFiles/main.dir/Robot_control.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Robot_control.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sergh/MAI/Architecture Program/DeliveryBotCode/Robot_control.cpp" -o CMakeFiles/main.dir/Robot_control.cpp.s

CMakeFiles/main.dir/User.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/User.cpp.o: User.cpp
CMakeFiles/main.dir/User.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/sergh/MAI/Architecture Program/DeliveryBotCode/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/User.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/User.cpp.o -MF CMakeFiles/main.dir/User.cpp.o.d -o CMakeFiles/main.dir/User.cpp.o -c "/home/sergh/MAI/Architecture Program/DeliveryBotCode/User.cpp"

CMakeFiles/main.dir/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/User.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/sergh/MAI/Architecture Program/DeliveryBotCode/User.cpp" > CMakeFiles/main.dir/User.cpp.i

CMakeFiles/main.dir/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/User.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/sergh/MAI/Architecture Program/DeliveryBotCode/User.cpp" -o CMakeFiles/main.dir/User.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/Camera.cpp.o" \
"CMakeFiles/main.dir/Robot.cpp.o" \
"CMakeFiles/main.dir/Robot_control.cpp.o" \
"CMakeFiles/main.dir/User.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/Camera.cpp.o
main: CMakeFiles/main.dir/Robot.cpp.o
main: CMakeFiles/main.dir/Robot_control.cpp.o
main: CMakeFiles/main.dir/User.cpp.o
main: CMakeFiles/main.dir/build.make
main: /usr/local/lib/libopencv_gapi.so.4.7.0
main: /usr/local/lib/libopencv_highgui.so.4.7.0
main: /usr/local/lib/libopencv_ml.so.4.7.0
main: /usr/local/lib/libopencv_objdetect.so.4.7.0
main: /usr/local/lib/libopencv_photo.so.4.7.0
main: /usr/local/lib/libopencv_stitching.so.4.7.0
main: /usr/local/lib/libopencv_video.so.4.7.0
main: /usr/local/lib/libopencv_videoio.so.4.7.0
main: /usr/local/lib/libopencv_imgcodecs.so.4.7.0
main: /usr/local/lib/libopencv_dnn.so.4.7.0
main: /usr/local/lib/libopencv_calib3d.so.4.7.0
main: /usr/local/lib/libopencv_features2d.so.4.7.0
main: /usr/local/lib/libopencv_flann.so.4.7.0
main: /usr/local/lib/libopencv_imgproc.so.4.7.0
main: /usr/local/lib/libopencv_core.so.4.7.0
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/sergh/MAI/Architecture Program/DeliveryBotCode/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd "/home/sergh/MAI/Architecture Program/DeliveryBotCode" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/sergh/MAI/Architecture Program/DeliveryBotCode" "/home/sergh/MAI/Architecture Program/DeliveryBotCode" "/home/sergh/MAI/Architecture Program/DeliveryBotCode" "/home/sergh/MAI/Architecture Program/DeliveryBotCode" "/home/sergh/MAI/Architecture Program/DeliveryBotCode/CMakeFiles/main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend
