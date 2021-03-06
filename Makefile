# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/rfulop/workspace/laba-diena-tts

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rfulop/workspace/laba-diena-tts

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rfulop/workspace/laba-diena-tts/CMakeFiles /home/rfulop/workspace/laba-diena-tts/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/rfulop/workspace/laba-diena-tts/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named TextNormalization

# Build rule for target.
TextNormalization: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 TextNormalization
.PHONY : TextNormalization

# fast build rule for target.
TextNormalization/fast:
	$(MAKE) -f CMakeFiles/TextNormalization.dir/build.make CMakeFiles/TextNormalization.dir/build
.PHONY : TextNormalization/fast

#=============================================================================
# Target rules for targets named LithuanianTTS

# Build rule for target.
LithuanianTTS: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 LithuanianTTS
.PHONY : LithuanianTTS

# fast build rule for target.
LithuanianTTS/fast:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/build
.PHONY : LithuanianTTS/fast

#=============================================================================
# Target rules for targets named UnitSelection

# Build rule for target.
UnitSelection: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 UnitSelection
.PHONY : UnitSelection

# fast build rule for target.
UnitSelection/fast:
	$(MAKE) -f CMakeFiles/UnitSelection.dir/build.make CMakeFiles/UnitSelection.dir/build
.PHONY : UnitSelection/fast

#=============================================================================
# Target rules for targets named Transcription

# Build rule for target.
Transcription: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Transcription
.PHONY : Transcription

# fast build rule for target.
Transcription/fast:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/build
.PHONY : Transcription/fast

#=============================================================================
# Target rules for targets named RateChange

# Build rule for target.
RateChange: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 RateChange
.PHONY : RateChange

# fast build rule for target.
RateChange/fast:
	$(MAKE) -f CMakeFiles/RateChange.dir/build.make CMakeFiles/RateChange.dir/build
.PHONY : RateChange/fast

native-modules/LithuanianTTS/LithuanianTTS.o: native-modules/LithuanianTTS/LithuanianTTS.cpp.o

.PHONY : native-modules/LithuanianTTS/LithuanianTTS.o

# target to build an object file
native-modules/LithuanianTTS/LithuanianTTS.cpp.o:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/LithuanianTTS.cpp.o
.PHONY : native-modules/LithuanianTTS/LithuanianTTS.cpp.o

native-modules/LithuanianTTS/LithuanianTTS.i: native-modules/LithuanianTTS/LithuanianTTS.cpp.i

.PHONY : native-modules/LithuanianTTS/LithuanianTTS.i

# target to preprocess a source file
native-modules/LithuanianTTS/LithuanianTTS.cpp.i:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/LithuanianTTS.cpp.i
.PHONY : native-modules/LithuanianTTS/LithuanianTTS.cpp.i

native-modules/LithuanianTTS/LithuanianTTS.s: native-modules/LithuanianTTS/LithuanianTTS.cpp.s

.PHONY : native-modules/LithuanianTTS/LithuanianTTS.s

# target to generate assembly for a file
native-modules/LithuanianTTS/LithuanianTTS.cpp.s:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/LithuanianTTS.cpp.s
.PHONY : native-modules/LithuanianTTS/LithuanianTTS.cpp.s

native-modules/LithuanianTTS/fv2id.o: native-modules/LithuanianTTS/fv2id.cpp.o

.PHONY : native-modules/LithuanianTTS/fv2id.o

# target to build an object file
native-modules/LithuanianTTS/fv2id.cpp.o:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/fv2id.cpp.o
.PHONY : native-modules/LithuanianTTS/fv2id.cpp.o

native-modules/LithuanianTTS/fv2id.i: native-modules/LithuanianTTS/fv2id.cpp.i

.PHONY : native-modules/LithuanianTTS/fv2id.i

# target to preprocess a source file
native-modules/LithuanianTTS/fv2id.cpp.i:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/fv2id.cpp.i
.PHONY : native-modules/LithuanianTTS/fv2id.cpp.i

native-modules/LithuanianTTS/fv2id.s: native-modules/LithuanianTTS/fv2id.cpp.s

.PHONY : native-modules/LithuanianTTS/fv2id.s

# target to generate assembly for a file
native-modules/LithuanianTTS/fv2id.cpp.s:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/fv2id.cpp.s
.PHONY : native-modules/LithuanianTTS/fv2id.cpp.s

native-modules/LithuanianTTS/getLUSSErrorMessages.o: native-modules/LithuanianTTS/getLUSSErrorMessages.cpp.o

.PHONY : native-modules/LithuanianTTS/getLUSSErrorMessages.o

# target to build an object file
native-modules/LithuanianTTS/getLUSSErrorMessages.cpp.o:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/getLUSSErrorMessages.cpp.o
.PHONY : native-modules/LithuanianTTS/getLUSSErrorMessages.cpp.o

native-modules/LithuanianTTS/getLUSSErrorMessages.i: native-modules/LithuanianTTS/getLUSSErrorMessages.cpp.i

.PHONY : native-modules/LithuanianTTS/getLUSSErrorMessages.i

# target to preprocess a source file
native-modules/LithuanianTTS/getLUSSErrorMessages.cpp.i:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/getLUSSErrorMessages.cpp.i
.PHONY : native-modules/LithuanianTTS/getLUSSErrorMessages.cpp.i

native-modules/LithuanianTTS/getLUSSErrorMessages.s: native-modules/LithuanianTTS/getLUSSErrorMessages.cpp.s

.PHONY : native-modules/LithuanianTTS/getLUSSErrorMessages.s

# target to generate assembly for a file
native-modules/LithuanianTTS/getLUSSErrorMessages.cpp.s:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/getLUSSErrorMessages.cpp.s
.PHONY : native-modules/LithuanianTTS/getLUSSErrorMessages.cpp.s

native-modules/LithuanianTTS/ilgiai.o: native-modules/LithuanianTTS/ilgiai.cpp.o

.PHONY : native-modules/LithuanianTTS/ilgiai.o

# target to build an object file
native-modules/LithuanianTTS/ilgiai.cpp.o:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/ilgiai.cpp.o
.PHONY : native-modules/LithuanianTTS/ilgiai.cpp.o

native-modules/LithuanianTTS/ilgiai.i: native-modules/LithuanianTTS/ilgiai.cpp.i

.PHONY : native-modules/LithuanianTTS/ilgiai.i

# target to preprocess a source file
native-modules/LithuanianTTS/ilgiai.cpp.i:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/ilgiai.cpp.i
.PHONY : native-modules/LithuanianTTS/ilgiai.cpp.i

native-modules/LithuanianTTS/ilgiai.s: native-modules/LithuanianTTS/ilgiai.cpp.s

.PHONY : native-modules/LithuanianTTS/ilgiai.s

# target to generate assembly for a file
native-modules/LithuanianTTS/ilgiai.cpp.s:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/ilgiai.cpp.s
.PHONY : native-modules/LithuanianTTS/ilgiai.cpp.s

native-modules/LithuanianTTS/raw2wav.o: native-modules/LithuanianTTS/raw2wav.cpp.o

.PHONY : native-modules/LithuanianTTS/raw2wav.o

# target to build an object file
native-modules/LithuanianTTS/raw2wav.cpp.o:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/raw2wav.cpp.o
.PHONY : native-modules/LithuanianTTS/raw2wav.cpp.o

native-modules/LithuanianTTS/raw2wav.i: native-modules/LithuanianTTS/raw2wav.cpp.i

.PHONY : native-modules/LithuanianTTS/raw2wav.i

# target to preprocess a source file
native-modules/LithuanianTTS/raw2wav.cpp.i:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/raw2wav.cpp.i
.PHONY : native-modules/LithuanianTTS/raw2wav.cpp.i

native-modules/LithuanianTTS/raw2wav.s: native-modules/LithuanianTTS/raw2wav.cpp.s

.PHONY : native-modules/LithuanianTTS/raw2wav.s

# target to generate assembly for a file
native-modules/LithuanianTTS/raw2wav.cpp.s:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/raw2wav.cpp.s
.PHONY : native-modules/LithuanianTTS/raw2wav.cpp.s

native-modules/LithuanianTTS/strtokf.o: native-modules/LithuanianTTS/strtokf.cpp.o

.PHONY : native-modules/LithuanianTTS/strtokf.o

# target to build an object file
native-modules/LithuanianTTS/strtokf.cpp.o:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/strtokf.cpp.o
.PHONY : native-modules/LithuanianTTS/strtokf.cpp.o

native-modules/LithuanianTTS/strtokf.i: native-modules/LithuanianTTS/strtokf.cpp.i

.PHONY : native-modules/LithuanianTTS/strtokf.i

# target to preprocess a source file
native-modules/LithuanianTTS/strtokf.cpp.i:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/strtokf.cpp.i
.PHONY : native-modules/LithuanianTTS/strtokf.cpp.i

native-modules/LithuanianTTS/strtokf.s: native-modules/LithuanianTTS/strtokf.cpp.s

.PHONY : native-modules/LithuanianTTS/strtokf.s

# target to generate assembly for a file
native-modules/LithuanianTTS/strtokf.cpp.s:
	$(MAKE) -f CMakeFiles/LithuanianTTS.dir/build.make CMakeFiles/LithuanianTTS.dir/native-modules/LithuanianTTS/strtokf.cpp.s
.PHONY : native-modules/LithuanianTTS/strtokf.cpp.s

native-modules/RateChange/Euristika.o: native-modules/RateChange/Euristika.cpp.o

.PHONY : native-modules/RateChange/Euristika.o

# target to build an object file
native-modules/RateChange/Euristika.cpp.o:
	$(MAKE) -f CMakeFiles/RateChange.dir/build.make CMakeFiles/RateChange.dir/native-modules/RateChange/Euristika.cpp.o
.PHONY : native-modules/RateChange/Euristika.cpp.o

native-modules/RateChange/Euristika.i: native-modules/RateChange/Euristika.cpp.i

.PHONY : native-modules/RateChange/Euristika.i

# target to preprocess a source file
native-modules/RateChange/Euristika.cpp.i:
	$(MAKE) -f CMakeFiles/RateChange.dir/build.make CMakeFiles/RateChange.dir/native-modules/RateChange/Euristika.cpp.i
.PHONY : native-modules/RateChange/Euristika.cpp.i

native-modules/RateChange/Euristika.s: native-modules/RateChange/Euristika.cpp.s

.PHONY : native-modules/RateChange/Euristika.s

# target to generate assembly for a file
native-modules/RateChange/Euristika.cpp.s:
	$(MAKE) -f CMakeFiles/RateChange.dir/build.make CMakeFiles/RateChange.dir/native-modules/RateChange/Euristika.cpp.s
.PHONY : native-modules/RateChange/Euristika.cpp.s

native-modules/RateChange/RateChange.o: native-modules/RateChange/RateChange.cpp.o

.PHONY : native-modules/RateChange/RateChange.o

# target to build an object file
native-modules/RateChange/RateChange.cpp.o:
	$(MAKE) -f CMakeFiles/RateChange.dir/build.make CMakeFiles/RateChange.dir/native-modules/RateChange/RateChange.cpp.o
.PHONY : native-modules/RateChange/RateChange.cpp.o

native-modules/RateChange/RateChange.i: native-modules/RateChange/RateChange.cpp.i

.PHONY : native-modules/RateChange/RateChange.i

# target to preprocess a source file
native-modules/RateChange/RateChange.cpp.i:
	$(MAKE) -f CMakeFiles/RateChange.dir/build.make CMakeFiles/RateChange.dir/native-modules/RateChange/RateChange.cpp.i
.PHONY : native-modules/RateChange/RateChange.cpp.i

native-modules/RateChange/RateChange.s: native-modules/RateChange/RateChange.cpp.s

.PHONY : native-modules/RateChange/RateChange.s

# target to generate assembly for a file
native-modules/RateChange/RateChange.cpp.s:
	$(MAKE) -f CMakeFiles/RateChange.dir/build.make CMakeFiles/RateChange.dir/native-modules/RateChange/RateChange.cpp.s
.PHONY : native-modules/RateChange/RateChange.cpp.s

native-modules/RateChange/VeiksmaiSuFailais.o: native-modules/RateChange/VeiksmaiSuFailais.cpp.o

.PHONY : native-modules/RateChange/VeiksmaiSuFailais.o

# target to build an object file
native-modules/RateChange/VeiksmaiSuFailais.cpp.o:
	$(MAKE) -f CMakeFiles/RateChange.dir/build.make CMakeFiles/RateChange.dir/native-modules/RateChange/VeiksmaiSuFailais.cpp.o
.PHONY : native-modules/RateChange/VeiksmaiSuFailais.cpp.o

native-modules/RateChange/VeiksmaiSuFailais.i: native-modules/RateChange/VeiksmaiSuFailais.cpp.i

.PHONY : native-modules/RateChange/VeiksmaiSuFailais.i

# target to preprocess a source file
native-modules/RateChange/VeiksmaiSuFailais.cpp.i:
	$(MAKE) -f CMakeFiles/RateChange.dir/build.make CMakeFiles/RateChange.dir/native-modules/RateChange/VeiksmaiSuFailais.cpp.i
.PHONY : native-modules/RateChange/VeiksmaiSuFailais.cpp.i

native-modules/RateChange/VeiksmaiSuFailais.s: native-modules/RateChange/VeiksmaiSuFailais.cpp.s

.PHONY : native-modules/RateChange/VeiksmaiSuFailais.s

# target to generate assembly for a file
native-modules/RateChange/VeiksmaiSuFailais.cpp.s:
	$(MAKE) -f CMakeFiles/RateChange.dir/build.make CMakeFiles/RateChange.dir/native-modules/RateChange/VeiksmaiSuFailais.cpp.s
.PHONY : native-modules/RateChange/VeiksmaiSuFailais.cpp.s

native-modules/RateChange/greitis.o: native-modules/RateChange/greitis.cpp.o

.PHONY : native-modules/RateChange/greitis.o

# target to build an object file
native-modules/RateChange/greitis.cpp.o:
	$(MAKE) -f CMakeFiles/RateChange.dir/build.make CMakeFiles/RateChange.dir/native-modules/RateChange/greitis.cpp.o
.PHONY : native-modules/RateChange/greitis.cpp.o

native-modules/RateChange/greitis.i: native-modules/RateChange/greitis.cpp.i

.PHONY : native-modules/RateChange/greitis.i

# target to preprocess a source file
native-modules/RateChange/greitis.cpp.i:
	$(MAKE) -f CMakeFiles/RateChange.dir/build.make CMakeFiles/RateChange.dir/native-modules/RateChange/greitis.cpp.i
.PHONY : native-modules/RateChange/greitis.cpp.i

native-modules/RateChange/greitis.s: native-modules/RateChange/greitis.cpp.s

.PHONY : native-modules/RateChange/greitis.s

# target to generate assembly for a file
native-modules/RateChange/greitis.cpp.s:
	$(MAKE) -f CMakeFiles/RateChange.dir/build.make CMakeFiles/RateChange.dir/native-modules/RateChange/greitis.cpp.s
.PHONY : native-modules/RateChange/greitis.cpp.s

native-modules/TextNormalization/TextNormalization.o: native-modules/TextNormalization/TextNormalization.cpp.o

.PHONY : native-modules/TextNormalization/TextNormalization.o

# target to build an object file
native-modules/TextNormalization/TextNormalization.cpp.o:
	$(MAKE) -f CMakeFiles/TextNormalization.dir/build.make CMakeFiles/TextNormalization.dir/native-modules/TextNormalization/TextNormalization.cpp.o
.PHONY : native-modules/TextNormalization/TextNormalization.cpp.o

native-modules/TextNormalization/TextNormalization.i: native-modules/TextNormalization/TextNormalization.cpp.i

.PHONY : native-modules/TextNormalization/TextNormalization.i

# target to preprocess a source file
native-modules/TextNormalization/TextNormalization.cpp.i:
	$(MAKE) -f CMakeFiles/TextNormalization.dir/build.make CMakeFiles/TextNormalization.dir/native-modules/TextNormalization/TextNormalization.cpp.i
.PHONY : native-modules/TextNormalization/TextNormalization.cpp.i

native-modules/TextNormalization/TextNormalization.s: native-modules/TextNormalization/TextNormalization.cpp.s

.PHONY : native-modules/TextNormalization/TextNormalization.s

# target to generate assembly for a file
native-modules/TextNormalization/TextNormalization.cpp.s:
	$(MAKE) -f CMakeFiles/TextNormalization.dir/build.make CMakeFiles/TextNormalization.dir/native-modules/TextNormalization/TextNormalization.cpp.s
.PHONY : native-modules/TextNormalization/TextNormalization.cpp.s

native-modules/TextNormalization/stringWithLetterPosition.o: native-modules/TextNormalization/stringWithLetterPosition.cpp.o

.PHONY : native-modules/TextNormalization/stringWithLetterPosition.o

# target to build an object file
native-modules/TextNormalization/stringWithLetterPosition.cpp.o:
	$(MAKE) -f CMakeFiles/TextNormalization.dir/build.make CMakeFiles/TextNormalization.dir/native-modules/TextNormalization/stringWithLetterPosition.cpp.o
.PHONY : native-modules/TextNormalization/stringWithLetterPosition.cpp.o

native-modules/TextNormalization/stringWithLetterPosition.i: native-modules/TextNormalization/stringWithLetterPosition.cpp.i

.PHONY : native-modules/TextNormalization/stringWithLetterPosition.i

# target to preprocess a source file
native-modules/TextNormalization/stringWithLetterPosition.cpp.i:
	$(MAKE) -f CMakeFiles/TextNormalization.dir/build.make CMakeFiles/TextNormalization.dir/native-modules/TextNormalization/stringWithLetterPosition.cpp.i
.PHONY : native-modules/TextNormalization/stringWithLetterPosition.cpp.i

native-modules/TextNormalization/stringWithLetterPosition.s: native-modules/TextNormalization/stringWithLetterPosition.cpp.s

.PHONY : native-modules/TextNormalization/stringWithLetterPosition.s

# target to generate assembly for a file
native-modules/TextNormalization/stringWithLetterPosition.cpp.s:
	$(MAKE) -f CMakeFiles/TextNormalization.dir/build.make CMakeFiles/TextNormalization.dir/native-modules/TextNormalization/stringWithLetterPosition.cpp.s
.PHONY : native-modules/TextNormalization/stringWithLetterPosition.cpp.s

native-modules/Transcription/ArKirciuoti.o: native-modules/Transcription/ArKirciuoti.cpp.o

.PHONY : native-modules/Transcription/ArKirciuoti.o

# target to build an object file
native-modules/Transcription/ArKirciuoti.cpp.o:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/ArKirciuoti.cpp.o
.PHONY : native-modules/Transcription/ArKirciuoti.cpp.o

native-modules/Transcription/ArKirciuoti.i: native-modules/Transcription/ArKirciuoti.cpp.i

.PHONY : native-modules/Transcription/ArKirciuoti.i

# target to preprocess a source file
native-modules/Transcription/ArKirciuoti.cpp.i:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/ArKirciuoti.cpp.i
.PHONY : native-modules/Transcription/ArKirciuoti.cpp.i

native-modules/Transcription/ArKirciuoti.s: native-modules/Transcription/ArKirciuoti.cpp.s

.PHONY : native-modules/Transcription/ArKirciuoti.s

# target to generate assembly for a file
native-modules/Transcription/ArKirciuoti.cpp.s:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/ArKirciuoti.cpp.s
.PHONY : native-modules/Transcription/ArKirciuoti.cpp.s

native-modules/Transcription/Kircdb.o: native-modules/Transcription/Kircdb.cpp.o

.PHONY : native-modules/Transcription/Kircdb.o

# target to build an object file
native-modules/Transcription/Kircdb.cpp.o:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/Kircdb.cpp.o
.PHONY : native-modules/Transcription/Kircdb.cpp.o

native-modules/Transcription/Kircdb.i: native-modules/Transcription/Kircdb.cpp.i

.PHONY : native-modules/Transcription/Kircdb.i

# target to preprocess a source file
native-modules/Transcription/Kircdb.cpp.i:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/Kircdb.cpp.i
.PHONY : native-modules/Transcription/Kircdb.cpp.i

native-modules/Transcription/Kircdb.s: native-modules/Transcription/Kircdb.cpp.s

.PHONY : native-modules/Transcription/Kircdb.s

# target to generate assembly for a file
native-modules/Transcription/Kircdb.cpp.s:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/Kircdb.cpp.s
.PHONY : native-modules/Transcription/Kircdb.cpp.s

native-modules/Transcription/Skiemen.o: native-modules/Transcription/Skiemen.cpp.o

.PHONY : native-modules/Transcription/Skiemen.o

# target to build an object file
native-modules/Transcription/Skiemen.cpp.o:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/Skiemen.cpp.o
.PHONY : native-modules/Transcription/Skiemen.cpp.o

native-modules/Transcription/Skiemen.i: native-modules/Transcription/Skiemen.cpp.i

.PHONY : native-modules/Transcription/Skiemen.i

# target to preprocess a source file
native-modules/Transcription/Skiemen.cpp.i:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/Skiemen.cpp.i
.PHONY : native-modules/Transcription/Skiemen.cpp.i

native-modules/Transcription/Skiemen.s: native-modules/Transcription/Skiemen.cpp.s

.PHONY : native-modules/Transcription/Skiemen.s

# target to generate assembly for a file
native-modules/Transcription/Skiemen.cpp.s:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/Skiemen.cpp.s
.PHONY : native-modules/Transcription/Skiemen.cpp.s

native-modules/Transcription/Transcription.o: native-modules/Transcription/Transcription.cpp.o

.PHONY : native-modules/Transcription/Transcription.o

# target to build an object file
native-modules/Transcription/Transcription.cpp.o:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/Transcription.cpp.o
.PHONY : native-modules/Transcription/Transcription.cpp.o

native-modules/Transcription/Transcription.i: native-modules/Transcription/Transcription.cpp.i

.PHONY : native-modules/Transcription/Transcription.i

# target to preprocess a source file
native-modules/Transcription/Transcription.cpp.i:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/Transcription.cpp.i
.PHONY : native-modules/Transcription/Transcription.cpp.i

native-modules/Transcription/Transcription.s: native-modules/Transcription/Transcription.cpp.s

.PHONY : native-modules/Transcription/Transcription.s

# target to generate assembly for a file
native-modules/Transcription/Transcription.cpp.s:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/Transcription.cpp.s
.PHONY : native-modules/Transcription/Transcription.cpp.s

native-modules/Transcription/Transkr.o: native-modules/Transcription/Transkr.cpp.o

.PHONY : native-modules/Transcription/Transkr.o

# target to build an object file
native-modules/Transcription/Transkr.cpp.o:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/Transkr.cpp.o
.PHONY : native-modules/Transcription/Transkr.cpp.o

native-modules/Transcription/Transkr.i: native-modules/Transcription/Transkr.cpp.i

.PHONY : native-modules/Transcription/Transkr.i

# target to preprocess a source file
native-modules/Transcription/Transkr.cpp.i:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/Transkr.cpp.i
.PHONY : native-modules/Transcription/Transkr.cpp.i

native-modules/Transcription/Transkr.s: native-modules/Transcription/Transkr.cpp.s

.PHONY : native-modules/Transcription/Transkr.s

# target to generate assembly for a file
native-modules/Transcription/Transkr.cpp.s:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/Transkr.cpp.s
.PHONY : native-modules/Transcription/Transkr.cpp.s

native-modules/Transcription/fv2id.o: native-modules/Transcription/fv2id.cpp.o

.PHONY : native-modules/Transcription/fv2id.o

# target to build an object file
native-modules/Transcription/fv2id.cpp.o:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/fv2id.cpp.o
.PHONY : native-modules/Transcription/fv2id.cpp.o

native-modules/Transcription/fv2id.i: native-modules/Transcription/fv2id.cpp.i

.PHONY : native-modules/Transcription/fv2id.i

# target to preprocess a source file
native-modules/Transcription/fv2id.cpp.i:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/fv2id.cpp.i
.PHONY : native-modules/Transcription/fv2id.cpp.i

native-modules/Transcription/fv2id.s: native-modules/Transcription/fv2id.cpp.s

.PHONY : native-modules/Transcription/fv2id.s

# target to generate assembly for a file
native-modules/Transcription/fv2id.cpp.s:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/fv2id.cpp.s
.PHONY : native-modules/Transcription/fv2id.cpp.s

native-modules/Transcription/strtokf.o: native-modules/Transcription/strtokf.cpp.o

.PHONY : native-modules/Transcription/strtokf.o

# target to build an object file
native-modules/Transcription/strtokf.cpp.o:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/strtokf.cpp.o
.PHONY : native-modules/Transcription/strtokf.cpp.o

native-modules/Transcription/strtokf.i: native-modules/Transcription/strtokf.cpp.i

.PHONY : native-modules/Transcription/strtokf.i

# target to preprocess a source file
native-modules/Transcription/strtokf.cpp.i:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/strtokf.cpp.i
.PHONY : native-modules/Transcription/strtokf.cpp.i

native-modules/Transcription/strtokf.s: native-modules/Transcription/strtokf.cpp.s

.PHONY : native-modules/Transcription/strtokf.s

# target to generate assembly for a file
native-modules/Transcription/strtokf.cpp.s:
	$(MAKE) -f CMakeFiles/Transcription.dir/build.make CMakeFiles/Transcription.dir/native-modules/Transcription/strtokf.cpp.s
.PHONY : native-modules/Transcription/strtokf.cpp.s

native-modules/UnitSelection/UnitSelection.o: native-modules/UnitSelection/UnitSelection.cpp.o

.PHONY : native-modules/UnitSelection/UnitSelection.o

# target to build an object file
native-modules/UnitSelection/UnitSelection.cpp.o:
	$(MAKE) -f CMakeFiles/UnitSelection.dir/build.make CMakeFiles/UnitSelection.dir/native-modules/UnitSelection/UnitSelection.cpp.o
.PHONY : native-modules/UnitSelection/UnitSelection.cpp.o

native-modules/UnitSelection/UnitSelection.i: native-modules/UnitSelection/UnitSelection.cpp.i

.PHONY : native-modules/UnitSelection/UnitSelection.i

# target to preprocess a source file
native-modules/UnitSelection/UnitSelection.cpp.i:
	$(MAKE) -f CMakeFiles/UnitSelection.dir/build.make CMakeFiles/UnitSelection.dir/native-modules/UnitSelection/UnitSelection.cpp.i
.PHONY : native-modules/UnitSelection/UnitSelection.cpp.i

native-modules/UnitSelection/UnitSelection.s: native-modules/UnitSelection/UnitSelection.cpp.s

.PHONY : native-modules/UnitSelection/UnitSelection.s

# target to generate assembly for a file
native-modules/UnitSelection/UnitSelection.cpp.s:
	$(MAKE) -f CMakeFiles/UnitSelection.dir/build.make CMakeFiles/UnitSelection.dir/native-modules/UnitSelection/UnitSelection.cpp.s
.PHONY : native-modules/UnitSelection/UnitSelection.cpp.s

native-modules/UnitSelection/strtokf.o: native-modules/UnitSelection/strtokf.cpp.o

.PHONY : native-modules/UnitSelection/strtokf.o

# target to build an object file
native-modules/UnitSelection/strtokf.cpp.o:
	$(MAKE) -f CMakeFiles/UnitSelection.dir/build.make CMakeFiles/UnitSelection.dir/native-modules/UnitSelection/strtokf.cpp.o
.PHONY : native-modules/UnitSelection/strtokf.cpp.o

native-modules/UnitSelection/strtokf.i: native-modules/UnitSelection/strtokf.cpp.i

.PHONY : native-modules/UnitSelection/strtokf.i

# target to preprocess a source file
native-modules/UnitSelection/strtokf.cpp.i:
	$(MAKE) -f CMakeFiles/UnitSelection.dir/build.make CMakeFiles/UnitSelection.dir/native-modules/UnitSelection/strtokf.cpp.i
.PHONY : native-modules/UnitSelection/strtokf.cpp.i

native-modules/UnitSelection/strtokf.s: native-modules/UnitSelection/strtokf.cpp.s

.PHONY : native-modules/UnitSelection/strtokf.s

# target to generate assembly for a file
native-modules/UnitSelection/strtokf.cpp.s:
	$(MAKE) -f CMakeFiles/UnitSelection.dir/build.make CMakeFiles/UnitSelection.dir/native-modules/UnitSelection/strtokf.cpp.s
.PHONY : native-modules/UnitSelection/strtokf.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... TextNormalization"
	@echo "... LithuanianTTS"
	@echo "... UnitSelection"
	@echo "... edit_cache"
	@echo "... Transcription"
	@echo "... RateChange"
	@echo "... native-modules/LithuanianTTS/LithuanianTTS.o"
	@echo "... native-modules/LithuanianTTS/LithuanianTTS.i"
	@echo "... native-modules/LithuanianTTS/LithuanianTTS.s"
	@echo "... native-modules/LithuanianTTS/fv2id.o"
	@echo "... native-modules/LithuanianTTS/fv2id.i"
	@echo "... native-modules/LithuanianTTS/fv2id.s"
	@echo "... native-modules/LithuanianTTS/getLUSSErrorMessages.o"
	@echo "... native-modules/LithuanianTTS/getLUSSErrorMessages.i"
	@echo "... native-modules/LithuanianTTS/getLUSSErrorMessages.s"
	@echo "... native-modules/LithuanianTTS/ilgiai.o"
	@echo "... native-modules/LithuanianTTS/ilgiai.i"
	@echo "... native-modules/LithuanianTTS/ilgiai.s"
	@echo "... native-modules/LithuanianTTS/raw2wav.o"
	@echo "... native-modules/LithuanianTTS/raw2wav.i"
	@echo "... native-modules/LithuanianTTS/raw2wav.s"
	@echo "... native-modules/LithuanianTTS/strtokf.o"
	@echo "... native-modules/LithuanianTTS/strtokf.i"
	@echo "... native-modules/LithuanianTTS/strtokf.s"
	@echo "... native-modules/RateChange/Euristika.o"
	@echo "... native-modules/RateChange/Euristika.i"
	@echo "... native-modules/RateChange/Euristika.s"
	@echo "... native-modules/RateChange/RateChange.o"
	@echo "... native-modules/RateChange/RateChange.i"
	@echo "... native-modules/RateChange/RateChange.s"
	@echo "... native-modules/RateChange/VeiksmaiSuFailais.o"
	@echo "... native-modules/RateChange/VeiksmaiSuFailais.i"
	@echo "... native-modules/RateChange/VeiksmaiSuFailais.s"
	@echo "... native-modules/RateChange/greitis.o"
	@echo "... native-modules/RateChange/greitis.i"
	@echo "... native-modules/RateChange/greitis.s"
	@echo "... native-modules/TextNormalization/TextNormalization.o"
	@echo "... native-modules/TextNormalization/TextNormalization.i"
	@echo "... native-modules/TextNormalization/TextNormalization.s"
	@echo "... native-modules/TextNormalization/stringWithLetterPosition.o"
	@echo "... native-modules/TextNormalization/stringWithLetterPosition.i"
	@echo "... native-modules/TextNormalization/stringWithLetterPosition.s"
	@echo "... native-modules/Transcription/ArKirciuoti.o"
	@echo "... native-modules/Transcription/ArKirciuoti.i"
	@echo "... native-modules/Transcription/ArKirciuoti.s"
	@echo "... native-modules/Transcription/Kircdb.o"
	@echo "... native-modules/Transcription/Kircdb.i"
	@echo "... native-modules/Transcription/Kircdb.s"
	@echo "... native-modules/Transcription/Skiemen.o"
	@echo "... native-modules/Transcription/Skiemen.i"
	@echo "... native-modules/Transcription/Skiemen.s"
	@echo "... native-modules/Transcription/Transcription.o"
	@echo "... native-modules/Transcription/Transcription.i"
	@echo "... native-modules/Transcription/Transcription.s"
	@echo "... native-modules/Transcription/Transkr.o"
	@echo "... native-modules/Transcription/Transkr.i"
	@echo "... native-modules/Transcription/Transkr.s"
	@echo "... native-modules/Transcription/fv2id.o"
	@echo "... native-modules/Transcription/fv2id.i"
	@echo "... native-modules/Transcription/fv2id.s"
	@echo "... native-modules/Transcription/strtokf.o"
	@echo "... native-modules/Transcription/strtokf.i"
	@echo "... native-modules/Transcription/strtokf.s"
	@echo "... native-modules/UnitSelection/UnitSelection.o"
	@echo "... native-modules/UnitSelection/UnitSelection.i"
	@echo "... native-modules/UnitSelection/UnitSelection.s"
	@echo "... native-modules/UnitSelection/strtokf.o"
	@echo "... native-modules/UnitSelection/strtokf.i"
	@echo "... native-modules/UnitSelection/strtokf.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

