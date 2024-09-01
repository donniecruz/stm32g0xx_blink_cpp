# -----------------------------------------------------------------------------
# @file                 arm-none-eabi-toolchain.cmake
# @brief                CMake ARM toolchain
# -----------------------------------------------------------------------------
set(C_FLAGS                         "-fdata-sections -ffunction-sections --specs=nano.specs -Wl,--gc-sections")
set(CPP_FLAGS                       "-fno-rtti -fno-exceptions -fno-threadsafe-statics")

# -----------------------------------------------------------------------------
# CMAKE Toolchain
# -----------------------------------------------------------------------------

set( CMAKE_SYSTEM_NAME      Generic )
set( CMAKE_SYSTEM_PROCESSOR arm     )

if( NOT DEFINED CMAKE_BUILD_TYPE )
    set( CMAKE_BUILD_TYPE   Debug )
endif()

# -----------------------------------------------------------------------------
# FIND_ROOT_PATH Configuration
# -----------------------------------------------------------------------------
set( CMAKE_FIND_ROOT_PATH
        /bin
        /sbin
        /usr/bin
        /usr/sbin
)

set( CMAKE_FIND_ROOT_PATH_MODE_PROGRAM  NEVER )
set( CMAKE_FIND_ROOT_PATH_MODE_LIBRARY  ONLY  )
set( CMAKE_FIND_ROOT_PATH_MODE_INCLUDE  ONLY  )
set( CMAKE_FIND_ROOT_PATH_MODE_PACKAGE  ONLY  )

# -----------------------------------------------------------------------------
# Setup the Required Build Tools
# -----------------------------------------------------------------------------
set( TOOLCHAIN "arm-none-eabi" CACHE STRING "" )

# C Compiler
find_program( CMAKE_C_COMPILER
    ${TOOLCHAIN}-gcc
    PATH_SUFFIXES bin
    REQUIRED
    ONLY_CMAKE_FIND_ROOT_PATH
)

# C++ Compiler
find_program( CMAKE_CXX_COMPILER
    ${TOOLCHAIN}-c++
    PATH_SUFFIXES bin
    REQUIRED
    ONLY_CMAKE_FIND_ROOT_PATH
)

# ASM Compiler
find_program( CMAKE_ASM_COMPILER
    ${TOOLCHAIN}-gcc
    PATH_SUFFIXES bin
    REQUIRED
    ONLY_CMAKE_FIND_ROOT_PATH
)

# GCC OBJCOPY
find_program( CMAKE_OBJCOPY
    ${TOOLCHAIN}-objcopy
    PATH_SUFFIXES bin
    REQUIRED
    ONLY_CMAKE_FIND_ROOT_PATH
)

# GCC Size
find_program( CMAKE_SIZE
    ${TOOLCHAIN}-size
    PATH_SUFFIXES bin
    REQUIRED
    ONLY_CMAKE_FIND_ROOT_PATH
)

# -----------------------------------------------------------------------------
# Setup the Compile and Linker Flags
# -----------------------------------------------------------------------------

# Set the C++ Debug Flags
set( CMAKE_CXX_FLAGS_DEBUG "-g -Og -g3 -DDEBUG" CACHE STRING "C++ Compiler Flags Debug")

# Set the C++ Release Flags
set( CMAKE_CXX_FLAGS_RELEASE "-O3 -flto" CACHE STRING "C++ Compiler Flags Release")

# Set the Linker Flags
set( CMAKE_EXE_LINKER_FLAGS "--specs=nano.specs --specs=nosys.specs" CACHE INTERNAL "Linker Options" )

# Set the compile options flags
set( PROJECT_COMPILE_OPTIONS
    -fno-common
    -fstack-usage
    -fdata-sections
    -ffunction-sections
    -fno-builtin
    -fno-strict-aliasing
    -fno-short-enums
    -fno-exceptions
    -fno-rtti
)

# Set the compile warnings flags
set( PROJECT_COMPILE_WARNINGS
    -Werror
    -Wall
    -Wextra
    -Wundef
    -Wshadow
    -Wunused
    -Wconversion
    -Wno-register
    -Wpointer-arith
    -Wno-write-strings
    -Wno-maybe-uninitialized
)

# Set the linker flags
set( PROJECT_LINKER_OPTIONS
    -Wl,--gc-sections
    -Wl,--warn-common
    -Wl,--warn-section-align
    -Wl,--cref
    -Wl,--no-enum-size-warning
)

# Set the CPU options
set( CM0_PLUS_OPTIONS
    -mthumb
    -mcpu=cortex-m0plus
    -mfloat-abi=soft
)
