# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = E:\vs2022\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe

# The command to remove a file.
RM = E:\vs2022\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\Electro\Computer\VirtualMachine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\Electro\Computer\build

# Include any dependencies generated for this target.
include CMakeFiles/VM.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/VM.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/VM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VM.dir/flags.make

CMakeFiles/VM.dir/src/pugixml/pugixml.cpp.obj: CMakeFiles/VM.dir/flags.make
CMakeFiles/VM.dir/src/pugixml/pugixml.cpp.obj: CMakeFiles/VM.dir/includes_CXX.rsp
CMakeFiles/VM.dir/src/pugixml/pugixml.cpp.obj: E:/Electro/Computer/VirtualMachine/src/pugixml/pugixml.cpp
CMakeFiles/VM.dir/src/pugixml/pugixml.cpp.obj: CMakeFiles/VM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Electro\Computer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VM.dir/src/pugixml/pugixml.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VM.dir/src/pugixml/pugixml.cpp.obj -MF CMakeFiles\VM.dir\src\pugixml\pugixml.cpp.obj.d -o CMakeFiles\VM.dir\src\pugixml\pugixml.cpp.obj -c E:\Electro\Computer\VirtualMachine\src\pugixml\pugixml.cpp

CMakeFiles/VM.dir/src/pugixml/pugixml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VM.dir/src/pugixml/pugixml.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Electro\Computer\VirtualMachine\src\pugixml\pugixml.cpp > CMakeFiles\VM.dir\src\pugixml\pugixml.cpp.i

CMakeFiles/VM.dir/src/pugixml/pugixml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VM.dir/src/pugixml/pugixml.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Electro\Computer\VirtualMachine\src\pugixml\pugixml.cpp -o CMakeFiles\VM.dir\src\pugixml\pugixml.cpp.s

CMakeFiles/VM.dir/src/Memory.cpp.obj: CMakeFiles/VM.dir/flags.make
CMakeFiles/VM.dir/src/Memory.cpp.obj: CMakeFiles/VM.dir/includes_CXX.rsp
CMakeFiles/VM.dir/src/Memory.cpp.obj: E:/Electro/Computer/VirtualMachine/src/Memory.cpp
CMakeFiles/VM.dir/src/Memory.cpp.obj: CMakeFiles/VM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Electro\Computer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/VM.dir/src/Memory.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VM.dir/src/Memory.cpp.obj -MF CMakeFiles\VM.dir\src\Memory.cpp.obj.d -o CMakeFiles\VM.dir\src\Memory.cpp.obj -c E:\Electro\Computer\VirtualMachine\src\Memory.cpp

CMakeFiles/VM.dir/src/Memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VM.dir/src/Memory.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Electro\Computer\VirtualMachine\src\Memory.cpp > CMakeFiles\VM.dir\src\Memory.cpp.i

CMakeFiles/VM.dir/src/Memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VM.dir/src/Memory.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Electro\Computer\VirtualMachine\src\Memory.cpp -o CMakeFiles\VM.dir\src\Memory.cpp.s

CMakeFiles/VM.dir/src/CPU.cpp.obj: CMakeFiles/VM.dir/flags.make
CMakeFiles/VM.dir/src/CPU.cpp.obj: CMakeFiles/VM.dir/includes_CXX.rsp
CMakeFiles/VM.dir/src/CPU.cpp.obj: E:/Electro/Computer/VirtualMachine/src/CPU.cpp
CMakeFiles/VM.dir/src/CPU.cpp.obj: CMakeFiles/VM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Electro\Computer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/VM.dir/src/CPU.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VM.dir/src/CPU.cpp.obj -MF CMakeFiles\VM.dir\src\CPU.cpp.obj.d -o CMakeFiles\VM.dir\src\CPU.cpp.obj -c E:\Electro\Computer\VirtualMachine\src\CPU.cpp

CMakeFiles/VM.dir/src/CPU.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VM.dir/src/CPU.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Electro\Computer\VirtualMachine\src\CPU.cpp > CMakeFiles\VM.dir\src\CPU.cpp.i

CMakeFiles/VM.dir/src/CPU.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VM.dir/src/CPU.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Electro\Computer\VirtualMachine\src\CPU.cpp -o CMakeFiles\VM.dir\src\CPU.cpp.s

CMakeFiles/VM.dir/src/VGA.cpp.obj: CMakeFiles/VM.dir/flags.make
CMakeFiles/VM.dir/src/VGA.cpp.obj: CMakeFiles/VM.dir/includes_CXX.rsp
CMakeFiles/VM.dir/src/VGA.cpp.obj: E:/Electro/Computer/VirtualMachine/src/VGA.cpp
CMakeFiles/VM.dir/src/VGA.cpp.obj: CMakeFiles/VM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Electro\Computer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/VM.dir/src/VGA.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VM.dir/src/VGA.cpp.obj -MF CMakeFiles\VM.dir\src\VGA.cpp.obj.d -o CMakeFiles\VM.dir\src\VGA.cpp.obj -c E:\Electro\Computer\VirtualMachine\src\VGA.cpp

CMakeFiles/VM.dir/src/VGA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VM.dir/src/VGA.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Electro\Computer\VirtualMachine\src\VGA.cpp > CMakeFiles\VM.dir\src\VGA.cpp.i

CMakeFiles/VM.dir/src/VGA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VM.dir/src/VGA.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Electro\Computer\VirtualMachine\src\VGA.cpp -o CMakeFiles\VM.dir\src\VGA.cpp.s

CMakeFiles/VM.dir/src/computer.cpp.obj: CMakeFiles/VM.dir/flags.make
CMakeFiles/VM.dir/src/computer.cpp.obj: CMakeFiles/VM.dir/includes_CXX.rsp
CMakeFiles/VM.dir/src/computer.cpp.obj: E:/Electro/Computer/VirtualMachine/src/computer.cpp
CMakeFiles/VM.dir/src/computer.cpp.obj: CMakeFiles/VM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Electro\Computer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/VM.dir/src/computer.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VM.dir/src/computer.cpp.obj -MF CMakeFiles\VM.dir\src\computer.cpp.obj.d -o CMakeFiles\VM.dir\src\computer.cpp.obj -c E:\Electro\Computer\VirtualMachine\src\computer.cpp

CMakeFiles/VM.dir/src/computer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VM.dir/src/computer.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Electro\Computer\VirtualMachine\src\computer.cpp > CMakeFiles\VM.dir\src\computer.cpp.i

CMakeFiles/VM.dir/src/computer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VM.dir/src/computer.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Electro\Computer\VirtualMachine\src\computer.cpp -o CMakeFiles\VM.dir\src\computer.cpp.s

CMakeFiles/VM.dir/src/main.cpp.obj: CMakeFiles/VM.dir/flags.make
CMakeFiles/VM.dir/src/main.cpp.obj: CMakeFiles/VM.dir/includes_CXX.rsp
CMakeFiles/VM.dir/src/main.cpp.obj: E:/Electro/Computer/VirtualMachine/src/main.cpp
CMakeFiles/VM.dir/src/main.cpp.obj: CMakeFiles/VM.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\Electro\Computer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/VM.dir/src/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/VM.dir/src/main.cpp.obj -MF CMakeFiles\VM.dir\src\main.cpp.obj.d -o CMakeFiles\VM.dir\src\main.cpp.obj -c E:\Electro\Computer\VirtualMachine\src\main.cpp

CMakeFiles/VM.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/VM.dir/src/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\Electro\Computer\VirtualMachine\src\main.cpp > CMakeFiles\VM.dir\src\main.cpp.i

CMakeFiles/VM.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/VM.dir/src/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\Electro\Computer\VirtualMachine\src\main.cpp -o CMakeFiles\VM.dir\src\main.cpp.s

# Object files for target VM
VM_OBJECTS = \
"CMakeFiles/VM.dir/src/pugixml/pugixml.cpp.obj" \
"CMakeFiles/VM.dir/src/Memory.cpp.obj" \
"CMakeFiles/VM.dir/src/CPU.cpp.obj" \
"CMakeFiles/VM.dir/src/VGA.cpp.obj" \
"CMakeFiles/VM.dir/src/computer.cpp.obj" \
"CMakeFiles/VM.dir/src/main.cpp.obj"

# External object files for target VM
VM_EXTERNAL_OBJECTS =

VM.exe: CMakeFiles/VM.dir/src/pugixml/pugixml.cpp.obj
VM.exe: CMakeFiles/VM.dir/src/Memory.cpp.obj
VM.exe: CMakeFiles/VM.dir/src/CPU.cpp.obj
VM.exe: CMakeFiles/VM.dir/src/VGA.cpp.obj
VM.exe: CMakeFiles/VM.dir/src/computer.cpp.obj
VM.exe: CMakeFiles/VM.dir/src/main.cpp.obj
VM.exe: CMakeFiles/VM.dir/build.make
VM.exe: CMakeFiles/VM.dir/linkLibs.rsp
VM.exe: CMakeFiles/VM.dir/objects1.rsp
VM.exe: CMakeFiles/VM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\Electro\Computer\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable VM.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\VM.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VM.dir/build: VM.exe
.PHONY : CMakeFiles/VM.dir/build

CMakeFiles/VM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\VM.dir\cmake_clean.cmake
.PHONY : CMakeFiles/VM.dir/clean

CMakeFiles/VM.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\Electro\Computer\VirtualMachine E:\Electro\Computer\VirtualMachine E:\Electro\Computer\build E:\Electro\Computer\build E:\Electro\Computer\build\CMakeFiles\VM.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/VM.dir/depend

