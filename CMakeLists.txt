cmake_minimum_required(VERSION 3.5.1)

project(image_transformation)

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

#generate project binary
add_executable(
        ${PROJECT_NAME}
        ${INC_DIR}/stb_image.h
        ${INC_DIR}/stb_image_write.h
        ${INC_DIR}/image.h

        ${SRC_DIR}/main.cpp
        ${SRC_DIR}/image.cpp
)

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${INC_DIR}
)



