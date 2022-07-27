cmake_minimum_required(VERSION 3.12)
project(numeric_optimal VERSION 1.0 DESCRIPTION "numeric optimal" LANGUAGES CXX)

# Build option
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_COMPILER /usr/bin/g++ CACHE PATH "")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Dependencies
file(GLOB_RECURSE CMAKES cmake/*.cmake)
foreach(CMAKE ${CMAKES})
  include(${CMAKE})
endforeach()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(apps/work0)
add_subdirectory(apps/work1)
