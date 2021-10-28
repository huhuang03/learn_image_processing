cmake_minimum_required(VERSION 3.12)

if (NOT DEFINED ENV{VCPKG_ROOT})
    message(Please set the vcpkg_root env)
else()
    if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
    endif()
endif()

project(learn_image_processing)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/imgs DESTINATION ${CMAKE_BINARY_DIR})

find_package(OpenCV REQUIRED)

add_subdirectory(week1)
add_subdirectory(week3)