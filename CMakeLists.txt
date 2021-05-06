cmake_minimum_required(VERSION 3.20)

project(Game)

set(CMAKE_CXX_STANDARD 17)
set(COMMON_CXX_FLAGS "${COMMON_CXX_FLAGS} -Wall -Werror")

add_subdirectory(libs/glfw)
add_subdirectory(libs/glad)

file(GLOB_RECURSE SRC_FILES
    src/*.cpp
    src/*.hpp
)

set(INCLUDE_DIRS
    src
    libs/glfw/include
    libs/glad/include
    libs/glm
)

set(LIBS
    glfw
    glad
)

add_executable(Game ${SRC_FILES})
target_include_directories(Game PUBLIC ${INCLUDE_DIRS})
target_compile_definitions(Game PUBLIC $<$<CONFIG:DEBUG>:DEBUG>)
target_link_libraries(Game PUBLIC ${LIBS})