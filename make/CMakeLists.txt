cmake_minimum_required (VERSION 3.0)

# FLAGS
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

#PROEJECT
project (LD44)

#DIRECTORY
set (ProjectRootFolder "${PROJECT_SOURCE_DIR}/..")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${ProjectRootFolder}/build/obj")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${ProjectRootFolder}/build/obj")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${ProjectRootFolder}/build/")

#ADD CODE
file (GLOB_RECURSE sourceFilies "${ProjectRootFolder}/code/*.cpp")
add_executable( LD44 ${sourceFilies})

# ADD LIBRARY
target_link_libraries(LD44 -lsfml-graphics)
target_link_libraries(LD44 -lsfml-window)
target_link_libraries(LD44 -lsfml-system)