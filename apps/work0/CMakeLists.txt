cmake_minimum_required(VERSION 3.12)
project(work VERSION 1.0 DESCRIPTION "home work" LANGUAGES CXX)

# Build
file(GLOB_RECURSE SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)
add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME}
  PUBLIC
    python3.10
    ${OpenCV_LIBS}
)
