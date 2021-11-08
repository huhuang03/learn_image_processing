add_executable(example_inverse example_inverse.cc)
target_link_libraries(example_inverse ${OpenCV_LIBS})
target_include_directories(example_inverse PRIVATE ${OpenCV_INCLUDE_DIRS})

add_executable(custom_equalize custom_equalize/custom_equalize.cc custom_equalize/main_custom_equalize.cc)
target_link_libraries(custom_equalize ${OpenCV_LIBS})
target_include_directories(custom_equalize PRIVATE ${OpenCV_INCLUDE_DIRS})

add_executable(demo_median_filter video10_demo_median_filter/demo_median_filter.cc)
target_link_libraries(demo_median_filter ${OpenCV_LIBS})
target_include_directories(demo_median_filter PRIVATE ${OpenCV_INCLUDE_DIRS})
