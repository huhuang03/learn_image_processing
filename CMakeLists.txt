cmake_minimum_required(VERSION 3.12)

project(learn_image_processing)

message(${CMAKE_SIZEOF_VOID_P})

if (NOT DEFINED ENV{VCPKG_ROOT})
    message(Please set the vcpkg_root env)
else()
    if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
    endif()
endif()

set( OpenCV_DIR )
if( NOT CMAKE_CL_64 )
    set( OpenCV_DIR "$ENV{VCPKG_ROOT}/installed/x86-windows/share/opencv" )
else()
    set( OpenCV_DIR "$ENV{VCPKG_ROOT}/installed/x64-windows/share/opencv" )
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/imgs DESTINATION ${CMAKE_BINARY_DIR})

# Found OpenCV: E:/source/vcpkg/installed/x64-windows (found version "4.3.0")
# why you can't use the x32 version?
add_subdirectory(week1)