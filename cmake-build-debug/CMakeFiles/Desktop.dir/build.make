# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\softwere\Clion\CLion 2023.3.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\softwere\Clion\CLion 2023.3.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Desktop.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Desktop.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Desktop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Desktop.dir/flags.make

CMakeFiles/Desktop.dir/main.c.obj: CMakeFiles/Desktop.dir/flags.make
CMakeFiles/Desktop.dir/main.c.obj: D:/softwere/One\ Drive/OneDrive\ -\ Afeka\ College\ Of\ Engineering/C\ projects/IOS_exe2/main.c
CMakeFiles/Desktop.dir/main.c.obj: CMakeFiles/Desktop.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Desktop.dir/main.c.obj"
	"D:\softwere\Clion\CLion 2023.3.3\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Desktop.dir/main.c.obj -MF CMakeFiles\Desktop.dir\main.c.obj.d -o CMakeFiles\Desktop.dir\main.c.obj -c "D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2\main.c"

CMakeFiles/Desktop.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Desktop.dir/main.c.i"
	"D:\softwere\Clion\CLion 2023.3.3\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2\main.c" > CMakeFiles\Desktop.dir\main.c.i

CMakeFiles/Desktop.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Desktop.dir/main.c.s"
	"D:\softwere\Clion\CLion 2023.3.3\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2\main.c" -o CMakeFiles\Desktop.dir\main.c.s

CMakeFiles/Desktop.dir/flight.c.obj: CMakeFiles/Desktop.dir/flags.make
CMakeFiles/Desktop.dir/flight.c.obj: D:/softwere/One\ Drive/OneDrive\ -\ Afeka\ College\ Of\ Engineering/C\ projects/IOS_exe2/flight.c
CMakeFiles/Desktop.dir/flight.c.obj: CMakeFiles/Desktop.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Desktop.dir/flight.c.obj"
	"D:\softwere\Clion\CLion 2023.3.3\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Desktop.dir/flight.c.obj -MF CMakeFiles\Desktop.dir\flight.c.obj.d -o CMakeFiles\Desktop.dir\flight.c.obj -c "D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2\flight.c"

CMakeFiles/Desktop.dir/flight.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Desktop.dir/flight.c.i"
	"D:\softwere\Clion\CLion 2023.3.3\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2\flight.c" > CMakeFiles\Desktop.dir\flight.c.i

CMakeFiles/Desktop.dir/flight.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Desktop.dir/flight.c.s"
	"D:\softwere\Clion\CLion 2023.3.3\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2\flight.c" -o CMakeFiles\Desktop.dir\flight.c.s

# Object files for target Desktop
Desktop_OBJECTS = \
"CMakeFiles/Desktop.dir/main.c.obj" \
"CMakeFiles/Desktop.dir/flight.c.obj"

# External object files for target Desktop
Desktop_EXTERNAL_OBJECTS =

Desktop.exe: CMakeFiles/Desktop.dir/main.c.obj
Desktop.exe: CMakeFiles/Desktop.dir/flight.c.obj
Desktop.exe: CMakeFiles/Desktop.dir/build.make
Desktop.exe: CMakeFiles/Desktop.dir/linkLibs.rsp
Desktop.exe: CMakeFiles/Desktop.dir/objects1.rsp
Desktop.exe: CMakeFiles/Desktop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable Desktop.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Desktop.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Desktop.dir/build: Desktop.exe
.PHONY : CMakeFiles/Desktop.dir/build

CMakeFiles/Desktop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Desktop.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Desktop.dir/clean

CMakeFiles/Desktop.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2" "D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2" "D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2\cmake-build-debug" "D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2\cmake-build-debug" "D:\softwere\One Drive\OneDrive - Afeka College Of Engineering\C projects\IOS_exe2\cmake-build-debug\CMakeFiles\Desktop.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Desktop.dir/depend

