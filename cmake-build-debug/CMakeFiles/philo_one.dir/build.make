# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/schips/Desktop/git_philo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/schips/Desktop/git_philo/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/philo_one.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/philo_one.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/philo_one.dir/flags.make

CMakeFiles/philo_one.dir/philo_one/main.c.o: CMakeFiles/philo_one.dir/flags.make
CMakeFiles/philo_one.dir/philo_one/main.c.o: ../philo_one/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/schips/Desktop/git_philo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/philo_one.dir/philo_one/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one.dir/philo_one/main.c.o   -c /Users/schips/Desktop/git_philo/philo_one/main.c

CMakeFiles/philo_one.dir/philo_one/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one.dir/philo_one/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/schips/Desktop/git_philo/philo_one/main.c > CMakeFiles/philo_one.dir/philo_one/main.c.i

CMakeFiles/philo_one.dir/philo_one/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one.dir/philo_one/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/schips/Desktop/git_philo/philo_one/main.c -o CMakeFiles/philo_one.dir/philo_one/main.c.s

CMakeFiles/philo_one.dir/philo_one/philo_print.c.o: CMakeFiles/philo_one.dir/flags.make
CMakeFiles/philo_one.dir/philo_one/philo_print.c.o: ../philo_one/philo_print.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/schips/Desktop/git_philo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/philo_one.dir/philo_one/philo_print.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one.dir/philo_one/philo_print.c.o   -c /Users/schips/Desktop/git_philo/philo_one/philo_print.c

CMakeFiles/philo_one.dir/philo_one/philo_print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one.dir/philo_one/philo_print.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/schips/Desktop/git_philo/philo_one/philo_print.c > CMakeFiles/philo_one.dir/philo_one/philo_print.c.i

CMakeFiles/philo_one.dir/philo_one/philo_print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one.dir/philo_one/philo_print.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/schips/Desktop/git_philo/philo_one/philo_print.c -o CMakeFiles/philo_one.dir/philo_one/philo_print.c.s

CMakeFiles/philo_one.dir/philo_one/philo_init.c.o: CMakeFiles/philo_one.dir/flags.make
CMakeFiles/philo_one.dir/philo_one/philo_init.c.o: ../philo_one/philo_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/schips/Desktop/git_philo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/philo_one.dir/philo_one/philo_init.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one.dir/philo_one/philo_init.c.o   -c /Users/schips/Desktop/git_philo/philo_one/philo_init.c

CMakeFiles/philo_one.dir/philo_one/philo_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one.dir/philo_one/philo_init.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/schips/Desktop/git_philo/philo_one/philo_init.c > CMakeFiles/philo_one.dir/philo_one/philo_init.c.i

CMakeFiles/philo_one.dir/philo_one/philo_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one.dir/philo_one/philo_init.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/schips/Desktop/git_philo/philo_one/philo_init.c -o CMakeFiles/philo_one.dir/philo_one/philo_init.c.s

CMakeFiles/philo_one.dir/philo_one/ft_atoi.c.o: CMakeFiles/philo_one.dir/flags.make
CMakeFiles/philo_one.dir/philo_one/ft_atoi.c.o: ../philo_one/ft_atoi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/schips/Desktop/git_philo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/philo_one.dir/philo_one/ft_atoi.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one.dir/philo_one/ft_atoi.c.o   -c /Users/schips/Desktop/git_philo/philo_one/ft_atoi.c

CMakeFiles/philo_one.dir/philo_one/ft_atoi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one.dir/philo_one/ft_atoi.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/schips/Desktop/git_philo/philo_one/ft_atoi.c > CMakeFiles/philo_one.dir/philo_one/ft_atoi.c.i

CMakeFiles/philo_one.dir/philo_one/ft_atoi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one.dir/philo_one/ft_atoi.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/schips/Desktop/git_philo/philo_one/ft_atoi.c -o CMakeFiles/philo_one.dir/philo_one/ft_atoi.c.s

CMakeFiles/philo_one.dir/philo_one/ft_itoa.c.o: CMakeFiles/philo_one.dir/flags.make
CMakeFiles/philo_one.dir/philo_one/ft_itoa.c.o: ../philo_one/ft_itoa.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/schips/Desktop/git_philo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/philo_one.dir/philo_one/ft_itoa.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one.dir/philo_one/ft_itoa.c.o   -c /Users/schips/Desktop/git_philo/philo_one/ft_itoa.c

CMakeFiles/philo_one.dir/philo_one/ft_itoa.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one.dir/philo_one/ft_itoa.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/schips/Desktop/git_philo/philo_one/ft_itoa.c > CMakeFiles/philo_one.dir/philo_one/ft_itoa.c.i

CMakeFiles/philo_one.dir/philo_one/ft_itoa.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one.dir/philo_one/ft_itoa.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/schips/Desktop/git_philo/philo_one/ft_itoa.c -o CMakeFiles/philo_one.dir/philo_one/ft_itoa.c.s

CMakeFiles/philo_one.dir/philo_one/philo_time.c.o: CMakeFiles/philo_one.dir/flags.make
CMakeFiles/philo_one.dir/philo_one/philo_time.c.o: ../philo_one/philo_time.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/schips/Desktop/git_philo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/philo_one.dir/philo_one/philo_time.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one.dir/philo_one/philo_time.c.o   -c /Users/schips/Desktop/git_philo/philo_one/philo_time.c

CMakeFiles/philo_one.dir/philo_one/philo_time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one.dir/philo_one/philo_time.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/schips/Desktop/git_philo/philo_one/philo_time.c > CMakeFiles/philo_one.dir/philo_one/philo_time.c.i

CMakeFiles/philo_one.dir/philo_one/philo_time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one.dir/philo_one/philo_time.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/schips/Desktop/git_philo/philo_one/philo_time.c -o CMakeFiles/philo_one.dir/philo_one/philo_time.c.s

CMakeFiles/philo_one.dir/philo_one/philo_life_circle.c.o: CMakeFiles/philo_one.dir/flags.make
CMakeFiles/philo_one.dir/philo_one/philo_life_circle.c.o: ../philo_one/philo_life_circle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/schips/Desktop/git_philo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/philo_one.dir/philo_one/philo_life_circle.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_one.dir/philo_one/philo_life_circle.c.o   -c /Users/schips/Desktop/git_philo/philo_one/philo_life_circle.c

CMakeFiles/philo_one.dir/philo_one/philo_life_circle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_one.dir/philo_one/philo_life_circle.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/schips/Desktop/git_philo/philo_one/philo_life_circle.c > CMakeFiles/philo_one.dir/philo_one/philo_life_circle.c.i

CMakeFiles/philo_one.dir/philo_one/philo_life_circle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_one.dir/philo_one/philo_life_circle.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/schips/Desktop/git_philo/philo_one/philo_life_circle.c -o CMakeFiles/philo_one.dir/philo_one/philo_life_circle.c.s

# Object files for target philo_one
philo_one_OBJECTS = \
"CMakeFiles/philo_one.dir/philo_one/main.c.o" \
"CMakeFiles/philo_one.dir/philo_one/philo_print.c.o" \
"CMakeFiles/philo_one.dir/philo_one/philo_init.c.o" \
"CMakeFiles/philo_one.dir/philo_one/ft_atoi.c.o" \
"CMakeFiles/philo_one.dir/philo_one/ft_itoa.c.o" \
"CMakeFiles/philo_one.dir/philo_one/philo_time.c.o" \
"CMakeFiles/philo_one.dir/philo_one/philo_life_circle.c.o"

# External object files for target philo_one
philo_one_EXTERNAL_OBJECTS =

philo_one: CMakeFiles/philo_one.dir/philo_one/main.c.o
philo_one: CMakeFiles/philo_one.dir/philo_one/philo_print.c.o
philo_one: CMakeFiles/philo_one.dir/philo_one/philo_init.c.o
philo_one: CMakeFiles/philo_one.dir/philo_one/ft_atoi.c.o
philo_one: CMakeFiles/philo_one.dir/philo_one/ft_itoa.c.o
philo_one: CMakeFiles/philo_one.dir/philo_one/philo_time.c.o
philo_one: CMakeFiles/philo_one.dir/philo_one/philo_life_circle.c.o
philo_one: CMakeFiles/philo_one.dir/build.make
philo_one: CMakeFiles/philo_one.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/schips/Desktop/git_philo/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable philo_one"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/philo_one.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/philo_one.dir/build: philo_one

.PHONY : CMakeFiles/philo_one.dir/build

CMakeFiles/philo_one.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/philo_one.dir/cmake_clean.cmake
.PHONY : CMakeFiles/philo_one.dir/clean

CMakeFiles/philo_one.dir/depend:
	cd /Users/schips/Desktop/git_philo/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/schips/Desktop/git_philo /Users/schips/Desktop/git_philo /Users/schips/Desktop/git_philo/cmake-build-debug /Users/schips/Desktop/git_philo/cmake-build-debug /Users/schips/Desktop/git_philo/cmake-build-debug/CMakeFiles/philo_one.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/philo_one.dir/depend
