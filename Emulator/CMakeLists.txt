cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Set the project name
project(tiaraCore)

# Enable testing
enable_testing()

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

# Set the optimization level (if not specified on the command line)
if(NOT CMAKE_BUILD_TYPE)
set(CMAKE_BUILD_TYPE Release)
endif()

# Add the emulator library
add_library(tiaraCore Tiara.cpp config.cpp)

# Add the console app (Tiara Headless)
add_executable(tiaraConsole Headless.cpp config.cpp)
target_link_libraries(tiaraConsole tiaraCore)

# Specify compile options
target_compile_definitions(tiaraCore PUBLIC _USE_MATH_DEFINES)
if(WIN32)
  target_link_libraries(tiaraConsole ws2_32)
endif()
if(MSVC)
  target_compile_options(tiaraCore PUBLIC /W4 /WX /Zc:preprocessor)
  target_compile_options(tiaraCore PUBLIC /wd4100 /wd4201 /wd4324 /wd4458 /wd4996)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(tiaraCore PUBLIC -Wall -Werror)
  target_compile_options(tiaraCore PUBLIC -Wno-restrict)
  target_compile_options(tiaraCore PUBLIC -Wno-unused-parameter)
  target_compile_options(tiaraCore PUBLIC -Wno-attributes)
  target_compile_options(tiaraCore PUBLIC -fconcepts)
else()
  target_compile_options(tiaraCore PUBLIC -Wall -Werror)
  target_compile_options(tiaraCore PUBLIC -Wno-unused-parameter)
  target_compile_options(tiaraCore PUBLIC -Wno-gnu-anonymous-struct)
  target_compile_options(tiaraCore PUBLIC -Wno-nested-anon-types)
endif()

# Add include paths
target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add sub directories
add_subdirectory(Base)
add_subdirectory(Components)
add_subdirectory(Media)
add_subdirectory(Misc)
add_subdirectory(Peripherals)
add_subdirectory(Utilities)

# Add libraries
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(tiaraCore Threads::Threads)

# Add tests
add_test(NAME SelfTest1 COMMAND tiaraConsole --verbose --footprint)
add_test(NAME SelfTest2 COMMAND tiaraConsole --verbose --smoke)
add_test(NAME SelfTest3 COMMAND tiaraConsole --verbose --diagnose)
