cmake_minimum_required(VERSION 3.10.0)
project(PROJECT_1 VERSION 1.0.0)

find_package(
    OpenGL REQUIRED 
)


add_executable(project_1 
    src/config.h 
    src/main.cpp 
    src/glad.c
)


target_include_directories(project_1 PRIVATE dependencies)
target_link_libraries(project_1 glfw3 OpenGL::GL)