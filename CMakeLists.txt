# Sets the minimum required version of cmake for a project. 
#If the running version of CMake is lower than the <min> required 
#version it will stop processing the project and report an error.

cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

# Set the name of the project and stores it in the variable PROJECT_NAME.
# When called from the CMakeLists.txt also stores the project name in the variable CMAKE_PROJECT_NAME.
# Also sets the variables:
# PROJECT_SOURCE_DIR, <PROJECT-NAME>_SOURCE_DIR
# PROJECT_BINARY_DIR, <PROJECT-NAME>_BINARY_DIR

project(ANFg4App)

#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#

find_package(Geant4 REQUIRED ui_all vis_all)


#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
# Setup include directory for this project
#
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

#----------------------------------------------------------------------------
# Locate sources and headers for this project
# NB: headers are included so they will show up in IDEs
#
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# Add an executable to the project using the specified source files.

add_executable(ANFmain ANF_Main.cc ${sources} ${headers})

target_link_libraries(ANFmain ${Geant4_LIBRARIES})
