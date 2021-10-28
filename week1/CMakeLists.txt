set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets)


add_executable(test_affine_transformation test_affine_transformation.cc)

target_link_libraries(test_affine_transformation ${OpenCV_LIBS})
target_include_directories(test_affine_transformation PRIVATE ${OpenCV_INCLUDE_DIRS})

add_executable(week1_exam week1_exam.cc)
target_link_libraries(week1_exam ${OpenCV_LIBS})
target_include_directories(week1_exam PRIVATE ${OpenCV_INCLUDE_DIRS})
