# -----------------------------------------------------------------------------
# @file                 CMakeLists.txt
# @brief                Top-Level CMakeList
# -----------------------------------------------------------------------------

# Set the minimum CMake version required for this project
cmake_minimum_required( VERSION 3.25 )

# Organize targets into different folders
set_property( GLOBAL PROPERTY USE_FOLDERS ON )

# Generate the compile commands
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
set( COMPILE_COMMANDS_PATH ${CMAKE_BINARY_DIR}/build/cmake )

# Set the project description
project(
        STM32G0XX_Blink_Cpp
        VERSION 0.1
        DESCRIPTION "STM32 Blink Written in C++"
        LANGUAGES CXX
)

# Set the C++ standard that will be used
set( CMAKE_CXX_STANDARD                 20  )
set( CMAKE_CXX_STANDARD_REQUIRED        ON  )
set( CMAKE_CXX_EXTENSIONS               OFF )

# Set the target variable for the project
set( MAIN_TARGET stm32g0xx_blink )

# Create the executable
add_executable( ${MAIN_TARGET} )

# Add the sources to the executable
target_sources( ${MAIN_TARGET} PUBLIC
        # Main File
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/startup_stm32g071.cpp
)

