# Somewhat arbitrary minimum version covers Debian Bullseye 11 (Fall 2022)
cmake_minimum_required(VERSION 3.18.0)

# Name your project
project(quadratic_formula C)

# Set defines/shorthand here
set(INC_DIR ${CMAKE_SOURCE_DIR}/include())

# Optimization flags - production vs debug, etc.
# cf. https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
#set(OPTIMIZATION_FLAGS "-Og -g3") # debug symbols
set(OPTIMIZATION_FLAGS "-O3") # Lots of optimization, no debug symbols

# Common flags usually for architecture or tuning
# cf. https://gcc.gnu.org/onlinedocs/gcc/x86-Options.html
set(COMMON_FLAGS "") # e.g. -march=znver3 for an AMD Zen 3 CPU, etc. with GCC 12+

# Set other options/flags
# cf. https://gcc.gnu.org/onlinedocs/gcc/Invoking-GCC.html
#set(OTHER_FLAGS "-pg --ftest-coverage")

# Concatenate flags
set(C_FLAGS "${OPTIMIZATION_FLAGS} ${COMMON_FLAGS}") # also include ${OTHER_FLAGS}, etc.
set(C_FLAGS "${C_FLAGS} -Wall -Wextra -Wpedantic -Werror") # always be pedantic, always error

set(LINKER_FLAGS "${OPTIMIZATION_FLAGS} ${COMMON_FLAGS}")
#set(LINKER_FLAGS "${LINKER_FLAGS} -Wl,-emain,--gc-sections,--print-memory-usage")

# Set the flags for CMake
set(CMAKE_C_FLAGS "${C_FLAGS} -std=c17" CACHE INTERNAL "")
set(CMAKE_EXE_LINKER_FLAGS "${LINKER_FLAGS}" CACHE INTERNAL "")

# First add the executable
add_executable(quadratic_formula ${CMAKE_SOURCE_DIR}/src/main.c)

# Set its properties
set_target_properties(quadratic_formula PROPERTIES C_STANDARD 17)

# Add other sources
target_sources(quadratic_formula PUBLIC src/quadratic.c)

# Link any libraries you might need (m for math.h)
target_link_libraries(quadratic_formula PRIVATE m)

# Include your headers
target_include_directories(quadratic_formula PUBLIC ${INC_DIR})

# Postbuild commands - objdump, readelf, etc.
#add_custom_command(
#    TARGET quadratic_formula
#    POST_BUILD
#    COMMAND some_postproc_command
#)
