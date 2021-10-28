add_executable(example_inverse example_inverse.cc)
target_link_libraries(example_inverse ${OpenCV_LIBS})
target_include_directories(example_inverse PRIVATE ${OpenCV_INCLUDE_DIRS})
